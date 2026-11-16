#pragma once
#include "types.h"
#include "Main/Item/pooled_map_object.h"
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

// The map object manager: the map object array, the draw and update lists and the flags for the special kinds present.
typedef struct MapObjects {
    /* 000 */ MapObject **mMapObjects;
    // Pinned at 0xff when the 0x100-pointer array is full.
    /* 004 */ vu16 mMapObjectCount;
    /* 006 */ u8 mUnk_006[2];
    /* 008 */ MapObjectList *mDrawLists[24];
    /* 068 */ MapObjectList *mFirstPassDrawLists[24];
    /* 0c8 */ MapObjectList *mSecondPassDrawLists[24];
    /* 128 */ u16 mDrawListCount;
    /* 12a */ u16 mFirstPassDrawListCount;
    /* 12c */ u16 mSecondPassDrawListCount;
    /* 12e */ u8 mUnk_12e[2];
    /* 130 */ BOOL mDrawListsBuilt;
    /* 134 */ MapObjectList *mUpdateLists[16];
    /* 174 */ u16 mUpdateListCount;
    /* 176 */ u8 mUnk_176[2];
    /* 178 */ BOOL mUpdateListsBuilt;
    /* 17c */ s32 mHasKoopaBlock;
    /* 180 */ s32 mHasRotary;
    /* 184 */ s32 mHasBridge;
    /* 188 */ s32 mHasMissionRunBox;
    /* 18c */ ItemObject mProbeItemObject;
    /* 2b8 */ s32 mRunUpdateLists;
} MapObjects;
