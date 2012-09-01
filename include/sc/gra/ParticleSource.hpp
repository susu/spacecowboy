#pragma once

#include <sc/phi/BaseTypes.hpp>

namespace sc
{
  namespace gra
  {
    class Model;
    class Engine;

    class ParticleSource
    {
      public:
        ParticleSource( sc::phi::Sector& sector, sc::gra::Engine& graphicalEngine );

        void createParticle(
            const sc::phi::Coordinate& coord,
            const sc::phi::Coordinate& baseSpeed,
            const sc::phi::Angle& heading );

      private:
        sc::phi::Sector& m_sector;
        sc::gra::Engine& m_graphicalEngine;
    };
  }
}

