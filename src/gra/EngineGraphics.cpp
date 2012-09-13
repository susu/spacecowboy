#include <sc/gra/EngineGraphics.hpp>
#include <sc/gra/ParticleSource.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Accessory.hpp>

sc::gra::EngineGraphics::EngineGraphics(
    sc::phi::Sector& sector,
    sc::gra::Engine& graphicalEngine,
    const unsigned int shipRadius,
    unsigned int particleDensity )
  : sc::phi::Accessory()
  , m_particleSource( sector, graphicalEngine, particleDensity, 5.0, 0.2 )
  , m_shipRadius( shipRadius )
{
}


sc::gra::EngineGraphics::~EngineGraphics()
{
}


void
sc::gra::EngineGraphics::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &EngineGraphics::pimpBackThruster, phi::slot::BACKTHRUSTER );
  registerMemberFunction( registry, &EngineGraphics::pimpCwThruster, phi::slot::CWTHRUSTER );
  registerMemberFunction( registry, &EngineGraphics::pimpCcwThruster, phi::slot::CCWTHRUSTER );
}


void
sc::gra::EngineGraphics::pimpBackThruster( sc::evt::Event& event )
{
  m_particleSource.createParticle(
      shipBack(),
      m_physicalModel->speed(),
      m_physicalModel->heading() - 3.14 );
}


void
sc::gra::EngineGraphics::pimpCwThruster( sc::evt::Event& event )
{
  m_particleSource.createParticle(
      shipFront(),
      m_physicalModel->speed(),
      right() );

  m_particleSource.createParticle(
      shipBack(),
      m_physicalModel->speed(),
      left() );
}


void
sc::gra::EngineGraphics::pimpCcwThruster( sc::evt::Event& event )
{
  m_particleSource.createParticle(
      shipFront(),
      m_physicalModel->speed(),
      left() );

  m_particleSource.createParticle(
      shipBack(),
      m_physicalModel->speed(),
      right() );
}


sc::phi::Coordinate
sc::gra::EngineGraphics::shipFront() const
{
  return m_physicalModel->coordinate() +
    sc::phi::CoordFromPolar( m_physicalModel->heading(), m_shipRadius );
}

sc::phi::Coordinate
sc::gra::EngineGraphics::shipBack() const
{
  return m_physicalModel->coordinate() - sc::phi::CoordFromPolar( m_physicalModel->heading(), m_shipRadius );
}


sc::phi::Angle
sc::gra::EngineGraphics::left() const
{
  return m_physicalModel->heading() + 3.14 / 2;
}

sc::phi::Angle
sc::gra::EngineGraphics::right() const
{
  return m_physicalModel->heading() - 3.14 / 2;
}

