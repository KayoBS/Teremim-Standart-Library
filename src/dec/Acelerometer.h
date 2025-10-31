#ifndef TEREMIM_ACELEROMETER_H_INCLUDED
#define TEREMIM_ACELEROMETER_H_INCLUDED

#include "EletronicComponent.h"

class Acelerometer : public EletronicComponent {
private:
  uint8_t x_pin;
  uint8_t y_pin;
  uint8_t z_pin; // zepellin

public:
  Acelerometer(uint8_t x, uint8_t y, uint8_t z);
  void start();

  // getters
  uint8_t getx();
  uint8_t gety();
  uint8_t getz();
};

#endif
