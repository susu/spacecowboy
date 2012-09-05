#include <cxxtest/TestSuite.h>

#include "TestHandler.hpp"
#include "sc/evt/Hub.hpp"

class HubTest : public CxxTest::TestSuite
{
  private:
    test::TestHandler m_handler_1 = 1;
    test::TestHandler m_handler_2 = 2;

    void setUp()
    {
      m_handler_1.reset();
      m_handler_2.reset();
    }

  public:
    void test_more_handlers_should_be_notified_for_the_same_slot_but_not_for_others()
    {
      sc::evt::Hub hub;
      test::TestHandler handler( 1 );
      hub.add( handler );
      hub.add( m_handler_1 );
      hub.add( m_handler_2 );

      sc::evt::BinaryEvent event( 1 );

      hub.dispatchEvent( event );
      handler.assertHandlerNotified( true );
      m_handler_1.assertHandlerNotified( true );
      m_handler_2.assertHandlerNotified( false );
    }


    void test_dispatch_should_not_fail_if_no_handler_registered_for_the_slot()
    {
      sc::evt::Hub hub;
      sc::evt::BinaryEvent event( 2 );
      hub.dispatchEvent( event );
    }


    void test_more_slots_should_be_notified_by_binary_event()
    {
      sc::evt::Hub hub;
      hub.add( m_handler_1 );
      hub.add( m_handler_2 );

      sc::evt::BinaryEvent event( 1 );
      event.addSlot( 2 );
      hub.dispatchEvent( event );

      m_handler_1.assertHandlerNotified( true );
      m_handler_2.assertHandlerNotified( true );
    }


    void test_hasHandlersFor()
    {
      sc::evt::Hub hub;
      hub.add( m_handler_1 );

      TS_ASSERT( hub.hasHandlerFor( 1 ) );
      TS_ASSERT( !hub.hasHandlerFor( 2 ) );
    }

};

