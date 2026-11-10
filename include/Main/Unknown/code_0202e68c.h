#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

void ScrollListMI_CpuClearFast(void *dest, u32 size);
void ScrollListMI_CpuFillFast(void *dest, u32 value, u32 size);
void AdvanceScrollListPick(void);
void AdvanceScrollListScrollDown(void);
void AdvanceScrollListScrollUp(void);
void AdvanceScrollListSelectDown(void);
void AdvanceScrollListSelectUp(void);
void AdvanceScrollListState0(void);
u16 ScrollListGetDownBits(u32 slotIndex, u32 mask);
u16 GetSlotDownBits(InputSlot *slot, u32 mask);
