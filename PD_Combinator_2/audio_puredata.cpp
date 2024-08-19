// Audio PureData wraper for Teensy //
 
#include "audio_puredata.h"
#include "Heavy_prog.hpp"

Heavy_prog pd_prog(AUDIO_SAMPLE_RATE);

void AudioProcessor::update(void) {
  
  audio_block_t *blockL, *blockR;
  float outL, outR;
  float buf_out[2];
  float buf_in[2];
  unsigned int i;

  blockL = allocate();
  if (!blockL) return;
  blockR = allocate();
  if (!blockR) return;

  for (i=0; i < AUDIO_BLOCK_SAMPLES; i++) {

    pd_prog.processInlineInterleaved(buf_in, buf_out, 1);

    outL = 32768.0f * buf_out[0];
    outR = 32768.0f * buf_out[1];

    blockL->data[i] = outL;
    blockR->data[i] = outR;

  }

  transmit(blockL,0);
  transmit(blockR,1);
  release(blockL);
  release(blockR);

}