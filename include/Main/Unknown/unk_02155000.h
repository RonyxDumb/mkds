#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
extern u8 data_02155048[];
extern u8 data_02155098[];
extern u8 data_021550a8[];
extern void (*data_02155a20[])(void *param_1);
extern u8 data_02155a64[];
extern const Vec3 data_021557ec;
extern s32 data_02155854[];
struct Unk0201ca6c;
struct Unk0206bcb0;

// Three pairs of words (func_02082e4c).
typedef struct Unk02155808 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void (*mUnk_04)(struct Unk0201ca6c *p, s32 a);
} Unk02155808;

extern Unk02155808 data_02155808[3];
extern Vec3 data_02155a08;
extern u32 data_021557f8[];
extern s32 data_02155800[];
extern Vec3 data_02155818[];
extern void (*data_02155830[])(struct Unk0206bcb0 *p);
extern Vec3 data_02155a14;
extern Vec3 data_02155a48;
extern Vec3 data_02155eb0;
extern Vec3 data_02155ebc;

// 12-byte entries; func_02088390 reads the string pointer at 0x00.
typedef struct Unk02155cf4 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ u8 mUnk_04[8];
} Unk02155cf4;

extern const Unk02155cf4 data_02155cf4[];
extern Vec3 data_02155a3c;
extern const u32 data_02155a54;
extern const u16 data_02155a74[12];
