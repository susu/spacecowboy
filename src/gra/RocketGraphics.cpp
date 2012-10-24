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
#include <sc/gra/RocketGraphics.hpp>
#include <sc/gra/Graphical.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>

sc::gra::RocketGraphics::RocketGraphics( sc::gra::Engine& graphicalEngine )
  : phi::Accessory()
  , Graphical( graphicalEngine )
{
}


sc::gra::RocketGraphics::~RocketGraphics()
{
}


void
sc::gra::RocketGraphics::subscribe( sc::evt::Registry& )
{
}


void
sc::gra::RocketGraphics::draw() const
{
  phi::Coordinate heading( phi::CoordFromPolar( m_physicalModel->heading(), 10.0 ) );
  m_graphicalEngine.drawPoint( m_physicalModel->coordinate(), 1, 0xff0000 );
}

