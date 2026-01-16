#include "../dec/MotorController.h"

MotorController::MotorController(Motor *leftMotor, Motor *rightMotor) {
  this->leftMotor = leftMotor;
  this->rightMotor = rightMotor;
}

void MotorController::setAll(bool direction) {
  this->leftMotor->setDirection(direction);
  this->rightMotor->setDirection(direction);
}

Motor** MotorController::getMotors() {
  static Motor* motors[2];
  motors[0] = this->leftMotor;
  motors[1] = this->rightMotor;
  return motors;
}
