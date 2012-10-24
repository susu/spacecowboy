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
#include <sc/gra/ExplosionGraphics.hpp>
#include <sc/gra/ParticleSource.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Accessory.hpp>

sc::gra::ExplosionGraphics::ExplosionGraphics(
    sc::phi::Sector& sector,
    sc::gra::Engine& graphicalEngine )
  : sc::phi::Accessory()
  , m_particleSource( sector, graphicalEngine, 300, 20.0, 6.28 )
{
}


sc::gra::ExplosionGraphics::~ExplosionGraphics()
{
}


void
sc::gra::ExplosionGraphics::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &ExplosionGraphics::timer, phi::slot::TIMEELAPSED );
}


void
sc::gra::ExplosionGraphics::timer( sc::evt::Event& )
{
  m_particleSource.createParticle(
      m_physicalModel->coordinate(),
      m_physicalModel->speed(),
      { 0.0 } );
}

