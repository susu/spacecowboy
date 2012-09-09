#pragma once

#include <sc/phi/Accessory.hpp>
#include <sc/gra/Graphical.hpp>

namespace sc
{
  namespace gra
  {
    class Engine;

    class RocketGraphics : public phi::Accessory, public gra::Graphical
    {
      public:
        RocketGraphics( sc::gra::Engine& graphicalEngine );
        virtual ~RocketGraphics();
        virtual void subscribe( sc::evt::Registry& registry );
        virtual void draw() const;
    };
  }
}

