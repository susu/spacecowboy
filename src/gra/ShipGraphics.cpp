#include <sc/gra/ShipGraphics.hpp>
#include <sc/gra/Graphical.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/IntegrityChangeEvent.hpp>

sc::gra::ShipGraphics::ShipGraphics( sc::gra::Engine& graphicalEngine )
  : phi::Accessory()
  , Graphical( graphicalEngine )
  , m_integrity( 100 )
{
}


sc::gra::ShipGraphics::~ShipGraphics()
{
}


void
sc::gra::ShipGraphics::shipIntegrityChanged( sc::evt::Event& event )
{
  sc::phi::IntegrityChanged integrityChanged(
      dynamic_cast< sc::phi::IntegrityChanged& >( event ) );
  m_integrity = integrityChanged.integrity();
}


void
sc::gra::ShipGraphics::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction(
      registry,
      &ShipGraphics::shipIntegrityChanged,
      sc::phi::slot::OBJECT_INTEGRITY_CHANGED );
}


void
sc::gra::ShipGraphics::draw() const
{
  phi::Coordinate heading( phi::CoordFromPolar( m_physicalModel->heading(), 10.0 ) );
  m_graphicalEngine.drawShip( m_physicalModel->coordinate(), heading, m_integrity );
}

