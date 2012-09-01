#include <sc/phi/Object.hpp>
#include <sc/phi/BaseTypes.hpp>
#include <sc/evt/Hub.hpp>

sc::phi::Object::Object( Sector& sector )
  : evt::Hub()
  , m_physicalModel( Coordinate( 100.0, 100.0 )
                    ,Coordinate( 0.0, 0.0 )
                    ,0.0
                    ,0.0 )
  , m_sector( sector )
{
}


sc::phi::Object::Object( Sector& sector, const Coordinate& coordinate, const Coordinate& speed )
  : evt::Hub()
  , m_physicalModel( coordinate
                    ,speed
                    ,0.0
                    ,0.0 )
  , m_sector( sector )
{
}


sc::phi::Object::~Object()
{
}


void
sc::phi::Object::timeElapsed( const Ratio& stepRatio )
{
  m_physicalModel.timeElapse( stepRatio );
  timerUpdate( stepRatio );
}
