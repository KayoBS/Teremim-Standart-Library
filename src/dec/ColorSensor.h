#ifndef TEREMIM_COLOR_SENSOR_H_INCLUDED
#define TEREMIM_COLOR_SENSOR_H_INCLUDED

#include "EletronicComponent.h"

class ColorSensor : public EletronicComponent {
private:
  byte S0;
  byte S1;
  byte S2;
  byte S3;
  byte OUT;

  unsigned int red;
  unsigned int blue;
  unsigned int green;

  unsigned int myr;
  unsigned int myg;
  unsigned int myb;

  unsigned int redError;
  unsigned int blueError;

  unsigned int blackLineValue;

  void readRed();
  void readGreen();
  void readBlue();

public:
  ColorSensor(byte S0, byte S1, byte S2, byte S3, byte OUT, byte blackLineValue, byte redError, byte blueError);

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
