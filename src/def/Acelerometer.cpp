#include "../dec/Acelerometer.h"

Acelerometer::Acelerometer(uint8_t x, uint8_t y, uint8_t z)
    : x_pin(x), y_pin(y), z_pin(z) {}
void start() override {
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(z_pin, INPUT);
}

// getters
uint8_t Acelerometer::getx() { return analogRead(x_pin); }
uint8_t Acelerometer::gety() { return analogRead(y_pin); }
uint8_t Acelerometer::getz() { return analogRead(z_pin); }
