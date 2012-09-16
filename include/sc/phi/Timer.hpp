#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <ctime>

namespace sc
{
  namespace phi
  {
    class Timer
    {
      public:
        Timer();
        sc::phi::Ratio timeFrameRatio();
      private:
        struct timeval m_previousTime;
        Ratio m_previousRatio;
    };
  }
}

