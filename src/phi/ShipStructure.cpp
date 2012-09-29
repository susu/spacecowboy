#include <sc/phi/ShipStructure.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/IntegrityChangeEvent.hpp>
#include <sc/evt/BaseTypes.hpp>


sc::phi::ShipStructure::ShipStructure()
  : Accessory()
  , m_integrity( 100 )
{
}


sc::phi::ShipStructure::~ShipStructure()
{
}


void
sc::phi::ShipStructure::collisionDamage( sc::evt::Event& )
{
  m_integrity-=3;
  handleShipDamaged();
}


void
sc::phi::ShipStructure::explosionDamage( sc::evt::Event& )
{
  m_integrity-=50;
  handleShipDamaged();
}


void
sc::phi::ShipStructure::handleShipDamaged()
{
  notifyAboutIntegrityChange();
  dieIfDamagedEnough();
}


void
sc::phi::ShipStructure::notifyAboutIntegrityChange()
{
  sc::phi::IntegrityChanged event( m_integrity );
  m_owningObject->dispatchEvent( event );
}


void
sc::phi::ShipStructure::dieIfDamagedEnough()
{
  if ( m_integrity > 0 )
  {
    return;
  }

  m_owningObject->deleteObject();
}


void
sc::phi::ShipStructure::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &ShipStructure::collisionDamage, slot::COLLISION_DAMAGE );
  registerMemberFunction( registry, &ShipStructure::explosionDamage, slot::EXPLOSION_DAMAGE );
}

