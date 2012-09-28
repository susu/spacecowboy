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

