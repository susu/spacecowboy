#include <sc/gra/RocketGraphics.hpp>
#include <sc/gra/Graphical.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>

sc::gra::RocketGraphics::RocketGraphics( sc::gra::Engine& graphicalEngine )
  : phi::Accessory()
  , Graphical( graphicalEngine )
{
}


sc::gra::RocketGraphics::~RocketGraphics()
{
}


void
sc::gra::RocketGraphics::subscribe( sc::evt::Registry& registry )
{
}


void
sc::gra::RocketGraphics::draw() const
{
  phi::Coordinate heading( phi::CoordFromPolar( m_physicalModel->heading(), 10.0 ) );
  m_graphicalEngine.drawPoint( m_physicalModel->coordinate(), 1, 0xff0000 );
}

