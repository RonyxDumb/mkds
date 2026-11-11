#include "Main/Unknown/code_020f9c6c.h"
#include "code_02012b30.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020fe450.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1a24.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020fcbb8.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01fff000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020fc000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01fff434.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fcb9c.h"
#include "Main/Unknown/code_020fcedc.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020fd254.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

void MarkItemInUseAsActiveItem(ItemInUse *itemInUse) {
    itemInUse->mIsActiveItem = TRUE;
}

void ResetItemKouraW(ItemKouraW *item) {
    InitStateMachine(&item->mStateMachine, gItemKouraWStateTable, 8, item);
    MTX_Identity43_(&item->mUnk_2b4);
    item->mRank = 1;
    item->mRankKartIndex = gRaceProgress->mKartAtRank[0];
    item->mRankTargetSkipped = 0;
    item->mPosStrip = NULL;
    item->mSoundId = 0xdc;
    item->mKartMask = 0;
    item->mHitSpinsKart = 0;
}

void InitItemKouraWCommon(ItemKouraW *item) {
    ResetSoundDistanceSquaredChange(&item->mSoundDistanceSquaredChange);
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraWSoundTrackParams;
    item->mLinkFollowingItemObject.mDirectedItemObject.mUnk_160 = 0;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos =
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
    FreeItemObjectCollisionSlot(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= 0x200000;
    ClearItemKouraWKartItemsAndAngle(item);
    if (gRaceProgress->mRaceDone != 0) {
        item->mRank = 1;
        item->mRankKartIndex = gRaceProgress->mKartAtRank[(item->mRank & 0xff) - 1];
    } else {
        item->mRankKartIndex = gRaceProgress->mKartAtRank[(item->mRank & 0xff) - 1];
        while (IsKartEnded(item->mRankKartIndex) != 0 && item->mRank < (u32) gRaceSetup->mKartCount) {
            item->mRank++;
            item->mRankKartIndex = gRaceProgress->mKartAtRank[(item->mRank & 0xff) - 1];
        }
    }
    item->mLift = 0x32000;
    item->mUnk_264 = 0xf000;
    item->mDrawOffsetAngle = 0;
    item->mUnk_27c = 0x1a000;
    item->mSmoothedDirectionDelta.x = 0;
    item->mSmoothedDirectionDelta.y = 0;
    item->mSmoothedDirectionDelta.z = 0;
    VEC_Subtract(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
                 &item->mSmoothedDirectionDelta, &item->mPreviousDirection);
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer =
        &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos;
    InitCourseColorBlend(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mColorBlend, 1);
}

void SetItemKouraWKartItemsAndStateIfNone(ItemKouraW *item, s32 kartIndex) {
    Kart *kart;

    if (item->mKartItems != NULL) {
        return;
    }
    SetItemKouraWKartItems(item, kartIndex);
    kart = item->mKartItems->mKart;
    item->mStateMachine.mNextState =
        ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) ||
         (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE))
            ? 2
            : 3;
    item->mStateMachine.mNextStateRequested = 1;
}

s32 InitItemKouraW(ItemInUse *itemInUse, ItemKouraW *item) {
    Kart *kart;

    StartItemObjectSoundSource(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    if (itemInUse->mKartItems->mItemLink.mLink != NULL) {
        InitLinkFollowingItemFromInUse(&item->mLinkFollowingItemObject, itemInUse, 0x14, 0xcc, 1, 1, 0, 0x6000,
                                       item->mRankKartIndex, 1);
        SetStateMachineState(&item->mStateMachine, 1);
    } else {
        SetItemKouraWKartItems(item, (u16) gRaceProgress->mKartAtRank[0]);
        kart = item->mKartItems->mKart;
        item->mStateMachine.mNextState =
            ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) ||
             (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE))
                ? 2
                : 3;
        item->mStateMachine.mNextStateRequested = 1;
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
            AddItemDataItemIdAndKart(5, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
    }
    InitItemKouraWCommon(item);
    // one 36-byte copy of the three vectors (three Vec3 assignments give 0x160 bytes against 0x150)
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mAxes = itemInUse->mKartOrientation;
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
        item->mStateMachine.mNextState = 0;
        item->mStateMachine.mNextStateRequested = 1;
    }
    return 1;
}

void UpdateItemKouraWDrawPos(ItemKouraW *item) {
    Vec3 buf;
    s16 angleFactor;
    s32 a;

    a = item->mLift;
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) {
        item->mDrawOffsetAngle += 0x5dc;
        angleFactor = FX_SinIdx(item->mDrawOffsetAngle);
        VEC_MultAdd(a + MUL_FIXED12_NO_ROUND(item->mUnk_264, angleFactor),
                    &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal,
                    &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos, &buf);
        VEC_Subtract(&buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos, &buf);
        VEC_MultAdd(0x333, &buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos,
                    &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos);
    } else {
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.y +=
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y >> 1;
        item->mDrawOffsetAngle += 0x5dc;
        angleFactor = FX_SinIdx(item->mDrawOffsetAngle);
        a += MUL_FIXED12_NO_ROUND(item->mUnk_264, angleFactor);
        a = a + item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.y -
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.y;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.y += MUL_FIXED12_NO_ROUND(a, 0x19a);
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.x =
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.x;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos.z =
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.z;
    }
}

