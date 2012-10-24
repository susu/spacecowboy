/*
 * spacecowboy - a 2D space adventure game
 *
 *  Copyright 2012, Peter Ferenc Hajdu.
 *  All rights reserved.
 *
 * This file is part of .
 *
 * spacecowboy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * spacecowboy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with spacecowboy. If not, see
 * <http://www.gnu.org/licenses/>.
 */
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
  phi::AccessoryRef engine( new Engine( 5.0, 0.5 ) );
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
  phi::AccessoryRef engine( new Engine( 5.0, 0.5 ) );
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

