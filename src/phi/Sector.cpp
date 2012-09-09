#include <sc/phi/Sector.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/Event.hpp>

#include <iostream>
#include <algorithm>

namespace
{
  void removeDeletable(
      std::list<sc::phi::ObjectRef>& from,
      const std::set<sc::phi::Object*>& what )
  {
    for ( auto& objPtr : what )
    {
      auto newEnd( std::remove_if( from.begin(), from.end(),
            [ &objPtr ]( const sc::phi::ObjectRef& objRef )
            { return objPtr == objRef.get(); } ) );

       from.erase( newEnd, from.end() );
    }
  }


  void updateTimeForEach(
      const std::list<sc::phi::ObjectRef>& collection,
      const sc::phi::Ratio& ratio )
  {
    sc::evt::BinaryEvent event( sc::phi::slot::TIMEELAPSED );
    for ( auto& i : collection )
    {
      i->timeElapsed( ratio );
      i->dispatchEvent( event );
    }
  }


  void checkCollisionForEach( const std::list<sc::phi::ObjectRef>& collection )
  {
    for ( auto& i : collection )
    {
      i->checkCollision( collection );
    }
  }

}

sc::phi::Sector::Sector()
  : m_nonColliders()
  , m_colliders()
  , m_deletables()
{
}


void
sc::phi::Sector::addObject( const ObjectRef& object )
{
  object->isColliding() ?
    m_colliders.push_back( object ) :
    m_nonColliders.push_back( object );
}


void
sc::phi::Sector::tick()
{
  checkCollisionForEach( m_colliders );

  removeDeletable( m_nonColliders, m_deletables );
  removeDeletable( m_colliders, m_deletables );
  m_deletables.clear();

  updateTimeForEach( m_nonColliders, 0.1 );
  updateTimeForEach( m_colliders, 0.1 );
}


void
sc::phi::Sector::deletable( Object* object )
{
  m_deletables.insert( object );
}

