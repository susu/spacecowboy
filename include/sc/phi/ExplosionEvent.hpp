#pragma once
#include <sc/evt/Event.hpp>
#include <sc/phi/BaseTypes.hpp>

#include <vector>

namespace sc
{
  namespace phi
  {
    class Model;

    class ExplosionEvent : public sc::evt::Event
    {
      public:
        ExplosionEvent( const Model& physicalModel, unsigned int power );
        virtual void handle( sc::evt::Registry& registry );

        Coordinate center() const;
        const Model& model() const;
        unsigned int power() const;

      private:
        const Model& m_physicalModel;
        unsigned int m_power;
    };
  }
}

