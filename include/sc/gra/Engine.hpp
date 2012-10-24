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

#include <vector>
#include <sc/gra/Focus.hpp>

namespace sc
{
  namespace phi
  {
    class Coordinate;
  }

  namespace gra
  {
    class Graphical;

    class Engine
    {
      public:
        Engine( unsigned int xRes, unsigned int yRes );
        virtual ~Engine();

        void removeObject( const Graphical* object );
        void addObject( const Graphical* object );

        virtual void drawShip(
            const sc::phi::Coordinate& coordinate,
            const sc::phi::Coordinate& heading,
            int integrity );

        virtual void drawPoint(
            const sc::phi::Coordinate& center,
            unsigned int size, unsigned int colour );

        virtual void drawCircle(
            const sc::phi::Coordinate& center,
            unsigned int radius, unsigned int colour );

        virtual void drawRawRectangle(
            unsigned int x,
            unsigned int y,
            int size, unsigned int colour ) = 0;

        virtual void updateScreen() = 0;

      protected:
        void drawObjects();
        std::vector< const Graphical* > m_objectContainer;

        Focus m_focus;
    };
  }
}

