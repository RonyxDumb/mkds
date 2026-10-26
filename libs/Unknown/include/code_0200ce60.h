#pragma once

#include "types.h"

// 8-byte slot at a fixed address; func_0200cdc0 reads its halfword at 4, func_0200cea0 and func_0200cf30 swap and clear
// its words.
typedef struct Unk0200ce60 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0200ce60;

extern s32 data_0216ff40;

s32 func_0200ce60(u32 a);
s32 func_0200ce80(u32 a);
s32 func_0200cea0(u32 a, Unk0200ce60 *p, u32 (*f)(void), s32 k);
s32 func_0200cf20(u32 a, Unk0200ce60 *p, u32 (*f)(void));
s32 func_0200cf30(u32 a, Unk0200ce60 *p, u32 (*f)(void), s32 k);
s32 func_0200cfc0(u32 a, Unk0200ce60 *p, u32 (*f)(void));
s32 func_0200cfd0(u32 a, Unk0200ce60 *p, u32 (*f)(void), s32 k);
void func_0200d028(void);
