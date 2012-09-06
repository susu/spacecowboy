#pragma once

#include "sc/evt/BaseTypes.hpp"
#include "sc/phi/Accessory.hpp"

namespace test
{

  class TestAccessory : public sc::phi::Accessory
  {
    public:
      TestAccessory( const sc::evt::SlotId& slot )
        : sc::phi::Accessory()
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
        registerMemberFunction( registry, &TestAccessory::handleEvent, m_slot );
      }

      void assertHandlerNotified( bool notified ) const
      {
        TS_ASSERT( notified ? m_called : !m_called );
      }

      void assertHasBeenInitialized() const
      {
        TS_ASSERT( m_physicalModel );
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

