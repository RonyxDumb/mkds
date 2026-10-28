#pragma once

#include "types.h"
#include "code_0201c528.h"

// Two halfwords.
typedef struct Unk02155888_00 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk02155888_00;

// Four pairs; rows of data_02155888 and the value of data_0217aea0.
typedef struct Unk02155888 {
    /* 00 */ Unk02155888_00 mUnk_00[4];
} Unk02155888;

extern const Unk02155888 data_02155888[];
extern Unk02155888 data_0217aea0;

void func_02082d64(Unk0201ca6c *p, s32 a);
void func_02082e4c(s32 a);
void func_02082f94(Unk0201ca6c *p, s32 a);
