#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

// Results of GetRaceEndResultKind, which picks the race end seq: best (first place, or a new record in time attack),
// won without being best, and lost.
#define RACE_END_RESULT_BEST 0
#define RACE_END_RESULT_WON 1
#define RACE_END_RESULT_LOST 2

// Calls of UpdateRaceEndSeq after which the follow-up seq starts, for a lost result and for the others.
#define RACE_END_NEXT_SEQ_CALLS_LOST 0x91
#define RACE_END_NEXT_SEQ_CALLS 0x82

void UpdateRaceEndSeq(void);
s32 GetKartSeqArcSoundOffsetByRank(s32 kartRank);
s32 GetRaceEndResultKind(void);
void MaybePlayCrowdAmbientNoise(s32 unused);
s32 GetLastLapCourseSoundId(void);
void SetKartModelMenuInputSeqs(s32 firstSeqChoice, s32 secondSeqEnabled);
void ResetEmblemSoundCounters(void);
void StartEmblemSound(s32 soundValue);

extern s32 gRaceEndSeqCallCount;
extern s32 gRaceEndNextSeqPending;
extern s32 gRaceEndSeqStarted;
extern SeqRowState g_GlobalCX;
