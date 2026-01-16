#include "../dec/InfraredSensor.h"

InfraredSensor::InfraredSensor(byte pin) {
    this->pin = pin;
}

void InfraredSensor::start() {
    pinMode(this->pin, INPUT);
}

bool InfraredSensor::isBlack() {
    return digitalRead(this->pin);
}
