#pragma once

#include <sc/gra/Graphical.hpp>
#include <sc/gra/Engine.hpp>

namespace sc
{
  namespace phi
  {
    class Coordinate;
  }
}

namespace test
{

  class GraphicalEngine : public sc::gra::Engine
  {
    public:
      GraphicalEngine() : sc::gra::Engine( 0, 0 )
      {
      }

      virtual void drawShip(
            const sc::phi::Coordinate&,
            const sc::phi::Coordinate&)
      {
      }

      virtual void drawPoint(
            const sc::phi::Coordinate&,
            int size, unsigned int colour )
      {
      }

      virtual void updateScreen()
      {
        drawObjects();
      }
  };

  class GraphicalObject : public sc::gra::Graphical
  {
    public:
      GraphicalObject( sc::gra::Engine& graphicalEngine )
        : sc::gra::Graphical( graphicalEngine )
      {
      }

        virtual ~GraphicalObject()
      {
      }

      virtual void draw() const
      {
        m_drawCalled = true;
      }

      void assertDrawCalled( bool called )
      {
        TS_ASSERT( called ? m_drawCalled : !m_drawCalled );
      }

    private:
      mutable bool m_drawCalled = false;
  };

}

