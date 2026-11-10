#pragma once

#include "types.h"
#include "mic.h" // MICAutoParam

// Object UpdateMicBufferInput and SetupMicAutoSampling take, 0x420 bytes: SetupMicAutoSampling zeroes 0x400 bytes and
// sets up the words at 0x400..0x418; UpdateMicBufferInput steps a signed number at 0x41c to 0x1e and then resets it.
typedef struct MicBuffer {
    /* 000 */ u8 mSamples[0x400];
    /* 400 */ MICAutoParam mAutoParam;
    /* 41c */ s32 mSkipCount;
} MicBuffer;

u32 UpdateMicBufferInput(MicBuffer *micBuffer);
