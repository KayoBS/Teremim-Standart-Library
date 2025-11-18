#ifndef TEREMIM_COLORSENSOR_H_INCLUDED
#define TEREMIM_COLOR_SENSOR_H_INCLUDED

#include "EletronicComponent.h"

class ColorSensor : public EletronicComponent {
private:
  uint8_t S0;
  uint8_t S1;
  uint8_t S2;
  uint8_t S3;
  uint8_t OUT;

  unsigned int red;
  unsigned int blue;
  unsigned int green;

  unsigned int redError;
  unsigned int blueError;

  unsigned int blackLineValueLine;

  void readRed();
  void readGreen();
  void readBlue();

public:
  ColorSensor(uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t OUT, uint8_t blackLineValueLine, uint8_t redError, uint8_t blueError);
  void start();

  void start();

  bool isWhite();
  bool isRed();
  bool isBlue();
  bool isGreen();
  bool isBlack();

  unsigned int getRed();
  unsigned int getGreen();
  unsigned int getBlue();

  unsigned int retRed();
  unsigned int retGreen();
  unsigned int retBlue();

  void readColors();
};

#endif
