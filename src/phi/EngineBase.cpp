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
#include <sc/phi/EngineBase.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/BaseTypes.hpp>

#include <functional>
#include <cassert>

sc::phi::Engine::Engine( const double& backThrustPower,
                         const double& spinThrustPower )
: Accessory()
, m_thrusterPower( backThrustPower )
, m_spinThrusterPower( spinThrustPower )
{
}


sc::phi::Engine::~Engine()
{
}


void
sc::phi::Engine::backThruster( sc::evt::Event& )
{
  m_physicalModel->push(
      CoordFromPolar( m_physicalModel->heading(), m_thrusterPower )
      );
}


void
sc::phi::Engine::cwThruster( sc::evt::Event& )
{
  spinShip( true );
}


void
sc::phi::Engine::ccwThruster( sc::evt::Event& )
{
  spinShip( false );
}


void
sc::phi::Engine::spinShip( bool clockWise )
{
  m_physicalModel->spin( m_spinThrusterPower * ( clockWise ? 1.0 : -1.0 ) );
}


void
sc::phi::Engine::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &Engine::backThruster, slot::BACKTHRUSTER );
  registerMemberFunction( registry, &Engine::cwThruster, slot::CWTHRUSTER );
  registerMemberFunction( registry, &Engine::ccwThruster, slot::CCWTHRUSTER );

}

