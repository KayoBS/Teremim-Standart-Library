#ifndef TEREMIM_MOTOR_H_INCLUDED
#define TEREMIM_MOTOR_H_INCLUDED

#include "EletronicComponent.h"

class Motor : public EletronicComponent {
private:
  byte leftPin;
  byte rightPin;
  byte enablePin;

  bool direction;
  byte velocity;

  void invertDirection();

public:
  Motor(byte leftPin, byte rightPin, byte enable, bool direction,
        byte velocity);

  void start() override;

  /*
  void setLeftPin(byte leftPin);
  void setRightPin(byte rightPin);
  void setEnablePin(byte enable);
  */

  byte getLeftPin();
  byte getRightPin();
  byte getEnablePin();

  void setDirection(bool direction);
  void setVelocity(byte velocity);

  bool getDirection();
  byte getVelocity();

  void toggleDirection();
  void run();
  void stop();
};

#endif
