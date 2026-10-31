#pragma once

#include "types.h"
#include "01/code_0219b250.h"
#include "01/code_02181820.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object passed to the per-frame functions func_ov001_02185bb8 and func_ov001_02185ca0.
typedef struct Unk02185bb8 {
    /* 000 */ Unk020e71a0 mUnk_000;
    /* 0a0 */ Unk020e71a0 *mUnk_0a0;
    /* 0a4 */ Unk020e71a0 *mUnk_0a4;
    /* 0a8 */ u16 mUnk_0a8;
    /* 0aa */ u8 mUnk_0aa[0x2];
    /* 0ac */ s32 mUnk_0ac;
} Unk02185bb8;

// Object whose flags and index func_ov001_02185d74 reads.
typedef struct Unk02185d74 {
    /* 00 */ u8 mUnk_00[0x48];
    /* 48 */ u32 mUnk_48;
    /* 4c */ u8 mUnk_4c[0x28];
    /* 74 */ u16 mUnk_74;
} Unk02185d74;

// Table of objects walked by func_ov001_02185c4c.
typedef struct Unk02185c4c {
    /* 00 */ Unk02185bb8 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk02185c4c;

extern Unk0219b250 *data_ov001_021a9b9c;

void func_ov001_02185bb8(void *param_1, Unk02185bb8 *param_2);
void func_ov001_02185c4c(Unk02185c4c *param_1);
void func_ov001_02185ca0(void *param_1, Unk02185bb8 *param_2);
u32 func_ov001_02185d74(Unk02185bb8 *param_1, Unk02185d74 *param_2, u8 *param_3, u8 *param_4);
void func_ov001_02185d18(void);
void func_ov001_02185d1c(void *param_1);
void func_ov001_02185dd0(Unk02185bb8 *param_1);
void *func_ov001_02185ef4(void);
