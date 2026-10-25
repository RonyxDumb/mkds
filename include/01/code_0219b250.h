#pragma once

#include "types.h"

// Object whose member at 8 receives a value.
typedef struct Unk0219b250_Item {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mUnk_08;
} Unk0219b250_Item;

typedef struct Unk0219b250 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ Unk0219b250_Item *mUnk_1c;
    /* 20 */ Unk0219b250_Item *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mUnk_28;
} Unk0219b250;

typedef struct Unk0219b418 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ u8 mUnk_1c[0x10];
} Unk0219b418;

void func_ov001_0219b250(Unk0219b250 *p0);
void func_ov001_0219b25c(Unk0219b250 *p0, void *p1);
void func_ov001_0219b28c(Unk0219b250 *p0, void *p1);
void func_ov001_0219b2e8(Unk0219b250 *p0, char *p1);
void func_ov001_0219b31c(Unk0219b250 *p0, char *p1);
void func_ov001_0219b380(Unk0219b250 *p0, char *p1);
void func_ov001_0219b3b4(Unk0219b250 *p0, char *p1);
Unk0219b418 *func_ov001_0219b418(Unk0219b250 *p0, char *p1);
Unk0219b418 *func_ov001_0219b478(Unk0219b250 *p0, char *p1);
void *func_ov001_0219b4d8(char *p0);
void *func_ov001_0219b510(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4, u16 p5, u16 p6);
void func_ov001_0219b540(void);
