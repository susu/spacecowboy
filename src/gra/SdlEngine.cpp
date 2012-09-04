#include <sc/gra/SdlEngine.hpp>
#include <sc/gra/Graphical.hpp>
#include <sc/phi/BaseTypes.hpp>

#include <cassert>
#include "SDL.h"

sc::gra::SdlEngine::SdlEngine( int x, int y )
  : m_x( x )
  , m_y( y )
{
	assert( SDL_Init( SDL_INIT_VIDEO ) == 0 && "Unable to initialize sdl!" );
	m_screen = SDL_SetVideoMode( x, y, 0, 0 );
}


sc::gra::SdlEngine::~SdlEngine()
{
	SDL_Quit();
}


void
sc::gra::SdlEngine::updateScreen()
{
  drawBackground();
  drawObjects();
  SDL_UpdateRect( m_screen, 0, 0, 0, 0 );
}


void
sc::gra::SdlEngine::drawShip(
    const sc::phi::Coordinate& coordinate,
    const sc::phi::Coordinate& heading )
{
  drawPoint( coordinate, 4, 0xaaaa00 );
  drawPoint( coordinate + heading, 4, 0x00ff00 );
  drawPoint( coordinate + heading * -1.0, 4, 0xff0000 );

  sc::phi::Coordinate perpendicular( heading.y, heading.x * -1.0 );
  drawPoint( coordinate + heading * -0.5 + perpendicular * 0.5, 4, 0xff0000 );
  drawPoint( coordinate + heading * -0.5 + perpendicular * -0.5, 4, 0xff0000 );
}


void
sc::gra::SdlEngine::drawPoint(
  const sc::phi::Coordinate& center,
  int size, unsigned int colour )
{
  SDL_Rect rectangle = {
    static_cast<Sint16>( center.x - size / 2 ),
    static_cast<Sint16>( center.y - size / 2 ),
    static_cast<Uint16>( size ),
    static_cast<Uint16>( size ) };

  SDL_FillRect( m_screen, &rectangle, colour );
}


void
sc::gra::SdlEngine::drawBackground()
{
  SDL_Rect rectangle =
  { static_cast<unsigned short>( 0 ), static_cast<unsigned short>( 0 ),
    static_cast<unsigned short>( m_x ), static_cast<unsigned short>( m_y ) };
  SDL_FillRect( m_screen, &rectangle, 0x000000 );
}
