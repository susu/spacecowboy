#include <sc/phi/PhysicalObjectFactory.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/EngineBase.hpp>
#include <sc/phi/Collider.hpp>
#include <sc/phi/RocketAi.hpp>
#include <sc/phi/ExplosionBehaviour.hpp>
#include <sc/phi/Launcher.hpp>
#include <sc/phi/ShipStructure.hpp>

sc::phi::PhysicalObjectFactory::PhysicalObjectFactory( Sector& sector )
  : ObjectFactory( sector )
{
}


sc::phi::PhysicalObjectFactory::~PhysicalObjectFactory()
{
}


sc::phi::ObjectRef
sc::phi::PhysicalObjectFactory::createWithColliderAndEngine( const ObjectProperties& properties )
{
  phi::ObjectRef object( createBasicObject( properties ) );
  phi::AccessoryRef engine( new Engine( 0.5, 0.05 ) );
  object->addAccessory( engine );

  AccessoryRef collider( new Collider() );
  object->addAccessory( collider );

  AccessoryRef launcher( new Launcher( *this ) );
  object->addAccessory( launcher );

  m_sector.addObject( object );

  return object;
}


sc::phi::ObjectRef
sc::phi::PhysicalObjectFactory::createShip( const ObjectProperties& properties )
{
  ObjectRef object( createWithColliderAndEngine( properties ) );

  AccessoryRef structure( new ShipStructure() );
  object->addAccessory( structure );

  return object;
}


sc::phi::ObjectRef
sc::phi::PhysicalObjectFactory::createRocket( const ObjectProperties& properties )
{
  phi::ObjectRef object( createBasicObject( properties ) );
  phi::AccessoryRef engine( new Engine( 1.5, 0.15 ) );
  object->addAccessory( engine );

  AccessoryRef collider( new Collider() );
  object->addAccessory( collider );

  AccessoryRef ai( new RocketAi( object.get(), *this ) );
  object->addAccessory( ai );

  m_sector.addObject( object );

  return object;
}


sc::phi::ObjectRef
sc::phi::PhysicalObjectFactory::createExplosion( const ObjectProperties& properties )
{
  ObjectRef explosion(createWithoutCollider( properties ) );

  AccessoryRef behaviour( new ExplosionBehaviour( m_sector, explosion.get() ) );
  explosion->addAccessory( behaviour );

  return explosion;
}


sc::phi::ObjectRef
sc::phi::PhysicalObjectFactory::createWithoutCollider( const ObjectProperties& properties )
{
  phi::ObjectRef object( createBasicObject( properties ) );
  m_sector.addObject( object );
  return object;
}


sc::phi::ObjectRef
sc::phi::PhysicalObjectFactory::createBasicObject( const ObjectProperties& properties )
{
  return ObjectRef( std::make_shared<Object>( m_sector, properties ) );
}

