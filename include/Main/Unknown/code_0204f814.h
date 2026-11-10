#pragma once

#include "types.h"

typedef struct GhostRecordHead GhostRecordHead;

void SetParentChannelLowestSum(void);
void SetGroupSendMaskAsParent(u8 sendMask);
void FillGhostParentParameter(GhostRecordHead *ghostRecord);
void FillParentParameter(s32 a);
BOOL TryGetPlayerName(u16 entryIndex, void *destination);
s32 GetScanSlotChildCount(u16 entryIndex);
BOOL IsScanSlotMultiBoot(u16 entryIndex);
BOOL TryGetScanSlotName(u16 entryIndex, void *destination);
BOOL IsDataSharingSyncDone(void);
u16 GetParticipantPadKeys(u32 participantIndex);
