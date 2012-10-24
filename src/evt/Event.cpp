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
#include <sc/evt/Event.hpp>
#include <algorithm>

void
sc::evt::Event::notifySlot( Registry& registry, const SlotId& slot )
{
  for ( auto& callback : registry[ slot ] )
  {
    callback( *this );
  }
}


sc::evt::Event::~Event()
{
}


sc::evt::BinaryEvent::BinaryEvent( const SlotId& slot )
  : Event()
  , m_slots( 1, slot )
{
}


void
sc::evt::BinaryEvent::addSlot( const SlotId& slot )
{
  m_slots.push_back( slot );
}


void
sc::evt::BinaryEvent::handle( Registry& registry )
{
  for ( auto& slot : m_slots )
  {
    notifySlot( registry, slot );
  }
}


sc::evt::BinaryEvent::~BinaryEvent()
{
}

