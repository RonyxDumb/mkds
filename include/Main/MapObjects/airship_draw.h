#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/code_020e005c.h" // GroupFollower
#include "Main/Item/item_koura_w.h" // CourseMapRow
#include "01/MapObjects/data_0209bc74.h"

// Object of kind 0x158 (Airship) with the GroupFollower base at 0xc8 (DrawAirship, InitAirshipObjects).
typedef struct Airship {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s16 mWobbleAngle;
    /* aa */ u8 mUnk_aa[2];
    /* ac */ s32 mWobbleOffset;
    /* b0 */ s32 mWobbleOffsetDelta;
    /* b4 */ s32 mWobbleMid;
    /* b8 */ s32 mWobbleAmplitude;
    /* bc */ u32 mWobbleAmplitudePerFrame;
    /* c0 */ s32 mWobbleAnglePerFrame;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ GroupFollower mUnk_c8;
    /* State number of this kind's own per-frame switch in UpdateAirship; this object does not use
       MapObject.mUnk_80's state machine; also written by the group pre-step */
    /* ec */ s32 mState;
} Airship;

// Array of object pointers: pointer to the array and the number of entries (InitAirshipObjects).
typedef struct AirshipObjectList {
    /* 00 */ Airship **mUnk_00;
    /* 04 */ u16 mUnk_04;
} AirshipObjectList;

void CreateAirship(void *mapObjectList);
void DrawAirship(void *mapObjectList, Airship *airship);
void InitAirshipObjects(AirshipObjectList *list);
s32 AirshipFX_CosIdx(s32 angle);
s32 AirshipFX_MulInline(s32 multiplicand, s32 multiplier);

extern struct MapObjectModel *gAirship;
