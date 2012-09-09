#include <cxxtest/TestSuite.h>

#include "sc/phi/BaseTypes.hpp"
#include "sc/phi/Sector.hpp"
#include "sc/phi/EventSlots.hpp"
#include "sc/phi/CollisionEvent.hpp"
#include "sc/phi/Model.hpp"
#include "sc/evt/Event.hpp"
#include "TestObjectFactory.hpp"


class RocketTest : public CxxTest::TestSuite
{
  protected:
    sc::phi::Coordinate m_speed_still = { 0.0, 0.0 };
    sc::phi::Coordinate m_speed_moving = { -10.0, 0.0 };
    sc::phi::Coordinate m_start_coordinate = { 100.0, 100.0 };
    sc::phi::Coordinate m_start_coordinate_2 = { 105.0, 100.0 };

  public:
    void test_rocket_should_move_by_itself()
    {
      sc::phi::Sector sector;
      test::TestObjectFactory objectFactory( sector );

      test::TestObject* testObject_1(
          objectFactory.createTestRocket( sc::phi::ObjectProperties( m_start_coordinate, m_speed_still ) ) );

      sector.tick();
      sector.tick();
      testObject_1->assertMoved();
    }
};

