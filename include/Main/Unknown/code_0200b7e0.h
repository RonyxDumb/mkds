#pragma once

#include "types.h"
#include "Main/Unknown/code_02008934.h"
#include "Main/Unknown/code_0200ba44.h"
#include "code_02142eac.h"

// Block the callback behind mUnk_05dc receives from func_0200b850.
typedef struct Unk0200b850 {
    /* 00 */ u16 mUnk_00;
    /* 04 */ Unk02008934 *mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0200b850;

// Block the callback behind mUnk_05dc receives from func_0200b820.
typedef struct Unk0200b820 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk0200b820;

extern u8 data_usa_02152be4[6];

void func_0200b7e0(const u8 *a);
void func_0200b820(u16 a, u16 b);
void func_0200b850(u32 a, Unk02008934 *b, u32 c);
void func_0200b894(Unk021425e8 *a);
void func_0200b934(void);
