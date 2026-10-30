#pragma once

#include "types.h"
#include "Main/Unknown/code_02025cd0.h"
#include "Main/Unknown/code_02025d8c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_021171a0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/unk_02174000.h"

// Halfword, hour and minute, as func_0202dcf4 fills them.
typedef struct Unk0202de00_g {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk0202de00_g;

void func_0202de00(Unk02174e14 *a, s16 (*b)[4], void *c, s32 d, s32 e, s32 f, Unk0202de00_g *g);
