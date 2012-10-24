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
#include <sc/phi/EventSlots.hpp>

const sc::evt::SlotId sc::phi::slot::TIMEELAPSED = 0;
const sc::evt::SlotId sc::phi::slot::BACKTHRUSTER = 1;
const sc::evt::SlotId sc::phi::slot::FRONTTHRUSTER = 2;
const sc::evt::SlotId sc::phi::slot::LEFTTHRUSTER = 3;
const sc::evt::SlotId sc::phi::slot::RIGHTTHRUSTER = 4;
const sc::evt::SlotId sc::phi::slot::CWTHRUSTER = 5;
const sc::evt::SlotId sc::phi::slot::CCWTHRUSTER = 6;
const sc::evt::SlotId sc::phi::slot::COLLISION = 7;
const sc::evt::SlotId sc::phi::slot::EXPLOSION = 8;
const sc::evt::SlotId sc::phi::slot::FIRE= 9;
const sc::evt::SlotId sc::phi::slot::COLLISION_DAMAGE = 10;
const sc::evt::SlotId sc::phi::slot::EXPLOSION_DAMAGE = 11;
const sc::evt::SlotId sc::phi::slot::OBJECT_INTEGRITY_CHANGED = 12;

