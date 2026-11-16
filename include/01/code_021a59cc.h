#pragma once

#include "types.h"
#include "code_02022030.h"

// Object at Unk021a5a58_2c.field2C.
typedef struct Unk021a5a58_2c_2c {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ u8 field4[0x4];
    /* 08 */ s16 field8[4];
} Unk021a5a58_2c_2c;

// Object at LldEntry.field2C.
typedef struct Unk021a5a58_2c {
    /* 00 */ u8 field0[0x8];
    /* 08 */ BOOL field8;
    /* 0c */ u8 fieldC[0x8];
    /* 14 */ s32 field14;
    /* 18 */ u8 field18[0x14];
    /* 2c */ Unk021a5a58_2c_2c *field2C;
    /* 30 */ u8 field30[0x24];
} Unk021a5a58_2c;

// Object that the per-entry update callbacks around func_ov001_021a5a58 work on.
typedef struct LldEntry {
    /* 00 */ u16 mAnimIndex;
    /* 02 */ u8 field2[0x2];
    /* 04 */ s32 mPosX;
    /* 08 */ s32 mPosY;
    /* 0c */ BOOL mShown;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 mScale;
    /* 1c */ s32 mBoundsLeft;
    /* 20 */ s32 mBoundsRight;
    /* 24 */ s32 mBoundsTop;
    /* 28 */ s32 mBoundsBottom;
    /* 2c */ Unk02022030 field2C;
    /* 80 */ struct Lld *mLld;
    /* 84 */ s32 (*mCallback)(struct LldEntry *);
} LldEntry;

void func_ov001_021a59cc(void *obj, s32 index);
void func_ov001_021a5a40(void *obj, s32 index);
BOOL func_ov001_021a5a58(LldEntry *entry);
void func_ov001_021a5ab0(void *obj, s32 index);
void func_ov001_021a5b4c(void *obj, s32 index);
BOOL func_ov001_021a5b70(LldEntry *entry);
void func_ov001_021a5c28(void *obj, s32 index);
BOOL func_ov001_021a5c40(LldEntry *entry);
void func_ov001_021a5d00(void *obj, s32 index);
BOOL func_ov001_021a5d18(LldEntry *entry);
void func_ov001_021a5df0(void *obj, s32 index);
BOOL func_ov001_021a5e60(LldEntry *entry);
BOOL func_ov001_021a5ef4(LldEntry *entry);
s32 func_ov001_021a5f70(s32 down, s32 x, s32 y, s32 d, s32 dx, s32 dy);
void func_ov001_021a6238(s32 originX, s32 originY, s32 side, s32 scrSide, s32 tableCount);
BOOL func_ov001_021a6278(void);
s32 func_ov001_021a62ac(void);
BOOL IsEmblemPointInGrid(s32 x, s32 y);
s32 func_ov001_021a6300(void);
s32 func_ov001_021a6314(void);
s32 func_ov001_021a6328(void);
s32 func_ov001_021a633c(void);
void func_ov001_021a6350(s32 x, s32 y);
s32 func_ov001_021a637c(void);
void func_ov001_021a6388(s32 sizeIndex);
s32 func_ov001_021a639c(void);
void func_ov001_021a63a8(s32 mode);
u8 func_ov001_021a63b4(void);
void func_ov001_021a63c0(u8 cellValue);
void func_ov001_021a63cc(s32 shift);
void func_ov001_021a63d8(void);
