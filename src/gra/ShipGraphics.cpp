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
#include <sc/gra/ShipGraphics.hpp>
#include <sc/gra/Graphical.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/IntegrityChangeEvent.hpp>

sc::gra::ShipGraphics::ShipGraphics( sc::gra::Engine& graphicalEngine )
  : phi::Accessory()
  , Graphical( graphicalEngine )
  , m_integrity( 100 )
{
}


sc::gra::ShipGraphics::~ShipGraphics()
{
}


void
sc::gra::ShipGraphics::shipIntegrityChanged( sc::evt::Event& event )
{
  sc::phi::IntegrityChanged integrityChanged(
      dynamic_cast< sc::phi::IntegrityChanged& >( event ) );
  m_integrity = integrityChanged.integrity();
}


void
sc::gra::ShipGraphics::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction(
      registry,
      &ShipGraphics::shipIntegrityChanged,
      sc::phi::slot::OBJECT_INTEGRITY_CHANGED );
}


void
sc::gra::ShipGraphics::draw() const
{
  phi::Coordinate heading( phi::CoordFromPolar( m_physicalModel->heading(), 10.0 ) );
  m_graphicalEngine.drawShip( m_physicalModel->coordinate(), heading, m_integrity );
}

