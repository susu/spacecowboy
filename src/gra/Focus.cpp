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
#include <sc/gra/Focus.hpp>
#include <sc/phi/BaseTypes.hpp>

#include <algorithm>

namespace
{
  const sc::phi::CoordinateType BOUNDARY( 100.0 );
}

sc::gra::Focus::Focus( unsigned int xResolution, unsigned int yResolution )
  : m_screenResolution( xResolution, yResolution )
  , m_screenCenter( ( xResolution - BOUNDARY ) / 2.0, ( yResolution - BOUNDARY ) / 2.0 )
  , m_spaceCenter( m_screenCenter )
  , m_min( 0.0, 0.0 )
  , m_max( xResolution, yResolution )
  , m_ratio( 1.0 )
  , m_targetRatio( m_ratio )
{
}


sc::phi::Coordinate
sc::gra::Focus::mapCoordinate( const sc::phi::Coordinate& coord )
{
  return ( coord - m_spaceCenter ) * m_ratio + m_screenCenter + sc::phi::Coordinate( BOUNDARY, BOUNDARY );
}


int
sc::gra::Focus::mapSize( int size )
{
  return size * m_ratio + 1;
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

  m_ratio = std::min( m_ratio, 1.0 );

  m_spaceCenter = m_min + physicalResolution * 0.5;

  m_min = m_spaceCenter;
  m_max = m_spaceCenter;
}

