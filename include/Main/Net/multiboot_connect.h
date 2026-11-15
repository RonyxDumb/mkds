#pragma once

#include "types.h"

typedef struct MultiBootStateView MultiBootStateView;
typedef struct MBUserInfo MBUserInfo;

void ReadMultiBootParentBssDesc(void);
void ReadFakeParentBssDesc(u16 entryIndex);
void StartConnectToScanEntry(u16 entryIndex);
void StartRequestEndScan(void);
void StartEndToIdle(void);
void StartBootRequestToAllChildren(void);
void StartSendingToAllChildren(void);
s32 AdvanceMultiBootSetup(s32 isParent);
s32 AdvanceMultiBootScanSetup(void);
s32 AdvanceMultiBootParentSetup(void);
void ScanConnectStateCallback(u32 state);
void RepeatedScanCallback(u32 code);
s32 FindScanEntryIndex(u32 entryIndex);
void StartRepeatedScanStep1E(void);
void StartRepeatedScanStep1D(void);
void StartCloseScanConnect(void);
void SetupScanConnect(void);
void StartMultiBootParent(void);
void ResetConnectionBuffers(MultiBootStateView *view);
void ParentStateCallback(u32 index, u32 code, MBUserInfo *childInfo);
void AllocConnectionBuffers(void *heap, u32 unused, void *bmg);
