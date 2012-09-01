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
        SdlEngine( int x, int y );
        ~SdlEngine();

        void drawShip(
            const sc::phi::Coordinate& coordinate,
            const sc::phi::Coordinate& heading );

        void drawPoint(
            const sc::phi::Coordinate& center,
            int size, unsigned int colour );

        void updateScreen();

      private:
        void drawBackground();

        SDL_Surface* m_screen = 0;

        int m_x;
        int m_y;
    };
  }
}

