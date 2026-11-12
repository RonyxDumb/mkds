#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

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
