#pragma once

#include "types.h"
#include "Main/Unknown/code_0210b000.h" // Unk0210b7a8, SoundDistanceSquaredChange
#include "code_0212bcac.h"

void sub_210B760(Unk0210b7a8 *request, NNSSndSeqPlayer **handle);
void sub_210B7A8(Unk0210b7a8 *request);
void AdvanceSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker, u32 distanceSquared);
