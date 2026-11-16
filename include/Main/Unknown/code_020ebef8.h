#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// First argument of wbox_trySpawnItem.
typedef struct Woodbox1 {
    /* 000 */ MapObject field0;
// mGroundUp plus mTiltOffset, normalized: the up direction of the tilted box.
    /* 0a0 */ Vec3 mTiltedUp;
    /* 0ac */ u16 mMatrixHeadingAngle;
    /* 0ae */ u16 fieldAE;
    /* 0b0 */ Vec3 mBasePos;
// Up direction of the ground under the box; (0, 0x1000, 0) when the lookup finds none.
    /* 0bc */ Vec3 mGroundUp;
    /* 0c8 */ u16 mHeadingAngle;
    /* 0ca */ u8 fieldCA[2];
    /* 0cc */ Vec3 mPosOffset;
// One of two stored vectors, stepped by mTiltOffsetPerFrame; leans mGroundUp.
    /* 0d8 */ Vec3 mTiltOffset;
    /* 0e4 */ Vec3 mTiltOffsetPerFrame;
    /* 0f0 */ u16 mHeadingAngleOffset;
    /* 0f2 */ u8 fieldF2[2];
    /* 0f4 */ Vec3 fieldF4;
    /* 100 */ Vec3 field100;
    /* 10c */ u16 field10C;
// Index + 1 into the item table rows, 0 = none.
    /* 10e */ u16 mItemRowHandle;
// Chance in percent that breaking the box starts an item.
    /* 110 */ u16 mItemChancePercent;
    /* 112 */ u8 field112[2];
    /* 114 */ u8 field114[4];
} Woodbox1;

extern Woodbox1 *data_0217bbf0;

// Argument of wbox_state0Init.
typedef struct Unk020ec194 {
    /* 000 */ u8 field0[4];
    /* 004 */ Vec3 field4;
    /* 010 */ Vec3 field10;
    /* 01c */ u8 field1C[0xc];
    /* 028 */ u8 field28[0x88];
    /* 0b0 */ Vec3 fieldB0;
    /* 0bc */ u8 fieldBC[0xc];
    /* 0c8 */ u16 fieldC8;
} Unk020ec194;

void wbox_trySpawnItem(Woodbox1 *woodbox, Vec3 *velocity);
void wbox_state0Init(Unk020ec194 *woodbox);
