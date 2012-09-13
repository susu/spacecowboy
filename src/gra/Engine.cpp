#include <sc/gra/Engine.hpp>
#include <sc/gra/Graphical.hpp>
#include <vector>
#include <algorithm>

sc::gra::Engine::Engine( unsigned int xRes, unsigned int yRes )
  : m_objectContainer()
  , m_focus( xRes, yRes )
{
}


sc::gra::Engine::~Engine()
{
}


void
sc::gra::Engine::drawObjects()
{
  for ( const auto& object : m_objectContainer )
  {
    object->draw();
  }
  m_focus.updateFocus();
}


void
sc::gra::Engine::addObject( const Graphical* object )
{
  m_objectContainer.push_back( object );
}


void
sc::gra::Engine::removeObject( const Graphical* object )
{
  auto newEnd( std::remove( m_objectContainer.begin(), m_objectContainer.end(), object ) );
  m_objectContainer.erase( newEnd, m_objectContainer.end() );
}

