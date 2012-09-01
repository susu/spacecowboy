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
  pimpBackThruster();
}


void
sc::phi::Engine::cwThruster( sc::evt::Event& )
{
  spinShip( true );
  pimpCwThruster();
}


void
sc::phi::Engine::ccwThruster( sc::evt::Event& )
{
  spinShip( false );
  pimpCcwThruster();
}


void
sc::phi::Engine::spinShip( bool clockWise )
{
  m_physicalModel.spin( m_spinThrusterPower * ( clockWise ? 1.0 : -1.0 ) );
}


void
sc::phi::Engine::subscribe( sc::evt::Registry& registry )
{
  registerFunction( registry, &Engine::backThruster, slot::BACKTHRUSTER );
  registerFunction( registry, &Engine::cwThruster, slot::CWTHRUSTER );
  registerFunction( registry, &Engine::ccwThruster, slot::CCWTHRUSTER );

}


void
sc::phi::Engine::registerFunction(
    sc::evt::Registry& registry,
    void (Engine::*funptr)( sc::evt::Event& ),
    const evt::SlotId& slot )
{
  std::function< void( Engine*, sc::evt::Event& ) > fun ( funptr );
  sc::evt::Callback callback( std::bind( fun, this, std::placeholders::_1 ));
  registry[ slot ].push_back( callback );
}


void
sc::phi::Engine::pimpBackThruster()
{
}


void
sc::phi::Engine::pimpCwThruster()
{
}


void
sc::phi::Engine::pimpCcwThruster()
{
}

