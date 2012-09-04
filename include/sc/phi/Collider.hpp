#pragma once

#include <sc/evt/BaseTypes.hpp>
#include <sc/evt/Handler.hpp>

namespace sc
{
  namespace phi
  {
    class Model;
    class Coordinate;
    class CollisionEvent;

    class Collider : public evt::Handler
    {
      public:
        Collider( Model& physicalModel );
        virtual ~Collider();

        void collision( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );
      private:
        Coordinate calculateCollisionForce( CollisionEvent& event ) const;

        Model& m_physicalModel;
    };
  }
}

