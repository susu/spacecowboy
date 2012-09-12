#include <sc/phi/ExplosionEvent.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Model.hpp>
#include <sc/evt/Event.hpp>

sc::phi::ExplosionEvent::ExplosionEvent( const Model& physicalModel, unsigned int power )
  : sc::evt::Event()
  , m_physicalModel( physicalModel )
  , m_power( power )
{
}

void
sc::phi::ExplosionEvent::handle( sc::evt::Registry& registry )
{
  notifySlot( registry, slot::EXPLOSION );
}


const sc::phi::Model&
sc::phi::ExplosionEvent::model() const
{
  return m_physicalModel;
}


unsigned int
sc::phi::ExplosionEvent::power() const
{
  return m_power;
}

