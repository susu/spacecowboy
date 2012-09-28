#include <cxxtest/TestSuite.h>

#include "sc/phi/BaseTypes.hpp"
#include "sc/phi/Sector.hpp"
#include "sc/phi/EventSlots.hpp"
#include "sc/evt/Event.hpp"
#include "TestObjectFactory.hpp"


class EngineTest : public CxxTest::TestSuite
{
  protected:
    sc::phi::Coordinate m_speed_still = { 0.0, 0.0 };
    sc::phi::Coordinate m_start_coordinate = { 0.0, 0.0 };

  public:
    void test_object_should_start_only_if_thruster_event_arrives()
    {
      sc::phi::Sector sector;
      test::TestObjectFactory objectFactory( sector );
      test::TestObject* testObject(
          objectFactory.createTestShip( sc::phi::ObjectProperties( m_start_coordinate, m_speed_still, 0.0, 10, 1 ) ) );

      sector.tick();
      testObject->assertDidNotMove();

      sc::evt::BinaryEvent event( sc::phi::slot::BACKTHRUSTER );
      event.addSlot( sc::phi::slot::CWTHRUSTER );
      testObject->dispatchEvent( event );

      sector.tick();
      testObject->assertMoved();
      testObject->assertRotated();
    }
};

