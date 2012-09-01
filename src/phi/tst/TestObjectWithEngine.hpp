#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/EngineBase.hpp>

#include "TestObject.hpp"

namespace test
{

  class TestObjectWithEngine : public TestObject
  {
    public:
      TestObjectWithEngine( sc::phi::Sector& sector, const sc::phi::Coordinate& coordinate, const sc::phi::Coordinate& speed )
        : TestObject( sector, coordinate, speed )
      {
        add( m_engine );
      }

    private:
      sc::phi::Engine m_engine = { m_physicalModel, 1.0, 1.0 };
  };
}

