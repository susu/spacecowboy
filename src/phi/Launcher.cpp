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
#include <sc/phi/Launcher.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/BaseTypes.hpp>

namespace
{
  const int COOLDOWN( 30 );
  const int ROCKET_SENSOR( 10 );
}

sc::phi::Launcher::Launcher( ObjectFactory& objectFactory )
  : Accessory()
  , m_objectFactory( objectFactory )
  , m_coolDown( 0 )
{
}


sc::phi::Launcher::~Launcher()
{
}


void
sc::phi::Launcher::fire( sc::evt::Event& )
{
  if ( m_coolDown > 0 )
  {
    return;
  }

  m_coolDown = COOLDOWN;

  m_objectFactory.createRocket(
      { m_physicalModel->coordinate() + CoordFromPolar( m_physicalModel->heading(), 30.0 ),
        m_physicalModel->speed(),
        m_physicalModel->heading(),
        ROCKET_SENSOR,
        1 } );
}


void
sc::phi::Launcher::timer( sc::evt::Event& )
{
  if ( m_coolDown > 0 )
  {
    --m_coolDown;
  }
}


void
sc::phi::Launcher::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &Launcher::fire, slot::FIRE );
  registerMemberFunction( registry, &Launcher::timer, slot::TIMEELAPSED );
}

