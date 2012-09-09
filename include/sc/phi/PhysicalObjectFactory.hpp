#pragma once

#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/BaseTypes.hpp>

namespace sc
{
  namespace phi
  {

    class PhysicalObjectFactory : public ObjectFactory
    {
      public:
        PhysicalObjectFactory( Sector& sector );
        virtual ~PhysicalObjectFactory();

        virtual ObjectRef createShip( const sc::phi::ObjectProperties& properties );
        virtual ObjectRef createRocket( const sc::phi::ObjectProperties& properties );

      protected:
        ObjectRef createWithColliderAndEngine( const sc::phi::ObjectProperties& properties );
        virtual ObjectRef createBasicObject( const sc::phi::ObjectProperties& properties );
    };

  }
}
