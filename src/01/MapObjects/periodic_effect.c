#include "01/MapObjects/periodic_effect.h"

#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Graphics/font_and_player_character.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Race/race_setup.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/bound.h"
#include "Main/System/init_after_startup.h"

MapObjectKindDescriptor gCameraEffectKindDescriptor = {0,
                                                       {0, 0},
                                                       0xa8,
                                                       NULL,
                                                       CreateEmptyMapObjectKindData,
                                                       NULL,
                                                       NULL,
                                                       NULL,
                                                       CreateCameraEffectUpdateList,
                                                       NULL,
                                                       {NULL, NULL, NULL, NULL}};
MapObjectKindDescriptor gPeriodicEffectKindDescriptor = {0,
                                                         {0, 0},
                                                         0xa0,
                                                         NULL,
                                                         CreateEmptyMapObjectKindData,
                                                         NULL,
                                                         NULL,
                                                         NULL,
                                                         CreatePeriodicEffectUpdateList,
                                                         NULL,
                                                         {NULL, NULL, NULL, NULL}};

void InitPeriodicEffectObjects(MapObjectList *objectList) {
    s32 objectIndex;
    EffectMapObject *object;
    RaceProgress *raceProgress;
    RandomState64 *localRandom;

    if (objectList != NULL) {
        objectIndex = 0;
        while (objectIndex < objectList->mMapObjectCount && (object = objectList->mMapObjects[objectIndex]) != NULL) {
            raceProgress = gRaceProgress;
            localRandom = &raceProgress->mLocalRandom;
            localRandom->mValue = (s64) localRandom->mMultiplier * (s64) localRandom->mValue + localRandom->mIncrement;
            object->mEffectDelayFrames =
                (u16) (((s64) (localRandom->mValue >> 32) * PERIODIC_EFFECT_DELAY_SPREAD) >> 32);
            object->mMapObject.mFlags &= ~2;
            object->mMapObject.mFlags &= ~8;
            object->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
            objectIndex++;
        }
    }
}

void UpdatePeriodicEffect(void *mapObjectList, EffectMapObject *object) {
    RaceProgress *raceProgress;
    RandomState64 *localRandom;

    object->mEffectDelayFrames -= 1;
    if (object->mEffectDelayFrames < 0) {
        raceProgress = gRaceProgress;
        localRandom = &raceProgress->mLocalRandom;
        localRandom->mValue = (s64) localRandom->mMultiplier * (s64) localRandom->mValue + localRandom->mIncrement;
        object->mEffectDelayFrames = (u16) (((s64) (localRandom->mValue >> 32) * PERIODIC_EFFECT_DELAY_SPREAD) >> 32) +
                                     PERIODIC_EFFECT_DELAY_MIN;
        if (!(object->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN)) {
            StartEffect(0x435, &object->mMapObject.mPos);
        }
    }
}

MapObjectList *CreatePeriodicEffectUpdateList(void) {
    return CreateMapObjectUpdateList(InitPeriodicEffectObjects, UpdatePeriodicEffect, NULL);
}

void ComputePointAheadOfCamera(EffectMapObject *object, Camera *camera, Vec3 *out) {
    out->x = camera->mPos.x + MUL_FIXED12_NO_ROUND(camera->mForward.x, CAMERA_EFFECT_AHEAD_DISTANCE);
    out->y = object->mMapObject.mPos.y;
    out->z = camera->mPos.z + MUL_FIXED12_NO_ROUND(camera->mForward.z, CAMERA_EFFECT_AHEAD_DISTANCE);
}

void UpdateCameraEffect(void *mapObjectList, EffectMapObject *object) {
    Camera *camera;
    Vec3 effectPosition = {0, 0, 0};

    camera = GetCurrentCamera();
    switch (object->mCameraEffectState) {
        case CAMERA_EFFECT_STATE_START:
            object->mCameraEffectState = CAMERA_EFFECT_STATE_FOLLOW;
            switch (object->mMapObject.mCourseMapRow->mSettings[0]) {
                case CAMERA_EFFECT_KIND_AT_CAMERA:
                    StartEffect(0x400, &effectPosition);
                    StartEffect(0x3ff, &effectPosition);
                    StartEffect(0x402, &effectPosition);
                    StartEffect(0x403, &effectPosition);
                    StartEffect(0x404, &effectPosition);
                    StartEffect(0x405, &effectPosition);
                    StartEffect(0x406, &effectPosition);
                    StartEffect(0x407, &effectPosition);
                    StartEffect(0x408, &effectPosition);
                    StartEffect(0x409, &effectPosition);
                    StartEffect(0x40a, &effectPosition);
                    StartEffect(0x40b, &effectPosition);
                    object->mEffectHandle = StartEffect(0x42f, &camera->mPos);
                    break;
                case CAMERA_EFFECT_KIND_NONE:
                    break;
                case CAMERA_EFFECT_KIND_AHEAD_OF_CAMERA:
                    StartEffect(0x43c, &effectPosition);
                    StartEffect(0x439, &effectPosition);
                    StartEffect(0x43a, &effectPosition);
                    StartEffect(0x43b, &effectPosition);
                    StartEffect(0x438, &effectPosition);
                    StartEffect(0x43d, &effectPosition);
                    StartEffect(0x43e, &effectPosition);
                    StartEffect(0x43f, &effectPosition);
                    ComputePointAheadOfCamera(object, camera, &effectPosition);
                    object->mEffectHandle = StartEffect(0x437, &effectPosition);
                    break;
            }
            break;
        case CAMERA_EFFECT_STATE_FOLLOW:
            switch (object->mMapObject.mCourseMapRow->mSettings[0]) {
                case CAMERA_EFFECT_KIND_AT_CAMERA:
                    PlaceEffect(object->mEffectHandle, &camera->mPos);
                    break;
                case CAMERA_EFFECT_KIND_NONE:
                    break;
                case CAMERA_EFFECT_KIND_AHEAD_OF_CAMERA:
                    ComputePointAheadOfCamera(object, camera, &effectPosition);
                    PlaceEffect(object->mEffectHandle, &effectPosition);
                    break;
            }
            break;
    }
}

MapObjectList *CreateCameraEffectUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateCameraEffect, NULL);
}
