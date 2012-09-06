#pragma once
#include <sc/evt/BaseTypes.hpp>
#include <sc/evt/Handler.hpp>

namespace sc
{
  namespace phi
  {
    class Model;

    class Accessory : public sc::evt::Handler
    {
      public:
        virtual void subscribe( sc::evt::Registry& registry ) = 0;
        void initialize( Model& physicalModel );

      protected:
        Model* m_physicalModel = nullptr;

    };
  }
}

