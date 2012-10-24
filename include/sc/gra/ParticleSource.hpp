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

#include <sc/phi/BaseTypes.hpp>

namespace sc
{
  namespace gra
  {
    class Model;
    class Engine;

    class ParticleSource
    {
      public:
        ParticleSource(
            sc::phi::Sector& sector,
            sc::gra::Engine& graphicalEngine,
            unsigned int density,
            const double& velocity,
            const double& deviation );

        void createParticle(
            const sc::phi::Coordinate& coord,
            const sc::phi::Coordinate& baseSpeed,
            const sc::phi::Angle& heading );

      private:
        sc::phi::Sector& m_sector;
        sc::gra::Engine& m_graphicalEngine;

        unsigned int m_density;
        double m_velocity;
        double m_deviation;
    };
  }
}

