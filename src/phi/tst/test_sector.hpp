#include <cxxtest/TestSuite.h>

#include "sc/phi/BaseTypes.hpp"
#include "sc/phi/Object.hpp"
#include "sc/phi/Sector.hpp"

#include "TestObject.hpp"

class SectorTest : public CxxTest::TestSuite
{
  protected:
    sc::phi::Coordinate m_speed_moving = { 1.0, 1.0 };
    sc::phi::Coordinate m_start_coordinate = { 0.0, 0.0 };

  public:
    void test_sector_should_signal_objects_about_time_elapse()
    {
      sc::phi::Sector sector;

      test::TestObject* testObject1(
          new test::TestObject( sector, sc::phi::ObjectProperties( m_start_coordinate, m_speed_moving, 0.0, 1, 1 ) ) );
      sc::phi::ObjectRef object1( testObject1 );

      test::TestObject* testObject2(
          new test::TestObject( sector, sc::phi::ObjectProperties( m_start_coordinate, m_speed_moving, 0.0, 1, 1 ) ) );
      sc::phi::ObjectRef object2( testObject2 );

      sector.addObject( object1 );
      sector.addObject( object2 );
      sector.tick();
      sector.tick();
      testObject1->assertMoved();
      testObject2->assertMoved();

      testObject1->assertTimerUpdateCalled();
      testObject2->assertTimerUpdateCalled();
    }


    void test_deleted_objects_going_to_be_removed_from_sector()
    {
      sc::phi::Sector sector;
      test::TestObject* testObject1(
          new test::TestObject( sector, sc::phi::ObjectProperties( m_start_coordinate, m_speed_moving, 0.0, 1, 1 ) ) );
      sc::phi::ObjectRef object1( testObject1 );
      sector.addObject( object1 );
      testObject1->deleteObject();
      sector.tick();
      testObject1->assertDidNotMove();
    }

};

