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

#include <sc/phi/BaseTypes.hpp>

namespace sc
{
  namespace phi
  {

    class ObjectFactory
    {
      public:
        ObjectFactory( Sector& sector );
        virtual ~ObjectFactory();

        virtual ObjectRef createShip( const ObjectProperties& properties ) = 0;
        virtual ObjectRef createRocket( const ObjectProperties& properties ) = 0;
        virtual ObjectRef createExplosion( const ObjectProperties& properties ) = 0;

      protected:
        virtual ObjectRef createBasicObject( const ObjectProperties& properties ) = 0;

        Sector& m_sector;
    };

  }
}

