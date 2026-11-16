#pragma once

#include "types.h"

typedef struct Camera Camera;

// Object whose address func_ov001_021a2048 receives as its second argument.
typedef struct Unk021a2048_9c {
    /* 00 */ u8 field0[0x28];
    /* 28 */ s16 field28;
} Unk021a2048_9c;

typedef struct Unk021a2048 {
    /* 00 */ u8 field0[2];
    /* 02 */ u16 field2;
    /* 04 */ Vec3 field4;
    /* 10 */ u8 field10[0x56];
    /* 66 */ u16 field66;
    /* 68 */ u8 field68[0x34];
    /* 9c */ Unk021a2048_9c *field9C;
    /* a0 */ s32 fieldA0;
    /* a4 */ void *fieldA4;
} Unk021a2048;

// Argument of func_ov001_021a2300: a table of objects and the number of its entries.
typedef struct Unk021a2300 {
    /* 00 */ Unk021a2048 **field0;
    /* 04 */ u16 field4;
} Unk021a2300;

void *func_ov001_021a2034(void);
void func_ov001_021a2048(void *p0, Unk021a2048 *p1);
// Writes into out the point 0x58000 (88.0) ahead of the camera g along its forward x and z, at the height of
// o->field4.y.
void ComputePointAheadOfCamera(Unk021a2048 *o, Camera *g, Vec3 *out);
void *func_ov001_021a226c(void);
void func_ov001_021a2284(void *p0, Unk021a2048 *p1);
void func_ov001_021a2300(Unk021a2300 *p);
