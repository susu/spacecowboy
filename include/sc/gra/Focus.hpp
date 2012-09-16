#pragma once

#include <sc/phi/BaseTypes.hpp>

namespace sc
{

  namespace gra
  {
    class Focus
    {
      public:
        Focus( unsigned int xResolution, unsigned int yResolution );
        sc::phi::Coordinate mapCoordinate( const sc::phi::Coordinate& );
        int mapSize( int size );
        void updateFocus();
        void inFocus( const sc::phi::Coordinate& coord );

      private:

        sc::phi::Coordinate m_screenResolution;

        sc::phi::Coordinate m_screenCenter;
        sc::phi::Coordinate m_spaceCenter;

        sc::phi::Coordinate m_min;
        sc::phi::Coordinate m_max;

        double m_ratio;
        double m_targetRatio;
    };
  }
}

