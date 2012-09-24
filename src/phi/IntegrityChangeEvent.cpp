#include <sc/phi/IntegrityChangeEvent.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/Event.hpp>

sc::phi::IntegrityChanged::IntegrityChanged( int integrity )
  : sc::evt::Event()
  , m_integrity( integrity )
{
}

void
sc::phi::IntegrityChanged::handle( sc::evt::Registry& registry )
{
  notifySlot( registry, slot::OBJECT_INTEGRITY_CHANGED );
}


int
sc::phi::IntegrityChanged::integrity() const
{
  return m_integrity;
}

