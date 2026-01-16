#include "../dec/ColorSensor.h"

// PRIVATE
void ColorSensor::readRed() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  //obs: pulseIn retorna unsigned long, isso pode dar overflow
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
ColorSensor::ColorSensor(byte S0, byte S1, byte S2, byte S3, byte OUT, byte blackLineValue, byte redError, byte blueError)
: S0(S0), S1(S1), S2(S2), S3(S3), blackLineValue(blackLineValue), redError(redError), blueError(blueError), OUT(OUT), red(0), blue(0), green(0) {
  this->red = 0;
  this->green = 0;
  this->blue = 0;
}

void ColorSensor::start() {
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
// obs: sempre que se for usar esses metódos no código, é necessário chamar getColors antes
bool ColorSensor::isWhite() { // sitcom do lab
  if (red <= (myr + 1) && green <= (myg + 1) && blue <= (myb + 1))
    return true;
  else
    return false;
}
bool ColorSensor::isRed() {
  if (red < blue && red <= green)
    return true;
  else
    return false;
}
bool ColorSensor::isBlue() {
  if (blue < green && blue < red)
    return true;
  else
    return false;
}
bool ColorSensor::isGreen() {
  if (green < red && green < blue)
    return true;
  else
    return false;
}
bool ColorSensor::isBlack() {
  if(red >= blackLineValue && green >= blackLineValue && blue >= blackLineValue)
    return true;
  else
    return false;
}

// GETTERS without parameters
unsigned int ColorSensor::getRed() {
  readRed();
  return this->red;
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
unsigned int ColorSensor::retGreen() {
  return this->green;
}
unsigned int ColorSensor::retBlue() {
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
