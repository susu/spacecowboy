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

#include <sc/gra/Engine.hpp>
#include <memory>

class SDL_Surface;

namespace sc
{
  namespace gra
  {
    class Graphical;

    class SdlEngine : public Engine
    {
      public:
        SdlEngine( unsigned int x, unsigned int y );
        ~SdlEngine();

        SdlEngine( const SdlEngine& ) = delete;
        SdlEngine& operator=( const SdlEngine& ) = delete;

        virtual void drawRawRectangle(
            unsigned int x,
            unsigned int y,
            int size, unsigned int colour );

        void updateScreen();

      private:
        void drawBackground();

        SDL_Surface* m_screen;

        unsigned int m_x;
        unsigned int m_y;
    };
  }
}

