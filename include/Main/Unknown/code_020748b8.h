#pragma once

#include "types.h"
#include "Main/Unknown/code_0207b960.h" // Unk0207b960
#include "Main/Unknown/unk_0217a000.h" // Unk02061808

// The 0x4c-byte entries of the table at Unk02175620::mUnk_7c: a vector at 0x00, the vectors at 0x18 and 0x24, an
// index into the table at Unk02175620::mUnk_08 at 0x40.
typedef struct Unk020748b8_218 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ Vec3 mUnk_24;
    /* 30 */ u8 mUnk_30[0x2];
    /* 32 */ s16 mUnk_32;
    /* 34 */ s16 mUnk_34;
    /* 36 */ u8 mUnk_36[0x2];
    /* 38 */ s16 mUnk_38;
    /* 3a */ s16 mUnk_3a;
    /* 3c */ s16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u16 mUnk_40;
    /* 42 */ s16 mUnk_42;
    /* 44 */ u16 mUnk_44;
    /* 46 */ u16 mUnk_46;
    /* 48 */ s16 mUnk_48;
    /* 4a */ u8 mUnk_4a;
    /* 4b */ u8 mUnk_4b;
} Unk020748b8_218;

void func_020748b8(Unk02061808 *p);
void func_02074978(Unk02061808 *p);
void func_020749a4(Unk02061808 *p, s32 a);