void UpdateItemKouraWOrientation(ItemKouraW *item, Vec3 *direction, s32 followDelta, Vec3 *normal) {
    Vec3 buf;
    Vec3 v3;
    Vec3 *previousDirection = &item->mPreviousDirection;
    Vec3 *smoothedDelta = &item->mSmoothedDirectionDelta;
    s32 ok;

    if (normal != NULL) {
        if (LENGTH_SQUARED(*direction) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(
                direction, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2]);
        }
        smoothedDelta->x = MUL_FIXED12_NO_ROUND(smoothedDelta->x, 0xccd);
        smoothedDelta->y = MUL_FIXED12_NO_ROUND(smoothedDelta->y, 0xccd);
        smoothedDelta->z = MUL_FIXED12_NO_ROUND(smoothedDelta->z, 0xccd);
        VEC_MultAdd(0x3000, smoothedDelta, normal, &buf);
        Vec3CrossUnrounded(&buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2],
                           &buf);
        if (LENGTH_SQUARED(buf) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(
                &buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0]);
        }
    } else {
        if (LENGTH_SQUARED(*direction) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(direction, &buf);
        }
        if (buf.x * buf.x + buf.z * buf.z < 0x112510) {
            return;
        }
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2] = buf;
        if (followDelta != 0) {
            smoothedDelta->x += MUL_FIXED12_NO_ROUND(direction->x - previousDirection->x - smoothedDelta->x, 0x148);
            smoothedDelta->z += MUL_FIXED12_NO_ROUND(direction->z - previousDirection->z - smoothedDelta->z, 0x148);
        } else {
            smoothedDelta->x = MUL_FIXED12_NO_ROUND(smoothedDelta->x, 0xc00);
            smoothedDelta->z = MUL_FIXED12_NO_ROUND(smoothedDelta->z, 0xc00);
        }
        v3 = gKouraWVec3UnitY;
        v3.x = MUL_FIXED12_NO_ROUND(smoothedDelta->x, 0x3000);
        v3.z = MUL_FIXED12_NO_ROUND(smoothedDelta->z, 0x3000);
        buf = v3;
        Vec3CrossUnrounded(&buf, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2],
                           &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0]);
        if ((s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].x *
                    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].x +
                (s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].y *
                    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].y +
                (s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].z *
                    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].z >=
            0x10) {
            ok = Vec3NormalizeAndGetLengthUnchecked(
                &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0],
                &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0]);
        } else {
            ok = 0;
        }
        if (ok == 0) {
            Vec3 t = {0, 0, 0};
            t.x = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].z;
            t.z = -item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0].x;
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0] = t;
        }
    }
    Vec3CrossUnrounded(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[2],
                       &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[0],
                       &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[1]);
    *previousDirection = *direction;
}

void AdvanceItemKouraW(ItemKouraW *item) {
    AdvanceStateMachine(&item->mStateMachine);
    ClearItemObjectCollisionBits(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0x3c000400u);
}

#pragma thumb off

void UpdateItemKouraWState0(ItemKouraW *item) {
    AdvanceItemObjectMotion((DirectedItemObject *) item, 0xd000);
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(
        &item->mSoundDistanceSquaredChange,
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
    if (item->mSoundId == 1) {
        return;
    }
    StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                             item->mSoundId, 0x7f, 0);
}

static inline Vec3 *func_020fbd98_inline(ItemKouraW *item) {
    if (item->mStateMachine.mState >= 3) {
        if (item->mKartItems->mKart->mUnk_48 & KART_48_ON_BOOST_SURFACE) {
            return &item->mKartItems->mKart->mGroundNormal;
        }
    } else if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) {
        return &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal;
    }
    return NULL;
}

void UpdateItemKouraWState1(ItemKouraW *item) {
    u32 i;
    s32 r;
    s32 v;
    void *normal;
    Kart *kart;

    if (item->mStateMachine.mStateFrames == 8) {
        item->mPosStrip = StartPosStrip(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer);
    }
    AdvanceLinkFollowingItem(&item->mLinkFollowingItemObject, item->mUnk_27c, 0x21, item->mRankKartIndex, 1);
    if (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(
            &item->mSoundDistanceSquaredChange,
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                                     item->mSoundId, 0x7f, 0);
        }
    }
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y -=
        MUL_FIXED12_NO_ROUND(item->mLinkFollowingItemObject.mDirectedItemObject.mSpeed, 0x66);
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    UpdateItemKouraWDrawPos(item);
    normal = func_020fbd98_inline(item);
    UpdateItemKouraWOrientation(item, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity, 1,
                                normal);
    if (item->mRankTargetSkipped == 0) {
        if (gRaceProgress->mRaceDone != 0) {
            item->mRank = 1;
            item->mRankKartIndex = GetKartAtRank(item->mRank);
        } else {
            item->mRankKartIndex = GetKartAtRank(item->mRank);
            while (IsKartEnded(item->mRankKartIndex) != 0 && (u32) item->mRank < gRaceSetup->mKartCount) {
                (item->mRank)++;
                item->mRankKartIndex = GetKartAtRank(item->mRank);
            }
        }
        if (item->mRankKartIndex ==
                (u16) (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
                         0x8000)
                           ? (u16) (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject
                                        .mOwnerKartIndexAndFlags &
                                    ~0xff00)
                           : 8) ||
            IsKartRemoved(GetKart(item->mRankKartIndex)) != 0) {
            item->mRankTargetSkipped = 1;
        } else {
            item->mKartMask |= 1 << item->mRankKartIndex;
        }
    }
    if (item->mRankTargetSkipped != 0) {
        u32 kartCount;
        kartCount = (u8) gRaceSetup->mKartCount;
        for (i = 1; i <= kartCount; i = (u16) (i + 1)) {
            item->mRankKartIndex = gRaceProgress->mKartAtRank[(u8) i - 1];
            if (IsKartRemoved(GetKart(item->mRankKartIndex)) == 0) {
                break;
            }
        }
        item->mKartMask |= 1 << item->mRankKartIndex;
    }
    if (TrySetItemKouraWKartItems(item, item->mRankKartIndex) != 0) {
        kart = item->mKartItems->mKart;
        r = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) ||
             (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE))
                ? 2
                : 3;
        item->mStateMachine.mNextState = r;
        item->mStateMachine.mNextStateRequested = 1;
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
            AddItemDataItemIdAndKart(5, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
        return;
    }
    r = (u16) GetRaceUpdateFramesMod8();
    if ((item->mKartMask & (1 << r)) != 0 && item->mRankKartIndex != r && IsKartEnded(r) != 0 &&
        TrySetItemKouraWKartItems(item, r) != 0) {
        kart = item->mKartItems->mKart;
        v = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) ||
             (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE))
                ? 2
                : 3;
        item->mStateMachine.mNextState = v;
        item->mStateMachine.mNextStateRequested = 1;
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
            AddItemDataItemIdAndKart(5, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
        return;
    }
    if (item->mStateMachine.mStateFrames <= 0xa8c) {
        return;
    }
    v = (u16) gRaceProgress->mKartAtRank[0];
    if (item->mKartItems != NULL) {
        return;
    }
    if ((u32) v >= 8) {
        v = 0;
    }
    SetItemKouraWKartItems(item, (u16) v);
    kart = item->mKartItems->mKart;
    r = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) ||
         (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE))
            ? 2
            : 3;
    item->mStateMachine.mNextState = r;
    item->mStateMachine.mNextStateRequested = 1;
}

