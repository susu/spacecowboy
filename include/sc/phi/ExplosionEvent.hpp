#pragma once
#include <sc/evt/Event.hpp>
#include <sc/phi/BaseTypes.hpp>

#include <vector>

namespace sc
{
  namespace phi
  {
    class ExplosionEvent : public sc::evt::Event
    {
      public:
        ExplosionEvent( const Coordinate& center, int power );
        virtual void handle( sc::evt::Registry& registry );

        Coordinate center() const;
        int power() const;

      private:
        Coordinate m_center;
        int m_power;
    };
  }
}

