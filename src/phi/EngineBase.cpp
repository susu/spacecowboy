#include <sc/phi/EngineBase.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/BaseTypes.hpp>

#include <functional>
#include <cassert>

sc::phi::Engine::Engine( Model& physicalModel,
                         const double& backThrustPower,
                         const double& spinThrustPower )
: m_physicalModel( physicalModel )
, m_thrusterPower( backThrustPower )
, m_spinThrusterPower( spinThrustPower )
{
}


sc::phi::Engine::~Engine()
{
}


void
sc::phi::Engine::backThruster( sc::evt::Event& )
{
  m_physicalModel.push(
      CoordFromPolar( m_physicalModel.heading(), m_thrusterPower )
      );
}


void
sc::phi::Engine::cwThruster( sc::evt::Event& )
{
  spinShip( true );
}


void
sc::phi::Engine::ccwThruster( sc::evt::Event& )
{
  spinShip( false );
}


void
sc::phi::Engine::spinShip( bool clockWise )
{
  m_physicalModel.spin( m_spinThrusterPower * ( clockWise ? 1.0 : -1.0 ) );
}


void
sc::phi::Engine::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &Engine::backThruster, slot::BACKTHRUSTER );
  registerMemberFunction( registry, &Engine::cwThruster, slot::CWTHRUSTER );
  registerMemberFunction( registry, &Engine::ccwThruster, slot::CCWTHRUSTER );

}

