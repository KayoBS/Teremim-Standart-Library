#ifndef TEREMIM_ACELEROMETER_H_INCLUDED
#define TEREMIM_ACELEROMETER_H_INCLUDED

#include "EletronicComponent.h"

class Acelerometer : public EletronicComponent {
private:
  byte x_pin;
  byte y_pin;
  byte z_pin; // zepellin

public:
  Acelerometer(byte x, byte y, byte z);
  void start() override;

  // getters
  byte getx();
  byte gety();
  byte getz();
};

#endif
