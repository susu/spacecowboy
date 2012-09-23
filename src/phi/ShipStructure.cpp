#include <sc/phi/ShipStructure.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Object.hpp>
#include <sc/evt/BaseTypes.hpp>

#include <iostream>

sc::phi::ShipStructure::ShipStructure( const ObjectRef& object )
  : Accessory()
  , m_object( object.get() )
  , m_integrity( 100 )
{
}


sc::phi::ShipStructure::~ShipStructure()
{
}


void
sc::phi::ShipStructure::collisionDamage( sc::evt::Event& )
{
  m_integrity-=10;
  dieIfDamagedEnough();
}


void
sc::phi::ShipStructure::explosionDamage( sc::evt::Event& )
{
  m_integrity-=30;
  dieIfDamagedEnough();
}


void
sc::phi::ShipStructure::dieIfDamagedEnough()
{
  if ( m_integrity > 0 )
  {
    return;
  }

  m_object->deleteObject();
}


int
sc::phi::ShipStructure::getIntegrity() const
{
  return m_integrity > 0 ? m_integrity : 0;
}


void
sc::phi::ShipStructure::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &ShipStructure::collisionDamage, slot::COLLISION_DAMAGE );
  registerMemberFunction( registry, &ShipStructure::explosionDamage, slot::EXPLOSION_DAMAGE );
}

