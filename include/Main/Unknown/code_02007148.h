#pragma once

#include "types.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200aeb4.h"

struct Unk02008188;

// The 0x16 bytes at 0x1300 of Unk0216fdac: a count at field1 and that many halfwords from field2.
typedef struct Unk02009ff4 {
    /* 00 */ u8 field0;
    /* 01 */ u8 field1;
    /* 02 */ u16 field2[10];
} Unk02009ff4;

// One of the 15 entries of 0x16 bytes in field1340 of Unk0216fdac.
typedef struct Unk0216fdac_1340 {
    /* 00 */ u8 field0_0 : 4;
    /* 00 */ u8 field0_4 : 4;
    /* 01 */ u8 field1[0x15];
} Unk0216fdac_1340;

// Object behind data_0216fdac. The members from 0x1788 on are reached from a pointer advanced in steps of 0x5d4
// bytes, so their offsets here include the 0x1788.
typedef struct Unk0216fdac {
    /* 0000 */ u8 field0[0x1300];
    /* 1300 */ Unk02009ff4 field1300;
    /* 1316 */ u16 field1316;
    /* 1318 */ s32 field1318;
    /* 131c */ u32 field131C;
    /* 1320 */ u32 field1320;
    /* 1324 */ u8 field1324[0x1340 - 0x1324];
    /* 1340 */ u8 field1340[0x14a];
    /* 148a */ u16 field148A[15];
    /* 14a8 */ u32 field14A8[15];
    /* 14e4 */ void (*mCallback)(u32, u32, void *);
    /* 14e8 */ u32 field14E8[15];
    /* 1524 */ u8 mEntryCount;
    /* 1525 */ u8 field1525;
    /* 1526 */ s8 mChildEntryIndex[15];
    /* 1535 */ u8 field1535;
    /* 1536 */ u16 field1536;
    /* 1538 */ u8 field1538[0x1754 - 0x1538];
    /* 1754 */ u16 field1754[15];
    /* 1772 */ u8 field1772[0x16];
    /* 1788 */ u8 field1788[0x1d1f - 0x1788];
    /* 1d1f */ u8 field1D1F;
    /* 1d20 */ u8 field1D20;
    /* 1d21 */ u8 field1D21;
    /* 1d22 */ u8 field1D22[0x1d2c - 0x1d22];
    /* 1d2c */ u8 field1D2C[0x14];
    /* 1d40 */ DataRangeTable *field1D40;
    /* 1d44 */ struct Unk02008188 *field1D44;
    /* 1d48 */ u16 field1D48;
    /* 1d4a */ u16 field1D4A;
    /* 1d4c */ u16 field1D4C;
    /* 1d4e */ u16 field1D4E;
    /* 1d50 */ u16 field1D50;
    /* 1d52 */ u8 mEntryUsed;
    /* 1d53 */ u8 field1D53;
    /* 1d54 */ DataRangeTable *field1D54;
    /* 1d58 */ u32 *field1D58;
    /* 1d5c */ u8 field1D5C[0x74c8 - 0x1d5c];
    /* 74c8 */ s32 field74C8;
    /* 74cc */ u8 field74CC[0x74e0 - 0x74cc];
    /* 74e0 */ WorkerQueue field74E0;
    /* ---- */ u8 mUnk_74e0_end[0x800 - sizeof(WorkerQueue)];
    /* 7ce0 */ u8 field7CE0[0x18];
} Unk0216fdac;

u32 GetLargerValue(u32 first, u32 second);
void func_02007154(u32 entryIndex);
