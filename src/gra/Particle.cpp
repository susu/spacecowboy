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
#include <sc/phi/Object.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/phi/Sector.hpp>
#include <sc/gra/Graphical.hpp>
#include <sc/gra/Engine.hpp>
#include <sc/gra/Particle.hpp>
#include <sc/utl/MemoryPool.hpp>

#include <vector>
#include <cstdlib>

namespace
{
  const std::vector< unsigned int > blackBody = {
    0xff5200,
    0xff6500,
    0xff7c00,
    0xff8300,
    0xff9829,
    0xff9d3f,
    0xffae54,
    0xffb165,
    0xffc076,
    0xffc184,
    0xffce92,
    0xffce9f,
    0xffd9ab,
    0xffd9b6,
    0xffe2c0,
    0xffe3ca,
    0xffead3,
    0xffebdc,
    0xfff0e4,
    0xfff2ec,
    0xfff6f3,
    0xfff8fb,
    0xfefaff,
    0xf7f5ff,
    0xf3f3ff,
    0xedefff,
    0xeaedff,
    0xe4eaff,
    0xe3e8ff,
    0xdde6ff,
    0xdce3ff,
    0xd7e2ff,
    0xd7dfff,
    0xd1dfff,
    0xd2dcff,
    0xcddcff,
    0xced9ff,
    0xc9d9ff,
    0xcad7ff,
    0xc5d7ff,
    0xc7d4ff,
    0xc2d5ff,
    0xc4d2ff,
    0xbfd3ff,
    0xc2d0ff,
    0xbdd2ff,
    0xbfcfff,
    0xbad0ff,
    0xbdcdff,
    0xb8cfff,
    0xbbccff,
    0xb6ceff,
    0xbacbff,
    0xb5cdff,
    0xb8c9ff,
    0xb3ccff,
    0xb7c8ff,
    0xb2cbff,
    0xb5c7ff,
    0xb0caff,
    0xb4c6ff,
    0xafc9ff,
    0xb3c6ff,
    0xaec8ff,
    0xb2c5ff,
    0xadc8ff,
    0xb1c4ff,
    0xacc7ff,
    0xb0c3ff,
    0xabc6ff,
    0xafc3ff,
    0xaac6ff,
    0xaec2ff,
    0xa9c5ff,
    0xaec1ff,
    0xa8c5ff,
    0xadc1ff,
    0xa8c4ff,
    0xacc0ff,
    0xa7c4ff,
    0xacc0ff,
    0xa6c3ff,
    0xabbfff,
    0xa6c3ff,
    0xabbfff,
    0xa5c3ff,
    0xaabfff,
    0xa5c2ff,
    0xaabeff,
    0xa4c2ff,
    0xa9beff,
    0xa4c2ff,
    0xa9bdff,
    0xa3c1ff,
    0xa8bdff,
    0xa3c1ff,
    0xa8bdff,
    0xa2c1ff,
    0xa7bcff,
    0xa2c0ff,
    0xa7bcff,
    0xa1c0ff,
    0xa7bcff,
    0xa1c0ff,
    0xa6bcff,
    0xa1c0ff,
    0xa6bbff,
    0xa0c0ff,
    0xa6bbff,
    0xa0bfff,
    0xa5bbff,
    0xa0bfff,
    0xa5bbff,
    0x9fbfff,
    0xa5baff,
    0x9fbfff,
    0xa5baff,
    0x9fbeff,
    0xa4baff,
    0x9fbeff,
    0xa4baff,
    0x9ebeff,
    0xa4baff,
    0x9ebeff,
    0xa4b9ff,
    0x9ebeff,
    0xa3b9ff,
    0x9ebeff,
    0xa3b9ff,
    0x9dbdff,
    0xa3b9ff,
    0x9dbdff,
    0xa3b9ff,
    0x9dbdff,
    0xa3b9ff,
    0x9dbdff,
    0xa2b8ff,
    0x9dbdff,
    0xa2b8ff,
    0x9cbdff,
    0xa2b8ff,
    0x9cbdff,
    0xa2b8ff,
    0x9cbdff,
    0xa2b8ff,
    0x9cbcff,
    0xa2b8ff,
    0x9cbcff,
    0xa2b8ff,
    0x9bbcff,
    0xa1b7ff,
    0x9bbcff,
    0xa1b7ff,
    0x9bbcff,
    0xa1b7ff,
    0x9bbcff,
  };

  unsigned int getRandomLessThan( unsigned int max )
  {
    return 1 + ( std::rand() * static_cast< double >( --max ) ) / RAND_MAX;
  }

}

sc::gra::Particle::Particle(
    sc::phi::Sector& sector,
    Engine& graphicalEngine,
    const sc::phi::Coordinate& coordinate,
    const sc::phi::Coordinate& speed )
  : sc::phi::Object( sector, { coordinate, speed, 0.0, 0, 0 } )
  , Graphical( graphicalEngine )
  , m_colourIndex( getRandomLessThan( blackBody.size() - 1 ) )
{
}


void
sc::gra::Particle::draw() const
{
  m_graphicalEngine.drawPoint( m_physicalModel.coordinate(), 2,
      blackBody[ m_colourIndex ] );
}


void
sc::gra::Particle::timerUpdate( const sc::phi::Ratio& )
{
  --m_colourIndex;
  if ( 0 == m_colourIndex )
  {
    deleteObject();
  }
}


namespace
{
  const unsigned int POOL_CAPACITY( 100000 );
  sc::utl::MemoryPool< sc::gra::Particle, POOL_CAPACITY > POOL;
}


void *
sc::gra::Particle::operator new( size_t size )
{
  return POOL.allocate( size );
}


void
sc::gra::Particle::operator delete( void *memory )
{
  POOL.release( memory );
}

