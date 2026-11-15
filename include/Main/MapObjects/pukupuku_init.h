#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_draw_list_flags.h" // MapObjectDrawList
#include "Main/MapObjects/send_obj_shadow.h" // ShadowMatrix
#include "Main/MapObjects/pushed_motion.h" // PushedObject
#include "Main/MapObjects/attractor.h"
#include "Main/Menu/second_menu_scene.h"

#define PUKUPUKU_HEIGHT_RANGE_MAX 0x2bc000

typedef struct Rotary Rotary;

// Object InitPukupuku sets up, 0x10c bytes.
typedef struct Pukupuku {
    /* 00 */ PushedObject mPushedObject;
    /* b8 */ Vec3 mInitialPos;
    /* c4 */ u16 mJumpsUntilHighJump;
    /* c6 */ u8 mUnk_c6[0x2];
    /* c8 */ ShadowMatrix mShadowMatrix;
    /* fc */ s32 mInitialGroundY;
    /* 100 */ s32 mGroundYOffset;
    /* 104 */ s32 mGroundSlopeX;
    /* 108 */ s32 mGroundSlopeZ;
} Pukupuku;

void UpdateRotary(u32 unused, Rotary *object);
MapObjectList *CreateRotaryUpdateList(void);
MapObjectDrawList *CreateRotaryDrawList(void);
MapObjectKindData *CreateRotaryBridgeKindData(void);
MapObjectKindData *CreateRotaryRoomKindData(void);
MapObjectKindData *CreateRotaryGearTestCylinderKindData(void);
void InitPukupuku(Pukupuku *pukupuku, Vec3 *position);

extern const MapObjectDrawList gRotaryDrawListData;
extern const MapObjectKindData gRotaryBridgeKindData;
extern const MapObjectKindData gRotaryRoomKindData;
extern const MapObjectList gRotaryUpdateListData;
extern const MapObjectKindData gRotaryGearTestCylinderKindData;
extern StateCallbacks gPukupukuStateTable[4];

