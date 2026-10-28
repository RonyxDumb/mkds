#pragma once

#include "types.h"
#include "Main/Unknown/code_0207b960.h" // Unk0207b960

// Object behind member 0x218 of Unk020748b8: vectors at 0x18 and 0x24, an index into the table at
// Unk02175620::mUnk_08 at 0x40.
typedef struct Unk020748b8_218 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ Vec3 mUnk_24;
    /* 30 */ u8 mUnk_30[0x10];
    /* 40 */ u16 mUnk_40;
    /* 42 */ s16 mUnk_42;
    /* 44 */ u16 mUnk_44;
} Unk020748b8_218;

// Object func_020748b8 to func_020749a4 take: vectors at 0x18 and 0x24, a Unk0207b960 at 0x194 and a word at 0x244.
typedef struct Unk020748b8 {
    /* 000 */ u8 mUnk_000[0x18];
    /* 018 */ Vec3 mUnk_018;
    /* 024 */ Vec3 mUnk_024;
    /* 030 */ u8 mUnk_030[0x164];
    /* 194 */ Unk0207b960 mUnk_194;
    /* 1d0 */ u8 mUnk_1d0[0x48];
    /* 218 */ Unk020748b8_218 *mUnk_218;
    /* 21c */ u8 mUnk_21c[0x28];
    /* 244 */ s32 mUnk_244;
} Unk020748b8;

void func_020748b8(Unk020748b8 *p);
void func_02074978(Unk020748b8 *p);
void func_020749a4(Unk020748b8 *p, s32 a);
