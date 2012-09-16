#include <sc/phi/RocketAi.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/Event.hpp>

sc::phi::RocketAi::RocketAi( Object* rocket, ObjectFactory& objectFactory )
  : Accessory()
  , m_rocket( rocket )
  , m_objectFactory( objectFactory )
  , m_ttl( 100 )
{
}


sc::phi::RocketAi::~RocketAi()
{
}


void
sc::phi::RocketAi::timer( sc::evt::Event& event )
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
sc::phi::RocketAi::collision( sc::evt::Event& event )
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
      50 } );
  m_rocket->deleteObject();
}


void
sc::phi::RocketAi::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &RocketAi::timer, slot::TIMEELAPSED );
  registerMemberFunction( registry, &RocketAi::collision, slot::COLLISION );
}

