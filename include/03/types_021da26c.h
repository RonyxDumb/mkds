#pragma once

#include "types.h"
#include "code_02142eac.h"

// Entry of the table at offset 0x1300 of an Unk021da26c.
typedef struct Unk021ccf30_1300 {
    /* 00 */ u8 field0[0x20];
    /* 20 */ u8 field20[6];
    /* 26 */ u16 field26;
    /* 28 */ u8 field28;
} Unk021ccf30_1300;

// 0x44 bytes: func_ov003_021cd1c4 copies them from data_ov003_021d6640; the first 0x38 bytes are the object
// WM_StartScanEx takes.
typedef struct Unk021da26c_1648 {
    /* 00 */ Unk021438f0 field0;
    /* 38 */ u8 field38[0xc];
} Unk021da26c_1648;

// Buffer WM_ReadStatus fills; field0 is the value func_ov003_021cd118 waits for.
typedef struct Unk021da26c_168c {
    // Same bytes as the mState member of Unk02142988.
    /* 00 */ u16 mState;
    /* 02 */ u8 field2[0x7ba];
} Unk021da26c_168c;

// Object that data_ov003_021da26c points to (0x1e60 bytes).
typedef struct Unk021da26c {
    /* 0000 */ u8 field0[0xf00];
    /* 0f00 */ u8 fieldF00[0x400];
    /* 1300 */ Unk021ccf30_1300 field1300[0x14];
    /* 1648 */ Unk021da26c_1648 field1648;
    /* 168c */ Unk021da26c_168c field168C;
    /* 1e48 */ u8 field1E48;
    /* 1e49 */ u8 field1E49[0x17];
} Unk021da26c;
