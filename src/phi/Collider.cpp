#include <sc/phi/Collider.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/CollisionEvent.hpp>
#include <sc/phi/ExplosionEvent.hpp>
#include <sc/phi/Object.hpp>
#include <sc/evt/BaseTypes.hpp>

#include <functional>

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

  evt::BinaryEvent damage( slot::COLLISION_DAMAGE );
  m_owningObject->dispatchEvent( damage );
}


sc::phi::Coordinate
sc::phi::Collider::calculateCollisionForce( CollisionEvent& event ) const
{
  Coordinate distanceVector( event.otherCoord() - m_physicalModel->coordinate() );
  Coordinate v2( project( event.otherSpeed(), distanceVector ) );
  Coordinate v1( project( m_physicalModel->speed(), distanceVector ) );

  double m1( static_cast<double>( m_physicalModel->mass() ) );
  double m2( static_cast<double>( event.otherMass() ) );
  Coordinate newSpeed(
      v1 * ( ( m1 - m2 ) / ( m1 + m2 ) ) +
      v2 * ( ( 2 * m2 ) / ( m1 + m2 ) ) );

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

  m_physicalModel->push( ( m_physicalModel->coordinate() - explosion.model().coordinate() ) * 100.0 );

  evt::BinaryEvent damage( slot::EXPLOSION_DAMAGE );
  m_owningObject->dispatchEvent( damage );
}


void
sc::phi::Collider::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &Collider::collision, slot::COLLISION );
  registerMemberFunction( registry, &Collider::explosion, slot::EXPLOSION );
}

