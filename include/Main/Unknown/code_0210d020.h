#pragma once

#include "types.h"
#include "code_0212bcac.h"

typedef struct SoundParams SoundParams;

void sfx_210D020(s32 (*volumeFunction)(SoundParams *));
void sfx_210D030(u32 (*distanceFunction)(SoundParams *));
void sfx_210D040(s32 (*panFunction)(SoundParams *));
void sound_startSeqArcWithPriority(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 soundId, u32 priority);
