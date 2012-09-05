#pragma once

#include <sc/evt/Handler.hpp>
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

    class EngineGraphics : public evt::Handler
    {
      public:
        EngineGraphics(
            sc::phi::Model& model,
            sc::phi::Sector& sector,
            sc::gra::Engine& graphicalEngine,
            unsigned int radius );
        virtual ~EngineGraphics();

        void pimpBackThruster( sc::evt::Event& event );
        void pimpCwThruster( sc::evt::Event& event );
        void pimpCcwThruster( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );

      private:
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

