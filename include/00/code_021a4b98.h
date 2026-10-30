#pragma once

#include "types.h"
#include "code_02142eac.h"

// Object data_ov000_021b5f50 points at; only the members the code reads are named.
typedef struct Unk021b5f50 {
    /* 0000 */ u8 mUnk_0000[0x2140];
    /* 2140 */ u8 mUnk_2140[0x30];
    /* 2170 */ u16 mUnk_2170;
    /* 2172 */ u8 mUnk_2172[0x8e];
    /* 2200 */ u8 mUnk_2200[0x50];
    /* 2250 */ u8 mUnk_2250;
    /* 2251 */ u8 mUnk_2251;
    /* 2252 */ u8 mUnk_2252[0xe];
    /* 2260 */ s32 mUnk_2260;
    /* 2264 */ u32 mUnk_2264;
    /* 2268 */ u8 mUnk_2268[3];
    /* 226b */ u8 mUnk_226b;
    /* 226c */ u8 mUnk_226c[0x14];
    /* 2280 */ s16 mUnk_2280;
    /* 2282 */ u16 mUnk_2282;
    /* 2284 */ s32 mUnk_2284;
    /* 2288 */ Unk021438f0 mUnk_2288;
    /* 22c0 */ u8 mUnk_22c0[0x38];
    /* 22f8 */ u16 mUnk_22f8;
} Unk021b5f50;

// Event of the callbacks func_ov000_021a5088 and func_ov000_021a52b0 take.
typedef struct Unk021a5088 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u8 *mUnk_10[16];
    /* 50 */ u16 mUnk_50[16];
} Unk021a5088;

#include "00/unk_021b5000.h"

// Declared here until the code that defines them is decompiled.
void func_ov000_021a54b0(Unk021425e8 *event);
void func_ov000_021a671c(u8 *a, u16 b);
u32 func_ov000_021a58dc(u16 a);
void func_ov000_021a6c08(u8 a);
void func_ov000_021a6bb4(void *a);

u32 func_ov000_021a4b98(u32 a);
u32 func_ov000_021a4bbc(u32 a);
void func_ov000_021a4bc4(Unk021425e8 *event);
void func_ov000_021a4e28(Unk021425e8 *event);
void func_ov000_021a4f10(Unk021425e8 *event);
void func_ov000_021a4fe0(Unk021425e8 *event);
void func_ov000_021a5088(Unk021a5088 *event);
void func_ov000_021a524c(Unk021425e8 *event);
void func_ov000_021a52b0(Unk021a5088 *event);
