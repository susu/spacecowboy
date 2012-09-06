#pragma once

#include <sc/evt/BaseTypes.hpp>
#include <sc/phi/Accessory.hpp>

namespace sc
{
  namespace phi
  {
    class Engine : public Accessory
    {
      public:
        Engine( const double& backThrustPower,
                const double& spinThrustPower );

        virtual ~Engine();

        void backThruster( sc::evt::Event& event );
        void cwThruster( sc::evt::Event& event );
        void ccwThruster( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );

      private:
        void spinShip( bool clockWiseSpin );

      protected:
        double m_thrusterPower;
        double m_spinThrusterPower;
    };
  }
}

