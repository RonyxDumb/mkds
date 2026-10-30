#pragma once

#include "types.h"
#include "Main/Unknown/code_0200692c.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02050320.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

typedef struct Unk0204ed04 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ void *mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk0204ed04;

void func_0204ed04(Unk0204ed04 *a);
void func_0204ed84(void);
