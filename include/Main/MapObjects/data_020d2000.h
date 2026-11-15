#pragma once
#include "types.h"
#include "Main/Item/pooled_map_object.h"
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

// 0x2bc bytes.
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
