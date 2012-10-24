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
#pragma once

#include <memory>
#include <vector>
#include <deque>

namespace sc
{
  namespace phi
  {
    class Object;
    typedef std::shared_ptr<Object> ObjectRef;
    typedef std::deque<ObjectRef> ObjectContainer;

    class Accessory;
    typedef std::unique_ptr<Accessory> AccessoryRef;
    typedef std::vector<AccessoryRef> AccessoryContainer;

    class Sector;

    typedef float Ratio;
    typedef double CoordinateType;
    typedef double Angle;

    struct Coordinate
    {
      Coordinate();
      Coordinate( double x, double y );

      CoordinateType x;
      CoordinateType y;
    };


    struct ObjectProperties
    {
      ObjectProperties();
      ObjectProperties( const Coordinate& coordinate, const Coordinate& speed, const Angle& heading, unsigned int radius, unsigned int mass );

      Coordinate coordinate;
      Coordinate speed;
      Angle heading;

      unsigned int radius;
      unsigned int mass;
    };

    bool operator==( const Coordinate& left, const Coordinate& right );
    sc::phi::Coordinate& operator+=( Coordinate& left, const Coordinate& right );
    sc::phi::Coordinate operator+( Coordinate left, const Coordinate& right );
    sc::phi::Coordinate& operator-=( Coordinate& left, const Coordinate& right );
    sc::phi::Coordinate operator-( Coordinate left, const Coordinate& right );
    sc::phi::Coordinate& operator*=( Coordinate& left, const double& right );
    sc::phi::Coordinate operator*( Coordinate left, const double& right );

    double distance( const Coordinate& left, const Coordinate& right );
    double dotproduct( const Coordinate& left, const Coordinate& right );
    sc::phi::Coordinate project( const Coordinate& left, const Coordinate& right );

    sc::phi::Coordinate CoordFromPolar( const Angle& angle, const double& length );
    double length( const Coordinate& vector );

    struct constant
    {
      static const double FLOATING_ERROR;
    };

  }
}

