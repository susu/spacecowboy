#include <sc/gra/Ship.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/gra/ShipEngine.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/BaseTypes.hpp>

namespace
{
  const unsigned int RADIUS( 10.0 );
}

sc::gra::Ship::Ship( sc::phi::Sector& sector, sc::gra::Engine& engine )
  : sc::phi::Object( sector )
  , Graphical( engine )
  , m_shipEngine( m_physicalModel, sector, engine, RADIUS )
{
  add( m_shipEngine );
}


void
sc::gra::Ship::draw() const
{
  sc::phi::Coordinate heading( sc::phi::CoordFromPolar( m_physicalModel.heading(), 10.0 ) );
  m_graphicalEngine.drawShip( m_physicalModel.coordinate(), heading );
}

