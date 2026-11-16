#pragma once

#include "types.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/unk_0217d000.h"

void sound_startOutputEffect(u32 type);
void sound_changeOutputEffect(s32 type);
void sound_startSeq(u32 seqNo, u32 volume, NNSSndSeqPlayer **handle);
void sub_210D7AC(void);
void sub_210D740(ScenePlayers *scenePlayers, SceneSoundState *sceneSoundState, u32 c, Unk021073ec d);
