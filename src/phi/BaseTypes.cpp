#include <sc/phi/BaseTypes.hpp>
#include <cmath>

sc::phi::Coordinate::Coordinate()
  : x( 0 )
  , y( 0 )
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
  return left.x==right.x &&
         left.y==right.y;
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

