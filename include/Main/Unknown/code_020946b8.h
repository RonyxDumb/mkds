#pragma once

#include "types.h"
#include "Main/Unknown/code_02094000.h"

// Table of the objects of func_02100138(0x13b) and their number.
typedef struct Unk020946b8 {
    /* 00 */ Unk02094000 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk020946b8;

// Object of func_02094db4: the word at 0x1c is set.
typedef struct Unk02094db4 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ s32 mUnk_1c;
} Unk02094db4;

void func_020946b8(void);
void func_02094724(void);
void func_02094744(void);
void func_02094768(void *a, Unk02094000 *o);
s16 func_02094bd0(s32 a);
s32 func_02094bf0(s32 a, s32 b);
s16 func_02094c0c(s32 a);
void func_02094c24(Unk020946b8 *a);
void func_02094c70(void *a, Unk02094000 *b);
void func_02094d9c(void *a);
void func_02094db4(Unk02094db4 *a);
