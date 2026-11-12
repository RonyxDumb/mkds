#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217d000.h" // SeqPlayerControl
#include "player.h"

void StopSndHandleSeq(NNSSndSeqPlayer **handle, u32 fadeSteps);
void StartSeqOnHandleIfEnabled(u32 soundId, NNSSndSeqPlayer **handle);
void UpdateSeqPlayerControl(SeqPlayerControl *control, NNSSndSeqPlayer **handle);
