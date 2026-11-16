#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_020e005c.h" // GroupFollower

typedef struct CourseMapRow CourseMapRow;

// Object allocated by water_setupWaterCollision; 0x40 bytes.
typedef struct Unk020da414 {
    /* 00 */ s32 field0[0x10];
} Unk020da414;

// Object of kind 0x191 (Kuribo), at least 0x108 bytes; also created in pools by ov001.
typedef struct Kuribo {
    /* 00 */ MapObject field0;
    /* a0 */ s32 fieldA0;
    /* a4 */ Quaternion fieldA4;
    /* b4 */ Quaternion fieldB4;
    /* c4 */ s32 fieldC4;
    /* c8 */ s32 fieldC8;
    /* cc */ GroupFollower fieldCC;
    /* f0 */ u16 fieldF0;
    /* f2 */ u8 fieldF2[2];
    /* f4 */ s32 fieldF4;
    /* f8 */ u16 fieldF8;
    /* fa */ u8 fieldFA[2];
    /* fc */ s32 fieldFC;
    /* 100 */ u16 field100;
    /* 102 */ s16 field102;
    /* 104 */ s32 field104;
} Kuribo;

/* also runs for source-created objects with b == NULL (then only field100 is set) */
void kuribo_init(Kuribo *kuribo, CourseMapRow *row);
Unk020da414 *water_setupWaterCollision(void);
