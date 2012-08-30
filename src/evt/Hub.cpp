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

