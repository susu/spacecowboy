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
        ShipStructure();
        virtual ~ShipStructure();

        ShipStructure( const ShipStructure& ) = delete;
        ShipStructure& operator=( const ShipStructure& ) = delete;

        void collisionDamage( sc::evt::Event& event );
        void explosionDamage( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );

      private:
        void handleShipDamaged();
        void notifyAboutIntegrityChange();
        void dieIfDamagedEnough();

        int m_integrity;
    };
  }
}

