#pragma once

#include <sc/phi/BaseTypes.hpp>

namespace sc
{
  namespace phi
  {

    class ObjectFactory
    {
      public:
        ObjectFactory( Sector& sector );

        virtual ObjectRef createShip(
          const sc::phi::Coordinate& coord,
          const sc::phi::Coordinate& speed ) = 0;

        virtual ~ObjectFactory();

      protected:
        Sector& m_sector;
    };

  }
}

