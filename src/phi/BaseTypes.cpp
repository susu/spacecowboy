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
#include <sc/phi/BaseTypes.hpp>
#include <cmath>


const double sc::phi::constant::FLOATING_ERROR( 0.0001 );


sc::phi::Coordinate::Coordinate()
  : x( 0.0 )
  , y( 0.0 )
{
}

sc::phi::Coordinate::Coordinate( double x, double y )
  : x( x )
  , y( y )
{
}


bool
sc::phi::operator==( const Coordinate& left, const Coordinate& right )
{
  return std::abs( left.x - right.x ) < constant::FLOATING_ERROR &&
         std::abs( left.y - right.y ) < constant::FLOATING_ERROR;
}


sc::phi::Coordinate&
sc::phi::operator+=( Coordinate& left, const Coordinate& right )
{
  left.x+=right.x;
  left.y+=right.y;

  return left;
}


sc::phi::Coordinate
sc::phi::operator+( Coordinate left, const Coordinate& right )
{
  return left+=right;
}


sc::phi::Coordinate&
sc::phi::operator-=( Coordinate& left, const Coordinate& right )
{
  left.x-=right.x;
  left.y-=right.y;

  return left;
}


sc::phi::Coordinate
sc::phi::operator-( Coordinate left, const Coordinate& right )
{
  return left-=right;
}


sc::phi::Coordinate&
sc::phi::operator*=( Coordinate& left, const double& right )
{
  left.x*=right;
  left.y*=right;

  return left;
}


sc::phi::Coordinate
sc::phi::operator*( Coordinate left, const double& right )
{
  return left*=right;
}


sc::phi::Coordinate
sc::phi::CoordFromPolar( const Angle& angle, const double& length )
{
  return Coordinate( 
      cos( angle ) * length,
      sin( angle ) * length );
}


double
sc::phi::dotproduct( const Coordinate& left, const Coordinate& right )
{
  return left.x * right.x + left.y * right.y;
}


sc::phi::Coordinate
sc::phi::project( const Coordinate& left, const Coordinate& right )
{
  if ( right == Coordinate( 0.0, 0.0 ) )
  {
    return { 0.0, 0.0 };
  }

  return right * ( dotproduct( left, right ) / dotproduct( right, right ) );
}


double
sc::phi::distance( const Coordinate& left, const Coordinate& right )
{
  return  sqrt(
      ( left.x - right.x ) * ( left.x - right.x ) +
      ( left.y - right.y ) * ( left.y - right.y ) );
}


double
sc::phi::length( const Coordinate& vector )
{
  return sqrt( vector.x * vector.x + vector.y * vector.y );
}


sc::phi::ObjectProperties::ObjectProperties()
  : ObjectProperties( { 0.0, 0.0 }, { 0.0, 0.0 }, 0.0, 0, 0 )
{
}


sc::phi::ObjectProperties::ObjectProperties( const Coordinate& coord, const Coordinate& speed, const Angle& heading, const unsigned int radius, const unsigned int mass )
  : coordinate( coord )
  , speed( speed )
  , heading( heading )
  , radius( radius )
  , mass( mass )
{
}

