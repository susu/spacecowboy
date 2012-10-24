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
#include <sc/gra/Engine.hpp>
#include <sc/gra/Graphical.hpp>
#include <vector>
#include <algorithm>

sc::gra::Engine::Engine( unsigned int xRes, unsigned int yRes )
  : m_objectContainer()
  , m_focus( xRes, yRes )
{
}


sc::gra::Engine::~Engine()
{
}


void
sc::gra::Engine::drawObjects()
{
  for ( const auto& object : m_objectContainer )
  {
    object->draw();
  }
  m_focus.updateFocus();
}


void
sc::gra::Engine::addObject( const Graphical* object )
{
  m_objectContainer.push_back( object );
}


void
sc::gra::Engine::removeObject( const Graphical* object )
{
  auto newEnd( std::remove( m_objectContainer.begin(), m_objectContainer.end(), object ) );
  m_objectContainer.erase( newEnd, m_objectContainer.end() );
}


void
sc::gra::Engine::drawShip(
    const sc::phi::Coordinate& coordinate,
    const sc::phi::Coordinate& heading,
    int integrity )
{
  drawPoint( coordinate, 4, 0xaaaa00 );
  drawPoint( coordinate + heading, 4, 0x00ff00 );
  drawPoint( coordinate - heading, 4, 0xff0000 );

  sc::phi::Coordinate perpendicular( heading.y, heading.x * -1.0 );
  drawPoint( coordinate - heading * 0.5 + perpendicular * 0.5, 4, 0xff0000 );
  drawPoint( coordinate - heading * 0.5 - perpendicular * 0.5, 4, 0xff0000 );

  m_focus.inFocus( coordinate );

  sc::phi::Coordinate mappedCenter( m_focus.mapCoordinate( coordinate ) );
  int scaledIntegrity( integrity / 10 );
  for ( int i( 0 ); i < scaledIntegrity; ++i )
  {
    sc::phi::Coordinate point( mappedCenter - sc::phi::Coordinate{ 15.0 - i * 5, 15.0 } );
    drawRawRectangle( point.x, point.y, 4, 0xffff00 );
  }
}


void
sc::gra::Engine::drawCircle(
    const sc::phi::Coordinate& center,
    unsigned int rad, unsigned int colour )
{
  unsigned int radius( m_focus.mapSize( rad ) );
  sc::phi::Coordinate mappedCenter( m_focus.mapCoordinate( center ) );
  unsigned int x0( static_cast< unsigned int >( mappedCenter.x ) );
  unsigned int y0( static_cast< unsigned int >( mappedCenter.y ) );

  unsigned int pixelSize( m_focus.mapSize( 5 ) );

  int f( 1 - radius );
  int ddF_x( 1 );
  int ddF_y( -2 * radius );
  int x( 0 );
  int y( radius );

  drawRawRectangle( x0, y0 + radius, pixelSize, colour );
  drawRawRectangle( x0, y0 - radius, pixelSize, colour );
  drawRawRectangle( x0 + radius, y0, pixelSize, colour );
  drawRawRectangle( x0 - radius, y0, pixelSize, colour );

  while( x < y )
  {
    if( f >= 0 )
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
    drawRawRectangle( x0 + x, y0 + y, pixelSize, colour );
    drawRawRectangle( x0 - x, y0 + y, pixelSize, colour );
    drawRawRectangle( x0 + x, y0 - y, pixelSize, colour );
    drawRawRectangle( x0 - x, y0 - y, pixelSize, colour );
    drawRawRectangle( x0 + y, y0 + x, pixelSize, colour );
    drawRawRectangle( x0 - y, y0 + x, pixelSize, colour );
    drawRawRectangle( x0 + y, y0 - x, pixelSize, colour );
    drawRawRectangle( x0 - y, y0 - x, pixelSize, colour );
  }
}


void
sc::gra::Engine::drawPoint(
  const sc::phi::Coordinate& center,
  unsigned int size, unsigned int colour )
{
  sc::phi::Coordinate mappedCenter( m_focus.mapCoordinate( center ) );
  drawRawRectangle( mappedCenter.x, mappedCenter.y, m_focus.mapSize( size ), colour );
}

