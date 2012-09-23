#include <sc/phi/Launcher.hpp>
#include <sc/phi/Accessory.hpp>
#include <sc/phi/ObjectFactory.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Model.hpp>
#include <sc/phi/EventSlots.hpp>
#include <sc/evt/BaseTypes.hpp>

namespace
{
  const int COOLDOWN( 30 );
}

sc::phi::Launcher::Launcher( ObjectFactory& objectFactory )
  : Accessory()
  , m_objectFactory( objectFactory )
  , m_coolDown( 0 )
{
}


sc::phi::Launcher::~Launcher()
{
}


void
sc::phi::Launcher::fire( sc::evt::Event& )
{
  if ( m_coolDown > 0 )
  {
    return;
  }

  m_coolDown = COOLDOWN;

  m_objectFactory.createRocket(
      { m_physicalModel->coordinate() + CoordFromPolar( m_physicalModel->heading(), 30.0 ),
        m_physicalModel->speed(),
        m_physicalModel->heading(),
        1 } );
}


void
sc::phi::Launcher::timer( sc::evt::Event& )
{
  if ( m_coolDown > 0 )
  {
    --m_coolDown;
  }
}


void
sc::phi::Launcher::subscribe( sc::evt::Registry& registry )
{
  registerMemberFunction( registry, &Launcher::fire, slot::FIRE );
  registerMemberFunction( registry, &Launcher::timer, slot::TIMEELAPSED );
}

