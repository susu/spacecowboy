#include <sc/phi/ExplosionBehaviour.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/ExplosionEvent.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/evt/Event.hpp>

sc::phi::ExplosionBehaviour::ExplosionBehaviour( Sector& sector, Object* explosion )
  : Accessory()
  , m_explosion( explosion )
  , m_sector( sector )
{
}


sc::phi::ExplosionBehaviour::~ExplosionBehaviour()
{
}


void
sc::phi::ExplosionBehaviour::timer( sc::evt::Event& event )
{
  sc::phi::ExplosionEvent explosion( *m_physicalModel, 100 );
  for ( auto& collider : m_sector.colliders() )
  {
    collider->dispatchEvent( explosion );
  }
  m_explosion->deleteObject();
}


void
sc::phi::ExplosionBehaviour::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &ExplosionBehaviour::timer, slot::TIMEELAPSED );
}

