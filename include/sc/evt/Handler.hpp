#pragma once
#include <sc/evt/BaseTypes.hpp>

namespace sc
{
  namespace evt
  {
    class Handler
    {
      public:
        virtual void subscribe( Registry& registry ) = 0;
    };
  }
}

