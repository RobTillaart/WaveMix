#pragma once
//
//    FILE: WaveMix.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: an Arduino library to mix two signals (A and B) with an adaptive weight.
//     URL: https://github.com/RobTillaart/CountDown
//


#include "Arduino.h"

#define WAVEMIX_LIB_VERSION               (F("0.1.1"))


class WaveMix
{
public:
  explicit WaveMix();

  //  w1 >= 0 && w2 >= 0 && (w1+w2) > 0
  void  setWeight(float weight1, float weight2);
  float getW1() { return _weight[0]; };
  float getW2() { return _weight[1]; };
  //  0 <= percentage <= 100
  void  setPercentage(float percentage);
  
  //  0.0 <= gain
  void  setGain(float gain);
  float getGain() { return _gain; };

  float mix(float s1, float s2 = 0);


private:
  // prep multi-channel
  float _weight[2] = { 0.5, 0.5 };
  float _gain    = 1.0;
  
};


// -- END OF FILE --
