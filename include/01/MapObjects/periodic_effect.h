#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/attractor.h"

typedef struct Camera Camera;

// A periodic effect starts every PERIODIC_EFFECT_DELAY_BASE plus one frames plus a random number of frames below
// PERIODIC_EFFECT_DELAY_RANDOM_LIMIT, unless the object is flagged MAP_OBJECT_FLAGS_NOT_DRAWN; the first wait is the
// random part plus one.
#define PERIODIC_EFFECT_DELAY_BASE 0x46
#define PERIODIC_EFFECT_DELAY_RANDOM_LIMIT 0x46

// How far ahead of the camera, along its forward x and z, the AHEAD_OF_CAMERA effect is placed (88.0).
#define CAMERA_EFFECT_AHEAD_DISTANCE TO_FIXED12(88)

// Values of EffectMapObject.mCameraEffectState for the camera effect: START starts its effects once, FOLLOW then moves
// the effect in mEffectHandle every update.
enum {
    CAMERA_EFFECT_STATE_START,
    CAMERA_EFFECT_STATE_FOLLOW,
};

// Values of the first course setting of the camera effect: 0 starts its effects and keeps the last one on the camera
// position, 1 starts none, 2 starts its effects and keeps the last one on a point ahead of the camera
// (ComputePointAheadOfCamera).
enum {
    CAMERA_EFFECT_KIND_AT_CAMERA,
    CAMERA_EFFECT_KIND_NONE,
    CAMERA_EFFECT_KIND_AHEAD_OF_CAMERA,
};

// A map object that spawns an effect: the delay or camera effect state and the handle of the effect.
typedef struct EffectMapObject {
    /* 00 */ MapObject mMapObject;
    /* a0 */ union {
        s32 mEffectDelayFrames;
        s32 mCameraEffectState;
    };
    /* a4 */ void *mEffectHandle;
} EffectMapObject;

MapObjectList *CreateCameraEffectUpdateList(void);
void UpdateCameraEffect(void *mapObjectList, EffectMapObject *object);
// Writes into out the point CAMERA_EFFECT_AHEAD_DISTANCE ahead of the camera along its forward x and z, at the height
// of the object's mMapObject.mPos.y.
void ComputePointAheadOfCamera(EffectMapObject *object, Camera *camera, Vec3 *out);
MapObjectList *CreatePeriodicEffectUpdateList(void);
void UpdatePeriodicEffect(void *mapObjectList, EffectMapObject *object);
void InitPeriodicEffectObjects(MapObjectList *objectList);

extern MapObjectKindDescriptor gCameraEffectKindDescriptor;
extern MapObjectKindDescriptor gPeriodicEffectKindDescriptor;
