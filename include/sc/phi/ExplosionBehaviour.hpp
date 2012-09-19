#pragma once

#include <sc/evt/BaseTypes.hpp>
#include <sc/phi/Accessory.hpp>

namespace sc
{
  namespace phi
  {
    class Object;
    class Sector;

    class ExplosionBehaviour : public Accessory
    {
      public:
        ExplosionBehaviour( Sector& sector, Object* rocket );
        virtual ~ExplosionBehaviour();

        ExplosionBehaviour( const ExplosionBehaviour& ) = delete;
        ExplosionBehaviour& operator=( const ExplosionBehaviour& ) = delete;

        void timer( sc::evt::Event& event );
        virtual void subscribe( sc::evt::Registry& registry );

      private:
        Object* m_explosion;
        Sector& m_sector;
    };
  }
}

