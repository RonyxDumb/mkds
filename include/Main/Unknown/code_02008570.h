#pragma once

#include "types.h"

extern u32 *data_02161788;
extern u8 aRom_3[];

typedef struct FSFile FSFile;

typedef struct Unk02008570Header {
    /* 00 */ u8 field0[0x20];
    /* 20 */ u32 field20;
    /* 24 */ u8 field24[0x4];
    /* 28 */ u32 field28;
    /* 2c */ u32 field2C;
    /* 30 */ u32 field30;
    /* 34 */ u8 field34[0x8];
    /* 3c */ u32 field3C;
    /* 40 */ u8 field40[0x20];
    /* 60 */ u32 field60;
    /* 64 */ u8 field64[0x1c];
    /* 80 */ u32 field80;
} Unk02008570Header;

int MB_ReadSegment(FSFile *file, void *buffer, u32 bufferSize);
