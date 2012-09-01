#pragma once

#include <vector>

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
        Engine();
        virtual ~Engine();

        void removeObject( const Graphical* object );
        void addObject( const Graphical* object );

        virtual void drawShip(
            const sc::phi::Coordinate& coordinate,
            const sc::phi::Coordinate& heading ) = 0;

        virtual void drawPoint(
            const sc::phi::Coordinate& center,
            int size, unsigned int colour ) = 0;

        virtual void updateScreen() = 0;

      protected:
        void drawObjects();
        std::vector< const Graphical* > m_objectContainer;
    };
  }
}

