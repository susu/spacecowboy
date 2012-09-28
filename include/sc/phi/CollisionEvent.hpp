#pragma once
#include <sc/evt/Event.hpp>
#include <sc/phi/BaseTypes.hpp>

#include <vector>

namespace sc
{
  namespace phi
  {
    class Model;

    class CollisionEvent : public sc::evt::Event
    {
      public:
        CollisionEvent( const ObjectRef& collidingObject, Model& physicalModel );
        virtual void handle( sc::evt::Registry& registry );

        Coordinate otherSpeed() const;
        Coordinate otherCoord() const;
        unsigned int otherMass() const;

      private:
        ObjectRef m_collidingObject;
        Model& m_modelOfCollider;
    };
  }
}

