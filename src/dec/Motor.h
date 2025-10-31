#ifndef TEREMIM_MOTOR_H_INCLUDED
#define TEREMIM_MOTOR_H_INCLUDED

#include "EletronicComponent.h"

class Motor : public EletronicComponent {
private:
  uint_8 leftPin;
  uint_8 rightPin;
  uint_8 enablePin;

  bool direction;
  uint_8 velocity;

  void invertDirection();

public:
  Motor(uint_8 leftPin, uint_8 rightPin, bool enable, uint_8 velocity);

  void start() override;

  void setLeftPin(uint_8 leftPin);
  void setRightPin(uint_8 rightPin);
  void setEnablePin(uint_8 enable);

  uint_8 getLeftPin();
  uint_8 getRightPin();
  uint_8 getEnablePin();

  void setDirection(bool direction);
  void setVelocity(uint_8 velocity);

  bool getDirection();
  uint_8 getVelocity();

  void toggleDirection();
  void run();
  void stop();
};

#endif
