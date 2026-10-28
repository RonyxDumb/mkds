#pragma once

#include "types.h"
#include "03/code_021d2060.h"

typedef struct Unk021c5c68State {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ Unk021d2060 *mUnk_0c;
    /* 10 */ u8 mUnk_10[0x41];
    /* 51 */ u8 mUnk_51;
} Unk021c5c68State;
#include "03/code_021c5000.h"
#include "03/code_021d1000.h"
#include "03/code_021d2000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_02147000.h"

void func_ov003_021c5c68(void);
