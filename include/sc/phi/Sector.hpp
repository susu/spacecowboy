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
        void removeDeletables();

        std::vector<ObjectRef> m_objects;
        std::set<Object*> m_deletables;
    };
  }
}

