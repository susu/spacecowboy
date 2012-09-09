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
        virtual ~ObjectFactory();

        virtual ObjectRef createShip( const ObjectProperties& properties ) = 0;
        virtual ObjectRef createRocket( const ObjectProperties& properties ) = 0;

      protected:
        virtual ObjectRef createBasicObject( const ObjectProperties& properties ) = 0;

        Sector& m_sector;
    };

  }
}

