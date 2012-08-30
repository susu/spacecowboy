#include <sc/evt/Event.hpp>
#include <algorithm>

void
sc::evt::Event::notifySlot( Registry& registry, const SlotId& slot )
{
  for ( auto& callback : registry[ slot ] )
  {
    callback( *this );
  }
}


sc::evt::BinaryEvent::BinaryEvent( const SlotId& slot )
  : Event()
  , m_slots( 1, slot )
{
}


void
sc::evt::BinaryEvent::addSlot( const SlotId& slot )
{
  m_slots.push_back( slot );
}


void
sc::evt::BinaryEvent::handle( Registry& registry )
{
  for ( auto& slot : m_slots )
  {
    notifySlot( registry, slot );
  }
}

