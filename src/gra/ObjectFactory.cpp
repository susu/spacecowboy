#include <sc/gra/ObjectFactory.hpp>
#include <sc/gra/EngineGraphics.hpp>
#include <sc/gra/ShipGraphics.hpp>
#include <sc/gra/RocketGraphics.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/phi/Object.hpp>

sc::gra::ObjectFactory::ObjectFactory( phi::Sector& sector, Engine& graphicalEngine )
  : phi::PhysicalObjectFactory( sector )
  , m_graphicalEngine( graphicalEngine )
{
}


sc::phi::ObjectRef
sc::gra::ObjectFactory::createShip( const sc::phi::ObjectProperties& properties )
{
  phi::ObjectRef object( createWithColliderAndEngine( properties ) );

  sc::phi::AccessoryRef shipGraphics( new sc::gra::ShipGraphics( m_graphicalEngine ) );
  object->addAccessory( shipGraphics );

  sc::phi::AccessoryRef engineGraphics( new sc::gra::EngineGraphics( m_sector, m_graphicalEngine, 10 ) );
  object->addAccessory( engineGraphics );

  return object;
}


sc::phi::ObjectRef
sc::gra::ObjectFactory::createRocket( const sc::phi::ObjectProperties& properties )
{
  phi::ObjectRef object( PhysicalObjectFactory::createRocket( properties ) );

  sc::phi::AccessoryRef rocketGraphics( new sc::gra::RocketGraphics( m_graphicalEngine ) );
  object->addAccessory( rocketGraphics );

  sc::phi::AccessoryRef engineGraphics( new sc::gra::EngineGraphics( m_sector, m_graphicalEngine, 10 ) );
  object->addAccessory( engineGraphics );

  return object;
}


sc::gra::ObjectFactory::~ObjectFactory()
{
}
