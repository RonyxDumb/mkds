#pragma once

#include "types.h"
#include "code_02142eac.h" // ScanParam

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
struct MB_CommPWork;
struct WorkerQueue;
