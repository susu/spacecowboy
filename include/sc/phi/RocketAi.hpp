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

        RocketAi( const RocketAi& ) = delete;
        RocketAi& operator=( const RocketAi& ) = delete;

        void collision( sc::evt::Event& event );
        void timer( sc::evt::Event& event );
        virtual void subscribe( sc::evt::Registry& registry );

      private:
        void explode();

        Object* m_rocket;
        ObjectFactory& m_objectFactory;
        unsigned int m_ttl;
    };
  }
}

