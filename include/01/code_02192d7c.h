#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"
#include "Main/Unknown/code_01ff9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020b502c.h"

typedef struct Unk02192d7c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ u8 mUnk_28[0x24];
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
} Unk02192d7c;

void func_ov001_02192d7c(void *param_1, Unk02192d7c *param_2);
void func_ov001_02192dd4(Unk0219b250 *param_1);
void func_ov001_02192e10(Unk02188950 *param_1);
