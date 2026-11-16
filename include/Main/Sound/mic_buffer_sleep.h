#pragma once

#include "types.h"
#include "microphone_sampling.h" // MICAutoParam

typedef struct MicBuffer MicBuffer;

void Struct59C4Sub_SomeFn_3(MicBuffer *micBuffer);
void Struct59C4Sub_SomeFn_2(MicBuffer *micBuffer);

// MicBuffer.mSkipFrames: 0 analyses the samples; a sleep hook starts a count at one of the first two values, which
// Struct59C4Sub_SomeFn_1 raises by one per call while it is below the last, then returns to 0.
#define MICROPHONE_BUFFER_SKIP_FROM_PRE_SLEEP 1
#define MICROPHONE_BUFFER_SKIP_FROM_POST_SLEEP 2
#define MICROPHONE_BUFFER_SKIP_LAST 0x1e

// The microphone sample buffer with its auto-sampling setup; mSkipFrames counts input calls after a sleep hook.
typedef struct MicBuffer {
    /* 000 */ u8 mSamples[0x400];
    /* 400 */ MICAutoParam mAutoParam;
    /* 41c */ s32 mSkipFrames;
} MicBuffer;

u32 Struct59C4Sub_SomeFn_1(MicBuffer *micBuffer);
