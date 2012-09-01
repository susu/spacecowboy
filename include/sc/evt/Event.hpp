#pragma once
#include <sc/evt/BaseTypes.hpp>

#include <vector>

namespace sc
{
  namespace evt
  {
    class Event
    {
      public:
        virtual void handle( Registry& registry ) = 0;

      protected:
        void notifySlot( Registry& registry, const SlotId& slot );
    };

    class BinaryEvent : public Event
    {
      public:
        BinaryEvent( const SlotId& slot );
        void addSlot( const SlotId& slot );

        void handle( Registry& registry );

      private:
        std::vector< SlotId > m_slots;
    };
  }
}
