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
#include <sc/phi/Accessory.hpp>

sc::phi::Accessory::Accessory()
  : evt::Handler()
  , m_physicalModel( nullptr )
  , m_owningObject( nullptr )
  , m_sector( nullptr )
{
}


void
sc::phi::Accessory::initialize( Object& owner, Model& physicalModel, Sector& sector )
{
  m_owningObject = &owner;
  m_physicalModel = &physicalModel;
  m_sector = &sector;
}


void
sc::phi::Accessory::subscribe( sc::evt::Registry& )
{
}


sc::phi::Accessory::~Accessory()
{
}

