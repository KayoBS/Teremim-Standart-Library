#ifndef TEREMIM_ULTRASONIC_SENSOR_H_INCLUDED
#define TEREMIM_ULTRASONIC_SENSOR_H_INCLUDED

#include "EletronicComponent"

class UltrasonicSensor : public EletronicComponent {
private:
  uint_8 trigger;
  uint_8 echo;
  double duration;
  double distance;

  void calculateDistance();

public:
  UltrasonicSensor(uint_8 trigger, uint_8 echo);

  void start();

  double getDistance();
  double getDistanceInMeters();
};

#endif
