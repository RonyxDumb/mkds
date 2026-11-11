#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_020debec.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020de000.h"
#include "Main/Unknown/unk_021759c0.h"

const Unk0215a64c gPooledItemBoxKindDescriptor = {0,
                                                  0x108,
                                                  InitPooledItemBox,
                                                  CreatePooledItemBoxKindData,
                                                  CreateItemBoxShadowDrawList,
                                                  CreateQuestionDrawList,
                                                  CreateBoxDrawList,
                                                  {0}};

const MapObjectKindData gPooledItemBoxKindData = {0, 0, 0, 0xf000, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0};

BOOL IsRaceSceneNormalOrReplay(void) {
    u32 result = 0;
    u32 isNormalOrReplay;
    if (GetCurrentSceneNumber() == 2) {
        s32 raceKind = gRaceSetup->mRaceKind;
        isNormalOrReplay = 1;
        if (raceKind != RACE_KIND_NORMAL && raceKind != RACE_KIND_REPLAY) {
            isNormalOrReplay = 0;
        }
        if (isNormalOrReplay != 0) {
            result = 1;
        }
    }
    return result;
}

BOOL IsMissionRunBossColumn(void) {
    u32 result = 0;
    s32 a = gRaceSetup->mMode;
    if (a != MODE_MISSION_RUN) {
        return result;
    }
    a = a == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1;
    if (a == 9) {
        result = 1;
    }
    return result;
}

MapObjectKindData *CreatePooledItemBoxKindData(void) {
    MapObjectKindData *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gPooledItemBoxKindData;
    return kindData;
}

void InitPooledItemBox(void *mapObject, void *row) {
    InitItemBox(mapObject, row);
    ParkMapObject(mapObject);
}

MapObject *AllocPooledMapObject(void) {
    u32 index = gPooledMapObjectNextIndex;
    MapObject **mapObjects = gPooledMapObjects;
    gPooledMapObjectNextIndex = index + 1;
    return mapObjects[index];
}

void ResetPooledMapObject(ItemBox *pooledObject) {
    UnparkMapObject(&pooledObject->mMapObject);
    pooledObject->mMapObject.mAlpha = 0x1f;
    pooledObject->mMapObject.mFlags &= ~2;
    pooledObject->mMapObject.mFlags &= ~8;
    pooledObject->mMapObject.mAlpha = 0x1f;
    pooledObject->mMapObject.mScale.x = 0;
    pooledObject->mMapObject.mScale.y = 0;
    pooledObject->mMapObject.mScale.z = 0;
    pooledObject->mBoxRotationIndex = 0;
    pooledObject->mQuestionRotationIndex = 0;
    pooledObject->mFramesSinceHit = 0x80;
}
