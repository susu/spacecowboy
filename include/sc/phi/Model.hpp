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
  namespace phi
  {
    class Model
    {
      public:
        Model( const Coordinate& coordinate,
               const Coordinate& speed,
               const Angle&      heading,
               const Angle&      angularVelocity,
               unsigned int      radius,
               unsigned int      mass );

        void timeElapse( const Ratio& timeFrameRatio );
        void spin( const double& force );
        void push( const Coordinate& force );

        Coordinate coordinate() const { return m_coordinate; }
        Angle heading() const { return m_heading; }
        Coordinate speed() const { return m_speed; }
        Angle angularVelocity() const { return m_angularVelocity; }

        unsigned int radius() const { return m_radius; }
        unsigned int mass() const { return m_mass; }
      private:
        void updateWithModifiers();

        Coordinate m_coordinate;
        Coordinate m_speed;
        Angle      m_heading;
        Angle      m_angularVelocity;

        Coordinate m_speedModifier;
        Angle      m_angularVelocityModifier;

        unsigned int m_radius;
        unsigned int m_mass;
    };

    bool collides( const Model& left, const Model& right );
  }
}

