#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/evt/Hub.hpp>

namespace sc
{
  namespace phi
  {
    class Object : public evt::Hub
    {
      public:
        Object( Sector& sector );
        Object( Sector& sector, const Coordinate& coordinate, const Coordinate& speed );
        void timeElapsed( const Ratio& stepRatio );
        virtual ~Object();

      protected:
        Model m_physicalModel;
        Sector& m_sector;

      private:
        virtual void timerUpdate( const Ratio& ratio ) {}
    };
  }
}

