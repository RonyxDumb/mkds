#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d6dc0.h"

// Object at 0x1d8 of Wanwan: a word at 0xa8.
typedef struct Unk020dc474_1d8 {
    /* 00 */ u8 field0[0xa8];
    /* a8 */ s32 fieldA8;
} Unk020dc474_1d8;

// Object of kinds 0x196 (with chain post kind 0x197) and 0x1a5 (fieldFC is 0 or 1) of Wanwan; wanwan_state3Update,
// wanwan_state2Update and the functions after it up to wanwan_setupCollision: vectors at 0x04, 0x10 and 0xa0, ring of
// four vector pointers at 0x160, words at 0xe8, 0xec, 0xf0 and 0x1fc.
typedef struct Wanwan {
    /* 00 */ MapObject field0;
    /* a0 */ Vec3 mCenterPos;
    /* ac */ s32 fieldAC;
    /* b0 */ s32 fieldB0;
    /* b4 */ Quaternion fieldB4;
    /* c4 */ Quaternion fieldC4;
    /* d4 */ Quaternion fieldD4;
    /* e4 */ s32 fieldE4;
    /* e8 */ s32 fieldE8;
    /* ec */ s32 fieldEC;
    /* f0 */ s32 fieldF0;
    /* f4 */ s32 fieldF4;
    /* f8 */ s32 fieldF8;
    /* fc */ s32 fieldFC;
    /* 100 */ SegmentProgress mSegmentProgress;
    /* 160 */ Vec3 *mCurvePoints[4];
    /* 170 */ Vec3 mCurvePointValues[4];
    /* 1a0 */ GroupFollowerWithSpeeds mFollower;
    /* 1d8 */ Unk020dc474_1d8 *mChainObject;
    /* 1dc */ s32 field1DC;
    /* 1e0 */ Vec3 field1E0;
    /* 1ec */ s32 mMaxRadius;
    /* 1f0 */ Vec3 *mKartPos;
    /* 1f4 */ Vec3 *mKartVelocity;
    /* 1f8 */ u16 field1F8;
    /* 1fa */ s16 field1FA;
    /* 1fc */ s32 field1FC;
    /* 200 */ Vec3 field200;
} Wanwan;

void wanwan_state3Update(Wanwan *wanwan);
