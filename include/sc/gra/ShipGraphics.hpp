#pragma once

#include <sc/phi/Accessory.hpp>
#include <sc/gra/Graphical.hpp>

namespace sc
{
  namespace gra
  {
    class Engine;

    class ShipGraphics : public phi::Accessory, public gra::Graphical
    {
      public:
        ShipGraphics( sc::gra::Engine& graphicalEngine );
        virtual ~ShipGraphics();

        void shipIntegrityChanged( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );
        virtual void draw() const;

      private:
        int m_integrity;

    };
  }
}

