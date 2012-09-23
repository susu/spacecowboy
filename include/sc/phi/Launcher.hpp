#pragma once

#include <sc/evt/BaseTypes.hpp>
#include <sc/phi/Accessory.hpp>

namespace sc
{
  namespace phi
  {
    class ObjectFactory;

    class Launcher : public Accessory
    {
      public:
        Launcher( ObjectFactory& objectFactory );
        virtual ~Launcher();

        void fire( sc::evt::Event& event );
        void timer( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );
      private:
        ObjectFactory& m_objectFactory;
        unsigned int m_coolDown;
    };
  }
}

