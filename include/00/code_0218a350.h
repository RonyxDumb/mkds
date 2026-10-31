#pragma once

#include "types.h"

typedef struct Unk0218a5b0 {
    /* 00 */ u8 mUnk_00[24];
} Unk0218a5b0;

extern s8 *data_ov000_021b20ec;
extern u8 data_ov000_021b0790[];
extern s8 *data_ov000_021b20f0;
extern u8 data_ov000_021b07a0[];
extern Unk0218a5b0 data_ov000_021b2118;
extern s8 *data_ov000_021b20f4;
extern s8 *data_ov000_021b20e8;

s32 func_ov000_0218a350(const u8 *a, u8 *b, s32 c, u32 d);
s32 func_ov000_0218a444(u32 c);
void func_ov000_0218a48c(const u8 *a, u8 *b);
void func_ov000_0218a57c(const u8 *a, u8 *b);
void func_ov000_0218a5b0(const u8 *a, u8 *b);
