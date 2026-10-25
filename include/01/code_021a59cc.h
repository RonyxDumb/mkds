#pragma once

#include "types.h"

// Object that the per-entry update callbacks around func_ov001_021a5a58 work on.
typedef struct Unk021a5a58 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[0x4];
    /* 18 */ s32 mUnk_18;
} Unk021a5a58;

s32 func_ov001_021a6430(s32 a, s32 b, s32 c, s32 d, s32 e, u16 f, s32 g);
void func_ov001_021a63d8(void);
void func_ov001_021a63cc(s32 value);
void func_ov001_021a63c0(u8 value);
u8 func_ov001_021a63b4(void);
void func_ov001_021a63a8(s32 value);
s32 func_ov001_021a639c(void);
void func_ov001_021a6388(s32 value);
s32 func_ov001_021a637c(void);
void func_ov001_021a6350(s32 x, s32 y);
s32 func_ov001_021a633c(void);
s32 func_ov001_021a6328(void);
s32 func_ov001_021a6314(void);
s32 func_ov001_021a6300(void);
s32 func_ov001_021a62c4(s32 x, s32 y);
s32 func_ov001_021a62ac(void);
s32 func_ov001_021a6278(void);
void func_ov001_021a6238(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_ov001_021a5f70(s32 a, s32 x, s32 y, s32 d, s32 dx, s32 dy);
s32 func_ov001_021a5ef4(Unk021a5a58 *entry);
s32 func_ov001_021a5e60(Unk021a5a58 *entry);
void func_ov001_021a5df0(void *obj, s32 index);
s32 func_ov001_021a5d18(Unk021a5a58 *entry);
void func_ov001_021a5d00(void *obj, s32 index);
s32 func_ov001_021a5c40(Unk021a5a58 *entry);
void func_ov001_021a5c28(void *obj, s32 index);
s32 func_ov001_021a5b70(Unk021a5a58 *entry);
void func_ov001_021a5b4c(void *obj, s32 index);
void func_ov001_021a5ab0(void *obj, s32 index);
s32 func_ov001_021a5a58(Unk021a5a58 *entry);
void func_ov001_021a5a40(void *obj, s32 index);
void func_ov001_021a59cc(void *obj, s32 index);
