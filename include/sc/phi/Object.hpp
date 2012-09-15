#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/evt/Hub.hpp>

#include <deque>

namespace sc
{
  namespace phi
  {
    class Object : public evt::Hub
    {
      public:
        Object( Sector& sector );
        Object( Sector& sector, const ObjectProperties& properties );

        void timeElapsed( const Ratio& stepRatio );
        virtual ~Object();

        bool isColliding() const;
        void checkCollision( const ObjectContainer& collection );
        void deleteObject();
        bool isDeleted() const;

        void addAccessory( const AccessoryRef& accessory );

      protected:
        Model m_physicalModel;
        Sector& m_sector;

      private:
        virtual void timerUpdate( const Ratio& ratio ) {}

        AccessoryContainer m_accessories;
        bool m_deleted = false;
    };
  }
}

