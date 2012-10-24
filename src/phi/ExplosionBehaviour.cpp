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
#include <sc/phi/ExplosionBehaviour.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/ExplosionEvent.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/evt/Event.hpp>

sc::phi::ExplosionBehaviour::ExplosionBehaviour( Sector& sector, Object* explosion )
  : Accessory()
  , m_explosion( explosion )
  , m_sector( sector )
{
}


sc::phi::ExplosionBehaviour::~ExplosionBehaviour()
{
}


void
sc::phi::ExplosionBehaviour::timer( sc::evt::Event& )
{
  sc::phi::ExplosionEvent explosion( *m_physicalModel, 100 );
  for ( auto& collider : m_sector.colliders() )
  {
    collider->dispatchEvent( explosion );
  }
  m_explosion->deleteObject();
}


void
sc::phi::ExplosionBehaviour::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &ExplosionBehaviour::timer, slot::TIMEELAPSED );
}

