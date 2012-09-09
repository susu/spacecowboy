#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/PhysicalObjectFactory.hpp>

namespace sc
{
  namespace phi
  {
    class Sector;
  }

  namespace gra
  {
    class Engine;

    class ObjectFactory : public phi::PhysicalObjectFactory
    {
      public:
        ObjectFactory( phi::Sector& sector, Engine& graphicalEngine );
        virtual ~ObjectFactory();

        virtual phi::ObjectRef createShip( const phi::ObjectProperties& properties );
        virtual phi::ObjectRef createRocket( const phi::ObjectProperties& properties );

      protected:
        Engine& m_graphicalEngine;
    };

  }
}

