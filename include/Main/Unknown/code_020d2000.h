#pragma once

#include "types.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Unknown/code_020f36d8.h"

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
    /* 130 */ BOOL mUnk_130;
    /* 134 */ MapObjectList *mUpdateLists[16];
    /* 174 */ u16 mUpdateListCount;
    /* 176 */ u8 mUnk_176[2];
    /* 178 */ BOOL mUnk_178;
    /* 17c */ s32 mHasKoopaBlock;
    /* 180 */ s32 mUnk_180;
    /* 184 */ s32 mUnk_184;
    /* 188 */ s32 mUnk_188;
    /* 18c */ ItemObject mUnk_18c;
    /* 2b8 */ s32 mRunUpdateLists;
} MapObjects;

#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/Unknown/code_020d2c2c.h"
#include "Main/MapObjects/map_object.h"
