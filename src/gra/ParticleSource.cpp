#include <sc/gra/ParticleSource.hpp>
#include <sc/gra/Particle.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Sector.hpp>

#include <cstdlib>

namespace
{
  double getRandom( const double& deviation )
  {
    return (std::rand() * deviation) / RAND_MAX - deviation / 2.0;
  }
}


sc::gra::ParticleSource::ParticleSource(
    sc::phi::Sector& sector,
    sc::gra::Engine& engine,
    unsigned int density,
    const double& velocity,
    const double& deviation )
  : m_sector( sector )
  , m_graphicalEngine( engine )
  , m_density( density )
  , m_velocity( velocity )
  , m_deviation( deviation )
{
}


void
sc::gra::ParticleSource::createParticle(
    const sc::phi::Coordinate& coord,
    const sc::phi::Coordinate& baseSpeed,
    const sc::phi::Angle& heading )
{
  try
  {
    for ( unsigned int i( 0 ); i < m_density; ++i)
    {
      sc::phi::ObjectRef particle(
          new Particle(
            m_sector, m_graphicalEngine,
            coord,
            baseSpeed + sc::phi::CoordFromPolar( heading + getRandom( m_deviation ), m_velocity + getRandom( 2.0 * m_velocity ) ) )
          );

      m_sector.addObject( particle );
    }
  }
  catch ( std::bad_alloc& )
  {
  }
}

