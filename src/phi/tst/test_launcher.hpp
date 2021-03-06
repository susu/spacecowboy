#include <cxxtest/TestSuite.h>

#include "sc/phi/BaseTypes.hpp"
#include "sc/phi/Sector.hpp"
#include "sc/phi/EventSlots.hpp"
#include "sc/phi/CollisionEvent.hpp"
#include "sc/evt/Event.hpp"
#include "TestObjectFactory.hpp"


class LauncherTest : public CxxTest::TestSuite
{
  protected:
    sc::phi::Coordinate m_speed_still = { 0.0, 0.0 };
    sc::phi::Coordinate m_speed_moving = { 1.0, 1.0 };
    sc::phi::Coordinate m_start_coordinate = { 100.0, 100.0 };

  public:
    void test_launcher_should_lauch_rocket_if_fire_event_arrives_and_has_cooldown()
    {
      sc::phi::Sector sector;
      test::TestObjectFactory objectFactory( sector );

      sc::phi::ObjectRef ship(
          objectFactory.createShip( sc::phi::ObjectProperties( m_start_coordinate, m_speed_still, 0.0, 10, 1 ) ) );

      sc::evt::BinaryEvent fire( sc::phi::slot::FIRE );
      ship->dispatchEvent( fire );

      objectFactory.assertRocketCreated_ResetFlag( true );

      ship->dispatchEvent( fire );
      objectFactory.assertRocketCreated_ResetFlag( false );
    }

    void test_rockets_should_have_the_same_speed_as_the_launching_object()
    {
      sc::phi::Sector sector;
      test::TestObjectFactory objectFactory( sector );

      sc::phi::ObjectRef ship(
          objectFactory.createShip( sc::phi::ObjectProperties( m_start_coordinate, m_speed_moving, 0.0, 10, 1 ) ) );

      sc::evt::BinaryEvent fire( sc::phi::slot::FIRE );
      ship->dispatchEvent( fire );

      objectFactory.assertRocketCreated_ResetFlag( true );
      objectFactory.assertCreatedRocketSpeedEquals( m_speed_moving );
    }


};

