#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

unsigned int MenuGetPairHasPair(InputSlotPair *pair);

u32 StartMenuSound(u32 seqIndex);

u32 MenuStartSeqArc(u32 seqIndex, u32 seqArcNo);
