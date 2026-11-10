#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h" // GhostRecordInfo

void InitTimeAttackGhostGetScan(void *parentHeap, void *mainOam, void *subOam);
BOOL AreGhostRecordInfosDifferent(GhostRecordInfo *storedInfo, GhostRecordInfo *newInfo);
void RefreshScanEntryPalettes(void);
void RefreshScanSelectedGhostInfo(void);
void UpdateScanSlideOffsets(void);
void UpdateScanEntryOffsetX(void);
void UpdateScanSelectedIndex(void);
