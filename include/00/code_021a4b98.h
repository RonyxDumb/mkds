#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_0200f790.h"

// Event the function at field227C is called with; built by func_ov000_021a586c.
typedef struct Unk021a586c {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ void *field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
} Unk021a586c;

// 0xd0 bytes. Entry of the list at field2270 of an Unk021b5f50.
typedef struct Unk021b5f50_2270_0c {
    /* 00 */ u8 field0;
    /* 02 */ u16 field2;
    /* 04 */ u32 field4;
    /* 08 */ struct Unk021b5f50_2270_0c *field8;
    /* 0c */ struct Unk021b5f50_2270_0c *fieldC;
    /* 10 */ u8 field10[0xc0];
} Unk021b5f50_2270_0c;

// Header of the list at field2270 of an Unk021b5f50: count, first and last entry, then the entries.
typedef struct Unk021b5f50_2270 {
    /* 00 */ u32 field0;
    /* 04 */ Unk021b5f50_2270_0c *field4;
    /* 08 */ Unk021b5f50_2270_0c *field8;
    /* 0c */ Unk021b5f50_2270_0c fieldC[1];
} Unk021b5f50_2270;

// 0x2300 bytes; the word data_ov000_021b5f50 points to it.
typedef struct Unk021b5f50 {
    /* 0000 */ u8 field0[0xf00];
    /* 0f00 */ u8 fieldF00[0x600];
    /* 1500 */ u8 field1500[0xc40];
    /* 2140 */ u8 field2140[4];
    /* 2144 */ u8 field2144[6];
    /* 214a */ u16 field214A;
    /* 214c */ u8 field214C[0x22];
    /* 216e */ u16 field216E;
    /* 2170 */ u16 field2170;
    /* 2172 */ u8 field2172[0x8e];
    /* 2200 */ u8 field2200[0x50];
    /* 2250 */ u8 field2250;
    /* 2251 */ u8 field2251;
    /* 2252 */ u8 field2252[0xe];
    /* 2260 */ s32 field2260;
    /* 2264 */ u32 field2264;
    /* 2268 */ u16 field2268;
    /* 226a */ u8 field226A;
    /* 226b */ u8 field226B;
    /* 226c */ u32 field226C;
    /* 2270 */ Unk021b5f50_2270 *field2270;
    /* 2274 */ u32 field2274;
    /* 2278 */ u32 field2278;
    /* 227c */ void (*field227C)(Unk021a586c *);
    /* 2280 */ s16 field2280;
    /* 2282 */ u16 field2282;
    /* 2284 */ s32 field2284;
    /* 2288 */ Unk021438f0 field2288;
    /* 22c0 */ u8 field22C0[0xc];
    /* 22cc */ OSAlarm field22CC;
    /* 22f8 */ u16 field22F8;
    /* 22fa */ u8 field22FA[6];
} Unk021b5f50;

// Event of the callbacks func_ov000_021a5088 and func_ov000_021a52b0 take.
typedef struct Unk021a5088 {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u16 field8;
    /* 0a */ u16 fieldA;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
    /* 10 */ u8 *field10[16];
    /* 50 */ u16 field50[16];
} Unk021a5088;

// Declared here until the code that defines them is decompiled.
void func_ov000_021a54b0(Unk021425e8 *event);

u32 func_ov000_021a4b98(u32 a);
u32 func_ov000_021a4bbc(u32 a);
void func_ov000_021a4bc4(Unk021425e8 *event);
void func_ov000_021a4e28(Unk021425e8 *event);
void func_ov000_021a4f10(Unk021425e8 *event);
void func_ov000_021a4fe0(Unk021425e8 *event);
void func_ov000_021a5088(Unk021a5088 *event);
void func_ov000_021a524c(Unk021425e8 *event);
void func_ov000_021a52b0(Unk021a5088 *event);
u32 func_ov000_021a5bfc(void);
s32 func_ov000_021a5db0(void);
s32 func_ov000_021a6024(void);
s32 func_ov000_021a61e4(void);
