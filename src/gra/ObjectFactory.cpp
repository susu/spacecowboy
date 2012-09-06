#include <sc/gra/ObjectFactory.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/gra/EngineGraphics.hpp>
#include <sc/gra/ShipGraphics.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/EngineBase.hpp>
#include <sc/phi/Collider.hpp>

sc::gra::ObjectFactory::ObjectFactory( phi::Sector& sector, Engine& graphicalEngine )
  : phi::ObjectFactory( sector )
  , m_graphicalEngine( graphicalEngine )
{
}


sc::phi::ObjectRef
sc::gra::ObjectFactory::createShip(
    const sc::phi::Coordinate& coord,
    const sc::phi::Coordinate& speed )
{
  phi::ObjectRef object( new phi::Object( m_sector, coord, speed ) );
  phi::AccessoryRef engine( new sc::phi::Engine( 0.5, 0.05 ) );
  object->addAccessory( engine );

  sc::phi::AccessoryRef collider( new sc::phi::Collider() );
  object->addAccessory( collider );

  sc::phi::AccessoryRef shipGraphics( new sc::gra::ShipGraphics( m_graphicalEngine ) );
  object->addAccessory( shipGraphics );

  sc::phi::AccessoryRef engineGraphics( new sc::gra::EngineGraphics( m_sector, m_graphicalEngine, 10 ) );
  object->addAccessory( engineGraphics );

  m_sector.addObject( object );

  return object;
}


sc::gra::ObjectFactory::~ObjectFactory()
{
}

