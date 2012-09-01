#pragma once

#include <sc/phi/EngineBase.hpp>
#include <sc/gra/ParticleSource.hpp>

namespace sc
{
  namespace phi
  {
    class Sector;
    class Coordinate;
    class Model;
  }

  namespace gra
  {
    class Model;
    class Engine;

    class ShipEngine : public phi::Engine
    {
      public:
        ShipEngine(
            sc::phi::Model& model,
            sc::phi::Sector& sector,
            sc::gra::Engine& graphicalEngine,
            unsigned int radius );
        virtual ~ShipEngine();

      private:
        void pimpBackThruster();
        void pimpCwThruster();
        void pimpCcwThruster();

        sc::phi::Coordinate shipFront() const;
        sc::phi::Coordinate shipBack() const;
        sc::phi::Angle left() const;
        sc::phi::Angle right() const;

        sc::gra::ParticleSource m_particleSource;
        sc::phi::Model& m_physicalModel;

        const unsigned int m_shipRadius;
    };
  }
}

