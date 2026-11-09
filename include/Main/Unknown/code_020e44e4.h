#pragma once

#include "types.h"
#include "Main/Unknown/unk_02158000.h" // MapObjectDrawList
#include "Main/Unknown/code_020e516c.h" // ShadowMatrix
#include "Main/Unknown/code_020ec538.h" // PushedObject

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

extern MapObjectList *gRotaryUpdateList;
extern MapObjectList data_02158e9c;

extern MapObjectDrawList data_02158ec4;

extern MapObjectKindData data_02158ef0;
extern MapObjectKindData data_02158f30;
extern MapObjectKindData data_02158f70;

void UpdateRotary(u32 unused, Rotary *object);
MapObjectList *CreateRotaryUpdateList(void);
MapObjectDrawList *CreateRotaryDrawList(void);
MapObjectKindData *CreateRotaryBridgeKindData(void);
MapObjectKindData *CreateRotaryRoomKindData(void);
MapObjectKindData *CreateRotaryGearTestCylinderKindData(void);
void InitPukupuku(Pukupuku *pukupuku, Vec3 *position);
