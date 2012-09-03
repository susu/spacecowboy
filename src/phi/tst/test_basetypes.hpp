#include <cxxtest/TestSuite.h>

#include "sc/phi/BaseTypes.hpp"
class BaseTypesTest : public CxxTest::TestSuite
{
  public:
    void test_basic_descartes_coordinate_from_polar_conversion()
    {
      sc::phi::Angle angle( 0.0 );
      double length( 2.0 );

      sc::phi::Coordinate coord( sc::phi::CoordFromPolar( angle, length ) );
      TS_ASSERT_EQUALS( coord.x, length );
      TS_ASSERT_EQUALS( coord.y, 0.0 );
    }

    void test_dot_product()
    {
      sc::phi::Coordinate a( 2.0, 3.0 );
      sc::phi::Coordinate b( 4.0, -5.0 );

      TS_ASSERT_EQUALS( dotproduct( a, b ), -7.0 );
    }

};

