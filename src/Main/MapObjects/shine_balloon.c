#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/Race/standings_balloons.h"

#include "Main/MapObjects/map_objects_get.h"
#include "Main/MapObjects/map_object_list_count_get.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/map_object_park.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/trophy.h"
#include "Main/MapObjects/balloon.h"
#include "Main/MapObjects/balloon_target.h"
#include "Main/MapObjects/balloon_draw.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"

MapObjectKindDescriptor gShineBalloonKindDescriptor = {0,
                                                       {0, 0},
                                                       0xb4,
                                                       InitShineBalloon,
                                                       (MapObjectKindData * (*) (void) ) CreateShineBalloonKindData,
                                                       CreateShineBalloonDrawList,
                                                       NULL,
                                                       NULL,
                                                       CreateShineBalloonUpdateList,
                                                       NULL,
                                                       {NULL, NULL, NULL, NULL}};
const u16 gShineBalloonEndSecondFlag = 8;
const u16 gShineBalloonEndFlag = 2;
MapObjectModel *gShineBalloon;

void InitShineBalloon(u32 mapObjectArg) {
    u32 mapObjectCopy = mapObjectArg;
    u32 unusedValue;
    ParkMapObject((void *) mapObjectCopy);
}

void CreateShineBalloon(void *mapObjectList) {
    MapObjectModel *mapObjectModelNsbmd;

    mapObjectModelNsbmd = CreateMapObjectModelNsbmd(mapObjectList, "shine_balloon.nsbmd");
    gShineBalloon = mapObjectModelNsbmd;
    SetMapObjectModelPolygonId(mapObjectModelNsbmd, 0x3f);
}

void SetupDrawShineBalloon(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gShineBalloon);
}

void DrawShineBalloon(void *mapObjectList, ShineBalloonObject *shineBalloonObject) {
    s32 gxParam;
    Vec3 cameraOffset;
    Vec3 heightOffset;
    Vec3 pulseScale;
    Vec3 distanceScale;
    s32 scale;
    s32 cameraDistance;

    if (shineBalloonObject->mKart->mVisible == 0) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&shineBalloonObject->mMapObject.mPos), 0xc);
    heightOffset.y = GetKartBalloonOrShineHeight(shineBalloonObject->mKart) >> 4;
    heightOffset.x = 0;
    heightOffset.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &heightOffset, 3);
    scale = shineBalloonObject->mPulseScale;
    if (scale != 0x1000) {
        pulseScale.x = scale;
        pulseScale.y = scale;
        pulseScale.z = scale;
        NNS_G3dGeBufferOP_N(0x1b, &pulseScale, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &shineBalloonObject->mMapObject.mScale, 3);
    VEC_Subtract(&shineBalloonObject->mMapObject.mPos, &GetCurrentCamera()->mPos, &cameraOffset);
    cameraDistance = VEC_Mag(&cameraOffset);
    distanceScale.x = cameraDistance;
    distanceScale.y = cameraDistance;
    distanceScale.z = cameraDistance;
    NNS_G3dGeBufferOP_N(0x1b, &distanceScale, 3);
    DrawMapObjectModel(mapObjectList, gShineBalloon, shineBalloonObject);
}

