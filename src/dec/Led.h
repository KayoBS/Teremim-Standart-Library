#ifndef TEREMIM_LED_H_INCLUDED
#define TEREMIM_LED_H_INCLUDED

#include "EletronicComponent.h"

class Led : public EletronicComponent {
private:
  bool state;
  uint8_t pin;

public:
  Led(uint8_t pin);
  void start();

  // void setPin( uint8_t pin );
  // uint8_t getPin();

  // getters
  bool getState();

  // setters
  void setState(bool state);

  void setOn(bool state);
  bool isOn();
};

#endif
