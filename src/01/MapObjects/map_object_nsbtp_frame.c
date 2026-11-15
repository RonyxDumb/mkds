#include "01/MapObjects/map_object_nsbtp_frame.h"

#include "01/MapObjects/hanachan_sound_and_item_hit.h"
#include "01/MapObjects/map_object_animation.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"

u32 GetMapObjectNsbtpFrameIndex(MissionRunMapObject *mapObject) {
    return GetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd);
}
