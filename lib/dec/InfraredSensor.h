#ifndef TEREMIM_INFRARED_SENSOR_H_INCLUDED
#define TEREMIM_INFRARED_SENSOR_H_INCLUDED

#include "EletronicComponent.h"

class InfraredSensor : public EletronicComponent {
private:
  byte pin;

public:
  InfraredSensor(byte pin);

  void start() override;

  bool isBlack();
};

#endif
