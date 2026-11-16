#pragma once

#include "types.h"

typedef struct MultiBootStateView MultiBootStateView;
typedef struct MBUserInfo MBUserInfo;

void ReadMultiBootParentBssDesc(void);
void ReadFakeParentBssDesc(u16 entryIndex);
void StartConnectToScanEntry(u16 entryIndex);
void StartRequestEndScan(void);
void StructZE_StateFn22_23_24_25_from_thumb(void);
void StartBootRequestToAllChildren(void);
void StartSendingToAllChildren(void);
s32 AdvanceMultiBootSetup(s32 isParent);
s32 AdvanceMultiBootScanSetup(void);
s32 AdvanceMultiBootParentSetup(void);
void ScanConnectStateCallback(u32 state, void *info);
void RepeatedScanCallback(u32 code, void *args);
s32 FindScanEntryIndex(u32 entryIndex);
void StartRepeatedScanStep1E(void);
void StartRepeatedScanStep1D(void);
void StructZE_StateFn_28_29_30_33_34_35_from_thumb(void);
void SetupScanConnect(void);
void StartMultiBootParent(void);
void StructBin_SomeFn_from_thumb(MultiBootStateView *view);
void ParentStateCallback(u32 index, u32 code, void *data);
void AllocConnectionBuffers(void *heap, u32 unused, void *bmg);
