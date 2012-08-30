#include <cxxtest/TestSuite.h>
#include "sc/phi/Model.hpp"

#include <memory>

class ModelTest : public CxxTest::TestSuite
{
  private:
    std::unique_ptr< sc::phi::Model > m_model;
    sc::phi::Ratio m_stepRatio = 0.5;

    void setUp()
    {
      m_model.reset( new sc::phi::Model(
          sc::phi::Coordinate( 0.0, 0.0 ),
          sc::phi::Coordinate( 0.0, 0.0 ),
          0.0,
          0.0 ) );
    }

  public:
    void test_spinned_model_should_rotate()
    {
      sc::phi::Angle force( 1.0 );
      m_model->spin( force );
      m_model->spin( force );
      TS_ASSERT_EQUALS( force * 2.0, m_model->angularVelocity() );

      m_model->timeElapse( m_stepRatio );
      m_model->timeElapse( m_stepRatio );
      TS_ASSERT_EQUALS( m_model->heading(), m_model->angularVelocity() * m_stepRatio * 2.0 );
    }


    void test_pushed_model_should_move()
    {
      sc::phi::Coordinate force( 1.0, 1.0 );

      m_model->push( force );
      m_model->push( force );
      TS_ASSERT_EQUALS( force * 2.0, m_model->speed() );

      m_model->timeElapse( m_stepRatio );
      m_model->timeElapse( m_stepRatio );
      TS_ASSERT_EQUALS( m_model->coordinate(), m_model->speed() * m_stepRatio * 2.0 );
    }

};

