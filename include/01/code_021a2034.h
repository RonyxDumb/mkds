#pragma once

#include "types.h"

typedef struct Camera Camera;

// Object whose address UpdateCameraEffect receives as its second argument.
typedef struct Unk021a2048_9c {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ s16 mUnk_28;
} Unk021a2048_9c;

typedef struct EffectMapObject {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0x56];
    /* 66 */ u16 mUnk_66;
    /* 68 */ u8 mUnk_68[0x34];
    /* 9c */ Unk021a2048_9c *mUnk_9c;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ void *mUnk_a4;
} EffectMapObject;

// Argument of InitPeriodicEffectObjects: a table of objects and the number of its entries.
typedef struct Unk021a2300 {
    /* 00 */ EffectMapObject **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021a2300;

void *CreateCameraEffectUpdateList(void);
void UpdateCameraEffect(void *p0, EffectMapObject *object);
// Writes into out the point 0x58000 (88.0) ahead of the camera along its forward x and z, at the height of
// the object's mUnk_04.y.
void ComputePointAheadOfCamera(EffectMapObject *object, Camera *camera, Vec3 *out);
void *CreatePeriodicEffectUpdateList(void);
void UpdatePeriodicEffect(void *p0, EffectMapObject *object);
void InitPeriodicEffectObjects(Unk021a2300 *objectList);
