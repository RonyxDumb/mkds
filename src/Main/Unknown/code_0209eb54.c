#include "Main/Unknown/code_0209eb54.h"
#include "Main/Unknown/code_0209b634.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_02167000.h"

void CreatePuddle(void *mapObjectList) {
    gPuddle = CreateMapObjectModelNsbmd(mapObjectList, gPuddleNsbmdName);
}

void SetupDrawPuddle(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gPuddle);
}

void DrawPuddle(void *mapObjectList, MapObject *mapObject) {
    s32 commandParam;
    s32 posX;
    s32 posY;
    s32 posZ;
    Vec3 position;

    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    posZ = mapObject->mPos.z >> 4;
    posY = (mapObject->mPos.y + 0x1ccd) >> 4;
    posX = mapObject->mPos.x >> 4;
    position.x = posX;
    position.y = posY;
    position.z = posZ;
    NNS_G3dGeBufferOP_N(0x1c, &position, 3);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    NNS_G3dGeBufferOP_N(0x1a, &mapObject->mMatrix, 9);
    DrawMapObjectModel(mapObjectList, gPuddle, mapObject);
}
