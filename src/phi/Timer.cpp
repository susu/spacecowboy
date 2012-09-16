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

