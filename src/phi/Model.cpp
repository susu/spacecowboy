#include <sc/phi/Model.hpp>
#include <sc/phi/BaseTypes.hpp>

sc::phi::Model::Model(
    const Coordinate& coordinate,
    const Coordinate& speed,
    const Angle&      heading,
    const Angle&      angularVelocity )
  : m_coordinate( coordinate  )
  , m_speed( speed )
  , m_heading( heading )
  , m_angularVelocity( angularVelocity )
{
}


void
sc::phi::Model::timeElapse( const Ratio& timeFrameRatio )
{
  m_coordinate+=m_speed * timeFrameRatio;
  m_heading+=m_angularVelocity * timeFrameRatio;
}


void
sc::phi::Model::spin( const double& force )
{
  m_angularVelocity+=force;
}


void
sc::phi::Model::push( const Coordinate& force )
{
  m_speed+=force;
}

