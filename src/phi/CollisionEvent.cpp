#include <sc/phi/CollisionEvent.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/phi/Model.hpp>
#include <sc/evt/Event.hpp>

sc::phi::CollisionEvent::CollisionEvent( const ObjectRef& collidingObject, Model& physicalModel )
  : sc::evt::Event()
  , m_collidingObject( collidingObject )
  , m_modelOfCollider( physicalModel )
{
}

void
sc::phi::CollisionEvent::handle( sc::evt::Registry& registry )
{
  notifySlot( registry, slot::COLLISION );
}


sc::phi::Coordinate
sc::phi::CollisionEvent::otherSpeed() const
{
  return m_modelOfCollider.speed();
}


sc::phi::Coordinate
sc::phi::CollisionEvent::otherCoord() const
{
  return m_modelOfCollider.coordinate();
}


unsigned int
sc::phi::CollisionEvent::otherMass() const
{
  return m_modelOfCollider.mass();
}

