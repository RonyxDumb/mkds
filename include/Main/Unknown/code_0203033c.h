#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;
typedef struct InputSlotPair InputSlotPair;

void func_0203033c(u32 lowBits, u32 extraBitFlag);
void func_02030364(u32 lowBits, u32 extraBitFlag);
void MultiSelectNSWriteSubWinEnableBits(u32 bits);
void func_020303a8(u32 bits);
void ReleaseMultiSelectNS(void);
s32 AdvanceMultiSelectNS(void);
void MultiSelectNSStartSeqArcWrapper(u32 index);
void MultiSelectNSStartSeqArc(u32 index, u32 seqArcNo);
void MultiSelectNSStartOnMemorySeqArc(u32 index);
u32 MultiSelectNSGetNewBits(u32 slotIndex, u32 mask);
u16 MultiSelectNSGetInputSlotNewBits(InputSlot *slot, u32 mask);
u32 MultiSelectNSGetSlotPairY(u32 slotIndex);
unsigned int MultiSelectNSGetPairY(InputSlotPair *pair);
u32 MultiSelectNSGetSlotPairX(u32 slotIndex);
unsigned int MultiSelectNSGetPairX(InputSlotPair *pair);
