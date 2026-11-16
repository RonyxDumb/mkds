#pragma once

#include "types.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/unk_0217d000.h"

void sound_startOutputEffect(u32 type);
void sound_changeOutputEffect(s32 type);
void sound_startSeq(u32 seqNo, u32 volume, NNSSndSeqPlayer **handle);
void func_0210d7ac(void);
void func_0210d740(ScenePlayers *scenePlayers, SceneSoundState *sceneSoundState, u32 c, Unk021073ec d);
