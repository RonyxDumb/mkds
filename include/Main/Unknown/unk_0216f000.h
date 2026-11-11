#pragma once

#include "types.h"
#include "os_thread.h"
#include "mb_data.h"

// Objects whose layout isn't known yet.
extern u32 data_0216f06c;
extern char data_0216f2a0[];
extern s8 data_0216f2b0[];
extern const char data_0216f2d4[];
extern u32 wbt_initialize_flag;
extern u8 gRequestId[];
extern s16 gReceiveChunkSize;
extern s16 gSendChunkSize;
struct WBTBlockInfoList;
extern struct WBTBlockInfoList *gBlockListHead;
struct BlockTransfer;
extern struct BlockTransfer gBlockTransfer;
struct WBTCommand;
extern struct WBTCommand gNextRequest;
extern u16 gScanConnectInitialized;
struct ScanConnectWork;
extern struct ScanConnectWork *gScanConnectWork;
struct MPLink;
extern struct MPLink *gMPLink;
extern u8 data_0216f2dc[];
extern u8 OverlaySignatures[][0x14];

// 1 while the main display is on; GX_DispOff clears it, GX_DispOn sets it, GX_SetGraphicsMode writes mode 0 while it is
// 0 and clears it when its first argument is 0. Initial value 1.
extern u8 gDispOn[];
extern u32 GXi_DmaId;
extern s32 sDayOfYear[12];

extern u32 data_0216ff44;
extern u32 data_0216ff48;
// The number OSi_GetUnusedThreadId last returned.
extern u32 gThreadIdCount;
extern void (*data_0216ff50)(OSThread *, OSThread *);
extern OSThread **data_0216ff54;
extern u32 data_0216ff58;
extern ThreadSystem OSi_ThreadInfo;
extern OSThread data_0216ff6c;
