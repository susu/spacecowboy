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
#include <sc/phi/Model.hpp>
#include <sc/evt/Hub.hpp>

#include <deque>

namespace sc
{
  namespace phi
  {
    class Object : public evt::Hub
    {
      public:
        Object( Sector& sector );
        Object( Sector& sector, const ObjectProperties& properties );

        void timeElapsed( const Ratio& stepRatio );
        virtual ~Object();

        bool isColliding() const;
        void checkCollision( const ObjectContainer& collection );
        void deleteObject();
        bool isDeleted() const;

        void addAccessory( AccessoryRef& accessory );

      protected:
        Model m_physicalModel;
        Sector& m_sector;

      private:
        virtual void timerUpdate( const Ratio& ) {}

        AccessoryContainer m_accessories;
        bool m_deleted;
    };
  }
}

