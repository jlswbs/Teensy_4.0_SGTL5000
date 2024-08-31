// Audio PureData wraper for Teensy //

#ifndef audio_puredata_h_
#define audio_puredata_h_

#include <Arduino.h>
#include <AudioStream.h>

class AudioProcessor : public AudioStream
{
public:
  AudioProcessor(void) : AudioStream(0, NULL) {  }
  virtual void update(void);

private:

};

#endif