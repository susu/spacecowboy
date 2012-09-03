#include <sc/evt/BaseTypes.hpp>
#include <sc/evt/Hub.hpp>
#include <sc/evt/Handler.hpp>
#include <sc/evt/Event.hpp>


sc::evt::Hub::~Hub()
{
}

void
sc::evt::Hub::dispatchEvent( Event& event )
{
  event.handle( m_registry );
}


void
sc::evt::Hub::add( Handler& handler )
{
  handler.subscribe( m_registry );
}


bool
sc::evt::Hub::hasHandlerFor( SlotId slot ) const
{
  Registry::const_iterator it( m_registry.find( slot ) );
  return it!=m_registry.end() && !it->second.empty();
}