void EnterItemKouraWState3(ItemKouraW *item) {
    item->mUnk_27c = VEC_Mag(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity);
    item->mUnk_284 = 0x1e000;
    if (item->mKartItems->mKartIndex == gRaceSetup->mEntryIndex) {
        item->mSoundId = 0xdd;
    }
}

void UpdateItemKouraWState3(ItemKouraW *item) {
    s32 gain;
    void *normal;
    Kart *kart;

    kart = item->mKartItems->mKart;
    gain = 0x800;
    if ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x10000000) &&
        (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        gain += 0x19a;
    }
    if (item->mUnk_27c > 0xd000) {
        item->mUnk_27c -= 0xccd;
    } else {
        item->mUnk_27c += 0xccd;
    }
    SteerItemKouraWAtAngleZero(item, gain, item->mUnk_27c, item->mUnk_284);
    if (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(
            &item->mSoundDistanceSquaredChange,
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                                     item->mSoundId, 0x7f, 0);
        }
    }
    if (HORIZONTAL_LENGTH_SQUARED(item->mToTarget) < 0x1900000000LL) {
        item->mStateMachine.mNextState = 4;
        item->mStateMachine.mNextStateRequested = 1;
    }
    UpdateItemKouraWDrawPos(item);
    normal = func_020fbd98_inline(item);
    UpdateItemKouraWOrientation(item, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity, 1,
                                normal);
}

void UpdateItemKouraWState2(ItemKouraW *item) {
    s32 i;
    void *normal;
    ItemPointLink *link;

    if (item->mUnk_27c > 0xd000) {
        item->mUnk_27c -= 0xccd;
    } else {
        item->mUnk_27c += 0xccd;
    }
    AdvanceLinkFollowingItem(&item->mLinkFollowingItemObject, item->mUnk_27c, 0x21, item->mRankKartIndex, 1);
    if (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(
            &item->mSoundDistanceSquaredChange,
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                                     item->mSoundId, 0x7f, 0);
        }
    }
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    UpdateItemKouraWDrawPos(item);
    normal = func_020fbd98_inline(item);
    UpdateItemKouraWOrientation(item, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity, 1,
                                normal);
    link = item->mKartItems->mItemLink.mLink;
    for (i = 0; i < 4; i++) {
        if (link == item->mLinkFollowingItemObject.mTargetLink.mLink) {
            item->mStateMachine.mNextState = 3;
            item->mStateMachine.mNextStateRequested = 1;
        }
        link = link->mNextLinks[0];
    }
}

void EnterItemKouraWState4(ItemKouraW *item) {
    item->mUnk_264 = 0x5000;
    item->mAngleStep = 0x3e8;
    VEC_Subtract(&item->mToTarget, &item->mSmoothedDirectionDelta, &item->mPreviousDirection);
    if (item->mPosStrip != NULL) {
        StopPosStrip(item->mPosStrip);
        item->mPosStrip = NULL;
    }
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
        AddItemDataItemIdAndKart(5, item->mKartItems->mKartIndex,
                                 item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
    }
}

void UpdateItemKouraWState4(ItemKouraW *item) {
    Vec3 direction;
    void *normal;

    if (item->mUnk_27c > 0xd000) {
        item->mUnk_27c -= 0xccd;
    } else {
        item->mUnk_27c += 0xccd;
    }
    item->mLift -= 0xccd;
    item->mAngleStep += 0x2d;
    if ((u32) item->mAngle < 0x8000) {
        item->mUnk_284 -= 0x666;
    } else {
        item->mUnk_284 -= 0xccd;
    }
    SteerItemKouraWToNextAnglePoint(item, 0x4cd, item->mUnk_27c, item->mUnk_284, item->mAngleStep);
    if (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(
            &item->mSoundDistanceSquaredChange,
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource,
                                     item->mSoundId, 0x7f, 0);
        }
    }
    UpdateItemKouraWDrawPos(item);
    if ((u32) item->mAngle < 0x11f40) {
        normal = func_020fbd98_inline(item);
        if (normal != NULL) {
            direction.x = item->mAnglePointOffset.x * 2;
            direction.y = item->mAnglePointOffset.y * 2;
            direction.z = item->mAnglePointOffset.z * 2;
            Vec3CrossUnrounded(normal, &direction, &direction);
            VEC_MultAdd(MUL_FIXED12_NO_ROUND(item->mAngle - 0x10000, 0xccd), normal, &direction, &direction);
        } else {
            direction.x = MUL_FIXED12_NO_ROUND(item->mAnglePointOffset.z, 0x2000);
            direction.y = MUL_FIXED12_NO_ROUND(item->mAngle - 0x10000, 0xccd);
            direction.z = -MUL_FIXED12_NO_ROUND(item->mAnglePointOffset.x, 0x2000);
        }
        if (item->mStateMachine.mStateFrames == 0) {
            VEC_Subtract(&direction, &item->mSmoothedDirectionDelta, &item->mPreviousDirection);
        }
        UpdateItemKouraWOrientation(item, &direction, 1, normal);
        return;
    }
    item->mStateMachine.mNextState = 5;
    item->mStateMachine.mNextStateRequested = 1;
}

