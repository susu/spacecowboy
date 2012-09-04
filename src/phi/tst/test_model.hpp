#include <cxxtest/TestSuite.h>
#include "sc/phi/Model.hpp"

#include <memory>

class ModelTest : public CxxTest::TestSuite
{
  private:
    std::unique_ptr< sc::phi::Model > m_model;
    sc::phi::Ratio m_stepRatio = 0.5;
    sc::phi::Coordinate m_startSpeed = { 0.0, 0.0 };
    sc::phi::Angle m_startAngularVelocity = 0.0;

    void setUp()
    {
      m_model.reset( new sc::phi::Model(
          sc::phi::Coordinate( 0.0, 0.0 ),
          m_startSpeed,
          0.0,
          m_startAngularVelocity ) );
    }

  public:
    void test_physical_attributes_should_change_only_during_timer_update()
    {
      sc::phi::Coordinate pushForce( 1.0, 1.0 );
      m_model->push( pushForce );
      TS_ASSERT_EQUALS( m_startSpeed, m_model->speed() );

      sc::phi::Angle rotationForce( 1.0 );
      m_model->spin( rotationForce );
      TS_ASSERT_EQUALS( m_startAngularVelocity, m_model->angularVelocity() );

      m_model->timeElapse( m_stepRatio );
      TS_ASSERT_EQUALS( pushForce, m_model->speed() );
      TS_ASSERT_EQUALS( rotationForce, m_model->angularVelocity() );
    }


    void test_spinned_model_should_rotate()
    {
      sc::phi::Angle force( 1.0 );
      m_model->spin( force );
      m_model->spin( force );

      m_model->timeElapse( m_stepRatio );
      m_model->timeElapse( m_stepRatio );
      TS_ASSERT_EQUALS( force * 2.0, m_model->angularVelocity() );
      TS_ASSERT_EQUALS( m_model->heading(), m_model->angularVelocity() * m_stepRatio * 2.0 );
    }


    void test_pushed_model_should_move()
    {
      sc::phi::Coordinate force( 1.0, 1.0 );

      m_model->push( force );
      m_model->push( force );

      m_model->timeElapse( m_stepRatio );
      m_model->timeElapse( m_stepRatio );
      TS_ASSERT_EQUALS( force * 2.0, m_model->speed() );
      TS_ASSERT_EQUALS( m_model->coordinate(), m_model->speed() * m_stepRatio * 2.0 );
    }


    void test_models_collide_only_if_circles_overlap()
    {
      {
        sc::phi::Model other(
            sc::phi::Coordinate( 20.0, 0.0 ),
            sc::phi::Coordinate( 0.0, 0.0 ),
            0.0,
            0.0 );

        TS_ASSERT( !collides( other, *m_model.get() ) );
      }

      {
        sc::phi::Model other(
            sc::phi::Coordinate( 19.0, 0.0 ),
            sc::phi::Coordinate( 0.0, 0.0 ),
            0.0,
            0.0 );
        TS_ASSERT( collides( other, *m_model.get() ) );
      }
    }

};

