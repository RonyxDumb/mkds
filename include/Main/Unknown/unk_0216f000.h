#pragma once

#include "types.h"
#include "os_thread.h"
#include "code_02142eac.h" // Unk02143a78

// Three words that SetupPieceSizes sets up.
typedef struct PieceSizes {
    /* 00 */ s32 mPieceSize;
    /* 04 */ s32 mPieceCount;
    /* 08 */ s32 field8;
} PieceSizes;

// Object behind gPieceBuffer: the words from 0x1e0 on are indexed like the 0x20-byte entries before them.
typedef struct PieceBuffer {
    /* 000 */ u8 mSlots[0x1e0];
    /* 1e0 */ u32 mReceivedPieceMasks[15];
} PieceBuffer;

// Objects whose layout isn't known yet.
extern u32 data_0216f06c;
extern char aSCCCCS[];
extern s8 a0123456789abcd[];
extern const char a012llu[];
extern u32 gBlockTransferStarted;
extern u8 gRequestId[];
extern s16 gReceiveChunkSize;
extern s16 gSendChunkSize;
struct BlockListNode;
extern struct BlockListNode *gBlockListHead;
extern u8 gBlockTransfer[];
extern u8 gNextRequest[];
struct WirelessWork;
extern struct WirelessWork *gWirelessWork;
struct Unk0216fdac;
extern struct Unk0216fdac *data_0216fdac;
struct WorkerQueue;
extern struct WorkerQueue *ctrdgi_task_work;
extern u8 mbf_initialize[];
struct ScanConnectWork;
extern struct ScanConnectWork *mbf_work;
struct MPLink;
extern struct MPLink *gMPLink;
struct PieceBuffer;
extern struct PieceBuffer *gPieceBuffer;
extern u8 gLastPieceIndex;
extern PieceSizes gPieceSizes;
extern u8 g_SomeDigest[];
extern u8 OverlaySignatures[][0x14];

// 1 while the NitroMain display is on; GX_DispOff clears it, GX_DispOn sets it, GX_SetGraphicsMode writes mode 0 while it is
// 0 and clears it when its first argument is 0. Initial value 1.
extern u8 gDispOn[];
extern u32 GXi_DmaId[];
extern void (*gClearBssidCallback)(void);
extern void (*gSetBssidCallback)(u8 *);
extern Unk02143a78 gScanParams;

extern u32 g_Os_ThreadDtorSp;
extern u32 g_Os_ThreadRescheduleCount;
// The number OSi_GetUnusedThreadId last returned.
extern u32 OSi_ThreadIdCount;
extern void (*data_0216ff50)(OSThread *, OSThread *);
extern OSThread **g_Os_CurrentThreadRef;
extern u32 g_Os_ThreadInit;
extern ThreadSystem OSi_ThreadInfo;
extern OSThread g_IdleThread;
