#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02050320.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_020b3f7c.h"

// Halfwords at 0x10 and 0x12 of the part of Unk021a99c0 from 0x18.
typedef struct Unk021a99c0_18 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk021a99c0_18;

// Object behind data_usa_ov001_021a99c0.
typedef struct Unk021a99c0 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ Unk021a99c0_18 mUnk_18;
    /* 2c */ u8 mUnk_2c[0xc];
    /* 38 */ Unk020b3fb0 *mUnk_38;
} Unk021a99c0;

extern Unk021a99c0 *data_usa_ov001_021a99c0;
extern s32 data_usa_02174e54;

void func_02001000(void);
void func_0200104c(void);
void func_020010e0(void);
void func_02001144(void);
void func_0200118c(void);
void func_020011f0(void);
void func_02001238(void);

// Declared here until the code that defines them is decompiled.
void func_02001a74(void *a);
void func_02001abc(void);
void func_02001b38(void);
void func_02001ba0(void *a);