void EnterItemKouraWState5(ItemKouraW *item) {
    enum { K0 } kind;

    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer ==
        &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos) {
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos =
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDrawPos;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer =
            &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
    }
    item->mLift = 0x28000;
    item->mUnk_264 = 0x333;
    kind = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mUnk_100 = gItemKinds[kind].mTargetScale;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= 0x800000;
    item->mEasedDirection = item->mPreviousDirection;
    item->mUnk_27c = 0x3000;
    item->mUnk_284 = 0x59a;
}

void UpdateItemKouraWState5(ItemKouraW *item) {
    Vec3 v;
    Vec3 *normal;
    s32 x;
    s32 y;
    s32 z;

    item->mLift += 0x4cd;
    SteerItemKouraWToKartForward(item, item->mUnk_264, item->mLift);
    if (item->mUnk_264 < 0xb33) {
        item->mUnk_264 += 0x52;
    }
    if (item->mLift > 0x2d000) {
        item->mStateMachine.mNextState = 6;
        item->mStateMachine.mNextStateRequested = 1;
    }
    item->mUnk_27c -= 0xa14;
    item->mUnk_284 -= 0x102;
    if (item->mUnk_284 < 0x7b) {
        item->mUnk_284 = 0x7b;
    }
    normal = func_020fbd98_inline(item);
    if (normal != NULL) {
        VEC_MultAdd(item->mUnk_27c, normal, &item->mKartForward, &v);
    } else {
        z = item->mKartForward.z;
        y = item->mUnk_27c;
        x = item->mKartForward.x;
        v.x = x;
        v.y = y;
        v.z = z;
    }
    VEC_Subtract(&v, &item->mEasedDirection, &v);
    VEC_MultAdd(item->mUnk_284, &v, &item->mEasedDirection, &item->mEasedDirection);
    UpdateItemKouraWOrientation(item, &item->mEasedDirection, 0, normal);
}

