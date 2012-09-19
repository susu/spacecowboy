#include <cxxtest/TestSuite.h>

#include "sc/utl/MemoryPool.hpp"

namespace test
{
  class DummyClass;
}

namespace
{
  const unsigned int POOL_CAPACITY( 2 );
  sc::utl::MemoryPool< test::DummyClass, POOL_CAPACITY > memoryPool;
}


namespace test
{
  class DummyClass
  {
    public:
      void * operator new( size_t size )
      {
        return memoryPool.allocate( size );
      }

      void operator delete( void * ptr )
      {
        memoryPool.release( ptr );
      }
  };
}


class MemoryPoolTest : public CxxTest::TestSuite
{
  public:
    void test_pool_should_throw_exception_only_if_capacity_is_exceeded()
    {
      test::DummyClass* pointer( new test::DummyClass() );
      TS_ASSERT( pointer );
      TS_ASSERT( new test::DummyClass() );
      TS_ASSERT_THROWS( new test::DummyClass(), std::bad_alloc );

      delete pointer;
      TS_ASSERT( new test::DummyClass() );
    }

};

