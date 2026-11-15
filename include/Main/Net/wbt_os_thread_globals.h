#pragma once
#include "types.h"
#include "thread_scheduler.h"
#include "mb_data.h"
#include "Main/Net/wbt_block_transfer.h"

// Objects whose layout isn't known yet.

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

extern u32 OSi_StackForDestructor;

extern u32 OSi_RescheduleCount;

// The number OSi_GetUnusedThreadId last returned.
extern u32 gThreadIdCount;

extern void (*OSi_SystemCallbackInSwitchThread)(OSThread *, OSThread *);

extern OSThread **OSi_CurrentThreadPtr;

extern u32 OSi_IsThreadInitialized;

extern ThreadSystem OSi_ThreadInfo;

extern OSThread OSi_IdleThread;
