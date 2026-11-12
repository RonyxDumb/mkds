#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

typedef struct Camera Camera;

typedef struct EffectMapObject {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mFlags;
    /* 04 */ Vec3 mPos;
    /* 10 */ u8 mUnk_10[0x56];
    /* 66 */ u16 mAlpha;
    /* 68 */ u8 mUnk_68[0x34];
    /* 9c */ CourseMapRow *mCourseMapRow;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ void *mEffectHandle;
} EffectMapObject;

MapObjectList *CreateCameraEffectUpdateList(void);
void UpdateCameraEffect(void *p0, EffectMapObject *object);
// Writes into out the point 0x58000 (88.0) ahead of the camera along its forward x and z, at the height of
// the object's mUnk_04.y.
void ComputePointAheadOfCamera(EffectMapObject *object, Camera *camera, Vec3 *out);
MapObjectList *CreatePeriodicEffectUpdateList(void);
void UpdatePeriodicEffect(void *p0, EffectMapObject *object);
void InitPeriodicEffectObjects(MapObjectList *objectList);

extern MapObjectKindDescriptor gCameraEffectKindDescriptor;
extern MapObjectKindDescriptor gPeriodicEffectKindDescriptor;
