#pragma once

#include "types.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_020a2e4c.h" // Unk020a2fe4

// List of entries: an array of pointers and its length.
typedef struct Unk021816b4 {
    /* 00 */ Unk020a2fe4 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021816b4;

s32 func_ov001_021816b4(void);
