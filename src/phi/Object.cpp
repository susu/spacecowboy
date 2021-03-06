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
#include <sc/phi/Object.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/CollisionEvent.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/evt/Hub.hpp>

#include <cmath>

sc::phi::Object::Object( Sector& sector )
  : Object(
      sector,
      ObjectProperties( Coordinate( 100.0, 100.0 ), Coordinate( 0.0, 0.0 ), 0.0, 10, 1 ) )
{
}


sc::phi::Object::Object( Sector& sector, const ObjectProperties& properties )
  : evt::Hub()
  , m_physicalModel( properties.coordinate
                    ,properties.speed
                    ,properties.heading
                    ,0.0
                    ,properties.radius
                    ,properties.mass )
  , m_sector( sector )
  , m_accessories()
  , m_deleted( false )
{
}


sc::phi::Object::~Object()
{
}


void
sc::phi::Object::timeElapsed( const Ratio& stepRatio )
{
  m_physicalModel.timeElapse( stepRatio );
  timerUpdate( stepRatio );
}


bool
sc::phi::Object::isColliding() const
{
  return hasHandlerFor( slot::COLLISION );
}


void
sc::phi::Object::checkCollision( const ObjectContainer& collection )
{
  for ( auto& i : collection )
  {
    if ( i.get() == this )
    {
      continue;
    }

    if ( collides( m_physicalModel, i->m_physicalModel ) )
    {
      CollisionEvent collision( i, i->m_physicalModel );
      dispatchEvent( collision );
    }
  }
}


void
sc::phi::Object::addAccessory( AccessoryRef& accessory )
{
  accessory->initialize( *this, m_physicalModel, m_sector );
  add( *accessory );
  m_accessories.push_back( std::move( accessory ) );
}


void
sc::phi::Object::deleteObject()
{
  m_deleted = true;
}


bool
sc::phi::Object::isDeleted() const
{
  return m_deleted;
}

