#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <vector>
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
        std::vector<ObjectRef> m_nonColliders;
        std::vector<ObjectRef> m_colliders;
        std::set<Object*> m_deletables;
    };
  }
}

