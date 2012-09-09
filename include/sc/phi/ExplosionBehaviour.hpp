#pragma once

#include <sc/evt/BaseTypes.hpp>
#include <sc/phi/Accessory.hpp>

namespace sc
{
  namespace phi
  {
    class Object;

    class ExplosionBehaviour : public Accessory
    {
      public:
        ExplosionBehaviour( Object* rocket );
        virtual ~ExplosionBehaviour();

        void timer( sc::evt::Event& event );
        virtual void subscribe( sc::evt::Registry& registry );

      private:
        Object* m_explosion;
    };
  }
}

