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
#include <sc/phi/RocketAi.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/Event.hpp>


namespace
{
  unsigned int LIFETIME( 100 );
  unsigned int EXPLOSION_RADIUS( 50 );
}

sc::phi::RocketAi::RocketAi( Object* rocket, ObjectFactory& objectFactory )
  : Accessory()
  , m_rocket( rocket )
  , m_objectFactory( objectFactory )
  , m_ttl( LIFETIME )
{
}


sc::phi::RocketAi::~RocketAi()
{
}


void
sc::phi::RocketAi::timer( sc::evt::Event& )
{
  if ( 0 == --m_ttl )
  {
    explode();
    return;
  }

  sc::evt::BinaryEvent gas( slot::BACKTHRUSTER );
  m_rocket->dispatchEvent( gas );
}


void
sc::phi::RocketAi::collision( sc::evt::Event& )
{
  if ( m_rocket->isDeleted() )
  {
    return;
  }
  explode();
}


void
sc::phi::RocketAi::explode()
{
  m_objectFactory.createExplosion( {
      m_physicalModel->coordinate(),
      m_physicalModel->speed(),
      0.0,
      EXPLOSION_RADIUS,
      1 } );
  m_rocket->deleteObject();
}


void
sc::phi::RocketAi::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &RocketAi::timer, slot::TIMEELAPSED );
  registerMemberFunction( registry, &RocketAi::collision, slot::COLLISION );
}

