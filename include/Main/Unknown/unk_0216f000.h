#pragma once

#include "types.h"
#include "os_thread.h"
#include "code_02142eac.h" // Unk02143a78

// Three words that MBi_SetChildMPMaxSize sets up.
typedef struct PieceSizes {
    /* 00 */ s32 mPieceSize;
    /* 04 */ s32 mPieceCount;
    /* 08 */ s32 mUnk_08;
} PieceSizes;

// Object behind gPieceBuffer (also the member of MB_CommPWork at 0x1538): the words from 0x1e0 on are indexed like the
// 0x20-byte entries before them.
typedef struct MbRequestPieceBuf {
    /* 000 */ u8 mDataBuf[0x1e0];
    /* 1e0 */ u32 mDataBmp[15];
} MbRequestPieceBuf;

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
struct MBiParam;
extern struct MBiParam *gWirelessWork;
struct MB_CommPWork;
extern struct MB_CommPWork *mbc;
struct WorkerQueue;
extern struct WorkerQueue *gWorkerQueue;
extern u16 gScanConnectInitialized;
struct ScanConnectWork;
extern struct ScanConnectWork *gScanConnectWork;
struct MPLink;
extern struct MPLink *gMPLink;
struct MbRequestPieceBuf;
extern struct MbRequestPieceBuf *gPieceBuffer;
extern u8 gLastPieceIndex;
extern PieceSizes gPieceSizes;
extern u8 data_0216f2dc[];
extern u8 OverlaySignatures[][0x14];

// 1 while the main display is on; GX_DispOff clears it, GX_DispOn sets it, GX_SetGraphicsMode writes mode 0 while it is
// 0 and clears it when its first argument is 0. Initial value 1.
extern u8 gDispOn[];
extern u32 data_0216f074[];
extern Unk02143a78 gScanParams;

extern u32 data_0216ff44;
extern u32 data_0216ff48;
// The number OSi_GetUnusedThreadId last returned.
extern u32 gThreadIdCount;
extern void (*data_0216ff50)(OSThread *, OSThread *);
extern OSThread **data_0216ff54;
extern u32 data_0216ff58;
extern ThreadSystem data_0216ff5c;
extern OSThread data_0216ff6c;
