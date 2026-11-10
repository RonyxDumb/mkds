#pragma once

#include "types.h"

typedef struct BlockTransferRecord BlockTransferRecord;
typedef struct Unk0217aa00_24_50 Unk0217aa00_24_50;

void SendWordRequestCallback(BlockTransferRecord *record);
void StartSendWordRequest(u16 indexMask, s32 value);
BOOL CopySingleChildName(void *destination);
BOOL TryGetScanGhostInfo(u8 entryIndex, void *destination, u8 *kartIndex, u8 *characterIndex, u8 *courseId, u8 *minute,
                         u8 *second, u16 *millisecond);
void SetScanGhostInfo(u32 entryIndex, Unk0217aa00_24_50 *gameInfo);
void StopBlockTransferStep(void);
