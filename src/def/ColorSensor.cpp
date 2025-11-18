#include "../dec/ColorSensor.h"

// PRIVATE
void ColorSensor::readRed() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH) + redError;
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
  blue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH) + blueError;
  this->blue = blue;
}

// PUBLIC
ColorSensor::ColorSensor(uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t OUT, uint8_t blackLineValueLine, uint8_t redError, uint8_t blueError)
    : S0(S0), S1(S1), S2(S2), S3(S3), blackLineValueLine(blackLineValueLine), redError(redError), blueError(blueError), OUT(OUT), red(0), blue(0), green(0) {}

void ColorSensor::start() override {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  delay(100);
  readColors();
  this->myr = this->red;
  this->myg = this->green;
  this->myb = this->blue;

  delay(200);
}

// IS methods
bool ColorSensor::isWhite() { // sitcom do lab
  if (retRed() <= (myr + 1) && retGreen() <= (myg + 1) && retBlue() <= (myb + 1))
    return true;
  else
    return false;
}
bool ColorSensor::isRed() {
  if (retRed() < retBlue() && retRed() <= retGreen())
    return true;
  else
    return false;
}
bool ColorSensor::isBlue() {
  if (retBlue() < retGreen() && retBlue() < retRed())
    return true;
  else
    return false;
}
bool ColorSensor::isGreen() {
  if (retGreen() < retRed() && retGreen() < retBlue())
    return true;
  else
    return false;
}
bool ColorSensor::isBlack() {
  this->readColors();
  if(retRed() >= blackLineValueLine && retGreen() >= blackLineValueLine && retBlue() >= blackLineValueLine)
    return true;
  else
    return false;
}
unsigned int getRed() {
  readRed();
  return this->red;
}

// GETTERS without parameters
unsigned int ColorSensor::getRed() {
  readRed();
  return this->red
}
unsigned int ColorSensor::getGreen() {
  readGreen();
  return this->green;
}
unsigned int ColorSensor::getBlue() {
  readBlue();
  return this->blue;
}

// GETTERS with parameters
unsigned int ColorSensor::retRed() {
    return this->red;
}
unsigned int ColorSensor::retRed() {
    return this->green;
}
unsigned int ColorSensor::retRed() {
    return this->blue;
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
