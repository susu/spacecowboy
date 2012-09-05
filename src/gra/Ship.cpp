#include <sc/gra/Ship.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/gra/EngineGraphics.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/EngineBase.hpp>

namespace
{
  const unsigned int RADIUS( 10.0 );
  const sc::phi::Coordinate INIT_POSITION( 100.0, 100.0 );
}

sc::gra::Ship::Ship( sc::phi::Sector& sector, sc::gra::Engine& engine )
  : Ship( sector, engine, INIT_POSITION )
{
}


sc::gra::Ship::Ship(
    sc::phi::Sector& sector,
    sc::gra::Engine& engine,
    const sc::phi::Coordinate& coordinate )
  : sc::phi::Object( sector, coordinate, { 0.0, 0.0 } )
  , Graphical( engine )
  , m_engineGraphics( m_physicalModel, sector, engine, RADIUS )
  , m_engine( m_physicalModel, 0.5, 0.05 )
  , m_collider( m_physicalModel )

{
  add( m_engine );
  add( m_engineGraphics );
  add( m_collider );
}


void
sc::gra::Ship::draw() const
{
  sc::phi::Coordinate heading( sc::phi::CoordFromPolar( m_physicalModel.heading(), 10.0 ) );
  m_graphicalEngine.drawShip( m_physicalModel.coordinate(), heading );
}

