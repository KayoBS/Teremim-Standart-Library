#ifndef TEREMIM_COLORSENSOR_H_INCLUDED
#define TEREMIM_COLOR_SENSOR_H_INCLUDED

#include "EletronicComponent.h"

class ColorSensor : public EletronicComponent {
private:
  uint_8 S0;
  uint_8 S1;
  uint_8 S2;
  uint_8 S3;
  uint_8 OUT;

  unsigned int red;
  unsigned int blue;
  unsigned int green;

  void readRed();
  void readGreen();
  void readBlue();

public:
  ColorSensor(uint_8 S0, uint_8 S1, uint_8 S2, uint_8 S3, uint_8 OUT);

  void start();

  bool isWhite();
  bool isRed();
  bool isBlue();
  bool isGreen();
  bool isBlack();

  unsigned int getRed();
  unsigned int getGreen();
  unsigned int getBlue();

  unsigned int getRedUnread();
  unsigned int getGreenUnread();
  unsigned int getBlueUnread();

  void readColors();
};

#endif
