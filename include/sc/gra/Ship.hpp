#pragma once

#include <sc/phi/Object.hpp>
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
        void draw() const;

      private:
        ShipEngine m_shipEngine;
    };

  }
}

