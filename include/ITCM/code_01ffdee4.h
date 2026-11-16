#pragma once

#include "types.h"
#include "code_02147cd8.h" // Vec3s16

// Sixteen bytes; gKCollisionData.field8 points to an array of these, which col_collide indexes by halfwords.
typedef struct Unk0217b614_08 {
    /* 00 */ s32 field0;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u16 field8;
    /* 0a */ u16 fieldA;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
} Unk0217b614_08;

// Object at gKCollisionData (0x3c bytes): three tables, a tree of word offsets, three words, three masks and three
// shift counts.
typedef struct CourseCollision {
    /* 00 */ Vec3 *field0;
    /* 04 */ Vec3s16 *field4;
    /* 08 */ Unk0217b614_08 *field8;
    /* 0c */ u8 *fieldC;
    /* 10 */ u8 field10[4];
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ s32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
    /* 28 */ u32 field28;
    /* 2c */ u32 field2C;
    /* 30 */ u32 field30;
    /* 34 */ u32 field34;
    /* 38 */ u8 field38[4];
} CourseCollision;

BOOL col_collide(void *param_1, void *param_2, Vec3 *param_3, int param_4, u16 param_5, short param_6, void *param_7,
                   void *param_8, void *param_9, u32 *param_10, u32 *param_11, int *param_12, u16 *param_13,
                   u32 *param_14);
