#include <cxxtest/TestSuite.h>

#include "sc/phi/BaseTypes.hpp"
#include "sc/phi/Sector.hpp"
#include "sc/phi/EventSlots.hpp"
#include "sc/phi/Model.hpp"
#include "sc/evt/Event.hpp"
#include "TestObjectFactory.hpp"


class ExplosionTest : public CxxTest::TestSuite
{
  protected:
    sc::phi::Coordinate m_speed_still = { 0.0, 0.0 };
    sc::phi::Coordinate m_start_explosion_coordinate = { 100.0, 100.0 };
    sc::phi::Coordinate m_start_coordinate_in_range = { 200.0, 100.0 };
    sc::phi::Coordinate m_start_coordinate_out_of_range = { 400.0, 400.0 };

  public:
    void test_explosion_should_notify_colliding_objects_in_range()
    {
      sc::phi::Sector sector;
      test::TestObjectFactory objectFactory( sector );

      test::TestObject* testObjectInRange(
          objectFactory.createTestShip( sc::phi::ObjectProperties( m_start_coordinate_in_range, m_speed_still, 0.0 ) ) );

      test::TestObject* testObjectOutOfRange(
          objectFactory.createTestShip( sc::phi::ObjectProperties( m_start_coordinate_out_of_range, m_speed_still, 0.0 ) ) );

      objectFactory.createExplosion( sc::phi::ObjectProperties( m_start_explosion_coordinate, m_speed_still, 0.0, 100 ) );

      sector.tick();
      sector.tick();
      testObjectInRange->assertMoved();
      testObjectOutOfRange->assertDidNotMove();
    }
};

