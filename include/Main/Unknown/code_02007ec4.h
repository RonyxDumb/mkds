#pragma once

#include "types.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"

// 0xc0-byte record: the first 0x3c bytes are taken from 0x027ffc42 when the halfword at 0x027ffc40 is 2 (or from
// address 0); the halfwords at 0x4c and 0x4e and the bytes from 0x4a are set by func_02007ec4 and MB_FakeReadParentBssDesc.
typedef struct ScanBlock {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[0x2a];
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u8 mUnk_3e[2];
    /* 40 */ u16 mUnk_40;
    /* 42 */ u8 mUnk_42[2];
    /* 44 */ u32 mUnk_44;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u8 mUnk_4a;
    /* 4b */ u8 mUnk_4b;
    /* 4c */ u16 mUnk_4c;
    /* 4e */ u16 mUnk_4e;
    /* 50 */ u8 mUnk_50[0x70];
} ScanBlock;

// Filled by MBi_get_blockinfo.
typedef struct Unk020072c0_buf {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d[3];
} Unk020072c0_buf;

// 0x14 bytes at 0x1d2c of an entry of Unk0216fdac: three words, then four halfwords.
typedef struct ChunkTable {
    /* 00 */ u32 mUnk_00[3];
    /* 0c */ u16 mUnk_0c[4];
} ChunkTable;

// 0x10-byte entry of Unk020082b4.
typedef struct Unk020082b4_0c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk020082b4_0c;

// 0xe4-byte object that MBi_MakeDownloadFileInfo sets up at 0x1788 of an entry of Unk0216fdac.
typedef struct Unk020082b4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ Unk020082b4_0c mUnk_0c[3];
    /* 3c */ u8 mUnk_3c[0x88];
    /* c4 */ u8 mUnk_c4[0x20];
} Unk020082b4;

// Object MB_RegisterFile and MBi_MakeDownloadFileInfo read; the DataRangeTable at 0x1e8 and the words at 0x258 go to the entry.
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
u32 IsAbleToLoad(u32 rangeIndex, u32 address, u32 size);
u32 MBi_IsAbleToRecv(u32 rangeIndex, u32 address, u32 size);
BOOL MBi_get_blockinfo(Unk020072c0_buf *result, void *b, u16 chunk, void *d);
u32 MBi_MakeBlockInfoTable(ChunkTable *chunkTable, Unk020082b4 *record);
void MBi_SetSegmentInfo(Unk02008188 *source, u32 *kindWord, Unk020082b4_0c *range, u32 *nextAddress);
void MBi_MakeDownloadFileInfo(Unk020082b4 *record, Unk02008188 *source);
u32 MB_RegisterFile(void *rangeTable, Unk02008188 *source);
