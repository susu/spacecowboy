#include <cxxtest/TestSuite.h>

#include "TestGraphical.hpp"

class GraphicalEngineTest : public CxxTest::TestSuite
{
  public:
    void test_graphical_objects_should_register_and_deregister_themselves_to_graphicalengine()
    {
      test::GraphicalEngine graphicalEngine;
      {
        test::GraphicalObject graphicalObject( graphicalEngine );
        graphicalObject.assertDrawCalled( false );
        graphicalEngine.updateScreen();
        graphicalObject.assertDrawCalled( true );
      }
      graphicalEngine.updateScreen();

    }
};

