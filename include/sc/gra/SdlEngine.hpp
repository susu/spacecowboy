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

        void drawShip(
            const sc::phi::Coordinate& coordinate,
            const sc::phi::Coordinate& heading );

        void drawPoint(
            const sc::phi::Coordinate& center,
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

