#pragma once
#include "types.h"

// The race start countdown: whether it is counting, whether it is done and the frames counted so far.
typedef struct RaceStartSequence {
    // Counter gate: FALSE at allocation and in ResetRaceStartSequenceFrames; set TRUE by UpdateRaceStartSequence when
    // FinishDataSharingSync()
    // == 1 (in mode 5: when gWiFiRaceSync.mFlags & 2, with SetRaceUpdateFramesUnlimited /
    // SetMapObjectsRunUpdateLists) and never cleared otherwise.
    /* 00 */ BOOL mCounting;
    // Set to 1 once, at frame 180; 0 at allocation, never cleared; read by IsRaceStartSequenceDone.
    /* 04 */ s32 mDone;
    // -0x78 after ResetRaceStartSequenceFrames; +1 per call of UpdateRaceStartSequence while mCounting; saturates only
    // at the largest s32 (the 200 limit ends the one-shot checks, not the count).
    /* 08 */ s32 mSequenceFrames;
} RaceStartSequence;

