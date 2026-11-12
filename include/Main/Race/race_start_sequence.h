#pragma once

#include "types.h"
#include "Main/Race/data_0217b358.h"

void ResetRaceStartSequenceFrames(void);
void UpdateRaceStartSequence(void);
void UpdateRaceStartSequenceSounds(void);
s32 GetRaceStartSequenceFrames(void);
s32 IsRaceStartSequenceDone(void);

void ClearRaceStartSequencePointer(void);

void InitRaceStartSequence(void);

extern struct RaceStartSequence *gRaceStartSequence;
