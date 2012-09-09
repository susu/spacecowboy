#include <sc/phi/RocketAi.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/Object.hpp>
#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/Event.hpp>

#include <cassert>

sc::phi::RocketAi::RocketAi( Object* rocket, ObjectFactory& objectFactory )
  : Accessory()
  , m_rocket( rocket )
  , m_objectFactory( objectFactory )
{
}


sc::phi::RocketAi::~RocketAi()
{
}


void
sc::phi::RocketAi::timer( sc::evt::Event& event )
{
  sc::evt::BinaryEvent gas( slot::BACKTHRUSTER );
  m_rocket->dispatchEvent( gas );
}


void
sc::phi::RocketAi::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &RocketAi::timer, slot::TIMEELAPSED );
}

