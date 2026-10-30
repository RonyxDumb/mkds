#pragma once

#include "types.h"
#include "03/code_021d1d88.h"
#include "03/code_021d2188.h"

typedef struct Unk021d1fd0 {
    /* 000 */ u8 mUnk_000[0x718];
    /* 718 */ Unk021d2188 mUnk_718[2];
    /* 788 */ Unk021d1d88 *mUnk_788;
    /* 78c */ u8 mUnk_78c[8];
    /* 794 */ u8 mUnk_794;
    /* 795 */ u8 mUnk_795;
} Unk021d1fd0;

void func_ov003_021d1fd0(void *object);
