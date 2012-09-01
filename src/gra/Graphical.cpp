#include <sc/gra/Graphical.hpp>
#include <sc/gra/Engine.hpp>

sc::gra::Graphical::Graphical( Engine& graphicalEngine )
  : m_graphicalEngine( graphicalEngine )
{
  m_graphicalEngine.addObject( this );
}


sc::gra::Graphical::~Graphical()
{
  m_graphicalEngine.removeObject( this );
}

