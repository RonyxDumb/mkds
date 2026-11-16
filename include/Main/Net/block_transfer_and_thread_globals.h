#pragma once
#include "types.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "Main/Net/wireless_block_transfer.h"


extern u32 wbt_initialize_flag;

extern u8 gRequestId[1];

extern s16 gReceiveChunkSize;

extern s16 gSendChunkSize;

struct WBTBlockInfoList;

extern struct WBTBlockInfoList *g_GlobalGO;

struct BlockTransfer;

extern struct BlockTransfer gBlockTransfer;

struct WBTCommand;

struct ScanConnectWork;

struct MPLink;

extern u32 g_Os_ThreadDtorSp;

extern u32 g_Os_ThreadRescheduleCount;

// The number Os_AllocateThreadId last returned.
extern u32 g_CurrentThreadId;

extern void (*Os_Thread_OnThreadSwitch)(OSThread *, OSThread *);

extern OSThread **g_Os_CurrentThreadRef;

extern u32 g_Os_ThreadInit;

extern ThreadSystem g_Os_ThreadInfo;

extern OSThread g_IdleThread;
