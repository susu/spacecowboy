#pragma once
#include <sc/evt/Event.hpp>
#include <sc/phi/BaseTypes.hpp>

namespace sc
{
  namespace phi
  {
    class IntegrityChanged : public sc::evt::Event
    {
      public:
        IntegrityChanged( int integrity );
        virtual void handle( sc::evt::Registry& registry );

        int integrity() const;

      private:
        int m_integrity;
    };
  }
}

