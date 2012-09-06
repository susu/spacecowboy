#pragma once

#include <sc/evt/BaseTypes.hpp>
#include <sc/phi/Accessory.hpp>

namespace sc
{
  namespace phi
  {
    class Model;
    class Coordinate;
    class CollisionEvent;

    class Collider : public Accessory
    {
      public:
        Collider();
        virtual ~Collider();

        void collision( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );
      private:
        Coordinate calculateCollisionForce( CollisionEvent& event ) const;
    };
  }
}

