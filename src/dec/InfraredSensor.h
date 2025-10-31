#ifndef TEREMIM_INFRARED_SENSOR_H_INCLUDED
#define TEREMIM_INFRARED_SENSOR_H_INCLUDED

#include "EletronicComponent.h"

class InfraredSensor : public EletronicComponent {
private:
  uint_8 pin;

public:
  InfraredSensor(uint_8 pin);

  void start() override;

  bool isBlack();
};

#endif
