#pragma once

#include <sc/evt/BaseTypes.hpp>

namespace sc
{
  namespace phi
  {
    class slot
    {
      public:
        static const evt::SlotId TIMEELAPSED;
        static const evt::SlotId BACKTHRUSTER;
        static const evt::SlotId FRONTTHRUSTER;
        static const evt::SlotId LEFTTHRUSTER;
        static const evt::SlotId RIGHTTHRUSTER;
        static const evt::SlotId CWTHRUSTER;
        static const evt::SlotId CCWTHRUSTER;
        static const evt::SlotId COLLISION;
        static const evt::SlotId EXPLOSION;
        static const evt::SlotId FIRE;
        static const evt::SlotId COLLISION_DAMAGE;
        static const evt::SlotId EXPLOSION_DAMAGE;
        static const evt::SlotId OBJECT_INTEGRITY_CHANGED;
    };
  }
}

