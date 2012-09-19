#pragma once

#include <memory>
#include <vector>

namespace sc
{
  namespace utl
  {

    template < typename T, size_t number >
    class MemoryPool
    {
      public:
        MemoryPool()
          : m_chunk( ::operator new( number * sizeof( T ) ) )
          , m_freeSlots()
        {
          for ( unsigned int i( 0 ); i < number; ++i )
          {
            release( ( T* )( m_chunk.get() ) + i );
          }
        }


        ~MemoryPool()
        {
        }


        MemoryPool( const MemoryPool& ) = delete;
        MemoryPool& operator=( const MemoryPool& ) = delete;


        void * allocate( size_t sizeOfObject )
        {
          if ( sizeof( T ) != sizeOfObject ||
              m_freeSlots.empty() )
          {
            throw std::bad_alloc();
          }

          void * freeSlot( m_freeSlots.back() );
          m_freeSlots.pop_back();
          return freeSlot;
        }


        void release( void * toRelease )
        {
          m_freeSlots.push_back( toRelease );
        }

      private:
        std::unique_ptr< void > m_chunk;
        std::vector< void * > m_freeSlots;
    };

  }
}

