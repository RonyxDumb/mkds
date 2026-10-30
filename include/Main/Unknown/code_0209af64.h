#pragma once

#include "types.h"
#include "Main/Unknown/code_0209a7dc.h"

// Table of object pointers with a halfword count behind it.
typedef struct Unk0209af98 {
    /* 00 */ Unk0209a7dc **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209af98;

s32 func_0209af64(s32 a, s32 b);
s16 func_0209af80(s32 a);
void func_0209af98(Unk0209af98 *p);
void func_0209b088(void *a, Unk0209a7dc *b);
