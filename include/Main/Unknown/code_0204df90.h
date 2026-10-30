#pragma once

#include "types.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/code_02007ea0.h"
#include "Main/Unknown/code_02008880.h"
#include "Main/Unknown/code_02009c04.h"
#include "Main/Unknown/code_0200b1b0.h"
#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/code_0200b9e0.h"
#include "Main/Unknown/code_0200ba84.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0204ea14.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02050320.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"

// Twenty bytes after a two-byte head.
typedef struct Unk0204e4d8 {
    /* 00 */ union {
        u8 mUnk_00;
        struct {
            u8 mUnk_00_0 : 4;
            u8 mUnk_00_4 : 4;
        };
    };
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[0x14];
} Unk0204e4d8;

// Declared here until the code that defines them is decompiled.
void func_02007ec4(Unk0217aa00_24 *a, u32 b, u32 c, s32 d, s32 e);
u32 func_0200b15c(u32 a, Unk0217aa00_24 *b, u32 c, u32 d, s32 e, s32 f);
void func_0200b70c(void);
void func_0200bae0(void);
void func_0200bb98(void *a, Unk0204e4d8 *b);
s32 func_02009ff4(void *a, Unk0204e4d8 *b, u32 c, u32 d, u32 e);
s32 func_02009f38(u32 a, u32 b);
s32 func_02009cc8(s32 a);

void func_0204df90(void);
void func_0204dfe0(u32 a);
void func_0204e03c(u32 a);
void func_0204e074(void);
void func_0204e090(void);
void func_0204e0bc(void);
void func_0204e128(void);
s32 func_0204e1a8(s32 a);
s32 func_0204e204(void);
s32 func_0204e29c(void);
void func_0204e304(u32 a);
void func_0204e3b4(u32 a);
s32 func_0204e3f0(u32 a);
void func_0204e474(void);
void func_0204e498(void);
void func_0204e4bc(void);
void func_0204e4d8(void);
void func_0204e568(void);
void func_0204e65c(Unk0217aa00_1658 *a);
void func_0204e6e8(u32 a, u32 b, Unk0204e4d8 *c);
void func_0204e928(void *a, u32 b, u32 c);
