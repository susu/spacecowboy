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
#include <sc/gra/ParticleSource.hpp>
#include <sc/gra/Particle.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Sector.hpp>

#include <cstdlib>

namespace
{
  double getRandom( const double& deviation )
  {
    return (std::rand() * deviation) / RAND_MAX - deviation / 2.0;
  }
}


sc::gra::ParticleSource::ParticleSource(
    sc::phi::Sector& sector,
    sc::gra::Engine& engine,
    unsigned int density,
    const double& velocity,
    const double& deviation )
  : m_sector( sector )
  , m_graphicalEngine( engine )
  , m_density( density )
  , m_velocity( velocity )
  , m_deviation( deviation )
{
}


void
sc::gra::ParticleSource::createParticle(
    const sc::phi::Coordinate& coord,
    const sc::phi::Coordinate& baseSpeed,
    const sc::phi::Angle& heading )
{
  try
  {
    for ( unsigned int i( 0 ); i < m_density; ++i)
    {
      sc::phi::ObjectRef particle(
          new Particle(
            m_sector, m_graphicalEngine,
            coord,
            baseSpeed + sc::phi::CoordFromPolar( heading + getRandom( m_deviation ), m_velocity + getRandom( 2.0 * m_velocity ) ) )
          );

      m_sector.addObject( particle );
    }
  }
  catch ( std::bad_alloc& )
  {
  }
}

