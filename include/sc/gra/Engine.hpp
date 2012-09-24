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
            int size, unsigned int colour );

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

