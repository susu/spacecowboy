#pragma once

#include <sc/evt/BaseTypes.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/BaseTypes.hpp>

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
        Collider( const ObjectRef& object );
        virtual ~Collider();

        Collider( const Collider& ) = delete;
        Collider& operator=( const Collider& ) = delete;

        void collision( sc::evt::Event& event );
        void explosion( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );
      private:
        Coordinate calculateCollisionForce( CollisionEvent& event ) const;
        Object* m_object;
    };
  }
}

