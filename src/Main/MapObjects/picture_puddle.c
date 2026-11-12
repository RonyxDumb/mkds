#include "Main/MapObjects/picture_puddle.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_0217b000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/data_02167000.h"
#include "Main/MapObjects/fireball2.h"
#include "Main/MapObjects/puddle_kind_data.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

MapObjectModel *gPuddle;

MapObjectKindDescriptor gPuddleKindDescriptor = {0, {0, 0}, 0xa0, 0, CreatePuddleKindData, CreatePuddleDrawList};

void CreatePuddle(void *mapObjectList) {
    gPuddle = CreateMapObjectModelNsbmd(mapObjectList, "puddle.nsbmd");
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
