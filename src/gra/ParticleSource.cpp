#include <sc/gra/ParticleSource.hpp>
#include <sc/gra/Particle.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Sector.hpp>

#include <cstdlib>

namespace
{
  sc::phi::Coordinate getRandomSpeed()
  {
    static const double multiplier( 10.0 );
    return sc::phi::Coordinate(
        (std::rand() * multiplier) / RAND_MAX - multiplier / 2.0,
        (std::rand() * multiplier) / RAND_MAX - multiplier / 2.0 );
  }
}


sc::gra::ParticleSource::ParticleSource( sc::phi::Sector& sector, sc::gra::Engine& engine )
  : m_sector( sector )
  , m_graphicalEngine( engine )
{
}


void
sc::gra::ParticleSource::createParticle(
    const sc::phi::Coordinate& coord,
    const sc::phi::Coordinate& baseSpeed,
    const sc::phi::Angle& heading )
{
  const static double VELOCITY( 30.0 );

  sc::phi::ObjectRef particle(
      new Particle( m_sector, m_graphicalEngine,
                    coord,
                    baseSpeed + sc::phi::CoordFromPolar( heading, VELOCITY ) + getRandomSpeed() )
      );

  m_sector.addObject( particle );
}

