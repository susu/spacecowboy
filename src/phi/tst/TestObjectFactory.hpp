#pragma once

#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/PhysicalObjectFactory.hpp>
#include <sc/phi/EngineBase.hpp>
#include <sc/phi/Collider.hpp>

#include "TestObject.hpp"

namespace test
{

  class TestObjectFactory : public sc::phi::PhysicalObjectFactory
  {
    public:
      TestObjectFactory( sc::phi::Sector& sector )
        : sc::phi::PhysicalObjectFactory( sector )
      {
      }

      test::TestObject* createTestShip( const sc::phi::ObjectProperties& prop )
      {
        sc::phi::ObjectRef ship( createShip( prop ) );
        return dynamic_cast< test::TestObject* >( ship.get() );
      }

      test::TestObject* createTestRocket( const sc::phi::ObjectProperties& prop )
      {
        sc::phi::ObjectRef rocket( createRocket( prop ) );
        return dynamic_cast< test::TestObject* >( rocket.get() );
      }

      sc::phi::ObjectRef createRocket( const sc::phi::ObjectProperties& prop )
      {
        m_rocketCreated = true;
        return sc::phi::PhysicalObjectFactory::createRocket( prop );
      }

      void assertRocketCreated_ResetFlag( bool created )
      {
        TS_ASSERT( created ? m_rocketCreated : !m_rocketCreated  );
        m_rocketCreated = false;
      }

    protected:
      virtual sc::phi::ObjectRef createBasicObject( const sc::phi::ObjectProperties& prop )
      {
        return sc::phi::ObjectRef( new test::TestObject( m_sector, prop ) );
      }

    private:
      bool m_rocketCreated = false;

  };
}

