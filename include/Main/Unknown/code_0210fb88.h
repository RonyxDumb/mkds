#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217d000.h" // SeqPlayerControl
#include "code_0212bcac.h"

void StopSndHandleSeq(NNSSndSeqPlayer **handle, u32 fadeSteps);
void sub_211003C(u32 soundId, NNSSndSeqPlayer **handle);
void sub_210FB88(SeqPlayerControl *control, NNSSndSeqPlayer **handle);