void UpdateShineBalloon(void *mapObjectList, ShineBalloonObject *shineBalloonObject) {
    switch (shineBalloonObject->mState) {
        case 0:
            if (GetBalloonOrShineCount(shineBalloonObject->mKart->mIndex) == 0) {
                return;
            }
            shineBalloonObject->mTimer = 0x1e;
            shineBalloonObject->mPulseScaleSpeed = 0x19;
            shineBalloonObject->mState = 1;
            shineBalloonObject->mMapObject.mFlags &= ~2;
            shineBalloonObject->mMapObject.mFlags &= ~8;
            shineBalloonObject->mMapObject.mAlpha = 0x1f;
            break;
        case 1:
            if (shineBalloonObject->mTimer-- > 0) {
                return;
            }
            shineBalloonObject->mTimer = 0;
            shineBalloonObject->mPulseScale += shineBalloonObject->mPulseScaleSpeed;
            shineBalloonObject->mPulseScaleSpeed -= 4;
            if (shineBalloonObject->mPulseScaleSpeed < 0) {
                if (shineBalloonObject->mPulseScale <= 0x4a) {
                    shineBalloonObject->mPulseScale = 0x4a;
                    shineBalloonObject->mState = 2;
                }
            }
            shineBalloonObject->mMapObject.mPos = shineBalloonObject->mKart->mPos;
            break;
        case 2:
            if (GetBalloonOrShineCount(shineBalloonObject->mKart->mIndex) == 0) {
                shineBalloonObject->mTimer = 0x1e;
                shineBalloonObject->mPulseScaleSpeed = 8;
                shineBalloonObject->mState = 3;
            }
            shineBalloonObject->mMapObject.mPos = shineBalloonObject->mKart->mPos;
            break;
        case 3:
            if (shineBalloonObject->mTimer-- <= 0) {
                shineBalloonObject->mTimer = 0;
                shineBalloonObject->mPulseScale += shineBalloonObject->mPulseScaleSpeed;
                shineBalloonObject->mPulseScaleSpeed -= 4;
                if (shineBalloonObject->mPulseScaleSpeed < 0) {
                    if (shineBalloonObject->mPulseScale <= 0) {
                        shineBalloonObject->mPulseScale = 0;
                        shineBalloonObject->mState = 0;
                        shineBalloonObject->mMapObject.mFlags |= gShineBalloonEndFlag;
                        shineBalloonObject->mMapObject.mFlags |= gShineBalloonEndSecondFlag;
                    }
                }
            }
            shineBalloonObject->mMapObject.mPos = shineBalloonObject->mKart->mPos;
            break;
    }
}

MapObjectKindData *CreateShineBalloonKindData(void) {
    return CreateMapObjectKindData(NULL, NULL, NULL, 1, 0);
}

MapObjectList *CreateShineBalloonDrawList(void) {
    return CreateMapObjectDrawList2(CreateShineBalloon, DrawShineBalloon, SetupDrawShineBalloon);
}

MapObjectList *CreateShineBalloonUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateShineBalloon, NULL);
}

void StartShineBalloon(Kart *kart) {
    ShineBalloonObject *shineBalloonObject;

    shineBalloonObject = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE_BALLOON));
    if (shineBalloonObject == NULL) {
        return;
    }
    shineBalloonObject->mMapObject.mPos.x = 0;
    shineBalloonObject->mMapObject.mPos.y = 0;
    shineBalloonObject->mMapObject.mPos.z = 0;
    shineBalloonObject->mMapObject.mPosStep.x = 0;
    shineBalloonObject->mMapObject.mPosStep.y = 0;
    shineBalloonObject->mMapObject.mPosStep.z = 0;
    shineBalloonObject->mKart = kart;
    shineBalloonObject->mPulseScale = 0;
    shineBalloonObject->mPulseScaleSpeed = 0;
    shineBalloonObject->mTimer = 0;
    shineBalloonObject->mState = 0;
}

// Creates b map objects of kind a from the source object c and parks each one that is not already parked.
void CreateParkedMapObjects(u32 kind, s32 count, void *object) {
    s32 index;
    MapObject *mapObject;

    for (index = 0; index < count; index++) {
        mapObject = CreateMapObjectFromObject(object, kind);
        if ((mapObject->mFlags & 0x100) == 0) {
            ParkMapObject(mapObject);
        }
    }
}

// Returns the first map object in the update list of kind a that has the parked bit 0x100, or NULL if there is none;
// changes nothing.
void *FindParkedMapObject(s32 kind) {
    MapObjectList *mapObjectList;
    void **mapObjects;
    s32 objectCount;
    s32 objectIndex;
    MapObject *mapObject;

    mapObjectList = FindMapObjectKindUpdateList(kind);
    mapObjects = GetMapObjects(mapObjectList);
    objectCount = GetMapObjectListCount(mapObjectList);
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        mapObject = mapObjects[objectIndex];
        if (mapObject->mFlags & 0x100) {
            return mapObject;
        }
    }
    return NULL;
}
