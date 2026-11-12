#pragma once

#include "types.h"

typedef struct SlotResultSyncState SlotResultSyncState;

void CopySlotResultToPending(SlotResultSyncState *syncState);

void SetParticipantHeldItem(s32 participantIndex, s32 itemInfoIndex, s32 count);
void ResetParticipantHeldItem(u32 participantIndex);
BOOL ApplyParticipantPendingItem(s32 participantIndex);
void InitSlotResultSyncStates(void);
void StartParticipantResultPending(s32 participantIndex);
void StartOwnSlotResultSync(s32 itemIndex);
void ClearSendSlotResultSync(s32 participantIndex);
void SetSendSlotResultSync(s32 participantIndex, u16 remaining, s32 itemIndex, s32 state);
void AddItemData(u32 itemKind, u32 messageKind, void *data, u8 size);
