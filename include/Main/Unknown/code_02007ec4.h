#pragma once

#include "types.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0217a000.h" // ScanBlock

// Filled by func_0200806c.
typedef struct Unk020072c0_buf {
    /* 00 */ u32 mChildAddress;
    /* 04 */ u32 mSize;
    /* 08 */ u32 mOffset;
    /* 0c */ u8 mSegmentNo;
    /* 0d */ u8 mUnk_0d[3];
} Unk020072c0_buf;

// 0x14 bytes at 0x1d2c of an entry of Unk0216fdac: three words, then four halfwords.
typedef struct ChunkTable {
    /* 00 */ u32 mRangeOffsets[3];
    /* 0c */ u16 mChunkStarts[4];
} ChunkTable;

// 0x10-byte entry of MBDownloadFileInfo.
typedef struct MbSegmentInfo {
    /* 00 */ u32 mRecvAddr;
    /* 04 */ u32 mLoadAddr;
    /* 08 */ u32 mSize;
    /* 0c */ u32 mTarget;
} MbSegmentInfo;

// 0xe4-byte object that MBi_MakeDownloadFileInfo sets up at 0x1788 of an entry of Unk0216fdac.
typedef struct MBDownloadFileInfo {
    /* 00 */ u32 mArm9EntryAddr;
    /* 04 */ u32 mArm7EntryAddr;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ MbSegmentInfo mSeg[3];
    /* 3c */ u8 mAuthCode[0x88];
    /* c4 */ u8 mReserved[0x20];
} MBDownloadFileInfo;

// Object MB_RegisterFile and MBi_MakeDownloadFileInfo read; the DataRangeTable at 0x1e8 and the words at 0x258 go to
// the entry.
typedef struct SegmentBuffer {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ u32 mUnk_024;
    /* 028 */ u32 mUnk_028[2];
    /* 030 */ u8 mUnk_030[4];
    /* 034 */ u32 mUnk_034;
    /* 038 */ u32 mUnk_038[2];
    /* 040 */ u8 mUnk_040[0x120];
    /* 160 */ u8 mUnk_160[0x88];
    /* 1e8 */ DataRangeTable mUnk_1e8;
    /* 258 */ u32 mUnk_258[1];
} SegmentBuffer;

void MB_ReadMultiBootParentBssDesc(ScanBlock *bssDesc, u16 parentMaxSize, u16 childMaxSize, u32 ksFlag, u32 flagTwo);
u32 IsAbleToLoad(u32 rangeIndex, u32 address, u32 size);
u32 MBi_IsAbleToRecv(u32 rangeIndex, u32 address, u32 size);
BOOL func_0200806c(Unk020072c0_buf *result, void *b, u16 chunk, void *d);
u32 MBi_MakeBlockInfoTable(ChunkTable *chunkTable, MBDownloadFileInfo *record);
void MBi_SetSegmentInfo(SegmentBuffer *source, u32 *kindWord, MbSegmentInfo *range, u32 *nextAddress);
void MBi_MakeDownloadFileInfo(MBDownloadFileInfo *record, SegmentBuffer *source);
u32 MB_RegisterFile(void *rangeTable, SegmentBuffer *source);
