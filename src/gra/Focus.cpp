#include <sc/gra/Focus.hpp>
#include <sc/phi/BaseTypes.hpp>

#include <algorithm>

namespace
{
  const sc::phi::CoordinateType BOUNDARY( 50.0 );
}

sc::gra::Focus::Focus( unsigned int xResolution, unsigned int yResolution )
  : m_screenResolution( xResolution, yResolution )
  , m_screenCenter( ( xResolution - BOUNDARY ) / 2.0, ( yResolution - BOUNDARY ) / 2.0 )
  , m_spaceCenter( m_screenCenter )
  , m_min( 0.0, 0.0 )
  , m_max( xResolution, yResolution )
  , m_ratio( 1.0 )
{
}


sc::phi::Coordinate
sc::gra::Focus::mapCoordinate( const sc::phi::Coordinate& coord )
{
  return ( coord + m_spaceCenter * -1.0 ) * m_ratio + m_screenCenter + sc::phi::Coordinate( BOUNDARY, BOUNDARY );
}


void
sc::gra::Focus::inFocus( const sc::phi::Coordinate& coord )
{
  m_min.x = std::min( m_min.x, coord.x );
  m_min.y = std::min( m_min.y, coord.y );
  m_max.x = std::max( m_max.x, coord.x );
  m_max.y = std::max( m_max.y, coord.y );
}


void
sc::gra::Focus::updateFocus()
{
  sc::phi::Coordinate physicalResolution( m_max.x - m_min.x, m_max.y - m_min.y );
  m_ratio = std::min( ( m_screenResolution.x - BOUNDARY * 2.0 ) / ( physicalResolution.x ),
                      ( m_screenResolution.y - BOUNDARY * 2.0 ) / ( physicalResolution.y ) );

  m_ratio = std::min( m_ratio, 3.0 );

  m_spaceCenter = m_min + physicalResolution * 0.5;

  m_min = m_spaceCenter;
  m_max = m_spaceCenter;
}

