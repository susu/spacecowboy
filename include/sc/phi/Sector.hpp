#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Timer.hpp>
#include <deque>
#include <vector>

namespace sc
{
  namespace phi
  {
    class Sector
    {
      public:
        Sector();
        void addObject( const ObjectRef& object );
        void tick();

        const ObjectContainer& colliders() const;

      private:
        ObjectContainer m_nonColliders;
        ObjectContainer m_colliders;
        std::vector<ObjectRef> m_newColliders;
        std::vector<ObjectRef> m_newNonColliders;

        Timer m_timer;
    };
  }
}