void EnterItemKouraWState6(ItemKouraW *item) {
    enum { K0 } kind;

    item->mLift = 0x28000;
    kind = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mUnk_100 = gItemKinds[kind].mTargetScale;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mUnk_100 += 0x800;
    CreateItemObjectCollisionSlotExact(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
}

void UpdateItemKouraWState6(ItemKouraW *item) {
    s32 grew;
    Vec3 hitOffset;

    item->mLift -= 0x7000;
    SteerItemKouraWToKartForward(item, 0xb33, item->mLift);
    if (item->mLift < -0x32000) {
        FadeOutEndedItemObject(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0);
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
            AddItemDataItemIdAndKart(5, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
    } else {
        Vec3 *position;

        position = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
        if (CollideSphereWithCourse(position, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPrevPos,
                                    0, item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCourseRadius, 4,
                                    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex,
                                    &hitOffset, NULL, NULL,
                                    &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionBits,
                                    NULL, NULL, NULL, NULL) != 0) {
            VEC_Add(&hitOffset, position, position);
            FadeOutEndedItemObject(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0);
            if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
                AddItemDataItemIdAndKart(5, item->mKartItems->mKartIndex,
                                         item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
            }
        }
    }
    grew = GrowItemObjectScale(
        &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject,
        gItemKinds[item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind].mTargetScale,
        gItemKinds[item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind].mScaleStep);
    if (EaseItemObjectScale(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject) != 0) {
        return;
    }
    if (grew) {
        RefreshItemObjectScale(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    }
}

void EnterItemKouraWState7(ItemKouraW *item) {
    NNSSndSeqPlayer **sndHandle;
    struct ModelEffect *effect;
    s32 *effectScale;

    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= 0x800000;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mUnk_100 = 0;
    item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScale = gKouraWState7StartScale;
    item->mModelEffect = StartModelEffect(
        1, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos,
        IsItemObjectTooFarForEffects(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject) == 0 ? 1 : 0);
    effect = item->mModelEffect;
    if (effect != NULL) {
        effectScale = effect->mScale;
        effectScale[0] = 0x1000;
        effectScale[1] = 0x1000;
        effectScale[2] = 0x1000;
    }
    StartItemObjectSoundIfNear(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0xdf);
    if (data_0217c780 & 1) {
        sndHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
        if (data_0217d084.mSeqStartEnabled != 0) {
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(sndHandle, 0, 0xe0);
        }
    }
    StartCameraWobbleAtDistance(
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
}

void UpdateItemKouraWState7(ItemKouraW *item) {
    u32 stateFrames;

    stateFrames = item->mStateMachine.mStateFrames;
    if (GrowItemObjectScale(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, gKouraWState7ScaleLimit,
                            gKouraWState7ScaleStep)) {
        RefreshItemObjectScaleExact(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    }
    if (stateFrames < 0x16) {
        return;
    }
    if (stateFrames == 0x16) {
        item->mHitSpinsKart = 1;
    } else if (stateFrames == 0x2a) {
        FreeItemObjectCollisionSlot(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    }
    if (stateFrames <= 0x55) {
        return;
    }
    ReleaseItemPoolObject(&gItemPools[item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind],
                          &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
}

void *CopyItemKouraWData(void *cursor, ItemKouraW *item, void *toData) {
    void *cursorAfterLink;
    void *cursorAfterObject;

    if (item != NULL && toData != NULL) {
        StoreItemDataFlagBit(Vec3DotUnrounded(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
                                              &item->mLinkFollowingItemObject.mDirectedItemObject.mDirection) < 0
                                 ? 1
                                 : 0,
                             &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y);
    }
    cursorAfterObject = CopyItemObjectData(cursor, item, toData);
    cursorAfterLink = CopyItemPointLinkIndex(
        cursorAfterObject, item != NULL ? (void *) &item->mLinkFollowingItemObject.mPreviousLink : 0, toData);
    if (item != NULL && toData == NULL) {
        LoadItemDataFlagBit(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y,
                            &item->mReverse);
    }
    if (item != NULL && toData != NULL) {
        return AddItemDataSizedByKind(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind);
    }
    return cursorAfterLink;
}

void InitItemKouraWFromData(ItemKouraW *item) {
    s32 kartIndex;
    DirectionQuaternion directionQuaternion;
    Kart *kart;
    s32 nextState;

    SetupItemObjectFromData(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    if (item->mLinkFollowingItemObject.mPreviousLink.mLink != NULL) {
        InitLinkFollowingItem(&item->mLinkFollowingItemObject, 0x14, 0xcc, 1, 0, item->mReverse,
                              gRaceProgress->mKartAtRank[0], 1);
        SetStateMachineState(&item->mStateMachine, 1);
    } else if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
        kartIndex = (u16) gRaceProgress->mKartAtRank[0];
        if (item->mKartItems == NULL) {
            SetItemKouraWKartItems(item, kartIndex);
            kart = item->mKartItems->mKart;
            nextState = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) ||
                         (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE))
                            ? 2
                            : 3;
            item->mStateMachine.mNextState = nextState;
            item->mStateMachine.mNextStateRequested = 1;
        }
    } else {
        kartIndex = (u16) gRaceProgress->mKartAtRank[0];
        SetItemKouraWKartItems(item, kartIndex);
        kart = item->mKartItems->mKart;
        nextState = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) ||
                     (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE))
                        ? 2
                        : 3;
        item->mStateMachine.mNextState = nextState;
        item->mStateMachine.mNextStateRequested = 1;
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
            AddItemDataItemIdAndKart(5, item->mKartItems->mKartIndex,
                                     item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        }
    }
    InitItemKouraWCommon(item);
    if ((s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.x *
                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.x +
            (s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y *
                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y +
            (s64) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.z *
                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
                                           &directionQuaternion.mDirection);
    }
    QuaternionFromYAxisToVec3(&directionQuaternion.mDirection, &directionQuaternion.mQuaternion);
    Matrix3x3FromQuaternion(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mAxes,
                            &directionQuaternion.mQuaternion);
}

void DrawItemKouraWModel(ItemKouraW *item, Vec3 *viewAxis, s32 model) {
    u32 alpha;
    Vec3 scale;
    void *matrix;

    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x2000) {
        if (IsItemObjectFartherFromCameraThan(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0x6a4) !=
            0) {
            return;
        }
    }
    scale.x = scale.z = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScale.x;
    scale.y = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScale.y;
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mAlpha != 0x1f) {
        u32 i;
        NNSG3dResMdl *o;

        o = gKouraW->mResMdl;
        alpha = (u16) item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mAlpha;
        for (i = 0; i < o->mInfo.mNumMat; i++) {
            NNS_G3dMdlSetMdlAlpha(o, i, alpha);
        }
    }
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x80000) {
        matrix = BuildItemObjectMatrix(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, viewAxis);
    } else {
        Vec3 *position;

        position = item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPosPointer;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[3].x = position->x >> 4;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[3].y = position->y >> 4;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx.mRows[3].z = position->z >> 4;
        matrix = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mTransformMtx;
    }
    DrawNsbmdWithMatrixAndMaxAlpha(gKouraW, matrix, &scale, 0x1f);
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mAlpha == 0x1f) {
        return;
    }
    {
        u32 i;
        NNSG3dResMdl *o;

        o = gKouraW->mResMdl;
        for (i = 0; i < o->mInfo.mNumMat; i++) {
            NNS_G3dMdlSetMdlAlpha(o, i, 0x1f);
        }
    }
}

void DrawItemKouraW(ItemKouraW *item, Vec3 *viewAxis, s32 model) {
    ModelEffect *effect;

    if (item->mStateMachine.mState != 7) {
        DrawItemKouraWModel(item, viewAxis, model);
        return;
    }
    effect = item->mModelEffect;
    if (effect == NULL) {
        return;
    }
    effect->mVisible = (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x10000) == 0;
}

// Asks for state 7 unless the object is already in it; returns 1.
s32 RequestItemKouraWState7(ItemKouraW *item) {
    if (item->mStateMachine.mState != 7) {
        InitStateMachine(&item->mStateMachine, gItemKouraWStateTable, 8, item);
        item->mStateMachine.mNextState = 7;
        item->mStateMachine.mNextStateRequested = 1;
        if ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x180000) == 0) {
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mAdvance =
                (void (*)(struct ItemObject *)) AdvanceItemKouraW;
        }
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &= ~0x8000;
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= 0x80000;
        CreateItemObjectCollisionSlotExact(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
        item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &= ~0x4000;
    }
    return 1;
}

BOOL IsItemKouraWState7(ItemKouraW *item) {
    return item->mStateMachine.mState == 7;
}

Vec3 *GetItemKouraWState7Info(ItemKouraW *item, s32 *stateFrames, s32 *scaleRatio) {
    *stateFrames = item->mStateMachine.mStateFrames;
    *scaleRatio = MUL_FIXED12_NO_ROUND(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mScale.z,
                                       gKouraWState7InverseLimit);
    return &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
}

#pragma thumb on

void SetupItemKouraWKind(void) {
    s32 scaleLimit;
    s32 radiusRatio;
    s32 maxRadius;

    gKouraWState7ScaleLimit = 0x1e000;
    gKouraWState7InverseLimit = FX_Div(0x1000, gKouraWState7ScaleLimit);
    gKouraWState7ScaleStep = 0x299a;
    scaleLimit = gKouraWState7ScaleLimit;
    radiusRatio = gItemKinds[5].mRadius;
    maxRadius = MUL_FIXED12_NO_ROUND(scaleLimit, radiusRatio);
    gKouraWState7MaxRadiusSquared = maxRadius;
    maxRadius >>= 12;
    gKouraWState7MaxRadiusSquared = maxRadius;
    gKouraWState7MaxRadiusSquared = maxRadius * maxRadius;
    gKouraW = CreateItemNsbmd(gKouraWNsbmdName, gKouraWNsbtxName);
    if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gKouraW->mResMdl, 0);
    }
}

