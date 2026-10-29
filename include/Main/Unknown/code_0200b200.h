#pragma once

#include "types.h"
#include "Main/Unknown/code_02008000.h"
#include "Main/Unknown/code_0200b000.h"
#include "Main/Unknown/code_0200ba44.h"
#include "Main/Unknown/code_0200ba84.h"
#include "Main/Unknown/code_0200c0ac.h"
#include "Main/Unknown/code_0200c090.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_02142eac.h"

// What func_02008934 returns: the members are the ones func_0200b610 reads.
typedef struct Unk0200b610 {
    /* 000 */ u8 mUnk_000[0x4b5];
    /* 4b5 */ u8 mUnk_4b5;
    /* 4b6 */ u8 mUnk_4b6[2];
    /* 4b8 */ u32 mUnk_4b8;
    /* 4bc */ u8 mUnk_4bc[4];
    /* 4c0 */ u8 mUnk_4c0[0xc0];
} Unk0200b610;

void func_0200b200(void);
void func_0200b344(Unk021425e8 *a);
void func_0200b43c(u32 a, Unk021425e8 *b);
u32 func_0200b610(void);
void func_0200b698(Unk021425e8 *a);
