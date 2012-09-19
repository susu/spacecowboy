#include <sc/gra/ShipGraphics.hpp>
#include <sc/gra/Graphical.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>

sc::gra::ShipGraphics::ShipGraphics( sc::gra::Engine& graphicalEngine )
  : phi::Accessory()
  , Graphical( graphicalEngine )
{
}


sc::gra::ShipGraphics::~ShipGraphics()
{
}


void
sc::gra::ShipGraphics::subscribe( sc::evt::Registry& )
{
}


void
sc::gra::ShipGraphics::draw() const
{
  phi::Coordinate heading( phi::CoordFromPolar( m_physicalModel->heading(), 10.0 ) );
  m_graphicalEngine.drawShip( m_physicalModel->coordinate(), heading );
}

