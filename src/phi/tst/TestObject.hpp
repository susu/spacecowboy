#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Object.hpp>

namespace test
{

  class TestObject : public sc::phi::Object
  {
    public:
      TestObject( sc::phi::Sector& sector, const sc::phi::ObjectProperties& prop )
        : sc::phi::Object( sector, prop )
        , m_startingPosition( prop.coordinate )
      {
      }

      void assertMoved()
      {
        TS_ASSERT_DIFFERS( m_startingPosition, m_physicalModel.coordinate() );
      }

      void assertRotated()
      {
        TS_ASSERT_DIFFERS( m_headingAtStart, m_physicalModel.heading() );
      }

      void assertDidNotMove()
      {
        TS_ASSERT_EQUALS( m_startingPosition, m_physicalModel.coordinate() );
      }

      void assertTimerUpdateCalled()
      {
        TS_ASSERT( m_timerUpdateCalled );
      }

    private:
      virtual void timerUpdate( const sc::phi::Ratio& ratio )
      {
        m_timerUpdateCalled = true;
      }

      sc::phi::Coordinate m_startingPosition;
      bool m_timerUpdateCalled = false;
      double m_headingAtStart = m_physicalModel.heading();
  };
}

