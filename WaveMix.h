#pragma once
//
//    FILE: WaveMix.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: Arduino library to mix two signals (A and B) with an adaptive weight.
//     URL: https://github.com/RobTillaart/WaveMix
//


#include "Arduino.h"

#define WAVEMIX_LIB_VERSION               (F("0.1.1"))


class WaveMix
{
public:
  explicit WaveMix();

  //  weight1 + weight2 != 0
  void  setWeight(float weight1, float weight2);
  float getW1() { return _weight[0]; };
  float getW2() { return _weight[1]; };
  //  preferably 0 <= percentage <= 100
  void  setPercentage(float percentage);

  void  setGain(float gain) { _gain = gain; };
  float getGain() { return _gain; };

  float mix(float s1, float s2 = 0);


private:
  float _weight[2] = { 0.5, 0.5 };
  float _gain      = 1.0;

};


// -- END OF FILE --
