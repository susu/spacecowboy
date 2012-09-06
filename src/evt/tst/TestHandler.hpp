#pragma once

#include "sc/evt/BaseTypes.hpp"
#include "sc/evt/Event.hpp"
#include "sc/evt/Handler.hpp"

namespace test
{

  class TestHandler : public sc::evt::Handler
  {
    public:
      TestHandler( const sc::evt::SlotId& slot )
        : sc::evt::Handler()
        , m_called( false )
        , m_slot( slot )
      {
      }

      void handleEvent( sc::evt::Event& event )
      {
        m_called = true;
      }

      void subscribe( sc::evt::Registry& registry )
      {
        registerMemberFunction( registry, &TestHandler::handleEvent, m_slot );
      }

      void assertHandlerNotified( bool notified ) const
      {
        TS_ASSERT( notified ? m_called : !m_called );
      }

      void reset()
      {
        m_called = false;
      }

    private:
      bool m_called;
      sc::evt::SlotId m_slot;
  };

}

