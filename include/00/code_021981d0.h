#pragma once

#include "types.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"
#include "00/code_02197b34.h"
#include "00/code_02197e8c.h"
#include "00/code_021a3690.h"
#include "00/code_02193818.h"
#include "00/code_0218d000.h"

struct Unk021981d0;
struct Unk02198394;

typedef struct Unk02198778 {
    /* 00 */ void (*mUnk_00)(struct Unk021981d0 *a, int b, void *c, int d);
    /* 04 */ void (*mUnk_04)(struct Unk021981d0 *a, void *b, int c, int d);
    /* 08 */ void (*mUnk_08)(struct Unk021981d0 *a, void *b);
    /* 0c */ u32 mUnk_0c;
} Unk02198778;

typedef struct Unk021987c8 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk021987c8;

typedef struct Unk02198394 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[4];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ void (*mUnk_20)(struct Unk02198394 *a, struct Unk021981d0 *b, int c, int d, int e, int f, int g);
    /* 24 */ void (*mUnk_24)(struct Unk02198394 *a);
} Unk02198394;

typedef struct Unk021981d0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 08 */ Unk02198394 *mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ Unk02198778 mUnk_28;
    /* 38 */ Unk021987c8 mUnk_38;
    /* 44 */ Unk021987c8 mUnk_44;
    /* 50 */ Unk021987c8 mUnk_50;
    /* 5c */ int *mUnk_5c;
    /* 60 */ int *mUnk_60;
    /* 64 */ u16 mUnk_64;
    /* 66 */ u16 mUnk_66;
    /* 68 */ u8 mUnk_68[0x20];
    /* 88 */ u32 mUnk_88;
    /* 8c */ u32 mUnk_8c;
    /* 90 */ u32 mUnk_90;
    /* 94 */ u32 mUnk_94;
    /* 98 */ int *mUnk_98;
    /* 9c */ int *mUnk_9c;
} Unk021981d0;

typedef struct Unk02198af4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u32 mUnk_0c;
} Unk02198af4;

// Declared here until the code that defines them is decompiled.
void func_ov000_0218dddc(void *a, void (*b)(Unk021981d0 **c), int d);
void func_ov000_0219a06c(Unk021981d0 *a);
void func_ov000_0219a220(Unk021981d0 *a);
int func_ov000_0219a28c(void *a, Unk021981d0 **b, int c, u32 d);
int func_ov000_0219a430(void *a, void *b, void *c, void *d, void *e);
void func_ov000_0219a61c(void *a, void *b);
int func_ov000_0219a654(u32 a, u32 *b, u16 *c);
int func_ov000_0219914c(Unk021981d0 *a);
int func_ov000_021990f8(Unk021981d0 *a, u16 b, int c);

int func_ov000_021981d0(Unk021981d0 *a, void *b);
int func_ov000_02198258(Unk021981d0 *a, void *b, int c, int d);
int func_ov000_021982f4(Unk021981d0 *a, int b, void *c, int d);
int func_ov000_02198394(Unk02198394 *a, Unk021981d0 *b, int c, int d, int e, int f, int g);
int func_ov000_02198448(Unk02198394 *a);
void func_ov000_021984b4(Unk021981d0 *a);
void func_ov000_02198514(Unk021981d0 *a, ...);
void func_ov000_02198548(Unk021981d0 *a, int b);
