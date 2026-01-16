#ifndef TEREMIM_MOTOR_CONTROLLER_H_INCLUDED
#define TEREMIM_MOTOR_CONTROLLER_H_INCLUDED

#include "Motor.h"

class MotorController
{
public:
    Motor* leftMotor;
    Motor* rightMotor;

    MotorController( Motor* leftMotor, Motor* rightMotor );

    void setAll( bool direction );
    Motor** getMotors();
};

#endif
