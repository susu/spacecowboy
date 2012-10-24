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
#include <sc/phi/ShipStructure.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/IntegrityChangeEvent.hpp>
#include <sc/evt/BaseTypes.hpp>


sc::phi::ShipStructure::ShipStructure()
  : Accessory()
  , m_integrity( 100 )
{
}


sc::phi::ShipStructure::~ShipStructure()
{
}


void
sc::phi::ShipStructure::collisionDamage( sc::evt::Event& )
{
  m_integrity-=3;
  handleShipDamaged();
}


void
sc::phi::ShipStructure::explosionDamage( sc::evt::Event& )
{
  m_integrity-=50;
  handleShipDamaged();
}


void
sc::phi::ShipStructure::handleShipDamaged()
{
  notifyAboutIntegrityChange();
  dieIfDamagedEnough();
}


void
sc::phi::ShipStructure::notifyAboutIntegrityChange()
{
  sc::phi::IntegrityChanged event( m_integrity );
  m_owningObject->dispatchEvent( event );
}


void
sc::phi::ShipStructure::dieIfDamagedEnough()
{
  if ( m_integrity > 0 )
  {
    return;
  }

  m_owningObject->deleteObject();
}


void
sc::phi::ShipStructure::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &ShipStructure::collisionDamage, slot::COLLISION_DAMAGE );
  registerMemberFunction( registry, &ShipStructure::explosionDamage, slot::EXPLOSION_DAMAGE );
}

