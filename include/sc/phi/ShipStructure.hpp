#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Accessory.hpp>

namespace sc
{
  namespace phi
  {
    class Model;
    class Coordinate;

    class ShipStructure : public Accessory
    {
      public:
        ShipStructure( const ObjectRef& object );
        virtual ~ShipStructure();

        ShipStructure( const ShipStructure& ) = delete;
        ShipStructure& operator=( const ShipStructure& ) = delete;

        void collisionDamage( sc::evt::Event& event );
        void explosionDamage( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );

        int getIntegrity() const;

      private:
        void dieIfDamagedEnough();

        Object* m_object;
        int m_integrity;
    };
  }
}

