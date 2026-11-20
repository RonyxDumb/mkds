#pragma once
#include "types.h"

// The race start countdown: whether it is counting, whether it is done and the frames counted so far.
typedef struct RaceStartSequence {
    // Whether the frames count up: FALSE at allocation and in ResetRaceStartSequenceFrames; UpdateRaceStartSequence
    // sets it TRUE in MODE_WIFI when WiFiRaceSync.mFlags has WIFI_RACE_SYNC_FLAG_IN_RACE (and calls
    // SetRaceUpdateFramesUnlimited and SetMapObjectsRunUpdateLists), else when FinishDataSharingSync() == 1; nothing
    // else clears it.
    /* 00 */ BOOL mCounting;
    // Set to 1 once, at frame 180; 0 at allocation, never cleared; read by IsRaceStartSequenceDone.
    /* 04 */ s32 mDone;
    // 0 at allocation, -0x78 after ResetRaceStartSequenceFrames; +1 per call of UpdateRaceStartSequence while
    // mCounting; saturates only at the largest s32 (the 200 limit ends the one-shot checks, not the count).
    /* 08 */ s32 mSequenceFrames;
} RaceStartSequence;

