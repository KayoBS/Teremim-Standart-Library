#include "../dec/Acelerometer.h"

Acelerometer::Acelerometer(byte x, byte y, byte z)
: x_pin(x), y_pin(y), z_pin(z) {}
void Acelerometer::start() {
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(z_pin, INPUT);
}

// getters
byte Acelerometer::getx() { return analogRead(x_pin); }
byte Acelerometer::gety() { return analogRead(y_pin); }
byte Acelerometer::getz() { return analogRead(z_pin); }
