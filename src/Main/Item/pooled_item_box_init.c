#include "Main/Item/pooled_item_box_init.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/MapObjects/item_box.h"

#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/System/heap_call.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Item/pooled_item_box.h"

const MapObjectKindDescriptor gPooledItemBoxKindDescriptor = {0,
                                                              {0, 0},
                                                              0x108,
                                                              InitPooledItemBox,
                                                              CreatePooledItemBoxKindData,
                                                              CreateItemBoxShadowDrawList,
                                                              CreateQuestionDrawList,
                                                              CreateBoxDrawList};

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
    s32 value = gRaceSetup->mMode;
    if (value != MODE_MISSION_RUN) {
        return result;
    }
    value = value == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1;
    if (value == 9) {
        result = 1;
    }
    return result;
}

MapObjectKindData *CreatePooledItemBoxKindData(void) {
    MapObjectKindData *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gPooledItemBoxKindData;
    return kindData;
}

void InitPooledItemBox(void *mapObject, struct CourseMapRow *row, void *unused) {
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
    pooledObject->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    pooledObject->mMapObject.mFlags &= ~2;
    pooledObject->mMapObject.mFlags &= ~8;
    pooledObject->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    pooledObject->mMapObject.mScale.x = 0;
    pooledObject->mMapObject.mScale.y = 0;
    pooledObject->mMapObject.mScale.z = 0;
    pooledObject->mBoxRotationIndex = 0;
    pooledObject->mQuestionRotationIndex = 0;
    pooledObject->mFramesSinceHit = ITEM_BOX_HIT_FRAMES_MAX;
}
