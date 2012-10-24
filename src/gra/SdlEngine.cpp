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

