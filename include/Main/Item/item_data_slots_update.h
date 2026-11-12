#pragma once

#include "types.h"

void UpdateItemDataSlots(void);

void ProcessOtherParticipantItemData(void);
void StoreReceivedItemDataSlots(void);
void ExpireItemDataSlots(void);
void WriteItemDataSlotsToSendBuffer(void);
BOOL IsAnyItemDataSlotFree(void);
void ResetItemDataSlots(void);
void SubtractDroppedFromRank(u32 kartIndex);
