#pragma once

#include "types.h"
#include "00/code_02190b80.h"
#include "00/code_021947e4.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "00/unk_021b4000.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "00/code_02190ba0.h"
#include "00/code_02192e04.h"
#include "00/code_02193818.h"
#include "00/code_021a4654.h"

// Object with the output buffer at 0x1f4 that Unk021919ac.mUnk_00 points to.
typedef struct Unk021919ac_00 {
    /* 000 */ u8 mUnk_000[0x100];
    /* 100 */ s32 mUnk_100;
    /* 104 */ u8 mUnk_104[8];
    /* 10c */ s32 mUnk_10c;
    /* 110 */ u8 mUnk_110[0x1f];
    /* 12f */ s8 mUnk_12f[0x15];
    /* 144 */ u8 mUnk_144[0x33];
    /* 177 */ u8 mUnk_177[0x1f];
    /* 196 */ u8 mUnk_196[2];
    /* 198 */ u32 mUnk_198;
    /* 19c */ u32 mUnk_19c;
    /* 1a0 */ u32 mUnk_1a0;
    /* 1a4 */ u8 mUnk_1a4[0x30];
    /* 1d4 */ s32 mUnk_1d4;
    /* 1d8 */ s32 mUnk_1d8;
    /* 1dc */ u8 mUnk_1dc[0x18];
    /* 1f4 */ u8 mUnk_1f4[0x10];
    /* 204 */ s32 mUnk_204;
    /* 208 */ u32 mUnk_208;
    /* 20c */ u8 mUnk_20c[0x234];
    /* 440 */ u8 mUnk_440[0x10];
    /* 450 */ u8 mUnk_450[0x1c];
    /* 46c */ u32 mUnk_46c;
    /* 470 */ u32 mUnk_470;
} Unk021919ac_00;

// First argument of the functions of this file.
typedef struct Unk021919ac {
    /* 00 */ Unk021919ac_00 *mUnk_00;
} Unk021919ac;

// Object of 0x308 bytes that func_ov000_02191cb0 allocates and fills.
typedef struct Unk021919ac_q {
    /* 000 */ u8 mUnk_000[0x80];
    /* 080 */ u8 mUnk_080[0x21];
    /* 0a1 */ u8 mUnk_0a1[0x21];
    /* 0c2 */ s8 mUnk_0c2[0x100];
    /* 1c2 */ s8 mUnk_1c2[0x100];
    /* 2c2 */ u8 mUnk_2c2[0x41];
    /* 303 */ u8 mUnk_303;
    /* 304 */ s32 mUnk_304;
} Unk021919ac_q;

// Object of 0xf0 bytes that func_ov000_0219218c copies.
typedef struct Unk021919ac_f0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[0xb0];
    /* c8 */ u32 mUnk_c8;
    /* cc */ u8 mUnk_cc[0x24];
} Unk021919ac_f0;

// Object that func_ov000_021938cc returns through its fourth argument.
typedef struct Unk021919ac_node {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk021919ac_f0 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk021919ac_node;

// Object of 0x204 bytes that func_ov000_0219222c allocates.
typedef struct Unk021919ac_m {
    /* 000 */ u32 mUnk_000;
    /* 004 */ u32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x1fc];
} Unk021919ac_m;

// Two words that func_ov000_0219488c returns through its last argument.
typedef struct Unk021919ac_h {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk021919ac_h;

// Address of 8 bytes that func_ov000_02191e58 passes on.
typedef union Unk021919ac_sa {
    struct {
        /* 00 */ u8 mUnk_00;
        /* 01 */ u8 mUnk_01;
        /* 02 */ u16 mUnk_02;
        /* 04 */ u32 mUnk_04;
    } f;
    u32 w[2];
} Unk021919ac_sa;

// Declared here until the code that defines them is decompiled.
s32 func_ov000_0218e4b4(s32 a, void *b, s32 c);
s32 func_ov000_0218e4e4(s32 a, void *b, s32 c);
void *func_ov000_0218e880(u8 *a);
void func_ov000_0219488c(Unk021919ac *p, u8 *a, u8 *b, Unk021919ac_h **c);

void func_ov000_021920d8(s8 *p, s32 n);
u32 func_ov000_021919ac(Unk021919ac *p, Unk021919ac_q *q);
u32 func_ov000_02191cb0(Unk021919ac *p, const u8 *a, const u8 *b, const u8 *c, const u8 *d, const s8 *e, const s8 *f,
                        const u8 *g, s32 h, s32 i, s32 j, s32 k, s32 l);
u32 func_ov000_02191e58(Unk021919ac *p, Unk021919ac_node *n);
