#include <sc/phi/ExplosionBehaviour.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/Event.hpp>

sc::phi::ExplosionBehaviour::ExplosionBehaviour( Object* explosion )
  : Accessory()
  , m_explosion( explosion )
{
}


sc::phi::ExplosionBehaviour::~ExplosionBehaviour()
{
}


void
sc::phi::ExplosionBehaviour::timer( sc::evt::Event& event )
{
  m_explosion->deleteObject();
}


void
sc::phi::ExplosionBehaviour::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &ExplosionBehaviour::timer, slot::TIMEELAPSED );
}

