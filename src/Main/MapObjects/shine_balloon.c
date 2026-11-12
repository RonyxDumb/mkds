#include "Main/MapObjects/shine_balloon.h"
#include "Main/Unknown/code_0209b634.h"
#include "fx_mtx33.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/MapObjects/bound.h"
#include "Main/Unknown/code_020a10f0.h"

#include "Main/Unknown/code_020ac6a8.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/MapObjects/map_objects_get.h"
#include "Main/MapObjects/map_object_list_count_get.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Unknown/code_020ac67c.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ac9fc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Race/race.h"

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

    if (shineBalloonObject->mUnk_ac->mVisible == 0) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&shineBalloonObject->mMapObject.mPos), 0xc);
    heightOffset.y = GetKartBalloonOrShineHeight(shineBalloonObject->mUnk_ac) >> 4;
    heightOffset.x = 0;
    heightOffset.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &heightOffset, 3);
    scale = shineBalloonObject->mUnk_a0;
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
            if (GetBalloonOrShineCount(shineBalloonObject->mUnk_ac->mIndex) == 0) {
                return;
            }
            shineBalloonObject->mTimer = 0x1e;
            shineBalloonObject->mUnk_a4 = 0x19;
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
            shineBalloonObject->mUnk_a0 += shineBalloonObject->mUnk_a4;
            shineBalloonObject->mUnk_a4 -= 4;
            if (shineBalloonObject->mUnk_a4 < 0) {
                if (shineBalloonObject->mUnk_a0 <= 0x4a) {
                    shineBalloonObject->mUnk_a0 = 0x4a;
                    shineBalloonObject->mState = 2;
                }
            }
            shineBalloonObject->mMapObject.mPos = shineBalloonObject->mUnk_ac->mPos;
            break;
        case 2:
            if (GetBalloonOrShineCount(shineBalloonObject->mUnk_ac->mIndex) == 0) {
                shineBalloonObject->mTimer = 0x1e;
                shineBalloonObject->mUnk_a4 = 8;
                shineBalloonObject->mState = 3;
            }
            shineBalloonObject->mMapObject.mPos = shineBalloonObject->mUnk_ac->mPos;
            break;
        case 3:
            if (shineBalloonObject->mTimer-- <= 0) {
                shineBalloonObject->mTimer = 0;
                shineBalloonObject->mUnk_a0 += shineBalloonObject->mUnk_a4;
                shineBalloonObject->mUnk_a4 -= 4;
                if (shineBalloonObject->mUnk_a4 < 0) {
                    if (shineBalloonObject->mUnk_a0 <= 0) {
                        shineBalloonObject->mUnk_a0 = 0;
                        shineBalloonObject->mState = 0;
                        shineBalloonObject->mMapObject.mFlags |= data_02156838;
                        shineBalloonObject->mMapObject.mFlags |= data_0215683c;
                    }
                }
            }
            shineBalloonObject->mMapObject.mPos = shineBalloonObject->mUnk_ac->mPos;
            break;
    }
}

void CreateShineBalloonKindData(void) {
    CreateMapObjectKindData(NULL, NULL, NULL, 1, 0);
}

void *CreateShineBalloonDrawList(void) {
    return CreateMapObjectDrawList2(CreateShineBalloon, DrawShineBalloon, SetupDrawShineBalloon);
}

void *CreateShineBalloonUpdateList(void) {
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
    shineBalloonObject->mUnk_ac = kart;
    shineBalloonObject->mUnk_a0 = 0;
    shineBalloonObject->mUnk_a4 = 0;
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
