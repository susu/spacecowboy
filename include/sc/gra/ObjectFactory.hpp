#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/ObjectFactory.hpp>

namespace sc
{
  namespace phi
  {
    class Sector;
  }

  namespace gra
  {
    class Engine;

    class ObjectFactory : public phi::ObjectFactory
    {
      public:
        ObjectFactory( phi::Sector& sector, Engine& graphicalEngine );

        virtual phi::ObjectRef createShip(
          const phi::Coordinate& coord,
          const phi::Coordinate& speed );

        virtual ~ObjectFactory();

      protected:
        Engine& m_graphicalEngine;
    };

  }
}

