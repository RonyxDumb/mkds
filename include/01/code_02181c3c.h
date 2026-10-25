#pragma once

#include "types.h"
#include "01/code_02181630.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02081f10.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_021759c0.h"

typedef struct Unk02181c3c_9c {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[0x1e];
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
} Unk02181c3c_9c;

// Object passed to func_020d8cc8 and func_020d8bf8.
typedef struct Unk02181c3c_b4 {
    /* 00 */ u8 mUnk_00[0x8];
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[0x1a];
} Unk02181c3c_b4;

// Object updated by func_ov001_02181c3c, one state per value of mUnk_0f8.
typedef struct Unk02181c3c {
    /* 000 */ u8 mUnk_000[0x2];
    /* 002 */ u16 mUnk_002;
    /* 004 */ Vec3 mUnk_004;
    /* 010 */ Vec3 mUnk_010;
    /* 01c */ u8 mUnk_01c[0x3c];
    /* 058 */ s32 mUnk_058;
    /* 05c */ u8 mUnk_05c[0x8];
    /* 064 */ s16 mUnk_064;
    /* 066 */ u8 mUnk_066[0x36];
    /* 09c */ Unk02181c3c_9c *mUnk_09c;
    /* 0a0 */ u16 mUnk_0a0;
    /* 0a2 */ u8 mUnk_0a2[0xa];
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ Unk02181c3c_b4 mUnk_0b4;
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ Vec3 *mUnk_0e8;
    /* 0ec */ Vec3 mUnk_0ec;
    /* 0f8 */ s32 mUnk_0f8;
    /* 0fc */ void *mUnk_0fc;
    /* 100 */ s32 mUnk_100;
} Unk02181c3c;

void func_ov001_02181c3c(void *param_1, Unk02181c3c *param_2);
