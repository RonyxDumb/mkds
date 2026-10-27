#pragma once

#include "types.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e6fd4.h"

// 0x40-byte block that func_020e7410 takes from data_02159370.
typedef struct Unk020e7410 {
    /* 00 */ u32 mUnk_00[0x10];
} Unk020e7410;

// Object filled in and handed to func_02046be8 by func_020e7760; func_020e84b0
// stores func_020d4ef4's return value at 0x0c before that call.
typedef struct Unk0217b9dc {
    /* 00 */ u32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217b9dc;

extern Unk0217b9dc data_0217b9dc;

// Source rows read by the second loop of func_020e7460, 0x0c bytes each; a
// row's non-zero words are names looked up by func_0204799c.
typedef struct Unk0216c324 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ const char *mUnk_04;
    /* 08 */ const char *mUnk_08;
} Unk0216c324;

extern Unk0216c324 data_0216c324[];

// Destination rows written by the second loop of func_020e7460, 0x10 bytes
// each: three objects allocated through func_02036bec.
typedef struct Unk0217bb08 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217bb08;

extern Unk0217bb08 data_0217bb08[];

// Container whose 0x0c and 0x1c pointers receive the objects func_020e6488
// creates for func_020e7460.
typedef struct Unk0217bae8 {
    /* 00 */ u8 mUnk_00[0x0c];
    /* 0c */ Unk020e6488 *mUnk_0c;
    /* 10 */ u8 mUnk_10[0x0c];
    /* 1c */ Unk020e6488 *mUnk_1c;
} Unk0217bae8;

extern Unk0217bae8 data_0217bae8;

Unk020e705c *func_020e73b4(void);
Unk020e7410 *func_020e7410(void);
void func_020e7460(void);
void func_020e7760(void);
void func_020e79c4(void);
void func_020e7a18(void);
