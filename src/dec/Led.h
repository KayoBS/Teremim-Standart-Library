#ifndef TEREMIM_LED_H_INCLUDED
#define TEREMIM_LED_H_INCLUDED

#include "EletronicComponent.h"

class Led : public EletronicComponent {
private:
  bool state;
  uint_8 pin;

public:
  Led(uint_8 pin);
  void start();

  // void setPin( uint_8 pin );
  // uint_8 getPin();

  // getters
  bool getState();

  // setters
  void setState(bool state);

  void setOn(bool state);
  bool isOn();
};

#endif
