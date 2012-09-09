#include <cxxtest/TestSuite.h>

#include "sc/phi/BaseTypes.hpp"
#include "sc/phi/Sector.hpp"
#include "TestAccessory.hpp"
#include "TestObject.hpp"


class ObjectTest : public CxxTest::TestSuite
{
  protected:
    sc::phi::Coordinate m_speed_still = { 0.0, 0.0 };
    sc::phi::Coordinate m_start_coordinate = { 0.0, 0.0 };

  public:
    void test_object_should_register_added_accessories_as_handlers_and_set_physicalmodel_reference()
    {
      sc::phi::Sector sector;

      test::TestObject* testObject(
          new test::TestObject( sector, sc::phi::ObjectProperties( m_start_coordinate, m_speed_still, 0.0 ) ) );
      sc::phi::ObjectRef object( testObject );

      test::TestAccessory* testAccessory( new test::TestAccessory( 1 ) );
      sc::phi::AccessoryRef accessory( testAccessory );

      object->addAccessory( accessory );
      testAccessory->assertHasBeenInitialized();

      sc::evt::BinaryEvent event( 1 );
      testObject->dispatchEvent( event );

      testAccessory->assertHandlerNotified( true );
    }

    void test_object_is_responsible_to_keep_accessories_alive()
    {
      sc::phi::Sector sector;

      test::TestObject* testObject(
          new test::TestObject( sector, sc::phi::ObjectProperties( m_start_coordinate, m_speed_still, 0.0 ) ) );
      sc::phi::ObjectRef object( testObject );

      test::TestAccessory* testAccessory( new test::TestAccessory( 1 ) );

      {
        sc::phi::AccessoryRef accessory( testAccessory );
        object->addAccessory( accessory );
        testAccessory->assertHasBeenInitialized();
      }

      sc::evt::BinaryEvent event( 1 );
      testObject->dispatchEvent( event );
      testAccessory->assertHandlerNotified( true );
    }

};

