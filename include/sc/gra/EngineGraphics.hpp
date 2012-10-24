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

#include <sc/phi/Accessory.hpp>
#include <sc/gra/ParticleSource.hpp>

namespace sc
{
  namespace phi
  {
    class Sector;
    class Coordinate;
    class Model;
  }

  namespace gra
  {
    class Model;
    class Engine;

    class EngineGraphics : public phi::Accessory
    {
      public:
        EngineGraphics(
            sc::phi::Sector& sector,
            sc::gra::Engine& graphicalEngine,
            unsigned int radius,
            unsigned int particleDensity );
        virtual ~EngineGraphics();

        void pimpBackThruster( sc::evt::Event& event );
        void pimpCwThruster( sc::evt::Event& event );
        void pimpCcwThruster( sc::evt::Event& event );

        virtual void subscribe( sc::evt::Registry& registry );

      private:
        sc::phi::Coordinate shipFront() const;
        sc::phi::Coordinate shipBack() const;
        sc::phi::Angle left() const;
        sc::phi::Angle right() const;

        sc::gra::ParticleSource m_particleSource;

        const unsigned int m_shipRadius;
    };
  }
}