#pragma thumb off

BOOL IsItemInfoObjectCountFree(s32 itemInfoIndex) {
    if (itemInfoIndex != 0x13) {
        return gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mObjectBudget -
                   gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mReservedCount >=
               gItemInfos[itemInfoIndex].mObjectCount;
    }
    return FALSE;
}

static inline BOOL func_020fab34_inline(s32 itemInfoIndex) {
    if (itemInfoIndex != 0x13) {
        return gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mObjectBudget -
                   gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mReservedCount >=
               gItemInfos[itemInfoIndex].mObjectCount;
    }
    return FALSE;
}

// Replaces the rolled item by the fallback item when nothing was rolled or no objects are free for it; returns TRUE
// when it did.
BOOL ReplaceUnavailableItem(s32 *itemInfoIndexPointer) {
    s32 itemInfoIndex;
    s32 dataSize;
    ItemInfo *itemInfo;
    s32 objectCount;

    itemInfoIndex = *itemInfoIndexPointer;
    if (itemInfoIndex == 0x13) {
        goto done;
    }
    if (gRaceSetup->mMode == MODE_WIFI) {
        itemInfo = &gItemInfos[itemInfoIndex];
        objectCount = itemInfo->mObjectCount;
        dataSize = objectCount * GetItemDataSize(itemInfo->mObjectKind, 0);
        if (func_020fab34_inline(itemInfoIndex) != FALSE && gWiFiRaceSync->mUnusedItemDataBytes >= dataSize) {
            return FALSE;
        }
    } else {
        if (func_020fab34_inline(itemInfoIndex) != FALSE) {
            return FALSE;
        }
    }
done:
    *itemInfoIndexPointer = gRaceSetup->mMode == MODE_WIFI ? 4 : 2;
    return TRUE;
}

BOOL TryReleaseItemObjectsForItemInfo(s32 itemInfoIndex) {
    ItemInfo *itemInfo;
    s32 objectCount;
    ItemPool *pool;
    enum { K0 } kind;

    itemInfo = &gItemInfos[itemInfoIndex];
    kind = itemInfo->mObjectKind;
    pool = &gItemPools[kind];
    objectCount = itemInfo->mObjectCount;
    while (pool->mObjectBudget - pool->mReservedCount < objectCount) {
        if (gItemKinds[kind].mLimit == 1) {
            return FALSE;
        }
        if (TryReleaseFirstItemObject(pool) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void ReleaseItemsAtFinish(void) {
    enum { K0 } poolIndex;
    u16 kartIndex;

    for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
        TryReleaseFirstItemObject(&gItemPools[poolIndex]);
    }
    for (kartIndex = 0; kartIndex < gKartItemsCount; kartIndex++) {
        ReleaseKartItems(&gKartItems[kartIndex]);
    }
}

void UpdateItems(void) {
    enum { K0 } poolIndex;
    u16 kartIndex;

    if (gRaceSetup->mMode == MODE_WIFI) {
        AddQueuedItemData();
        ProcessDelayedItemData();
    }
    for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
        if (gItemPools[poolIndex].mActiveCount != 0) {
            UpdateItemPool(&gItemPools[poolIndex]);
        }
    }
    for (kartIndex = 0; kartIndex < gKartItemsCount; kartIndex++) {
        UpdateKartItems(&gKartItems[kartIndex]);
    }
    AdvanceItemBlockTimers();
    UpdateOrthoQuads();
    UpdateBouncingItemBoxTimers();
}

void DrawItems(void *a) {
    enum { K0 } poolIndex;
    void *viewAxis;

    viewAxis = &((Unk020e6b38 *) GetViewTransposeMatrix())->mUnk_18;
    QueueViewMatrix();
    for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
        if (gItemPools[poolIndex].mTakenCount > 0 && gItemPools[poolIndex].mDrawnByMapObjects == 0) {
            DrawItemPool(&gItemPools[poolIndex], viewAxis);
        }
    }
}

void StartItemSlotForKart(s32 kartIndex, s32 forcedRowHandle, s32 shortSpin) {
    s32 playerKind;
    BOOL isHumanGhostOrPeer;

    if (gKartItems[kartIndex].mHeldItem.mItemInfoIndex != 0x13) {
        return;
    }
    playerKind = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
    if (playerKind == PLAYER_KIND_PEER) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        isHumanGhostOrPeer = FALSE;
        if ((u32) playerKind > 3) {
        } else if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
        StartItemSlot(&gKartItems[kartIndex], forcedRowHandle, GetBattleItemRank(kartIndex), isHumanGhostOrPeer ? 1 : 0,
                      shortSpin);
    } else {
        isHumanGhostOrPeer = FALSE;
        if ((u32) playerKind > 3) {
        } else if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
        StartItemSlot(&gKartItems[kartIndex], forcedRowHandle, GetKartRank(kartIndex), isHumanGhostOrPeer ? 1 : 0,
                      shortSpin);
    }
}

