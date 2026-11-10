#pragma once

#include "types.h"
#include "Main/Unknown/code_020467d0.h" // StateMachine
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"

// Object of item kind 11, element of gItemPools[11].
typedef struct ItemTeresa {
    /* 000 */ ItemObject mItemObject;
    /* 12c */ StateMachine mStateMachine;
    /* 140 */ s32 mPickedKartIndex;
// TRUE once the followed kart is hurt or the owner lost the Boo; the Boo then moves on the saved kart velocity.
    /* 144 */ BOOL mFollowEnded;
    /* 148 */ BOOL mPicksAheadFirst;
    /* 14c */ s32 mSavedOffsetY;
    /* 150 */ s32 mSavedOffsetVelocityY;
    /* 154 */ s32 mItemInfoIndex;
    /* 158 */ s32 mItemCount;
    /* 15c */ BOOL mFollowsPath;
    /* 160 */ s32 mItemObjectKind;
    /* 164 */ s16 mItemModelAlpha;
    /* 166 */ u8 mUnk_166[0x2];
    /* 168 */ Kart *mKart;
    /* 16c */ union {
        Vec3 mOffset;
        struct {
            /* 16c */ s32 mOffsetX;
            /* 170 */ s32 mOffsetY;
            /* 174 */ s32 mOffsetZ;
        };
    };
    /* 178 */ s32 mOffsetVelocityX;
    /* 17c */ s32 mOffsetVelocityY;
    /* 180 */ s32 mOffsetVelocityZ;
    /* 184 */ Vec3 mKartDrawMatrixPos;
    /* 190 */ Vec3 mKartVelocity;
    /* 19c */ s32 mOffsetAccelerationY;
    /* 1a0 */ s32 mStartOffsetVelocityY;
    /* 1a4 */ SegmentPoints mPathSegmentPoints;
    /* 248 */ s32 mPointIndex;
    /* 24c */ BOOL mUnk_24c;
    /* 250 */ s32 mPendingPickedKartIndex;
    /* 254 */ s32 mTakenItemInfoIndex;
    /* 258 */ s32 mTakenItemCount;
    /* 25c */ s32 mGivenItemInfoIndex;
    /* 260 */ s32 mGivenItemCount;
    /* 264 */ u32 mReportedState;
    /* 268 */ s32 mDelayTimer;
    /* 26c */ BOOL mStalled;
    /* 270 */ s32 mStallFrames;
} ItemTeresa;

s32 RemoveItemTeresaPickedKartItem(ItemTeresa *teresa);
void EnterItemTeresaState2(ItemTeresa *teresa);
s32 AdvanceItemTeresaFadeIn(ItemTeresa *teresa, s32 param_2, s32 param_3);
BOOL AdvanceItemTeresaFadeOut(ItemTeresa *teresa, s32 param_2, s32 param_3);
void AdvanceItemTeresaPath(ItemTeresa *teresa);
void EnterItemTeresaState0(ItemTeresa *teresa);
void PlaceItemTeresaAtKart(ItemTeresa *teresa, s32 param_2);
void UpdateItemTeresaState0(ItemTeresa *teresa);
void EnterItemTeresaState1(ItemTeresa *teresa);
void UpdateItemTeresaState1(ItemTeresa *teresa);
void PickItemTeresaKartBattle(ItemTeresa *teresa, s32 param_2);
void PickItemTeresaKartByRank(ItemTeresa *teresa, s32 param_2);
void UpdateItemTeresaState2(ItemTeresa *teresa);
void AdvanceItemTeresa(ItemTeresa *teresa);
void InitItemTeresa(ItemInUse *inUse, ItemTeresa *teresa);
