#pragma once

#include "types.h"
#include "mic.h" // MICAutoParam

typedef struct MicBuffer MicBuffer;

void PostSleepMicBuffer(MicBuffer *micBuffer);
void PreSleepMicBuffer(MicBuffer *micBuffer);

// MicBuffer.mSkipFrames: 0 analyses the samples; a sleep hook starts a count at one of the first two values, which
// UpdateMicBufferInput raises by one per call while it is below the last, then returns to 0.
#define MIC_BUFFER_SKIP_FROM_PRE_SLEEP 1
#define MIC_BUFFER_SKIP_FROM_POST_SLEEP 2
#define MIC_BUFFER_SKIP_LAST 0x1e

// Object UpdateMicBufferInput and SetupMicAutoSampling take, 0x420 bytes: SetupMicAutoSampling zeroes 0x400 bytes and
// sets up the words at 0x400..0x418; mSkipFrames counts calls: a sleep hook starts it, input returns 0 to 0x1e.
typedef struct MicBuffer {
    /* 000 */ u8 mSamples[0x400];
    /* 400 */ MICAutoParam mAutoParam;
    /* 41c */ s32 mSkipFrames;
} MicBuffer;

u32 UpdateMicBufferInput(MicBuffer *micBuffer);
