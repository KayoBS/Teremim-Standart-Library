#ifndef TEREMIM_MOTOR_H_INCLUDED
#define TEREMIM_MOTOR_H_INCLUDED

#include "EletronicComponent.h"

class Motor : public EletronicComponent {
private:
  uint8_t leftPin;
  uint8_t rightPin;
  uint8_t enablePin;

  bool direction;
  uint8_t velocity;

  void invertDirection();

public:
  Motor(uint8_t leftPin, uint8_t rightPin, uint8_t enable, bool direction,
        uint8_t velocity);

  void start() override;

  void setLeftPin(uint8_t leftPin);
  void setRightPin(uint8_t rightPin);
  void setEnablePin(uint8_t enable);

  uint8_t getLeftPin();
  uint8_t getRightPin();
  uint8_t getEnablePin();

  void setDirection(bool direction);
  void setVelocity(uint8_t velocity);

  bool getDirection();
  uint8_t getVelocity();

  void toggleDirection();
  void run();
  void stop();
};

#endif
