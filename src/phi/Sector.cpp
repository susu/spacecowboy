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
#include <sc/phi/Sector.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Timer.hpp>
#include <sc/evt/Event.hpp>

#include <algorithm>

namespace
{

  void updateTimeForEachAndRemoveDeleted(
      sc::phi::ObjectContainer& collection,
      const sc::phi::Ratio& ratio )
  {
    sc::evt::BinaryEvent event( sc::phi::slot::TIMEELAPSED );
    for ( sc::phi::ObjectContainer::iterator i( collection.begin() ); i!=collection.end(); )
    {
      sc::phi::Object& object( **i );
      if ( object.isDeleted() )
      {
        i = collection.erase( i );
        continue;
      }

      object.timeElapsed( ratio );
      object.dispatchEvent( event );
      ++i;
    }
  }


  void checkCollisionForEach( const sc::phi::ObjectContainer& collection )
  {
    for ( auto& i : collection )
    {
      i->checkCollision( collection );
    }
  }


  void pourNewObjects( std::vector<sc::phi::ObjectRef>& from, sc::phi::ObjectContainer& to )
  {
    to.insert( to.end(), from.begin(), from.end() );
    from.clear();
  }

}

  sc::phi::Sector::Sector()
  : m_nonColliders()
  , m_colliders()
  , m_newColliders()
  , m_newNonColliders()
  , m_timer()
{
}


void
sc::phi::Sector::addObject( const ObjectRef& object )
{
  object->isColliding() ?
    m_newColliders.push_back( object ) :
    m_newNonColliders.push_back( object );
}


void
sc::phi::Sector::tick()
{
  pourNewObjects( m_newColliders, m_colliders );
  pourNewObjects( m_newNonColliders, m_nonColliders );

  checkCollisionForEach( m_colliders );
  Ratio timeFrameRatio( m_timer.timeFrameRatio() );

  updateTimeForEachAndRemoveDeleted( m_nonColliders, timeFrameRatio );
  updateTimeForEachAndRemoveDeleted( m_colliders, timeFrameRatio );
}


const sc::phi::ObjectContainer&
sc::phi::Sector::colliders() const
{
  return m_colliders;
}

