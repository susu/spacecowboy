#pragma once

#include <sc/phi/Accessory.hpp>
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

    class ExplosionGraphics : public phi::Accessory
    {
      public:
        ExplosionGraphics( sc::phi::Sector& sector, sc::gra::Engine& graphicalEngine );
        virtual ~ExplosionGraphics();

        void timer( sc::evt::Event& event );
        virtual void subscribe( sc::evt::Registry& registry );

      private:
        sc::gra::ParticleSource m_particleSource;

    };
  }
}

