#pragma once
#include "types.h"

// The race start countdown: whether it is counting, whether it is done and the frames counted so far.
typedef struct RaceStartSequence {
    // Counter gate: FALSE at allocation and in MaybeClearGlobalB358; set TRUE by IncreaseB358Countdown when
    // FinishDataSharingSync()
    // == 1 (in mode 5: when g_GlobalAA.mFlags & 2, with SetRaceUpdateFramesUnlimited /
    // SetMapObjectsRunUpdateLists) and never cleared otherwise.
    /* 00 */ BOOL mCounting;
    // Set to 1 once, at frame 180; 0 at allocation, never cleared; read by IsRaceCountdownEnded.
    /* 04 */ s32 mDone;
    // -0x78 after MaybeClearGlobalB358; +1 per call of IncreaseB358Countdown while mCounting; saturates only
    // at the largest s32 (the 200 limit ends the one-shot checks, not the count).
    /* 08 */ s32 mSequenceFrames;
} RaceStartSequence;

