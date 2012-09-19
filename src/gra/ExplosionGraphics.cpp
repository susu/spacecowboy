#include <sc/gra/ExplosionGraphics.hpp>
#include <sc/gra/ParticleSource.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Accessory.hpp>

sc::gra::ExplosionGraphics::ExplosionGraphics(
    sc::phi::Sector& sector,
    sc::gra::Engine& graphicalEngine )
  : sc::phi::Accessory()
  , m_particleSource( sector, graphicalEngine, 300, 20.0, 6.28 )
{
}


sc::gra::ExplosionGraphics::~ExplosionGraphics()
{
}


void
sc::gra::ExplosionGraphics::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &ExplosionGraphics::timer, phi::slot::TIMEELAPSED );
}


void
sc::gra::ExplosionGraphics::timer( sc::evt::Event& )
{
  m_particleSource.createParticle(
      m_physicalModel->coordinate(),
      m_physicalModel->speed(),
      { 0.0 } );
}

