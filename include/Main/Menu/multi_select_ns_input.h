#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;
typedef struct InputSlotPair InputSlotPair;

void MultiSelectNSG2S_SetWndOutsidePlane(u32 lowBits, u32 extraBitFlag);
void MultiSelectNSG2S_SetWnd0InsidePlane(u32 lowBits, u32 extraBitFlag);
void MultiSelectNSWriteSubWinEnableBits(u32 bits);
void MultiSelectNSGXS_SetVisiblePlane(u32 bits);
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
