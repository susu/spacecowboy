/*
 * spacecowboy - a 2D space adventure game
 *
 *  Copyright 2012, Peter Ferenc Hajdu.
 *  All rights reserved.
 *
 * This file is part of .
 *
 * spacecowboy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * spacecowboy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with spacecowboy. If not, see
 * <http://www.gnu.org/licenses/>.
 */
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

