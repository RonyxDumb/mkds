#pragma once

#include "types.h"
#include "Main/Unknown/code_02025ebc.h"

// Object behind data_02174e58; func_02030a20 reads the words at 0x84 and 0x94 and passes the Unk02025ebc at 0xc0.
typedef struct Unk02174e58 {
    /* 00 */ u8 mUnk_00[0x84];
    /* 84 */ s32 mUnk_84;
    /* 88 */ u8 mUnk_88[0xc];
    /* 94 */ s32 mUnk_94;
    /* 98 */ u8 mUnk_98[0x28];
    /* c0 */ Unk02025ebc mUnk_c0;
} Unk02174e58;

void func_02030a20(void);
