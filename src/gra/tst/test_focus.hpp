#include <cxxtest/TestSuite.h>

#include <iostream>

#include <sc/phi/BaseTypes.hpp>
#include <sc/gra/Focus.hpp>

class FocusTest : public CxxTest::TestSuite
{
  private:
    unsigned int m_xResolution{ 400 };
    unsigned int m_yResolution{ 300 };

    bool isInsideVisibleArea( const sc::phi::Coordinate& coord ) const
    {
      return coord.x < m_xResolution &&
             coord.x > 0 &&
             coord.y < m_yResolution &&
             coord.y > 0;
    }

  public:
    void test_all_coordinates_should_be_mapped_in_the_visual_area()
    {
      sc::gra::Focus focus( m_xResolution, m_yResolution );

      sc::phi::Coordinate outsideMinusXMinusY{ -100.0, -1.0 };
      sc::phi::Coordinate outsidePlusXPlusY{ 2.0 * m_xResolution, 1.5 * m_yResolution };

      focus.inFocus( outsideMinusXMinusY );
      focus.inFocus( outsidePlusXPlusY );
      focus.updateFocus();
      TS_ASSERT( isInsideVisibleArea( focus.mapCoordinate( outsideMinusXMinusY ) ) );
      TS_ASSERT( isInsideVisibleArea( focus.mapCoordinate( outsidePlusXPlusY ) ) );
    }
};

