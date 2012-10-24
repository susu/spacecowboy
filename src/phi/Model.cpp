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
#include <sc/phi/Model.hpp>
#include <sc/phi/BaseTypes.hpp>

sc::phi::Model::Model(
    const Coordinate& coordinate,
    const Coordinate& speed,
    const Angle&      heading,
    const Angle&      angularVelocity,
    unsigned int      radius,
    unsigned int      mass )
  : m_coordinate( coordinate  )
  , m_speed( speed )
  , m_heading( heading )
  , m_angularVelocity( angularVelocity )
  , m_speedModifier( 0.0, 0.0 )
  , m_angularVelocityModifier( 0.0 )
  , m_radius( radius )
  , m_mass( mass )
{
}


void
sc::phi::Model::timeElapse( const Ratio& timeFrameRatio )
{
  updateWithModifiers();

  m_coordinate+=m_speed * timeFrameRatio;
  m_heading+=m_angularVelocity * timeFrameRatio;
}


void
sc::phi::Model::updateWithModifiers()
{
  m_speed += m_speedModifier;
  m_speedModifier = { 0.0, 0.0 };

  m_angularVelocity += m_angularVelocityModifier;
  m_angularVelocityModifier = 0.0;
}


void
sc::phi::Model::spin( const double& force )
{
  m_angularVelocityModifier+=force / m_mass;
}


void
sc::phi::Model::push( const Coordinate& force )
{
  m_speedModifier+=force * ( 1.0 / m_mass );
}


bool
sc::phi::collides( const Model& left, const Model& right )
{
  return distance( left.coordinate(), right.coordinate() ) <
         left.radius() + right.radius();
}

