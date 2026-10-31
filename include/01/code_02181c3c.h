#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // Unk020e71a0
#include "01/code_02181630.h"
#include "01/unk_021a6000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02081f10.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_021759c0.h"

// Object updated by func_ov001_02181c3c, one state per value of mUnk_0f8.
typedef struct Unk02181c3c {
    /* 000 */ Unk020e71a0 mUnk_000;
    /* 0a0 */ u16 mUnk_0a0;
    /* 0a2 */ u8 mUnk_0a2[0x2];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ Unk020e0144 mUnk_0b4;
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ Vec3 *mUnk_0e8;
    /* 0ec */ Vec3 mUnk_0ec;
    /* 0f8 */ s32 mUnk_0f8;
    /* 0fc */ void *mUnk_0fc;
    /* 100 */ s32 mUnk_100;
} Unk02181c3c;

// List of objects, as returned by func_02100138(0x68).
typedef struct Unk02181c3c_list {
    /* 00 */ Unk02181c3c **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk02181c3c_list;

void func_ov001_02181c3c(void *param_1, Unk02181c3c *param_2);
