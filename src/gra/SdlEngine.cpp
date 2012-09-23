#include <sc/gra/SdlEngine.hpp>
#include <sc/gra/Graphical.hpp>
#include <sc/phi/BaseTypes.hpp>

#include <cassert>
#include "SDL.h"

sc::gra::SdlEngine::SdlEngine( unsigned int x, unsigned int y )
  : Engine( x, y )
  , m_screen( nullptr )
  , m_x( x )
  , m_y( y )
{
	assert( SDL_Init( SDL_INIT_VIDEO ) == 0 && "Unable to initialize sdl!" );
	m_screen = SDL_SetVideoMode( x, y, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
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
  SDL_Flip( m_screen );
}


void
sc::gra::SdlEngine::drawRawRectangle(
    unsigned int x,
    unsigned int y,
    int size, unsigned int colour )
{
  SDL_Rect rectangle = {
    static_cast<Sint16>( x - size / 2 ),
    static_cast<Sint16>( y - size / 2 ),
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

