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

