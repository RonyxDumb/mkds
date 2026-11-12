#pragma once
#include "types.h"
#include "os_thread.h"
#include "mb_data.h"
#include "Main/Net/wbt_block_transfer.h"

// Objects whose layout isn't known yet.

extern char data_0216f2a0[];

extern s8 data_0216f2b0[];

extern const char data_0216f2d4[];

extern u32 wbt_initialize_flag;

extern u8 gRequestId[1];

extern s16 gReceiveChunkSize;

extern s16 gSendChunkSize;

struct WBTBlockInfoList;

extern struct WBTBlockInfoList *gBlockListHead;

struct BlockTransfer;

extern struct BlockTransfer gBlockTransfer;

struct WBTCommand;



struct ScanConnectWork;


struct MPLink;


extern u8 SDK_OVERLAYTABLE_DIGEST[];

extern u8 OverlaySignatures[][0x14];

extern u32 GXi_DmaId;

extern s32 sDayOfYear[12];

extern u32 OSi_StackForDestructor;

extern u32 OSi_RescheduleCount;

// The number OSi_GetUnusedThreadId last returned.
extern u32 gThreadIdCount;

extern void (*OSi_SystemCallbackInSwitchThread)(OSThread *, OSThread *);

extern OSThread **OSi_CurrentThreadPtr;

extern u32 OSi_IsThreadInitialized;

extern ThreadSystem OSi_ThreadInfo;

extern OSThread OSi_IdleThread;
