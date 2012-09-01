#pragma once

namespace sc
{
  namespace gra
  {
    class Engine;

    class Graphical
    {
      public:
        Graphical( Engine& graphicalEngine );
        virtual void draw() const = 0;
        virtual ~Graphical();

      protected:
        Engine& m_graphicalEngine;
    };
  }
}

