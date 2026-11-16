#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

// Results of GetRaceEndResultKind, which picks the race end seq: best (first place in a grand prix, WiFi or VS race, a
// win in a win-count VS, mission run or battle, a won time attack with a first record), won but not best, and lost.
#define RACE_END_RESULT_BEST 0
#define RACE_END_RESULT_WON 1
#define RACE_END_RESULT_LOST 2

// Counted calls of UpdateRaceEndSeq (only while the race end seq has started and no scene seq plays) after which the
// follow-up seq starts, for a lost result and for the others.
#define RACE_END_NEXT_SEQ_CALLS_LOST 0x91
#define RACE_END_NEXT_SEQ_CALLS_NOT_LOST 0x82

void UpdateRaceEndSeq(void);
s32 GetKartSeqArcSoundOffsetByRank(s32 kartRank);
s32 GetRaceEndResultKind(void);
void StartRaceEndSeq(s32 unused);
s32 GetLastLapCourseSoundId(void);
void SetKartModelMenuInputSeqs(s32 firstSeqChoice, s32 secondSeqEnabled);
void ResetEmblemSoundCounters(void);
void StartEmblemSound(s32 soundValue);

extern s32 gRaceEndSeqCallCount;
extern s32 gRaceEndNextSeqPending;
extern s32 gRaceEndSeqStarted;
extern SeqRowState gSeqRowState;
