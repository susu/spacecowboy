#include <sc/phi/ExplosionEvent.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/Event.hpp>

sc::phi::ExplosionEvent::ExplosionEvent( const Coordinate& center, int power )
  : sc::evt::Event()
  , m_center( center )
  , m_power( power )
{
}

void
sc::phi::ExplosionEvent::handle( sc::evt::Registry& registry )
{
  notifySlot( registry, slot::EXPLOSION );
}


sc::phi::Coordinate
sc::phi::ExplosionEvent::center() const
{
  return m_center;
}


int
sc::phi::ExplosionEvent::power() const
{
  return m_power;
}

