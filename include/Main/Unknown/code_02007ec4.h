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
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d[3];
} Unk020072c0_buf;

// 0x14 bytes at 0x1d2c of an entry of Unk0216fdac: three words, then four halfwords.
typedef struct ChunkTable {
    /* 00 */ u32 mRangeOffsets[3];
    /* 0c */ u16 mChunkStarts[4];
} ChunkTable;

// 0x10-byte entry of Unk020082b4.
typedef struct Unk020082b4_0c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk020082b4_0c;

// 0xe4-byte object that func_020082b4 sets up at 0x1788 of an entry of Unk0216fdac.
typedef struct Unk020082b4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ Unk020082b4_0c mUnk_0c[3];
    /* 3c */ u8 mUnk_3c[0x88];
    /* c4 */ u8 mUnk_c4[0x20];
} Unk020082b4;

// Object func_02008310 and func_020082b4 read; the DataRangeTable at 0x1e8 and the words at 0x258 go to the entry.
typedef struct Unk02008188 {
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
} Unk02008188;

void func_02007ec4(ScanBlock *record, u16 b, u16 c, u32 d, u32 e);
u32 func_02007f38(u32 rangeIndex, u32 address, u32 size);
u32 func_02007ff0(u32 rangeIndex, u32 address, u32 size);
BOOL func_0200806c(Unk020072c0_buf *result, void *b, u16 chunk, void *d);
u32 func_020080e8(ChunkTable *chunkTable, Unk020082b4 *record);
void func_02008188(Unk02008188 *source, u32 *kindWord, Unk020082b4_0c *range, u32 *nextAddress);
void func_020082b4(Unk020082b4 *record, Unk02008188 *source);
u32 func_02008310(void *rangeTable, Unk02008188 *source);
