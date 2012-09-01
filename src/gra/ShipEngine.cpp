#include <sc/gra/ShipEngine.hpp>
#include <sc/gra/ParticleSource.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/EngineBase.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/Sector.hpp>

sc::gra::ShipEngine::ShipEngine(
    sc::phi::Model& model,
    sc::phi::Sector& sector,
    sc::gra::Engine& graphicalEngine,
    const unsigned int shipRadius )
  : sc::phi::Engine( model, 0.5, 0.05 )
  , m_particleSource( sector, graphicalEngine )
  , m_physicalModel( model )
  , m_shipRadius( shipRadius )
{
}


sc::gra::ShipEngine::~ShipEngine()
{
}


void
sc::gra::ShipEngine::pimpBackThruster()
{
  m_particleSource.createParticle(
      shipBack(),
      m_physicalModel.speed(),
      m_physicalModel.heading() - 3.14 );
}


void
sc::gra::ShipEngine::pimpCwThruster()
{
  m_particleSource.createParticle(
      shipFront(),
      m_physicalModel.speed(),
      right() );

  m_particleSource.createParticle(
      shipBack(),
      m_physicalModel.speed(),
      left() );
}


void
sc::gra::ShipEngine::pimpCcwThruster()
{
  m_particleSource.createParticle(
      shipFront(),
      m_physicalModel.speed(),
      left() );

  m_particleSource.createParticle(
      shipBack(),
      m_physicalModel.speed(),
      right() );
}


sc::phi::Coordinate
sc::gra::ShipEngine::shipFront() const
{
  return m_physicalModel.coordinate() +
    sc::phi::CoordFromPolar( m_physicalModel.heading(), m_shipRadius );
}

sc::phi::Coordinate
sc::gra::ShipEngine::shipBack() const
{
  return m_physicalModel.coordinate() +
    sc::phi::CoordFromPolar( m_physicalModel.heading(), m_shipRadius ) * -1.0;
}


sc::phi::Angle
sc::gra::ShipEngine::left() const
{
  return m_physicalModel.heading() + 3.14 / 2;
}

sc::phi::Angle
sc::gra::ShipEngine::right() const
{
  return m_physicalModel.heading() - 3.14 / 2;
}

