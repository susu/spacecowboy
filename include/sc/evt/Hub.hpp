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
        Hub();
        virtual ~Hub();

        void dispatchEvent( Event& event );
        void add( Handler& handler );
        bool hasHandlerFor( SlotId slot ) const;

      private:
        Registry m_registry;
    };
  }
}

