#pragma once

#include "types.h"

// Two words filled by func_0200c4c0 and func_0200c534 and read back by func_0200c4a4 and func_0200c508.
typedef struct Unk0200c4a4 {
    /* 00 */ vs32 mUnk_00;
    /* 04 */ vs32 mUnk_04;
} Unk0200c4a4;

// Two halfwords at the start of the first object this file defines.
typedef struct Unk0216fe04 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk0216fe04;

// 0x40 bytes that func_0200c6b8 flushes and fills with a copy, then reads fields from.
typedef struct Unk0216fea0 {
    /* 00 */ u8 mUnk_00[0x2c];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[3];
    /* 35 */ u8 mUnk_35[3];
    /* 38 */ u8 mUnk_38[6];
    /* 3e */ u16 mUnk_3e;
} Unk0216fea0;

typedef struct Unk0216fe20 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x7c];
    /* 80 */ Unk0216fea0 mUnk_80;
} Unk0216fe20;

// Fixed-address object written by func_0200c6b8 and read by func_0200c568.
typedef struct Unk027ffc30 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[3];
    /* 05 */ u8 mUnk_05_0 : 1;
    u8 mUnk_05_1 : 1;
    u8 mUnk_05_2 : 6;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u32 mUnk_08;
} Unk027ffc30;

// Fixed-address object read by func_0200c568.
typedef struct Unk08000000 {
    /* 00 */ u8 mUnk_00[0xac];
    /* ac */ u32 mUnk_ac;
    /* b0 */ u8 mUnk_b0[2];
    /* b2 */ u8 mUnk_b2;
    /* b3 */ u8 mUnk_b3[0xb];
    /* be */ u16 mUnk_be;
} Unk08000000;

extern Unk0216fe04 data_0216fe04;
extern s32 data_0216fe08;
extern s32 data_0216fe0c;
extern s32 (*data_0216fe10)(void);
extern Unk0216fe20 data_0216fe20;

void func_0200c4a4(u32 a, Unk0200c4a4 *p);
void func_0200c4c0(u32 a, Unk0200c4a4 *p);
void func_0200c508(Unk0200c4a4 *p);
void func_0200c534(Unk0200c4a4 *p);
s32 func_0200c568(void);
void func_0200c620(void);
void func_0200c648(void);
void func_0200c65c(u32 a, u32 b);
void func_0200c690(u32 a, u32 b);
void func_0200c6b8(void);
void func_0200c7f4(void);
