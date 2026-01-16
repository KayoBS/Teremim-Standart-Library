#ifndef TEREMIM_ULTRASONIC_SENSOR_H_INCLUDED
#define TEREMIM_ULTRASONIC_SENSOR_H_INCLUDED

#include "EletronicComponent.h"

class UltrasonicSensor : public EletronicComponent {
private:
  byte trigger;
  byte echo;
  double duration;
  double distance;

  void calculateDistance();

public:
  UltrasonicSensor(byte trigger, byte echo);

  void start();

  double getDistance();
  double getDistanceInMeters();
};

#endif
