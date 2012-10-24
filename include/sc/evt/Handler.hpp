/*
 * spacecowboy - a 2D space adventure game
 *
 *  Copyright 2012, Peter Ferenc Hajdu.
 *  All rights reserved.
 *
 * This file is part of .
 *
 * spacecowboy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * spacecowboy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with spacecowboy. If not, see
 * <http://www.gnu.org/licenses/>.
 */
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

