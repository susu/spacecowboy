#include <sc/phi/Collider.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/CollisionEvent.hpp>
#include <sc/evt/BaseTypes.hpp>

#include <functional>

sc::phi::Collider::Collider( Model& physicalModel )
: m_physicalModel( physicalModel )
{
}


sc::phi::Collider::~Collider()
{
}


void
sc::phi::Collider::collision( sc::evt::Event& event )
{
  CollisionEvent& collisionEvent( dynamic_cast<CollisionEvent&>( event ) );
  m_physicalModel.push( calculateCollisionForce( collisionEvent ) );
}


sc::phi::Coordinate
sc::phi::Collider::calculateCollisionForce( CollisionEvent& event ) const
{
  Coordinate distanceVector(
      m_physicalModel.coordinate() * -1.0 +
      event.otherCoord() );

  return ( project( event.otherSpeed(), distanceVector ) * -1.0 +
         project( m_physicalModel.speed(), distanceVector ) ) * -1.0;
}

void
sc::phi::Collider::subscribe( sc::evt::Registry& registry )
{
  std::function< void( Collider*, sc::evt::Event& ) > fun ( &Collider::collision );
  sc::evt::Callback callback( std::bind( fun, this, std::placeholders::_1 ) );
  registry[ slot::COLLISION ].push_back( callback );
}

