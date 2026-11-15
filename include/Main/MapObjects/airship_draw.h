#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/segment_group_collision.h" // GroupFollower
#include "Main/Item/item_koura_w.h" // CourseMapRow
#include "01/MapObjects/map_object_model.h"

#define AIRSHIP_WOBBLE_AMPLITUDE 0x50000
#define AIRSHIP_WOBBLE_ANGLE_PER_FRAME 0xb6

// Values of Airship.mState: waits for a kart on its second lap, raises the model to its place, then follows the path.
enum {
    AIRSHIP_STATE_WAIT_SECOND_LAP,
    AIRSHIP_STATE_RISE,
    AIRSHIP_STATE_FOLLOW_PATH,
};

// Object of kind 0x158 (Airship) with the GroupFollower base at 0xc8 (DrawAirship, InitAirshipObjects).
typedef struct Airship {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mModelHeightOffset;
    /* a4 */ s32 mPathSpeed;
    /* a8 */ u16 mWobbleAngle;
    /* aa */ u8 mUnk_aa[2];
    /* ac */ s32 mWobbleOffset;
    /* b0 */ s32 mWobbleOffsetDelta;
    /* b4 */ s32 mWobbleMid;
    /* b8 */ s32 mWobbleAmplitude;
    /* bc */ u32 mWobbleAmplitudePerFrame;
    /* c0 */ s32 mWobbleAnglePerFrame;
    /* c4 */ s32 mWobbleAnglePerFrameStep;
    /* c8 */ GroupFollower mGroupFollower;
    /* State number of this kind's own per-frame switch in UpdateAirship; this object does not use
       MapObject.mUnk_80's state machine; also written by the group pre-step */
    /* ec */ s32 mState;
} Airship;

// Array of object pointers: pointer to the array and the number of entries (InitAirshipObjects).
typedef struct AirshipObjectList {
    /* 00 */ Airship **mAirships;
    /* 04 */ u16 mCount;
} AirshipObjectList;

void CreateAirship(void *mapObjectList);
void DrawAirship(void *mapObjectList, Airship *airship);
void InitAirshipObjects(AirshipObjectList *list);
s32 AirshipFX_CosIdx(s32 angle);
s32 AirshipFX_MulInline(s32 multiplicand, s32 multiplier);

extern struct MapObjectModel *gAirship;
