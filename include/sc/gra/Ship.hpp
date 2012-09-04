#pragma once

#include <sc/phi/Object.hpp>
#include <sc/phi/Collider.hpp>
#include <sc/gra/Graphical.hpp>
#include <sc/gra/ShipEngine.hpp>

namespace sc
{
  namespace phi
  {
    class Sector;
  }

  namespace gra
  {
    class Engine;

    class Ship : public phi::Object, public Graphical
    {
      public:
        Ship( sc::phi::Sector& sector, sc::gra::Engine& engine );
        Ship( sc::phi::Sector& sector,
              sc::gra::Engine& engine,
              const sc::phi::Coordinate& coordinate );
        void draw() const;

      private:
        ShipEngine m_shipEngine;
        sc::phi::Collider m_collider;
    };

  }
}

