#include "../dec/UltrasonicSensor.h"

// PRIVATE
void UltrasonicSensor::calculateDistance() {
  digitalWrite(this->trigger, false);
  delayMicroseconds(2);
  digitalWrite(this->trigger, true);
  delayMicroseconds(10);
  digitalWrite(this->trigger, false);
  duration = pulseIn(this->echo, true);
  distance = (duration * 0.0343f) / 2.f; // 0.0343 é a velocidade do som em
  // cm / μs
  // delay(100);
}

// PUBLIC
UltrasonicSensor::UltrasonicSensor(byte trigger, byte echo) {
  this->trigger = trigger;
  this->echo = echo;
}
void UltrasonicSensor::start() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}
double UltrasonicSensor::getDistance() {
  calculateDistance();
  return this->distance;
}
double UltrasonicSensor::getDistanceInMeters() {
  calculateDistance();
  return (this->distance / 100.f);
}
