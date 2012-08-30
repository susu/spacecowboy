#pragma once
#include <sc/evt/BaseTypes.hpp>

namespace sc
{
  namespace evt
  {
    class Event;
    class Handler;

    class Hub
    {
      public:
        void dispatchEvent( Event& event );
        virtual ~Hub();
        void add( Handler& handler );

      private:
        Registry m_registry;
    };
  }
}

