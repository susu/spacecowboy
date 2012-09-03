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
  , m_speedModifier( 0.0, 0.0 )
  , m_angularVelocityModifier( 0.0 )
{
}


void
sc::phi::Model::timeElapse( const Ratio& timeFrameRatio )
{
  updateWithModifiers();

  m_coordinate+=m_speed * timeFrameRatio;
  m_heading+=m_angularVelocity * timeFrameRatio;
}


void
sc::phi::Model::updateWithModifiers()
{
  m_speed += m_speedModifier;
  m_speedModifier = { 0.0, 0.0 };

  m_angularVelocity += m_angularVelocityModifier;
  m_angularVelocityModifier = 0.0;
}


void
sc::phi::Model::spin( const double& force )
{
  m_angularVelocityModifier+=force;
}


void
sc::phi::Model::push( const Coordinate& force )
{
  m_speedModifier+=force;
}

