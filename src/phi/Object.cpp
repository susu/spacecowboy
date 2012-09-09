#include <sc/phi/Object.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/CollisionEvent.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/evt/Hub.hpp>

#include <cmath>

sc::phi::Object::Object( Sector& sector )
  : evt::Hub()
  , m_physicalModel( Coordinate( 100.0, 100.0 )
                    ,Coordinate( 0.0, 0.0 )
                    ,0.0
                    ,0.0
                    ,10.0 )
  , m_sector( sector )
{
}


sc::phi::Object::Object( Sector& sector, const ObjectProperties& properties )
  : evt::Hub()
  , m_physicalModel( properties.coordinate
                    ,properties.speed
                    ,properties.heading
                    ,0.0
                    ,properties.radius )
  , m_sector( sector )
{
}


sc::phi::Object::~Object()
{
}


void
sc::phi::Object::timeElapsed( const Ratio& stepRatio )
{
  m_physicalModel.timeElapse( stepRatio );
  timerUpdate( stepRatio );
}


bool
sc::phi::Object::isColliding() const
{
  return hasHandlerFor( slot::COLLISION );
}


void
sc::phi::Object::checkCollision( const std::list<sc::phi::ObjectRef>& collection )
{
  for ( auto& i : collection )
  {
    if ( i.get() == this )
    {
      continue;
    }

    if ( collides( m_physicalModel, i->m_physicalModel ) )
    {
      CollisionEvent collision( i, i->m_physicalModel );
      dispatchEvent( collision );
    }
  }
}


void
sc::phi::Object::addAccessory( const AccessoryRef& accessory )
{
  m_accessories.push_back( accessory );
  accessory->initialize( m_physicalModel );
  add( *accessory );
}

