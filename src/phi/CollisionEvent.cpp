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
#include <sc/phi/CollisionEvent.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Model.hpp>
#include <sc/evt/Event.hpp>

sc::phi::CollisionEvent::CollisionEvent( const ObjectRef& collidingObject, Model& physicalModel )
  : sc::evt::Event()
  , m_collidingObject( collidingObject )
  , m_modelOfCollider( physicalModel )
{
}

void
sc::phi::CollisionEvent::handle( sc::evt::Registry& registry )
{
  notifySlot( registry, slot::COLLISION );
}


sc::phi::Coordinate
sc::phi::CollisionEvent::otherSpeed() const
{
  return m_modelOfCollider.speed();
}


sc::phi::Coordinate
sc::phi::CollisionEvent::otherCoord() const
{
  return m_modelOfCollider.coordinate();
}


unsigned int
sc::phi::CollisionEvent::otherMass() const
{
  return m_modelOfCollider.mass();
}

