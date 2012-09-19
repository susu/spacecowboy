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

        template< class T >
        void registerMemberFunction(
            sc::evt::Registry& registry,
            void (T::*funptr)( sc::evt::Event& ),
            const sc::evt::SlotId& slot )
        {
          std::function< void( T*, sc::evt::Event& ) > fun ( funptr );
          sc::evt::Callback callback( std::bind( fun, dynamic_cast<T*>( this ), std::placeholders::_1 ));
          registry[ slot ].push_back( callback );
        }

        virtual ~Handler();

    };
  }
}

