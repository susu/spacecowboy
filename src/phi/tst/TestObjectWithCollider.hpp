#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Collider.hpp>

#include "TestObject.hpp"

namespace test
{

  class TestObjectWithCollider : public TestObject
  {
    public:
      TestObjectWithCollider( sc::phi::Sector& sector, const sc::phi::Coordinate& coordinate, const sc::phi::Coordinate& speed )
        : TestObject( sector, coordinate, speed )
      {
        addAccessory( sc::phi::AccessoryRef( new sc::phi::Collider() ));
      }
  };
}

