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
#include <sc/phi/Timer.hpp>
#include <sc/phi/BaseTypes.hpp>

#include <sys/time.h>

sc::phi::Timer::Timer()
  : m_previousTime()
  , m_previousRatio( 0.1 )
{
  gettimeofday( &m_previousTime, nullptr );
}


sc::phi::Ratio
sc::phi::Timer::timeFrameRatio()
{
  struct timeval currentTime;
  gettimeofday( &currentTime, nullptr );

  struct timeval tempPrevious( m_previousTime );
  m_previousTime = currentTime;

  if ( currentTime.tv_usec - tempPrevious.tv_usec < 0 )
  {
    currentTime.tv_usec += 1000000;
  }

  Ratio currentRatio( ( ( currentTime.tv_usec - tempPrevious.tv_usec ) / 100000.0 ) );
  m_previousRatio+= 0.001 * ( currentRatio > m_previousRatio ? 1.0 : -1.0 );
  return m_previousRatio;
}

