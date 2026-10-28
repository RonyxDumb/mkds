#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Unk020a2fe4

// Object func_020a3eb8 sets the word at 0x1c of.
typedef struct Unk020a3eb8 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ s32 mUnk_1c;
} Unk020a3eb8;

void func_020a3948(void *p, Unk020a2fe4 *a);
void func_020a3e38(void *p);
void func_020a3eb8(Unk020a3eb8 *a);
