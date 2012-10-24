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
#include <sc/evt/BaseTypes.hpp>
#include <sc/evt/Hub.hpp>
#include <sc/evt/Handler.hpp>
#include <sc/evt/Event.hpp>

sc::evt::Hub::Hub()
  : m_registry()
{
}


sc::evt::Hub::~Hub()
{
}

void
sc::evt::Hub::dispatchEvent( Event& event )
{
  event.handle( m_registry );
}


void
sc::evt::Hub::add( Handler& handler )
{
  handler.subscribe( m_registry );
}


bool
sc::evt::Hub::hasHandlerFor( SlotId slot ) const
{
  Registry::const_iterator it( m_registry.find( slot ) );
  return it!=m_registry.end() && !it->second.empty();
}

