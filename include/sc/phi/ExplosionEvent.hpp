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
#include <sc/evt/Event.hpp>
#include <sc/phi/BaseTypes.hpp>

#include <vector>

namespace sc
{
  namespace phi
  {
    class Model;

    class ExplosionEvent : public sc::evt::Event
    {
      public:
        ExplosionEvent( const Model& physicalModel, unsigned int power );
        virtual void handle( sc::evt::Registry& registry );

        Coordinate center() const;
        const Model& model() const;
        unsigned int power() const;

      private:
        const Model& m_physicalModel;
        unsigned int m_power;
    };
  }
}

