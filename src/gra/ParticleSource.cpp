#include <sc/gra/ParticleSource.hpp>
#include <sc/gra/Particle.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Sector.hpp>

#include <cstdlib>

namespace
{
  sc::phi::Coordinate getRandomSpeed( const double velocity )
  {
    const double multiplier( velocity / 3.0 );
    return sc::phi::Coordinate(
        (std::rand() * multiplier) / RAND_MAX - multiplier / 2.0,
        (std::rand() * multiplier) / RAND_MAX - multiplier / 2.0 );
  }
}


sc::gra::ParticleSource::ParticleSource( sc::phi::Sector& sector, sc::gra::Engine& engine, unsigned int density )
  : m_sector( sector )
  , m_graphicalEngine( engine )
  , m_density( density )
{
}


void
sc::gra::ParticleSource::createParticle(
    const sc::phi::Coordinate& coord,
    const sc::phi::Coordinate& baseSpeed,
    const sc::phi::Angle& heading )
{
  const static double VELOCITY( 5.0 );

  for ( unsigned char i( 0 ); i < m_density; ++i)
  {
    sc::phi::ObjectRef particle(
        new Particle( m_sector, m_graphicalEngine,
          coord,
          baseSpeed + sc::phi::CoordFromPolar( heading, VELOCITY ) + getRandomSpeed( VELOCITY ) )
        );
    m_sector.addObject( particle );
  }
}

