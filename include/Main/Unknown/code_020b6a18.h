#pragma once

#include "types.h"
#include "Main/Unknown/code_020b502c.h" // UnkPair020b502c

// 0x20 bytes filled in by func_02056bc0: ten halfwords from 0x04 and bytes at 0x18 and 0x19.
typedef struct Unk02056bc0 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04[10];
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;
    /* 1a */ u8 mUnk_1a[6];
} Unk02056bc0;

void func_020b6a18(UnkPair020b502c *a, UnkPair020b502c *b);
void func_020b6a98(UnkPair020b502c *a, UnkPair020b502c *b);
void func_020b6b18(UnkPair020b502c *a, UnkPair020b502c *b, s32 c, s32 d, s16 e, s16 f);
void func_020b6b54(UnkPair020b502c *a, UnkPair020b502c *b);
void func_020b6bd4(UnkPair020b502c *a, UnkPair020b502c *b, s32 c, s32 d, s16 e, s16 f);
void func_020b6c74(u32 a, u16 *b, u32 c);
