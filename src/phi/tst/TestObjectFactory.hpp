#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/EngineBase.hpp>
#include <sc/phi/Collider.hpp>

#include "TestObject.hpp"

namespace test
{

  class TestObjectFactory : public sc::phi::ObjectFactory
  {
    public:
      TestObjectFactory( sc::phi::Sector& sector )
        : sc::phi::ObjectFactory( sector )
      {
      }

      test::TestObject* createTestShip(
          const sc::phi::Coordinate& coord,
          const sc::phi::Coordinate& speed )
      {
        sc::phi::ObjectRef ship( createShip( coord, speed ) );
        return dynamic_cast< test::TestObject* >( ship.get() );
      }

      virtual sc::phi::ObjectRef createShip(
          const sc::phi::Coordinate& coord,
          const sc::phi::Coordinate& speed )
      {
        sc::phi::ObjectRef object( new test::TestObject( m_sector, coord, speed ) );
        sc::phi::AccessoryRef engine( new sc::phi::Engine( 1.0, 1.0 ) );
        object->addAccessory( engine );

        sc::phi::AccessoryRef collider( new sc::phi::Collider() );
        object->addAccessory( collider );
        m_sector.addObject( object );

        return object;
      }
  };
}

