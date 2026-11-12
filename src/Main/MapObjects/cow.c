#include "Main/MapObjects/cow.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/basabasa.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/data_02166000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/data_0210b000.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bound.h"

MapObjectModel *gCow;

MapObjectKindDescriptor gCowKindDescriptor = {0, {0, 0}, 0xa0, 0, CreateEmptyMapObjectKindData, CreateCowDrawList};

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
    gCow = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "cow.nsbmd", "cow.nsbtp");
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

MapObjectList *CreateCowDrawList(void) {
    return CreateMapObjectDrawList2(CreateCow, DrawCow, SetupDrawCow);
}
