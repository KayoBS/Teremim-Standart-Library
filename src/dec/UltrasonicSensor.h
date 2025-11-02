#ifndef TEREMIM_ULTRASONIC_SENSOR_H_INCLUDED
#define TEREMIM_ULTRASONIC_SENSOR_H_INCLUDED

#include "EletronicComponent.h"

class UltrasonicSensor : public EletronicComponent {
private:
  uint8_t trigger;
  uint8_t echo;
  double duration;
  double distance;

  void calculateDistance();

public:
  UltrasonicSensor(uint8_t trigger, uint8_t echo);

  void start();

  double getDistance();
  double getDistanceInMeters();
};

#endif