static inline s32 func_020fa4c8_inline(ItemObject *item, Kart *kart) {
    Vec3 previousDelta;
    Vec3 delta;
    s32 previousDistanceSquared;
    s32 distanceSquared;
    s32 radius;
    s32 x;
    s64 fullDistanceSquared;

    if (!(item->mFlags & 0x8000)) {
        return 1;
    }
    if (kart->mIndex !=
        (u16) (!(item->mOwnerKartIndexAndFlags & 0x8000) ? (u16) (item->mOwnerKartIndexAndFlags & ~0xff00) : 8)) {
        return 1;
    }
    if (item->mVelocity.x != 0 || item->mVelocity.y != 0 || item->mVelocity.z != 0 || kart->mForwardSpeed != 0) {
        VEC_Subtract(&item->mPrevPos, &kart->mPrevPointAlongUp, &previousDelta);
        previousDelta.y = 0;
        VEC_Subtract(&item->mPos, &kart->mPointAlongUp, &delta);
        delta.y = 0;
        previousDistanceSquared = Vec3DotUnrounded(&previousDelta, &previousDelta);
        distanceSquared = Vec3DotUnrounded(&delta, &delta);
        if (previousDistanceSquared - 0x1000 > distanceSquared) {
            return 1;
        }
    }
    radius = item->mRadius;
    x = item->mPos.x - kart->mPointAlongUp.x;
    fullDistanceSquared =
        (s64) (item->mPos.z - kart->mPointAlongUp.z) * (item->mPos.z - kart->mPointAlongUp.z) +
        ((s64) x * x + (s64) (item->mPos.y - kart->mPointAlongUp.y) * (item->mPos.y - kart->mPointAlongUp.y));
    return fullDistanceSquared < (s64) radius * radius ? 1 : 0;
}

// Returns how many item objects hit the kart; GetCollidedItemObject reads them.
s32 CollideKartWithItemObjects(Kart *kart) {
    s32 i;
    s32 hitCount;
    BOOL isFarFromEntryKart;
    s32 isHit;
    s32 hitCountCap;
    ItemObject *item;
    enum { K0 } kind;

    hitCount = 0;
    isFarFromEntryKart = (kart->mUnk_48 & 0x8000000) != 0;
    hitCountCap = 0xf;
    for (i = 0; i < gFoundCollisionSlotCount; i++) {
        if (!(gFoundCollisionSlotFlags[i] & 0x4000)) {
            continue;
        }
        item = gFoundCollisionSlotObjects[i];
        if (isFarFromEntryKart && !(item->mFlags & 0x200000)) {
            continue;
        }
        if (!IsItemObjectOverlappingKart(item, kart)) {
            continue;
        }
        isHit = func_020fa4c8_inline(item, kart);
        if (isHit == 0) {
            continue;
        }
        if ((kart->mUnk_7c & KART_7C_TERESA) && DoesItemObjectHurtKart(item) != 0) {
            continue;
        }
        gCollidedItemObjects[hitCount++] = item;
        if (item->mFlags & 0x1000) {
            RemoveItemInUseObject(&GetKartItems(item->mOwnerKartIndexAndFlags & ~0xff00)->mItemInUse, item);
        }
        kind = item->mKind;
        if (gItemKinds[kind].mEndsOnKartHit != 0) {
            if (DoesItemObjectHurtKart(item) != 0) {
                ApplyItemObjectPush(item, &kart->mCollisionCenter, &kart->mVelocity, &kart->mSignedTurnedForward);
                FadeOutItemObjectHitByKart(item, 1, (u16) kart->mIndex);
            } else {
                StartItemObjectReleaseSynced(item, 1);
            }
        }
        if (hitCount >= 0x10) {
            hitCount = hitCountCap;
        }
    }
    return hitCount;
}

#pragma thumb on

#pragma thumb off

struct ItemObject *GetCollidedItemObject(u32 index) {
    return gCollidedItemObjects[index];
}

#pragma thumb off

void *StartItemObjectOrZero(s32 kind, u16 kartIndex, void *pos, void *normal) {
    ItemObject *item;
    ItemPool *pool;

    item = 0;
    if (gItemPools[kind].mLimit - gItemPools[kind].mReservedCount <= 0) {
        return 0;
    }
    TakeItemPoolObjects(&gItemPools[kind], 1, &item, kartIndex, pos);
    pool = &gItemPools[kind];
    pool->mReservedCount++;
    StartItemObject(&gItemPools[item->mKind], item);
    SetItemObjectPlacement(item, pos, normal, 0, 0);
    if (kartIndex == 8) {
        item->mOwnerKartIndexAndFlags |= gItemObjectNoOwnerBit;
    }
    return item;
}

#pragma thumb on

static inline ItemObject *func_020fa3d0_inline(s32 kind, u16 kartIndex, void *pos, void *normal) {
    ItemObject *item;
    ItemPool *pool;

    item = 0;
    if (gItemPools[kind].mLimit - gItemPools[kind].mReservedCount <= 0) {
        return 0;
    }
    TakeItemPoolObjects(&gItemPools[kind], 1, &item, kartIndex, pos);
    pool = &gItemPools[kind];
    pool->mReservedCount++;
    StartItemObject(&gItemPools[item->mKind], item);
    SetItemObjectPlacement(item, pos, normal, 0, 0);
    if (kartIndex == 8) {
        item->mOwnerKartIndexAndFlags |= gItemObjectNoOwnerBit;
    }
    return item;
}

// Starts an item object at every course map row of object kind 0x6d and rests it on the floor.
void StartCourseMapItemObjects(void) {
    u32 i;
    u32 rowCount;
    u32 v;
    ItemObject *item;
    Vec3 normal;
    enum { K0 } kind;
    CourseMapRow *row;

    rowCount = gCourseMap->mRowCount;
    for (i = 0; i < rowCount; i++) {
        row = &gCourseMap->mRows[i];
        if (row->mKind == 0x6d) {
            kind = row->mUnk_28;
            if (CollideSphereWithCourse(&row->mUnk_00, 0, 0, 0xa000, 8, -2, 0, &normal, 0, 0, 0, 0, 0, &v) == 0) {
                normal = gCourseMapItemVec3UnitY;
            }
            item = func_020fa3d0_inline(kind, 8, row, &normal);
            if (item != 0) {
                void (*advance)(ItemObject *);

                kind = item->mKind;
                advance = gItemKinds[kind].mAdvance;
                if ((item->mFlags & 0x180000) == 0) {
                    item->mAdvance = advance;
                }
                StartRestingItemObject(item, &v);
            }
        }
    }
}

