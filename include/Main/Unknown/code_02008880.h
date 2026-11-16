#pragma once

#include "types.h"

typedef struct FSFile FSFile;

// Two words of the 0x60-byte block that FS_ReadFile reads.
typedef struct Unk02008880 {
    /* 00 */ u8 field0[0x2c];
    /* 2c */ u32 field2C;
    /* 30 */ u8 field30[0xc];
    /* 3c */ u32 field3C;
    /* 40 */ u8 field40[0x20];
} Unk02008880;

u32 MB_GetSegmentLength(FSFile *a);
u16 MBi_calc_cksum(const u16 *data, s32 byteCount);
