#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <deque>
#include <set>

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

        void deletable( Object* object );

        const ObjectContainer& colliders() const;

      private:
        ObjectContainer m_nonColliders;
        ObjectContainer m_colliders;
        std::set<Object*> m_deletables;
    };
  }
}

