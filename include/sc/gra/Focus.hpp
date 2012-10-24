/*
 * spacecowboy - a 2D space adventure game
 *
 *  Copyright 2012, Peter Ferenc Hajdu.
 *  All rights reserved.
 *
 * This file is part of .
 *
 * spacecowboy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * spacecowboy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with spacecowboy. If not, see
 * <http://www.gnu.org/licenses/>.
 */
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

