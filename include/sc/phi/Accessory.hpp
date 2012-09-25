#pragma once
#include <sc/evt/BaseTypes.hpp>
#include <sc/evt/Handler.hpp>

namespace sc
{
  namespace phi
  {
    class Model;
    class Object;
    class Sector;

    class Accessory : public sc::evt::Handler
    {
      public:
        Accessory();

        Accessory( const Accessory& ) = delete;
        Accessory& operator=( const Accessory& ) = delete;

        virtual void subscribe( sc::evt::Registry& registry );
        void initialize( Object& owner, Model& physicalModel, Sector& sector );
        virtual ~Accessory();

      protected:
        Model* m_physicalModel;
        Object* m_owningObject;
        Sector* m_sector;

    };
  }
}

