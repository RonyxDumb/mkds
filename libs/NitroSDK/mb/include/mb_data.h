#pragma once

#include "types.h"
#include "wireless_link_control.h" // ScanParam

// Three words that MBi_SetChildMPMaxSize sets up.
typedef struct PieceSizes {
    /* 00 */ s32 mPieceSize;
    /* 04 */ s32 mPieceCount;
    /* 08 */ s32 mBufSize;
} PieceSizes;

// The piece buffer of a multiboot request: mDataBuf and the bitmap (mDataBmp) of the pieces received.
typedef struct MbRequestPieceBuf {
    /* 000 */ u8 mDataBuf[0x1e0];
    /* 1e0 */ u32 mDataBmp[15];
} MbRequestPieceBuf;

struct MBiParam;
struct MB_CommPWork;
struct WorkerQueue;
