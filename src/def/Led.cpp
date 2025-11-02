#include "../dec/Led.h"

Led::Led(uint8_t pin) : pin(pin) {}

void Led::start() { pinMode(pin, OUTPUT); }

bool Led::getState() { return this->state; }

void Led::setState(bool state) { this->state = state; }

bool Led::isOn() { this->getState(); }
void Led::setOn(bool state) { this->setState(state); }
