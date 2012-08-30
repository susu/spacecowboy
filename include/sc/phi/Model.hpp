#pragma once

#include <sc/phi/BaseTypes.hpp>

namespace sc
{
  namespace phi
  {
    class Model
    {
      public:
        Model( const Coordinate& m_coordinate,
               const Coordinate& m_speed,
               const Angle&      m_heading,
               const Angle&      m_angularVelocity );

        void timeElapse( const Ratio& timeFrameRatio );
        void spin( const double& force );
        void push( const Coordinate& force );

        Coordinate coordinate() const { return m_coordinate; }
        Angle heading() const { return m_heading; }
        Coordinate speed() const { return m_speed; }
        Angle angularVelocity() const { return m_angularVelocity; }

      private:
        Coordinate m_coordinate;
        Coordinate m_speed;
        Angle      m_heading;
        Angle      m_angularVelocity;
    };

  }
}
