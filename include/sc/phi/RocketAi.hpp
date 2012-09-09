#pragma once

#include <sc/evt/BaseTypes.hpp>
#include <sc/phi/Accessory.hpp>

namespace sc
{
  namespace phi
  {
    class Object;
    class ObjectFactory;

    class RocketAi : public Accessory
    {
      public:
        RocketAi( Object* rocket, ObjectFactory& objectFactory );
        virtual ~RocketAi();

        void timer( sc::evt::Event& event );
        virtual void subscribe( sc::evt::Registry& registry );

      private:
        Object* m_rocket;
        ObjectFactory& m_objectFactory;
        unsigned int m_coolDown = 0;
    };
  }
}

