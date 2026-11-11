#include "01/code_021a2034.h"

#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"

void InitPeriodicEffectObjects(Unk021a2300 *objectList) {
    s32 objectIndex;
    EffectMapObject *object;
    RaceProgress *raceProgress;
    RandomState64 *localRandom;

    if (objectList != NULL) {
        objectIndex = 0;
        while (objectIndex < objectList->mUnk_04 && (object = objectList->mUnk_00[objectIndex]) != NULL) {
            raceProgress = gRaceProgress;
            localRandom = &raceProgress->mLocalRandom;
            localRandom->mValue = (s64) localRandom->mMultiplier * (s64) localRandom->mValue + localRandom->mIncrement;
            object->mUnk_a0 = (u16) (((s64) (localRandom->mValue >> 32) * 0x46) >> 32);
            object->mUnk_02 &= ~2;
            object->mUnk_02 &= ~8;
            object->mUnk_66 = 0x1f;
            objectIndex++;
        }
    }
}

void UpdatePeriodicEffect(void *p0, EffectMapObject *object) {
    RaceProgress *raceProgress;
    RandomState64 *localRandom;

    object->mUnk_a0 -= 1;
    if (object->mUnk_a0 < 0) {
        raceProgress = gRaceProgress;
        localRandom = &raceProgress->mLocalRandom;
        localRandom->mValue = (s64) localRandom->mMultiplier * (s64) localRandom->mValue + localRandom->mIncrement;
        object->mUnk_a0 = (u16) (((s64) (localRandom->mValue >> 32) * 0x46) >> 32) + 0x46;
        if (!(object->mUnk_02 & 0x12)) {
            StartEffect(0x435, &object->mUnk_04);
        }
    }
}

void *CreatePeriodicEffectUpdateList(void) {
    return CreateMapObjectUpdateList(InitPeriodicEffectObjects, UpdatePeriodicEffect, NULL);
}

void ComputePointAheadOfCamera(EffectMapObject *object, Camera *camera, Vec3 *out) {
    out->x = camera->mPos.x + MUL_FIXED12_NO_ROUND(camera->mForward.x, 0x58000);
    out->y = object->mUnk_04.y;
    out->z = camera->mPos.z + MUL_FIXED12_NO_ROUND(camera->mForward.z, 0x58000);
}

void UpdateCameraEffect(void *p0, EffectMapObject *object) {
    Camera *camera;
    Vec3 effectPosition = {0, 0, 0};

    camera = GetCurrentCamera();
    switch (object->mUnk_a0) {
        case 0:
            object->mUnk_a0 = 1;
            switch (object->mUnk_9c->mUnk_28) {
                case 0:
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
                    object->mUnk_a4 = StartEffect(0x42f, &camera->mPos);
                    break;
                case 1:
                    break;
                case 2:
                    StartEffect(0x43c, &effectPosition);
                    StartEffect(0x439, &effectPosition);
                    StartEffect(0x43a, &effectPosition);
                    StartEffect(0x43b, &effectPosition);
                    StartEffect(0x438, &effectPosition);
                    StartEffect(0x43d, &effectPosition);
                    StartEffect(0x43e, &effectPosition);
                    StartEffect(0x43f, &effectPosition);
                    ComputePointAheadOfCamera(object, camera, &effectPosition);
                    object->mUnk_a4 = StartEffect(0x437, &effectPosition);
                    break;
            }
            break;
        case 1:
            switch (object->mUnk_9c->mUnk_28) {
                case 0:
                    PlaceEffect(object->mUnk_a4, &camera->mPos);
                    break;
                case 1:
                    break;
                case 2:
                    ComputePointAheadOfCamera(object, camera, &effectPosition);
                    PlaceEffect(object->mUnk_a4, &effectPosition);
                    break;
            }
            break;
    }
}

void *CreateCameraEffectUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateCameraEffect, NULL);
}
