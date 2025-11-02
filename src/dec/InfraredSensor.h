#ifndef TEREMIM_INFRARED_SENSOR_H_INCLUDED
#define TEREMIM_INFRARED_SENSOR_H_INCLUDED

#include "EletronicComponent.h"

class InfraredSensor : public EletronicComponent {
private:
  uint8_t pin;

public:
  InfraredSensor(uint8_t pin);

  void start() override;

  bool isBlack();
};

#endif
