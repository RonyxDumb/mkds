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

const Unk0215a680 gPooledItemBoxKindData = {{0, 0, 0, 0xf000, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0}};

BOOL IsRaceSceneNormalOrKind2(void) {
    u32 result = 0;
    u32 isNormalOrKind2;
    if (GetCurrentSceneNumber() == 2) {
        s32 raceKind = gRaceSetup->mRaceKind;
        isNormalOrKind2 = 1;
        if (raceKind != RACE_KIND_NORMAL && raceKind != 2) {
            isNormalOrKind2 = 0;
        }
        if (isNormalOrKind2 != 0) {
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

Unk0215a680 *CreatePooledItemBoxKindData(void) {
    Unk0215a680 *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
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
    UnparkMapObject(&pooledObject->mUnk_000);
    pooledObject->mUnk_000.mAlpha = 0x1f;
    pooledObject->mUnk_000.mFlags &= ~2;
    pooledObject->mUnk_000.mFlags &= ~8;
    pooledObject->mUnk_000.mAlpha = 0x1f;
    pooledObject->mUnk_000.mScale.x = 0;
    pooledObject->mUnk_000.mScale.y = 0;
    pooledObject->mUnk_000.mScale.z = 0;
    pooledObject->mBoxRotationIndex = 0;
    pooledObject->mQuestionRotationIndex = 0;
    pooledObject->mFramesSinceHit = 0x80;
}
