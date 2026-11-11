#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e516c.h" // ShadowMatrix

// First argument of StartWoodbox1ItemObject.
typedef struct Woodbox1 {
    /* 000 */ MapObject mMapObject;
// mGroundUp plus mTiltOffset, normalized: the up direction of the tilted box.
    /* 0a0 */ Vec3 mTiltedUp;
    /* 0ac */ u16 mMatrixHeadingAngle;
    /* 0ae */ u16 mUnk_0ae;
    /* 0b0 */ Vec3 mBasePos;
// Up direction of the ground under the box; (0, 0x1000, 0) when the lookup finds none.
    /* 0bc */ Vec3 mGroundUp;
    /* 0c8 */ u16 mHeadingAngle;
    /* 0ca */ u8 mUnk_0ca[2];
    /* 0cc */ Vec3 mPosOffset;
// One of two stored vectors, stepped by mTiltOffsetPerFrame; leans mGroundUp.
    /* 0d8 */ Vec3 mTiltOffset;
    /* 0e4 */ Vec3 mTiltOffsetPerFrame;
    /* 0f0 */ u16 mHeadingAngleOffset;
    /* 0f2 */ u8 mUnk_0f2[2];
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ Vec3 mUnk_100;
    /* 10c */ u16 mUnk_10c;
// Index + 1 into the item table rows, 0 = none.
    /* 10e */ u16 mItemRowHandle;
// Chance in percent that breaking the box starts an item.
    /* 110 */ u16 mItemChancePercent;
    /* 112 */ u8 mUnk_112[2];
    /* 114 */ ShadowMatrix mUnk_114;
} Woodbox1;

extern Woodbox1 *gBouncingWoodbox1;

void StartWoodbox1ItemObject(Woodbox1 *woodbox, Vec3 *velocity);
void EnterWoodbox1State0(Woodbox1 *woodbox);
