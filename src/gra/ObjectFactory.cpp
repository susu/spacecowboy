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
#include <sc/gra/ObjectFactory.hpp>
#include <sc/gra/EngineGraphics.hpp>
#include <sc/gra/ShipGraphics.hpp>
#include <sc/gra/RocketGraphics.hpp>
#include <sc/gra/ExplosionGraphics.hpp>
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
  phi::ObjectRef object( PhysicalObjectFactory::createShip( properties ) );

  sc::phi::AccessoryRef shipGraphics( new sc::gra::ShipGraphics( m_graphicalEngine ) );
  object->addAccessory( shipGraphics );

  sc::phi::AccessoryRef engineGraphics( new sc::gra::EngineGraphics( m_sector, m_graphicalEngine, 10, 5 ) );
  object->addAccessory( engineGraphics );

  return object;
}


sc::phi::ObjectRef
sc::gra::ObjectFactory::createRocket( const sc::phi::ObjectProperties& properties )
{
  phi::ObjectRef object( PhysicalObjectFactory::createRocket( properties ) );

  sc::phi::AccessoryRef rocketGraphics( new sc::gra::RocketGraphics( m_graphicalEngine ) );
  object->addAccessory( rocketGraphics );

  sc::phi::AccessoryRef engineGraphics( new sc::gra::EngineGraphics( m_sector, m_graphicalEngine, 1, 1 ) );
  object->addAccessory( engineGraphics );

  return object;
}


sc::phi::ObjectRef
sc::gra::ObjectFactory::createExplosion( const sc::phi::ObjectProperties& properties )
{
  phi::ObjectRef object( PhysicalObjectFactory::createExplosion( properties ) );

  sc::phi::AccessoryRef explosionGraphics( new sc::gra::ExplosionGraphics( m_sector, m_graphicalEngine ) );
  object->addAccessory( explosionGraphics );

  return object;
}


sc::gra::ObjectFactory::~ObjectFactory()
{
}

