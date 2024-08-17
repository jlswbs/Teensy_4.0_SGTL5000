// Melodic noodle 01 - random sequence with modulated delay and drums //

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "AudioSampleKick.h"
#include "AudioSampleSnare.h"
#include "AudioSampleHihat.h"

#define BPM 120

AudioSynthWaveform       gen;
AudioSynthWaveform       lfo;
AudioPlayMemory          kick;
AudioSynthNoisePink      pink;
AudioSynthWaveformSine   sine;
AudioSynthWaveformSineModulated sine_fm;
AudioEffectMultiply      multiply;
AudioEffectEnvelope      envelope2;
AudioEffectEnvelope      envelope1;
AudioMixer4              mixer1;
AudioMixer4              mixer2;
AudioFilterStateVariable filter;
AudioEffectDelay         delays;
AudioEffectMidSide       decoder;
AudioOutputI2S           out;

AudioConnection          patchCord0(filter, 0, mixer2, 2);
AudioConnection          patchCord1(kick, 0, mixer2, 1);
AudioConnection          patchCord2(pink, envelope2);
AudioConnection          patchCord3(sine, 0, multiply, 0);
AudioConnection          patchCord4(lfo, sine_fm);
AudioConnection          patchCord5(sine_fm, 0, multiply, 1);
AudioConnection          patchCord6(multiply, envelope1);
AudioConnection          patchCord7(envelope2, 0, mixer1, 2);
AudioConnection          patchCord8(envelope1, 0, mixer1, 0);
AudioConnection          patchCord10(mixer1, delays);
AudioConnection          patchCord11(delays, 0, mixer1, 1);
AudioConnection          patchCord12(gen, 0, filter, 0);
AudioConnection          patchCord13(lfo, 0, filter, 1);
AudioConnection          patchCord14(mixer1, 0, decoder, 0);
AudioConnection          patchCord15(mixer2, 0, decoder, 1);
AudioConnection          patchCord16(decoder, 0, out, 0);
AudioConnection          patchCord17(decoder, 1, out, 1);

AudioControlSGTL5000 audioShield;

bool d = false, d2 = true;

int cnt = 0;

void setup() {
  
  AudioMemory(300);
  
  audioShield.enable();
  audioShield.volume(0.3);

  decoder.encode();

  mixer1.gain(0, 0.6);
  mixer1.gain(1, 0.8);
  mixer1.gain(2, 0.6);
  
  mixer2.gain(0, 0.7);
  mixer2.gain(1, 0.9);
  mixer2.gain(2, 0.3);
  
  sine.amplitude(1.0);
  
  sine_fm.amplitude(1.0);
  
  delays.delay(0, 100);
  
  envelope1.attack(1.5);
  envelope1.decay(50);
  envelope1.sustain(50);
  envelope1.release(50);
  
  envelope2.attack(0.5);
  envelope2.decay(1);
  envelope2.sustain(10);
  envelope2.release(10);
  
  pink.amplitude(1.0);
  
  gen.begin(1.0, 1.0, WAVEFORM_SAMPLE_HOLD); 
  
  lfo.begin(0.5, 1.0, WAVEFORM_SAMPLE_HOLD); 
  
  filter.resonance(4);
  filter.frequency(440);
  filter.octaveControl(2);
  
}

void loop() {

  int tempo = 60000 / BPM;
  
  if (d == true) { 
    kick.play(AudioSampleSnare);
    gen.frequency(rand()%2200);
    delays.delay(0,1+rand()%499);
  }
  
  sine.frequency(110 + rand()%880);
  
  sine_fm.frequency(rand()%4400);

  filter.frequency(rand()%440);
  
  if (cnt == 2+d2) {
    
    if (d2 == true) kick.play(AudioSampleHihat);
    else kick.play(AudioSampleKick);
    
    cnt = 0;
    d2 = !d2;
    
  }
  
  envelope1.noteOn();
  envelope2.noteOn();
  
  delay(5);
 
  envelope1.noteOff();
  envelope2.noteOff();
  
  delay((tempo / 4) - 5);
  envelope2.noteOn();

  delay(5);

  envelope2.noteOff(); 
  delay((tempo / 4) - 5);
  
  d = !d;
  cnt ++;

}