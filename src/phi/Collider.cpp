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
#include <sc/phi/Collider.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/CollisionEvent.hpp>
#include <sc/phi/ExplosionEvent.hpp>
#include <sc/phi/Object.hpp>
#include <sc/evt/BaseTypes.hpp>

#include <functional>


namespace
{
  const double ELASTIC_COLLISION_CONSTANT( 0.5 );
}


sc::phi::Collider::Collider()
  : Accessory()
{
}


sc::phi::Collider::~Collider()
{
}


void
sc::phi::Collider::collision( sc::evt::Event& event )
{
  CollisionEvent& collisionEvent( dynamic_cast<CollisionEvent&>( event ) );
  m_physicalModel->push( calculateCollisionForce( collisionEvent ) );

  //TODO: add collision force dependent damage
  evt::BinaryEvent damage( slot::COLLISION_DAMAGE );
  m_owningObject->dispatchEvent( damage );
}


sc::phi::Coordinate
sc::phi::Collider::calculateCollisionForce( CollisionEvent& event ) const
{
  Coordinate distanceVector( event.otherCoord() - m_physicalModel->coordinate() );
  Coordinate v2( project( event.otherSpeed(), distanceVector ) );
  Coordinate v1( project( m_physicalModel->speed(), distanceVector ) );

  //TODO: this is a nasty workaround for collision system problems
  //TODO: reimplementation of collision needed
  if ( length( distanceVector + v1 ) < length( distanceVector ) )
  {
    return { 0.0, 0.0 };
  }

  double m1( static_cast<double>( m_physicalModel->mass() ) );
  double m2( static_cast<double>( event.otherMass() ) );
  Coordinate newSpeed(
      v1 * ( ( m1 - m2 ) / ( m1 + m2 ) ) +
      v2 * ( ( 2 * m2 ) / ( m1 + m2 ) ) );
  newSpeed *= ELASTIC_COLLISION_CONSTANT;

  return ( newSpeed - v1 ) * m1;
}


void
sc::phi::Collider::explosion( sc::evt::Event& event )
{
  ExplosionEvent& explosion( dynamic_cast<ExplosionEvent&>( event ) );
  if ( !collides( explosion.model(), *m_physicalModel ) )
  {
    return;
  }

  m_physicalModel->push( ( m_physicalModel->coordinate() - explosion.model().coordinate() ) * 50.0 );

  evt::BinaryEvent damage( slot::EXPLOSION_DAMAGE );
  m_owningObject->dispatchEvent( damage );
}


void
sc::phi::Collider::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &Collider::collision, slot::COLLISION );
  registerMemberFunction( registry, &Collider::explosion, slot::EXPLOSION );
}

