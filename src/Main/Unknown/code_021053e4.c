#include "Main/Unknown/code_021053e4.h"
#include "Main/System/Heap.h"
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

const Unk0215a64c data_0215a64c = {
    0, 0x108, func_02105464, func_02105480, ibox_setupShadowRenderPart, ibox_setupQuestionRenderPart, ibox_setupBoxRenderPart, {0}};

const Unk0215a680 data_0215a680 = {{0, 0, 0, 0xf000, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0}};

u32 IsInRaceSceneNormalOrReplay(void) {
    u32 result = 0;
    u32 isNormalOrKind2;
    if (scproc_getCurrentScene() == 2) {
        s32 raceKind = gRaceMultiConfig->mRaceKind;
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

u32 race_isBossBattle(void) {
    u32 result = 0;
    s32 a = gRaceMultiConfig->mMode;
    if (a != MODE_MISSION_RUN) {
        return result;
    }
    a = a == MODE_MISSION_RUN ? gRaceMultiConfig->mMissionTableColumn : -1;
    if (a == 9) {
        result = 1;
    }
    return result;
}

Unk0215a680 *func_02105480(void) {
    Unk0215a680 *data = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *data = data_0215a680;
    return data;
}

void func_02105464(void *mapObject, void *q) {
    ibox_init(mapObject, q);
    mobj_setInvisible(mapObject);
}

MapObject *AllocPooledMapObject(void) {
    u32 index = gPooledMapObjectNextIndex;
    MapObject **mapObjects = gPooledMapObjects;
    gPooledMapObjectNextIndex = index + 1;
    return mapObjects[index];
}

void ResetPooledMapObject(PooledMapObject *pooledObject) {
    mobj_setVisible(&pooledObject->field0);
    pooledObject->field0.mAlpha = 0x1f;
    pooledObject->field0.mFlags &= ~2;
    pooledObject->field0.mFlags &= ~8;
    pooledObject->field0.mAlpha = 0x1f;
    pooledObject->field0.mScale.x = 0;
    pooledObject->field0.mScale.y = 0;
    pooledObject->field0.mScale.z = 0;
    pooledObject->fieldA0 = 0;
    pooledObject->fieldA2 = 0;
    pooledObject->fieldA4 = 0x80;
}
