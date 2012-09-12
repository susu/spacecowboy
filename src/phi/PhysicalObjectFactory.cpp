#include <sc/phi/PhysicalObjectFactory.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/EngineBase.hpp>
#include <sc/phi/Collider.hpp>
#include <sc/phi/RocketAi.hpp>
#include <sc/phi/ExplosionBehaviour.hpp>
#include <sc/phi/Launcher.hpp>

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
  phi::AccessoryRef engine( new sc::phi::Engine( 0.5, 0.05 ) );
  object->addAccessory( engine );

  sc::phi::AccessoryRef collider( new sc::phi::Collider() );
  object->addAccessory( collider );

  sc::phi::AccessoryRef launcher( new sc::phi::Launcher( *this ) );
  object->addAccessory( launcher );

  m_sector.addObject( object );

  return object;
}


sc::phi::ObjectRef
sc::phi::PhysicalObjectFactory::createShip( const ObjectProperties& properties )
{
  phi::ObjectRef object( createWithColliderAndEngine( properties ) );

  return object;
}


sc::phi::ObjectRef
sc::phi::PhysicalObjectFactory::createRocket( const ObjectProperties& properties )
{
  phi::ObjectRef object( createWithColliderAndEngine( properties ) );

  sc::phi::AccessoryRef ai( new sc::phi::RocketAi( object.get(), *this ) );
  object->addAccessory( ai );

  return object;
}


sc::phi::ObjectRef
sc::phi::PhysicalObjectFactory::createExplosion( const ObjectProperties& properties )
{
  ObjectRef explosion(createWithoutCollider( properties ) );

  sc::phi::AccessoryRef behaviour( new sc::phi::ExplosionBehaviour( m_sector, explosion.get() ) );
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
  return sc::phi::ObjectRef( new Object( m_sector, properties ) );
}

