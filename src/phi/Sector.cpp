#include <sc/phi/Sector.hpp>
#include <sc/phi/Object.hpp>

#include <iostream>
#include <algorithm>

sc::phi::Sector::Sector()
  : m_objects()
  , m_deletables()
{
}


void
sc::phi::Sector::addObject( const ObjectRef& object )
{
  m_objects.push_back( object );
}


void
sc::phi::Sector::tick()
{
  removeDeletables();

  for ( auto& i : m_objects )
  {
    i->timeElapsed( 0.01 );
  }
}


void
sc::phi::Sector::removeDeletables()
{
  for ( auto& objPtr : m_deletables )
  {
    auto newEnd( std::remove_if( m_objects.begin(), m_objects.end(),
        [ &objPtr ]( const ObjectRef& objRef )
        { return objPtr == objRef.get(); } ) );

    m_objects.erase( newEnd, m_objects.end() );
  }

  m_deletables.clear();
}


void
sc::phi::Sector::deletable( Object* object )
{
  m_deletables.insert( object );
}

