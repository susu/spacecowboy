#pragma once

#include <sc/phi/Object.hpp>
#include <sc/gra/Graphical.hpp>

namespace sc
{
  namespace phi
  {
    class Sector;
    class Coordinate;
  }

  namespace gra
  {
    class Engine;

    class Particle : public sc::phi::Object, public Graphical
    {
      public:
        Particle( sc::phi::Sector& sector,
                  Engine& graphicalEngine,
                  const sc::phi::Coordinate& coordinate,
                  const sc::phi::Coordinate& speed );

        void draw() const;

      private:
        void timerUpdate( const sc::phi::Ratio& ratio );
        unsigned int m_colourIndex;
    };
  }
}

