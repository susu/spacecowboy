#include <sc/phi/Sector.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/Event.hpp>

#include <iostream>
#include <algorithm>

namespace
{

  void updateTimeForEachAndRemoveDeleted(
      sc::phi::ObjectContainer& collection,
      const sc::phi::Ratio& ratio )
  {
    sc::evt::BinaryEvent event( sc::phi::slot::TIMEELAPSED );
    for ( sc::phi::ObjectContainer::iterator i( collection.begin() ); i!=collection.end(); )
    {
      sc::phi::Object& object( **i );
      if ( object.isDeleted() )
      {
        i = collection.erase( i );
        continue;
      }

      object.timeElapsed( ratio );
      object.dispatchEvent( event );
      ++i;
    }
  }


  void checkCollisionForEach( const sc::phi::ObjectContainer& collection )
  {
    for ( auto& i : collection )
    {
      i->checkCollision( collection );
    }
  }


  void pourNewObjects( std::vector<sc::phi::ObjectRef>& from, sc::phi::ObjectContainer& to )
  {
    to.insert( to.end(), from.begin(), from.end() );
    from.clear();
  }

}

  sc::phi::Sector::Sector()
  : m_nonColliders()
  , m_colliders()
  , m_newColliders()
  , m_newNonColliders()
{
}


void
sc::phi::Sector::addObject( const ObjectRef& object )
{
  object->isColliding() ?
    m_newColliders.push_back( object ) :
    m_newNonColliders.push_back( object );
}


void
sc::phi::Sector::tick()
{
  checkCollisionForEach( m_colliders );

  updateTimeForEachAndRemoveDeleted( m_nonColliders, 0.1 );
  updateTimeForEachAndRemoveDeleted( m_colliders, 0.1 );

  pourNewObjects( m_newColliders, m_colliders );
  pourNewObjects( m_newNonColliders, m_nonColliders );
}


const sc::phi::ObjectContainer&
sc::phi::Sector::colliders() const
{
  return m_colliders;
}

