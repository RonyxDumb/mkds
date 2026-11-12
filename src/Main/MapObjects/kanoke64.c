#include "Main/MapObjects/kanoke64.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/basabasa.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Race/course_list.h"
#include "Main/Kart/karts.h"

static inline u32 MapObjectRandomBelow(u32 limit) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return ((mapObjectRandom->mValue >> 32) * limit) >> 32;
}

static inline s64 XzDistanceSquared(const Vec3 *firstPos, const Vec3 *secondPos) {
    s32 deltaX;
    s32 deltaZ;

    deltaX = firstPos->x - secondPos->x;
    deltaZ = firstPos->z - secondPos->z;
    return (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
}

void CreateCow(void *mapObjectList) {
    gCow = CreateMapObjectModelNsbmdNsbtp(mapObjectList, gCowNsbmdName, gCowNsbtpName);
    SetMapObjectModelPolygonId(gCow, 0x3f);
}

void SetupDrawCow(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gCow);
}

void DrawCow(void *mapObjectList, MapObject *mapObject) {
    s32 commandArg;

    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&mapObject->mPos), 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gCow, mapObject->mCourseMapRow->mSettings[0]);
    DrawMapObjectModel(mapObjectList, gCow, mapObject);
}

void CreateCowDrawList(void) {
    CreateMapObjectDrawList2(CreateCow, DrawCow, SetupDrawCow);
}
