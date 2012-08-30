#include <cxxtest/TestSuite.h>

#include "sc/evt/Hub.hpp"
#include "sc/evt/Handler.hpp"
#include "sc/evt/Event.hpp"
#include "sc/evt/BaseTypes.hpp"

class DummyHandler : public sc::evt::Handler
{
  public:
    DummyHandler( const sc::evt::SlotId& slot )
      : sc::evt::Handler()
      , m_called( false )
      , m_slot( slot )
    {
    }

    void handleEvent( const sc::evt::Event& event )
    {
      m_called = true;
    }

    void subscribe( sc::evt::Registry& registry )
    {
      std::function< void( DummyHandler*, const sc::evt::Event& ) > fun1(
          &DummyHandler::handleEvent
          );

      sc::evt::Callback callback(
          std::bind( fun1, this, std::placeholders::_1 )
          );

      registry[ m_slot ].push_back( callback );
    }

    bool isCalled() const
    {
      return m_called;
    }

    void reset()
    {
      m_called = false;
    }

  private:
    bool m_called;
    sc::evt::SlotId m_slot;
};


class HubTest : public CxxTest::TestSuite
{
  private:
    DummyHandler m_handler_1 = 1;
    DummyHandler m_handler_2 = 2;

    void setUp()
    {
      m_handler_1.reset();
      m_handler_2.reset();
    }

  public:
    void test_more_handlers_should_be_notified_for_the_same_slot()
    {
      sc::evt::Hub hub;
      DummyHandler handler( 1 );
      hub.add( handler );
      hub.add( m_handler_1 );

      sc::evt::BinaryEvent event( 1 );

      hub.dispatchEvent( event );
      TS_ASSERT( handler.isCalled() );
      TS_ASSERT( m_handler_1.isCalled() );
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

      TS_ASSERT( m_handler_1.isCalled() );
      TS_ASSERT( m_handler_2.isCalled() );
    }
};

