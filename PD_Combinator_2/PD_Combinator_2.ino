// Combinator 2 - PureData noodle //

#include <Audio.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include "audio_puredata.h"

AudioOutputI2S           i2s;
AudioProcessor           proc; 

AudioConnection          patchCord3(proc, 0, i2s, 0);
AudioConnection          patchCord4(proc, 1, i2s, 1);

AudioControlSGTL5000     audioShield;

void setup() {

  AudioMemory(12);

  audioShield.enable();
  audioShield.volume(0.5);

}

void loop() {

}