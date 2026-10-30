#pragma once

#include "types.h"
#include "00/code_021af550.h"
#include "Main/Unknown/unk_0216f000.h"

typedef struct Unk021adbac {
    /* 00 */ Unk0200db5c *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a[6];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ u32 mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u8 mUnk_38[8];
    /* 40 */ u8 *mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ u8 mUnk_48[0x14];
    /* 5c */ u8 *mUnk_5c;
    /* 60 */ u32 mUnk_60;
} Unk021adbac;

extern u32 (*data_ov000_021b6388)(void);
extern u8 data_ov000_021b6364;
extern u16 data_ov000_021b6370;

// Declared here until the code that defines them is decompiled.
s32 func_ov000_021a9280(const u8 *a, s32 b, const u8 *c, s32 d, Unk021adbac *e);
s32 func_ov000_021a9358(Unk021adbac *a);
void func_ov000_021a9394(u32 a, Unk021adbac *b);
u8 *func_ov000_021a93e0(u32 *a, Unk021adbac *b);
void func_ov000_021a9228(Unk021adbac *a);
void func_ov000_021ae0c4(Unk021adbac *a);
void func_ov000_021b04d4(void);
void func_ov000_021b04f8(u32 a);
void func_ov000_021a91cc(u32 a);
void func_ov000_021afc5c(u32 a);

s32 func_ov000_021adbac(void);
s32 func_ov000_021adbf4(const u8 *a, s32 b);
s32 func_ov000_021adc64(const u8 *a, s32 b, const u8 *c, s32 d);
s32 func_ov000_021adcec(const u8 *a, u32 b, const u8 *c, s32 d, void *e);
void func_ov000_021ade40(const u8 *a, s32 b, const u8 *c, s32 d, Unk021adbac *e, s32 f);
s32 func_ov000_021ade6c(const u8 *a, s32 b, Unk021adbac *c, s32 d);
void func_ov000_021adf00(u32 a);
void func_ov000_021adf30(u32 a, Unk021adbac *b);
u8 *func_ov000_021adf78(u32 *a);
u8 *func_ov000_021adfc8(u32 *a, Unk021adbac *b);
