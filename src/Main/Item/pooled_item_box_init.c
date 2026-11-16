#include "Main/Item/pooled_item_box_init.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/MapObjects/item_box.h"

#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/System/heap_call.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
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
