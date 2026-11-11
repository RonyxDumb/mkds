#pragma once

#include "types.h"

typedef struct MultiBootStateView MultiBootStateView;

// Twenty bytes after a two-byte head.
typedef struct Unk0204e4d8 {
    /* 00 */ union {
        u8 mUnk_00;
        struct {
            u8 mUnk_00_0 : 4;
            u8 mUnk_00_4 : 4;
        };
    };
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[0x14];
} Unk0204e4d8;

void ReadMultiBootParentBssDesc(void);
void ReadFakeParentBssDesc(u32 entryIndex);
void StartConnectToScanEntry(u32 entryIndex);
void StartRequestEndScan(void);
void StartEndToIdle(void);
void StartBootRequestToAllChildren(void);
void StartSendingToAllChildren(void);
s32 AdvanceMultiBootSetup(s32 a);
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
void ParentStateCallback(u32 index, u32 code, Unk0204e4d8 *childInfo);
void AllocConnectionBuffers(void *heap, u32 unused, void *bmg);
