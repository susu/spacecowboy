#pragma once

#include <memory>

namespace sc
{
  namespace phi
  {
    class Object;
    class Sector;
    typedef std::shared_ptr<Object> ObjectRef;

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

    bool operator==( const Coordinate& left, const Coordinate& right );
    sc::phi::Coordinate& operator+=( Coordinate& left, const Coordinate& right );
    sc::phi::Coordinate operator+( Coordinate left, const Coordinate& right );
    sc::phi::Coordinate& operator*=( Coordinate& left, const double& right );
    sc::phi::Coordinate operator*( Coordinate left, const double& right );

    sc::phi::Coordinate CoordFromPolar( const Angle& angle, const double& length );

  }
}

