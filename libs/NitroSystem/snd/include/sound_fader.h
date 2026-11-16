#pragma once

#include "types.h"
#include "sound_archive_load.h"

// A fader: it fades a value from mOrigin to mTarget over mFrame steps.
typedef struct NNSSndFader {
    /* 00 */ s32 mOrigin;
    /* 04 */ s32 mTarget;
    /* 08 */ s32 mCounter;
    /* 0c */ s32 mFrame;
} NNSSndFader;

NNSSndSeqArcSeqInfo *NNSi_SndSeqArcGetSeqInfo(NNSSndSeqArc *archive, s32 entry);
u32 NNSi_SndFaderIsFinished(NNSSndFader *fade);
void NNSi_SndFaderUpdate(NNSSndFader *fade);
s32 NNSi_SndFaderGet(NNSSndFader *fade);
void NNSi_SndFaderSet(NNSSndFader *fade, s32 target, s32 steps);
