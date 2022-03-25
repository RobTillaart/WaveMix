
[![Arduino CI](https://github.com/RobTillaart/WaveMix/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/WaveMix/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/WaveMix/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/WaveMix/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/WaveMix/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/WaveMix/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/WaveMix.svg?maxAge=3600)](https://github.com/RobTillaart/WaveMix/releases)


# WaveMix

WaveMix is an Arduino library to mix two signals (A and B) with an adaptive weight.


## Description

WaveMix is a very simple library to mix two signals (A and B) with an adaptive weight.

Depending on the weights applied the output signal (O) looks more on signal A or on signal B. A gain can be applied to amplify weak signals 
or to be used for modulation.


Inspired by - https://www.codeproject.com/Articles/5323200/On-how-to-mix-two-signals-by-using-Spectral-Foreca

Differences
- simpler algorithm
- WaveMix works on streams of measurements too.


## Interface

The main functions of the WaveMix 

- **explicit WaveMix()** Constructor
- **void  setWeight(float weight1, float weight2)** set the weight of the channels A and B. The weights do not need to be normalized, so one can use e.g **setWeight(7, 13)** See below.
- **float getW1()** return the normalized weight for channel A.
- **float getW2()** return the normalized weight for channel B.
- **void  setPercentage(float percentage)** sets the weight for channel A preferably to 0 <= percentage <= 100. Channel B will have 100 - percentage.
- **void  setGain(float gain)** sets the gain factor.
An important use of gain is to amplify weak signals but one can also use it as a modulator of a signal. See examples.
- **float getGain()** return the gain set.
- **float mix(float s1, float s2 = 0)** returns the weighted average of signal1 and signal2. Signal2 is made optional to allow single signal processes e.g. modulation by **setGain()**.


### About weights

**setWeight()** typically uses positive weights, e.g. **setWeight(7, 13)**
counts A for 7/20 part and B for 13/20 part. 
It is also possible to use one or two negative weights. 
Using negative weights means effectively the input value is inverted before it is added. 
E.g. **setWeight(-1, 0)** would effectively invert signal A.
Only restriction to the weights is that the sum of the weights may not be zero.
Weights cannot be used to amplify the signal, use **setGain()** for that.


## Operation

See examples.


## Future ideas

- make a N channel variant.
- add **addSignal(channel, value)**, allow update of channels at a
different frequency.
- add **getValue()**, read the current output given the value of the 
channels.
- add **void setOffset(float)** and ** void getOffset()**


#### low
- add increment() / decrement() ?
  - percentages


