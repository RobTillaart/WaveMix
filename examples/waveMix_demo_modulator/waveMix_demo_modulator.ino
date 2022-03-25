//
//    FILE: waveMix_demo_modulator.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//     URL: https://github.com/RobTillaart/WaveMix
//


#include "WaveMix.h"

WaveMix wm;

float n = 0;


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("WAVEMIX_LIB_VERSION: ");
  Serial.println(WAVEMIX_LIB_VERSION);

  wm.setWeight(1, 0);
  wm.setGain(100);
}


void loop()
{
  while (n < (2 * PI))
  {
    //  square modulation with setGain();
    if ((PI * 0.5) < n && n < PI) wm.setGain(1);
    else if ((PI * 1.5) < n) wm.setGain(1);
    else wm.setGain(0);

    Serial.println(wm.mix(sin(n)));
    n = n + 0.01;
  }
}


// -- END OF FILE --
