#include "../dec/ColorSensor.h"

// PRIVATE
void ColorSensor::readRed() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH) + 2;
  this->red = red;
}
void ColorSensor::readGreen() {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  green = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  this->green = green;
}
void ColorSensor::readBlue() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH) + 3;
  this->blue = blue;
}

// PUBLIC
ColorSensor::ColorSensor(uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3,
                         uint8_t OUT)
    : S0(S0), S1(S1), S2(S2), S3(S3), OUT(OUT), red(0), blue(0), green(0) {}

void ColorSensor::start() override {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH);
}

// IS methods
bool ColorSensor::isWhite() { // sitcom do lab
  if (getRed(true) <= 12 && getGreen(true) <= 12 && getBlue(true) <= 12)
    return true;
  else
    return false;
}
bool ColorSensor::isRed() {
  if (getRed(true) < getBlue(true) && getRed(true) <= getGreen(true))
    return true;
  else
    return false;
}
bool ColorSensor::isBlue() {
  if (getBlue(true) < getGreen(true) && getBlue(true) < getRed(true))
    return true;
  else
    return false;
}
bool ColorSensor::isGreen() {
  if (getGreen(true) < getRed(true) && getGreen(true) < getBlue(true))
    return true;
  else
    return false;
}
bool ColorSensor::isBlack() {
  return !(isWhite() && isRed() && isGreen() && isBlue());
}
unsigned int getRed() {
  readRed();
  return this->red;
}

// GETTERS without parameters
unsigned int ColorSensor::getRed() { readRed() return this->red; }
unsigned int ColorSensor::getGreen() {
  readGreen();
  return this->green;
}
unsigned int ColorSensor::getBlue() {
  readBlue();
  return this->blue;
}

// GETTERS with parameters
unsigned int ColorSensor::getRedUnread() {
  if (unread)
    return this->red;
  else
    return 0;
}
unsigned int ColorSensor::getGreen(bool unread) {
  if (unread)
    return this->green;
  else
    return 0;
}
unsigned int ColorSensor::getBlue(bool unread) {
  if (unread)
    return this->blue;
  else
    return 0;
}

// readColors();
void ColorSensor::readColors() {
  // digitalWrite(S2, LOW);
  // digitalWrite(S3, LOW);
  //  red = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  // delay(20);
  // digitalWrite(S3, HIGH);
  //  blue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  // delay(20);
  // digitalWrite(S2, HIGH);
  //  green = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  // delay(20);
  getRed();
  getBlue();
  getGreen();
}
