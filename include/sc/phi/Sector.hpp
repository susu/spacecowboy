#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <list>
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

      private:
        std::list<ObjectRef> m_nonColliders;
        std::list<ObjectRef> m_colliders;
        std::set<Object*> m_deletables;
    };
  }
}

