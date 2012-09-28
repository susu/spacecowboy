#include <cxxtest/TestSuite.h>

#include "sc/phi/BaseTypes.hpp"
#include "sc/phi/Sector.hpp"
#include "sc/phi/EventSlots.hpp"
#include "sc/phi/CollisionEvent.hpp"
#include "sc/phi/ExplosionEvent.hpp"
#include "sc/evt/Event.hpp"
#include "TestObjectFactory.hpp"


class ShipStructureTest : public CxxTest::TestSuite
{
  protected:
    sc::phi::Coordinate m_speed_moving = { -10.0, 0.0 };
    sc::phi::Coordinate m_start_coordinate = { 100.0, 100.0 };
    sc::phi::Coordinate m_start_coordinate_2 = { 105.0, 100.0 };

  public:
    void test_ship_structure_should_delete_object_if_colliding_too_much()
    {
      sc::phi::Sector sector;
      test::TestObjectFactory objectFactory( sector );

      test::TestObject* testObject_1(
          objectFactory.createTestShip( sc::phi::ObjectProperties( m_start_coordinate, m_speed_moving, 0.0, 10, 1 ) ) );

      sc::phi::Model colliderModel(
          m_start_coordinate_2,
          m_speed_moving,
          0.0,
          0.0,
          10.0,
          1 );


      sc::phi::CollisionEvent collisionEvent( sc::phi::ObjectRef( nullptr ), colliderModel );

      for ( int i( 0 ); i < 10; ++i )
      {
        testObject_1->dispatchEvent( collisionEvent );
      }

      TS_ASSERT( testObject_1->isDeleted() );
    }


    void test_ship_structure_should_delete_object_if_explodes_too_much()
    {
      sc::phi::Sector sector;
      test::TestObjectFactory objectFactory( sector );

      test::TestObject* testObject_1(
          objectFactory.createTestShip( sc::phi::ObjectProperties( m_start_coordinate, m_speed_moving, 0.0, 10, 1 ) ) );

      sc::phi::Model colliderModel(
          m_start_coordinate_2,
          m_speed_moving,
          0.0,
          0.0,
          10.0,
          1 );


      sc::phi::CollisionEvent collisionEvent( sc::phi::ObjectRef( nullptr ), colliderModel );

      for ( int i( 0 ); i < 10; ++i )
      {
        testObject_1->dispatchEvent( collisionEvent );
      }

      TS_ASSERT( testObject_1->isDeleted() );
    }

};

