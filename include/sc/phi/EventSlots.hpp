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
  namespace phi
  {
    class slot
    {
      public:
        static const evt::SlotId TIMEELAPSED;
        static const evt::SlotId BACKTHRUSTER;
        static const evt::SlotId FRONTTHRUSTER;
        static const evt::SlotId LEFTTHRUSTER;
        static const evt::SlotId RIGHTTHRUSTER;
        static const evt::SlotId CWTHRUSTER;
        static const evt::SlotId CCWTHRUSTER;
        static const evt::SlotId COLLISION;
        static const evt::SlotId EXPLOSION;
        static const evt::SlotId FIRE;
        static const evt::SlotId COLLISION_DAMAGE;
        static const evt::SlotId EXPLOSION_DAMAGE;
        static const evt::SlotId OBJECT_INTEGRITY_CHANGED;
    };
  }
}

