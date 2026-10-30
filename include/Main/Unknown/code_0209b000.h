#pragma once

#include "Main/Unknown/code_0209b60c.h"

#include "types.h"
#include "01/code_02181c3c.h"
#include "Main/Unknown/code_0209bc74.h"

// Declared here until the code that defines them is decompiled.
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bc5c.h"
// Object returned by func_0209bf70; the code writes the words at 0x24, 0x28, 0x38 and 0x3c.
// Object returned by func_0209bf70; the code writes the words at 0x28, 0x38 and 0x3c.
typedef struct Unk0209bf70 {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c[0xc];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk0209bf70;

Unk0209bf70 *func_0209bf70(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void *func_0209bfa8(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5);
void func_0209be50(Unk0209bc74 *a, const char *b);
void *func_0209be84(void *a, const char *b);
void *func_0209bfe0(s32 a);
void *func_0209bc74(void *a, const char *b, const char *c);
void *func_0209bd08(void *a, const char *b);
void *func_0209bd90(void *a, const char *b);
void func_0209bde8(Unk0209bc74 *a, const char *b);
void func_0209be1c(Unk0209bc74 *a, const char *b);
