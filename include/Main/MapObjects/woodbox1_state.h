#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/send_obj_shadow.h" // ShadowMatrix

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
    /* 0f4 */ Vec3 mTiltOffsetOnOddFrame;
    /* 100 */ Vec3 mTiltOffsetOnEvenFrame;
    /* 10c */ u16 mStoredHeadingAngleOffset;
// Index + 1 into the item table rows, 0 = none.
    /* 10e */ u16 mItemRowHandle;
// Chance in percent that breaking the box starts an item.
    /* 110 */ u16 mItemChancePercent;
    /* 112 */ u8 mUnk_112[2];
    /* 114 */ ShadowMatrix mShadowMatrix;
} Woodbox1;

void StartWoodbox1ItemObject(Woodbox1 *woodbox, Vec3 *velocity);
void EnterWoodbox1Intact(void *stateObject);
