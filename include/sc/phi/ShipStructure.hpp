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
#include <sc/phi/Accessory.hpp>

namespace sc
{
  namespace phi
  {
    class Model;
    class Coordinate;

    class ShipStructure : public Accessory
    {
      public:
        ShipStructure();
        virtual ~ShipStructure();

        ShipStructure( const ShipStructure& ) = delete;
        ShipStructure& operator=( const ShipStructure& ) = delete;

        void collisionDamage( sc::evt::Event& event );
        void explosionDamage( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );

      private:
        void handleShipDamaged();
        void notifyAboutIntegrityChange();
        void dieIfDamagedEnough();

        int m_integrity;
    };
  }
}