void InitItems(void) {
    void *heap;
    s32 objectIdCounter;
    s32 i;
    enum { K0 } kind;
    HeldItem *heldItem;
    u8 kartCount;

    heap = GetHeap(GetCurrentHeapCall());
    objectIdCounter = 0;
    CreateItemSlotTables();
    StartThunderBlockTimer(1);
    StartKouraWBlockTimer(1);
    StartGessoBlockTimer(1);
    CreateItemInfos();
    InitItemKinds();
    CreateItemPushVector();
    InitItemPointLinkDirections();
    kartCount = gRaceSetup->mKartCount;
    gKartItemsCount = kartCount;
    gKartItems = HeapAlloc(heap, kartCount * 0x210);
    for (i = 0; i < gKartItemsCount; i++) {
        InitKartItems(&gKartItems[i], (u16) i);
    }
    gItemPools = HeapAlloc(heap, 0x3b8);
    for (kind = 0; kind < 0xe; kind++) {
        CreateItemPool(&gItemPools[kind], kind, &objectIdCounter);
    }
    CreateItemModels();
    if (gRaceSetup->mMode == MODE_WIFI) {
        InitItemDataQueueLinks();
        InitItemDataDelayedLinks();
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        for (i = 0; i < gKartItemsCount; i++) {
            heldItem = &gKartItems[i].mHeldItem;
            SetHeldItem(heldItem, 5);
            switch (GetKartVariant((u16) i)) {
                case 0:
                    RemoveHeldItemObjects(heldItem, 1);
                    break;
                case 1:
                    RemoveHeldItemObjects(heldItem, 2);
                    break;
            }
        }
    }
    gCollidedItemObjects = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    StartCourseMapItemObjects();
    CreateItemTeresaFrameScaleTable();
    InitOrthoQuads();
    InitBouncingItemBoxTimers();
}

s32 GetItemDataSize(s32 itemKind, s32 messageKind) {
    switch (messageKind) {
        case 0:
            return (u8) ((u8) gItemKinds[itemKind].mDataSize + 1);
        case 1:
            return 0x12;
        case 2:
            return 3;
        case 3:
            return (u8) ((itemKind == 0xb ? 3 : 2) + 1);
    }
    return 0;
}

#pragma thumb off

s32 GrowItemObjectScale(ItemObject *item, s32 limit, s32 step) {
    if (item->mScale.z < limit) {
        item->mScale.z += step;
        if (item->mScale.z > limit) {
            item->mScale.z = limit;
        }
        return 1;
    }
    return 0;
}

void RefreshItemObjectScale(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    kind = item->mKind;
    item->mFlags |= 0x40;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &gItemKinds[kind];
    radiusRatio = kindInfo->mRadius;
    item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindInfo->mCourseRadius);
    item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, radiusRatio);
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
}

void RefreshItemObjectScaleExact(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    kind = item->mKind;
    item->mFlags |= 0x40;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &gItemKinds[kind];
    radiusRatio = kindInfo->mRadius;
    item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindInfo->mCourseRadius);
    item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, radiusRatio);
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius);
}

void SetItemObjectScaleByRatios(ItemObject *objectParam, s32 xRatio, s32 yRatio) {
    ItemObject *item = objectParam;
    enum { K0 } kind;
    s32 m;

    kind = item->mKind;
    m = gItemKinds[kind].mUnk_68;
    item->mScale.x = MUL_FIXED12_NO_ROUND(item->mScale.z, xRatio);
    item->mScale.y = MUL_FIXED12_NO_ROUND(item->mScale.z, yRatio);
    item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, gItemKinds[kind].mCourseRadius);
    item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, m);
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
}

BOOL SwingItemObjectScale(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    if (item->mUnk_100 <= -0x29 || item->mUnk_100 >= 0x29 || item->mScale.x - item->mScale.y <= -0x29 ||
        item->mScale.x - item->mScale.y >= 0x29) {
        kind = item->mKind;
        item->mFlags |= 0x40;
        item->mScale.y += item->mUnk_100;
        item->mUnk_100 += MUL_FIXED12_NO_ROUND(item->mScale.z - item->mScale.y, 0x333);
        item->mUnk_100 = MUL_FIXED12_NO_ROUND(item->mUnk_100, 0xc00);
        item->mScale.x = item->mScale.z * 2 - item->mScale.y;
        kindInfo = &gItemKinds[kind];
        radiusRatio = kindInfo->mRadius;
        item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindInfo->mCourseRadius);
        item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, radiusRatio);
        SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
        return 1;
    }
    item->mUnk_100 = 0;
    return 0;
}

BOOL EaseItemObjectScale(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    if (item->mUnk_100 != 0) {
        kind = item->mKind;
        item->mFlags |= 0x40;
        item->mScale.y += MUL_FIXED12_NO_ROUND(item->mUnk_100 - item->mScale.y, 0x333);
        item->mScale.x = item->mScale.z * 2 - item->mScale.y;
        kindInfo = &gItemKinds[kind];
        radiusRatio = kindInfo->mRadius;
        item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindInfo->mCourseRadius);
        item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, radiusRatio);
        SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
        return 1;
    }
    return 0;
}

void CreateItemObjectCollisionSlot(ItemObject *item) {
    if (item->mCollisionSlotIndex != -1) {
        return;
    }
    item->mCollisionSlotIndex = CreateCollisionSlot(&item->mPos, item->mRadius + 0xa000, 0x4000, item);
}

void CreateItemObjectCollisionSlotExact(ItemObject *item) {
    if (item->mCollisionSlotIndex != -1) {
        return;
    }
    item->mCollisionSlotIndex = CreateCollisionSlot(&item->mPos, item->mRadius, 0x4000, item);
}

#pragma thumb on
