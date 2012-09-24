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
sc::gra::Engine::drawPoint(
  const sc::phi::Coordinate& center,
  int size, unsigned int colour )
{
  sc::phi::Coordinate mappedCenter( m_focus.mapCoordinate( center ) );
  drawRawRectangle( mappedCenter.x, mappedCenter.y, m_focus.mapSize( size ), colour );
}

