#include <cxxtest/TestSuite.h>

#include "sc/phi/BaseTypes.hpp"
#include "sc/phi/Sector.hpp"
#include "sc/phi/EventSlots.hpp"
#include "sc/phi/CollisionEvent.hpp"
#include "sc/phi/ExplosionEvent.hpp"
#include "sc/phi/Model.hpp"
#include "sc/evt/Event.hpp"
#include "TestObjectFactory.hpp"


class ColliderTest : public CxxTest::TestSuite
{
  protected:
    sc::phi::Coordinate m_speed_still = { 0.0, 0.0 };
    sc::phi::Coordinate m_speed_moving = { -10.0, 0.0 };
    sc::phi::Coordinate m_start_coordinate = { 100.0, 100.0 };
    sc::phi::Coordinate m_start_coordinate_2 = { 105.0, 100.0 };

  public:
    void test_collider_should_change_the_speed_of_colliding_object()
    {
      sc::phi::Sector sector;
      test::TestObjectFactory objectFactory( sector );

      test::TestObject* testObject_1(
          objectFactory.createTestShip( sc::phi::ObjectProperties( m_start_coordinate, m_speed_still, 0.0, 10, 1 ) ) );

      sc::phi::Model colliderModel(
          m_start_coordinate_2,
          m_speed_moving,
          0.0,
          0.0,
          10.0,
          1 );

      sc::phi::CollisionEvent collisionEvent(
          sc::phi::ObjectRef( nullptr ), colliderModel );
      testObject_1->dispatchEvent( collisionEvent );
      testObject_1->timeElapsed( 1.0 );
      testObject_1->assertMoved();
    }

    void test_still_object_should_start_moving_after_collision()
    {
      sc::phi::Sector sector;
      test::TestObjectFactory objectFactory( sector );

      test::TestObject* testObject_1(
          objectFactory.createTestShip( sc::phi::ObjectProperties(  m_start_coordinate, m_speed_still, 0.0, 10, 1 ) ) );
      objectFactory.createTestShip( sc::phi::ObjectProperties( m_start_coordinate_2, m_speed_moving, 0.0, 10, 1 ) );

      sector.tick();
      sector.tick();
      testObject_1->assertMoved();
    }

};

