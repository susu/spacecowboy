#pragma once

#include <sc/evt/BaseTypes.hpp>
#include <sc/evt/Handler.hpp>

namespace sc
{
  namespace phi
  {
    class Model;

    class Engine : public evt::Handler
    {
      public:
        Engine( Model& physicalModel,
                const double& backThrustPower,
                const double& spinThrustPower );

        virtual ~Engine();

        void backThruster( sc::evt::Event& event );
        void cwThruster( sc::evt::Event& event );
        void ccwThruster( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );

      private:
        virtual void pimpBackThruster();
        virtual void pimpCwThruster();
        virtual void pimpCcwThruster();

        void registerFunction(
            sc::evt::Registry& registry,
            void (Engine::*)( sc::evt::Event& ),
            const sc::evt::SlotId& slot );

        void spinShip( bool clockWiseSpin );
        Model& m_physicalModel;

      protected:
        double m_thrusterPower;
        double m_spinThrusterPower;

    };
  }
}
