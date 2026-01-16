#ifndef TEREMIM_LED_H_INCLUDED
#define TEREMIM_LED_H_INCLUDED

#include "EletronicComponent.h"

class Led : public EletronicComponent {
private:
  bool state;
  byte pin;

public:
  Led(byte pin);
  void start();

  // void setPin( byte pin );
  // byte getPin();

  // getters
  bool getState();

  // setters
  void setState(bool state);

  void setOn(bool state);
  bool isOn();
};

#endif
