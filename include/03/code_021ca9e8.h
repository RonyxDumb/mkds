#pragma once

#include "types.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"

// Object behind data_ov003_021da234.
typedef struct Unk021da234 {
    /* 00 */ void *mUnk_00;
    /* 04 */ Unk021d1770 *mUnk_04[3];
    /* 10 */ Unk021d1770 *mUnk_10[3];
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
} Unk021da234;

void func_ov003_021ca9e8(void);
void func_ov003_021caae0(void);
void func_ov003_021cab4c(int param_1);
void func_ov003_021caca8(void);
void func_ov003_021cacfc(void);
void func_ov003_021cae28(void);
