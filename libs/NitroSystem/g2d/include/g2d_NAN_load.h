#pragma once

#include "types.h"

// Two words.
typedef struct Unk02021e40 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
} Unk02021e40;

// 16 bytes: field0 elements of 8 bytes at fieldC.
typedef struct Unk02021e1c {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
} Unk02021e1c;

// Header: field4, field8 and fieldC are offsets from the start that NNS_G2dUnpackNAN turns into addresses.
// field4 holds field0 entries (16 bytes, or 8 bytes without bit 0 of field2, see NNS_G2dGetCellDataByIdx).
typedef struct Unk02021dc8 {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ Unk02021e40 *fieldC;
} Unk02021dc8;

void *NNS_G2dGetAnimSequenceByIdx(void *bank, u32 idx);
void NNS_G2dUnpackNAN(Unk02021dc8 *bank);
