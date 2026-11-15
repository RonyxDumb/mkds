#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

typedef struct Camera Camera;

// A periodic effect starts again after PERIODIC_EFFECT_DELAY_MIN frames plus a random number of frames below
// PERIODIC_EFFECT_DELAY_SPREAD; the first start only waits the random part.
#define PERIODIC_EFFECT_DELAY_MIN 0x46
#define PERIODIC_EFFECT_DELAY_SPREAD 0x46

// How far ahead of the camera, along its forward direction, the camera effect is placed (88.0).
#define CAMERA_EFFECT_AHEAD_DISTANCE TO_FIXED12(88)

// Values of EffectMapObject.mUnk_a0 for the camera effect: start its effects, then keep them on the camera.
enum {
    CAMERA_EFFECT_STATE_START,
    CAMERA_EFFECT_STATE_FOLLOW,
};

typedef struct EffectMapObject {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mFlags;
    /* 04 */ Vec3 mPos;
    /* 10 */ u8 mUnk_10[0x56];
    /* 66 */ u16 mAlpha;
    /* 68 */ u8 mUnk_68[0x34];
    /* 9c */ CourseMapRow *mCourseMapRow;
    /* a0 */ union {
        s32 mEffectDelayFrames;
        s32 mCameraEffectState;
    };
    /* a4 */ void *mEffectHandle;
} EffectMapObject;

MapObjectList *CreateCameraEffectUpdateList(void);
void UpdateCameraEffect(void *mapObjectList, EffectMapObject *object);
// Writes into out the point CAMERA_EFFECT_AHEAD_DISTANCE ahead of the camera along its forward x and z, at the height
// of the object's mUnk_04.y.
void ComputePointAheadOfCamera(EffectMapObject *object, Camera *camera, Vec3 *out);
MapObjectList *CreatePeriodicEffectUpdateList(void);
void UpdatePeriodicEffect(void *mapObjectList, EffectMapObject *object);
void InitPeriodicEffectObjects(MapObjectList *objectList);

extern MapObjectKindDescriptor gCameraEffectKindDescriptor;
extern MapObjectKindDescriptor gPeriodicEffectKindDescriptor;
