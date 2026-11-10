#pragma once

#include "types.h"
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

struct MBiParam;
extern struct MBiParam *gWirelessWork;
struct MB_CommPWork;
extern struct MB_CommPWork *mbc;
struct WorkerQueue;
extern struct WorkerQueue *gWorkerQueue;
extern struct MbRequestPieceBuf *gPieceBuffer;
extern u8 gLastPieceIndex;
extern PieceSizes gPieceSizes;
extern Unk02143a78 gScanParams;
