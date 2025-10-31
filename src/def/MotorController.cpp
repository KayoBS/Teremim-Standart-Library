#include "../dec/Motor.h"

MotorController(Motor *leftMotor, Motor *rightMotor) {
  this->*leftMotor = &leftMotor;
  this->*rightMotor = &rightMotor;
}

void setAll(bool direction) { this->*leftMotor->setDirection(direction); }

Motor **getMotors() {
  Motor **motors = {this->& leftMotor, this->rightMotor};
  return motors;
}
