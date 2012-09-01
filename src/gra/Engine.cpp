#include <sc/gra/Engine.hpp>
#include <sc/gra/Graphical.hpp>
#include <vector>
#include <algorithm>

sc::gra::Engine::Engine()
  : m_objectContainer()
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

