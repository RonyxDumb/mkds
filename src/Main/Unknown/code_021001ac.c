#include "Main/Unknown/code_021001ac.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fe4b4.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100de4.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ed578.h"
#include "Main/Unknown/code_020ed588.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02100700.h"
#include "Main/Unknown/code_02100704.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02100b78.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02100b84.h"
#include "Main/Unknown/code_02100dd8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020e6a74.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_021025d8.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "01/code_021a2034.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void TeresaMarkItemInUseAsActiveItem(ItemInUse *itemInUse) {
    itemInUse->mIsActiveItem = TRUE;
}

void ResetItemTeresa(ItemTeresa *teresa) {
    const StateCallbacks *stateTable;
    teresa->mItemInfoIndex = 0x13;
    teresa->mItemCount = 0;
    stateTable = gItemTeresaStateTable;
    teresa->mFollowsPath = 0;
    teresa->mItemObjectKind = 0xe;
    InitStateMachine(&teresa->mStateMachine, stateTable, 7, teresa);
    teresa->mPickedKartIndex = 8;
    teresa->mFollowEnded = 0;
    FreeItemObjectCollisionSlot(&teresa->mItemObject);
    teresa->mUnk_24c = 0;
    teresa->mPendingPickedKartIndex = 0xffffffff;
    teresa->mTakenItemInfoIndex = 0x12;
    teresa->mTakenItemCount = 0xffffffff;
    teresa->mGivenItemInfoIndex = 0x12;
    teresa->mGivenItemCount = 0xffffffff;
    teresa->mReportedState = 0xffffffff;
    teresa->mDelayTimer = 0;
    teresa->mStalled = 0;
    teresa->mStallFrames = 0;
}

static inline u32 ItemTeresaNextRandomBelow_inline(RandomState64 *random, u32 range) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (range == 0) {
        return random->mValue >> 32;
    }
    return ((random->mValue >> 32) * range) >> 32;
}

static inline s32 IsItemTeresaTargetKart_inline(KartItems *kartItems, RaceSetup *raceSetup, s32 teamIndex,
                                                u16 kartIndex) {
    KartItems *entry;
    Kart *kart;
    BOOL v2;
    s32 l;

    l = 1;
    v2 = TRUE;
    entry = &kartItems[kartIndex];
    kart = entry->mKart;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mUnk_7c & 0x400020) == 0) {
        v2 = FALSE;
    }
    if (v2 == FALSE && (kart->mUnk_4c & 0x10000800) == 0) {
        l = 0;
    }
    if (l | ((kart->mUnk_4c & 0x40) ? 1 : 0)) {
        v2 = FALSE;
    } else if (teamIndex != -1 && teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
        v2 = FALSE;
    } else {
        v2 = FALSE;
        if (entry->mHeldItem.mItemInfoIndex != 0x13 && entry->mHeldItem.mObjectStartFramesLeft == 0) {
            v2 = entry->mHeldItem.mItemInfoIndex != 0x10;
        }
    }
    return v2;
}

void PickItemTeresaKartByRank(ItemTeresa *teresa, s32 teamIndex) {
    u16 cumulativeWeights[7];
    u16 candidateKarts[7];
    u32 kartCount;
    RaceProgress *raceProgress;
    u32 rankBehind;
    u16 kartIndex;
    u16 randomValue;
    RandomState64 *random;
    u16 index;
    s32 candidateCount;
    u16 weightSum;
    u16 *weightCursor;
    u32 rankAhead;
    KartItems *kartItemsBehindFirst;
    RaceSetup *raceSetupBehindFirst;
    KartItems *kartItems;
    RaceSetup *raceSetup;

    kartCount = gRaceSetup->mKartCount;
    weightSum = candidateCount = 0;
    weightCursor = gItemTeresaPickWeights;
    rankBehind = rankAhead = GetKartRank((u16) ((teresa->mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0
                                                    ? (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~0xff00)
                                                    : 8));
    if (teresa->mPicksAheadFirst != FALSE) {
        raceProgress = gRaceProgress;
        kartItems = gKartItems;
        raceSetup = gRaceSetup;
        do {
            if (rankAhead > 1) {
                rankAhead = (u16) (rankAhead - 1);
                kartIndex = GetKartAtRank(rankAhead);
                if (IsItemTeresaTargetKart_inline(kartItems, raceSetup, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
            if (rankBehind < kartCount) {
                rankBehind = (u16) (rankBehind + 1);
                kartIndex = GetKartAtRank(rankBehind);
                if (IsItemTeresaTargetKart_inline(kartItems, raceSetup, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
        } while (rankBehind < kartCount || rankAhead > 1);
    } else {
        raceProgress = gRaceProgress;
        kartItemsBehindFirst = gKartItems;
        raceSetupBehindFirst = gRaceSetup;
        do {
            if (rankBehind < kartCount) {
                rankBehind = (u16) (rankBehind + 1);
                kartIndex = GetKartAtRank(rankBehind);
                if (IsItemTeresaTargetKart_inline(kartItemsBehindFirst, raceSetupBehindFirst, teamIndex, kartIndex) !=
                    0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
            if (rankAhead > 1) {
                rankAhead = (u16) (rankAhead - 1);
                kartIndex = GetKartAtRank(rankAhead);
                if (IsItemTeresaTargetKart_inline(kartItemsBehindFirst, raceSetupBehindFirst, teamIndex, kartIndex) !=
                    0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
        } while (rankBehind < kartCount || rankAhead > 1);
    }
    random = &raceProgress->mRandom;
    randomValue = weightSum == 0 ? 0 : ItemTeresaNextRandomBelow_inline(random, weightSum);
    for (index = 0; index < candidateCount; index++) {
        if (randomValue < cumulativeWeights[index]) {
            teresa->mPickedKartIndex = candidateKarts[index];
            return;
        }
    }
}

void PickItemTeresaKartBattle(ItemTeresa *teresa, s32 teamIndex) {
    RaceProgress *raceProgress;
    RandomState64 *random;
    s32 endIndex;
    s32 rowIndex;
    u32 kartCount;
    s32 skippedKartIndex;
    KartItems *kartItems;
    RaceSetup *raceSetup;
    s32 kartIndex;
    KartItems *entry;
    Kart *kart;
    s32 l;
    s32 n;
    u8 *row;

    raceProgress = gRaceProgress;
    random = &raceProgress->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    raceSetup = gRaceSetup;
    rowIndex = (u16) (((u64) (u32) (random->mValue >> 32) * 8) >> 32);
    endIndex = rowIndex + 8;
    kartCount = raceSetup->mKartCount;
    skippedKartIndex = (u16) ((teresa->mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0
                                  ? (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~0xff00)
                                  : 8);
    if (rowIndex >= endIndex) {
        return;
    }
    kartItems = gKartItems;
    row = &gItemTeresaBattleKartOrder[rowIndex];
    do {
        kartIndex = *row;
        if (kartIndex < kartCount && kartIndex != skippedKartIndex) {
            entry = &kartItems[kartIndex];
            kart = entry->mKart;
            n = l = 1;
            if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mUnk_7c & 0x400020) == 0) {
                n = 0;
            }
            if (n == 0 && (kart->mUnk_4c & 0x10000800) == 0) {
                l = 0;
            }
            if (l | ((kart->mUnk_4c & 0x40) ? 1 : 0)) {
                l = 0;
            } else if (teamIndex != -1 && teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                l = 0;
            } else {
                l = 0;
                if (entry->mHeldItem.mItemInfoIndex != 0x13 && entry->mHeldItem.mObjectStartFramesLeft == 0) {
                    l = entry->mHeldItem.mItemInfoIndex != 0x10;
                }
            }
            if (l != 0) {
                teresa->mPickedKartIndex = kartIndex;
                return;
            }
        }
        rowIndex++;
        row++;
    } while (rowIndex < endIndex);
}

void InitItemTeresa(ItemInUse *inUse, ItemTeresa *teresa) {
    Kart *kart;

    kart = inUse->mKart;
    StartKartTeresa(kart);
    StartEntryKartSound(kart, 0xf6);
    SetActiveItem(inUse->mKartItems, 0x10);
    InitCourseColorBlend(&teresa->mItemObject.mColorBlend, 1);
    if (inUse->mKartItems->mFlags & KART_ITEMS_DOWN) {
        teresa->mPicksAheadFirst = FALSE;
    } else {
        teresa->mPicksAheadFirst = TRUE;
    }
    SetStateMachineState(&teresa->mStateMachine, 0);
    teresa->mUnk_24c = TRUE;
}

void AdvanceItemTeresa(ItemTeresa *teresa) {
    Kart *kart;
    Vec3 *kartDrawMatrixPos;
    Vec3 offset;

    AdvanceStateMachine(&teresa->mStateMachine);
    VEC_Subtract(&teresa->mItemObject.mPos, &teresa->mItemObject.mPrevPos, &teresa->mItemObject.mVelocity);
    if (teresa->mItemObject.mPosPointer != &teresa->mItemObject.mDrawPos) {
        return;
    }
    kart = teresa->mKart;
    if (kart == NULL) {
        return;
    }
    kartDrawMatrixPos = &kart->mDrawMatrixPos;
    VEC_Subtract(&teresa->mItemObject.mPos, kartDrawMatrixPos, &offset);
    MTX_MultVec33(&offset, GetViewTransposeMatrix(), &offset);
    VEC_Add(kartDrawMatrixPos, &offset, &teresa->mItemObject.mDrawPos);
}

void PlaceItemTeresaAtKart(ItemTeresa *teresa, s32 shiftAlongCameraSide) {
    Kart *kart;
    Vec3 *position;
    Camera *camera;
    Vec3 *cameraSide;
    s32 delta[3];
    s32 k;
    BOOL m;
    s32 easeFactor;
    s32 maxOffsetChange;
    s32 sideDistance;
    s32 scaledRadius;

    kart = teresa->mKart;
    camera = GetCurrentCamera();
    position = &teresa->mItemObject.mPos;
    k = m = TRUE;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mUnk_7c & 0x400020) == 0) {
        k = 0;
    }
    if (k == 0 && (kart->mUnk_4c & 0x10000800) == 0) {
        m = FALSE;
    }
    if (m != FALSE) {
        if (teresa->mFollowEnded == FALSE && (teresa->mItemObject.mFlags & 0x8000000) && teresa->mUnk_24c != FALSE) {
            teresa->mFollowEnded = TRUE;
            AddItemDataItemIdAndBytes(0xb, teresa->mItemObject.mId, 1, teresa->mStateMachine.mState & 0xff);
        } else {
            teresa->mFollowEnded = TRUE;
        }
    }
    ((Vec3 *) delta)->x = position->x - (&teresa->mItemObject.mVelocity)->x;
    delta[2] = position->z - (&teresa->mItemObject.mVelocity)->z;
    if (teresa->mFollowEnded != FALSE) {
        VEC_Add(&teresa->mKartDrawMatrixPos, &teresa->mKartVelocity, &teresa->mKartDrawMatrixPos);
        teresa->mKartVelocity.x = MUL_FIXED12_NO_ROUND(teresa->mKartVelocity.x, 0xeb8);
        teresa->mKartVelocity.y = MUL_FIXED12_NO_ROUND(teresa->mKartVelocity.y, 0xeb8);
        teresa->mKartVelocity.z = MUL_FIXED12_NO_ROUND(teresa->mKartVelocity.z, 0xeb8);
        *position = teresa->mKartDrawMatrixPos;
    } else {
        *position = kart->mDrawMatrixPos;
        VEC_Subtract(position, &teresa->mKartDrawMatrixPos, &teresa->mKartVelocity);
        teresa->mKartDrawMatrixPos = *position;
        position->y -= kart->mHopHeight;
    }
    VEC_Add(position, &teresa->mOffset, position);
    cameraSide = &camera->mSide;
    if (teresa->mFollowsPath != FALSE) {
        easeFactor = 0xccd;
        maxOffsetChange = 0x800;
    } else {
        easeFactor = 0x800;
        maxOffsetChange = 0x400;
    }
    if (shiftAlongCameraSide != 0) {
        scaledRadius = MUL_FIXED12_ROUNDED(kart->mPhysicalParam->mRadius, kart->mScale.z);
        position->x += MUL_FIXED12_NO_ROUND(-scaledRadius, cameraSide->x);
        position->z += MUL_FIXED12_NO_ROUND(-scaledRadius, cameraSide->z);
    }
    delta[0] -= position->x;
    delta[2] -= position->z;
    sideDistance = DOT2_FIXED12(cameraSide->x, delta[0], cameraSide->z, delta[2]);
    delta[0] = MUL_FIXED12_NO_ROUND(cameraSide->x, sideDistance);
    delta[2] = MUL_FIXED12_NO_ROUND(cameraSide->z, sideDistance);
    delta[0] = MUL_FIXED12_NO_ROUND(delta[0], easeFactor);
    delta[2] = MUL_FIXED12_NO_ROUND(delta[2], easeFactor);
    if (delta[0] > maxOffsetChange) {
        delta[0] = maxOffsetChange;
    } else if (delta[0] < -maxOffsetChange) {
        delta[0] = -maxOffsetChange;
    }
    if (delta[2] > maxOffsetChange) {
        delta[2] = maxOffsetChange;
    } else if (delta[2] < -maxOffsetChange) {
        delta[2] = -maxOffsetChange;
    }
    teresa->mOffsetX = delta[0] + (s32) teresa->mOffsetX;
    teresa->mOffsetZ = delta[2] + (s32) teresa->mOffsetZ;
}

void EnterItemTeresaState0(ItemTeresa *teresa) {
    teresa->mKart = GetKart((u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~0xff00));
    teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
    teresa->mKartVelocity = teresa->mKart->mVelocity;
    teresa->mOffset =
        (Vec3){0, MUL_FIXED12_ROUNDED(teresa->mKart->mPhysicalParam->mRadius, teresa->mKart->mScale.z), 0};
    teresa->mOffsetVelocityY = 0;
    teresa->mItemObject.mAlpha = 0x1f;
    if (teresa->mKart->mUnk_48 & KART_48_ON_BOOST_SURFACE) {
        teresa->mItemObject.mPosPointer = &teresa->mItemObject.mDrawPos;
    }
}

void AdvanceItemTeresaPath(ItemTeresa *teresa) {
    Vec3 targetOffset;
    Vec3 s;
    Vec3 *viewAxis0;

    if (teresa->mPointIndex >= 0xb) {
        return;
    }
    if (AdvanceSegmentProgress(&teresa->mPathSegmentPoints.mSegmentProgress) != FALSE) {
        do {
            teresa->mPointIndex++;
            if (teresa->mPointIndex >= 0xb) {
                return;
            }
        } while (PushSegmentPoint(&teresa->mPathSegmentPoints, &gItemTeresaPathPoints[teresa->mPointIndex]) != 0);
    }
    GetSegmentProgressPoint(&teresa->mPathSegmentPoints, &s);
    SetSegmentProgressRate(&teresa->mPathSegmentPoints.mSegmentProgress, s.y);
    if (teresa->mItemObject.mPosPointer == &teresa->mItemObject.mDrawPos) {
        targetOffset = (Vec3){s.x};
    } else {
        s32 f = s.x;

        viewAxis0 = GetViewTransposeMatrixAxis0();
        targetOffset.x = MUL_FIXED12_NO_ROUND(viewAxis0->x, f);
        targetOffset.y = MUL_FIXED12_NO_ROUND(viewAxis0->y, f);
        targetOffset.z = MUL_FIXED12_NO_ROUND(viewAxis0->z, f);
    }
    targetOffset.y += s.z;
    VEC_Subtract(&targetOffset, &teresa->mOffset, &s);
    VEC_MultAdd(0x4f6, &s, &teresa->mOffset, &teresa->mOffset);
}

BOOL AdvanceItemTeresaFadeOut(ItemTeresa *teresa, s32 shiftAlongCameraSide, s32 nextState) {
    s32 stateFrames;
    s32 fadeStartFrame;
    s32 fadeStep;

    stateFrames = teresa->mStateMachine.mStateFrames;
    if (teresa->mFollowsPath != FALSE) {
        fadeStartFrame = -7;
        fadeStep = GetRaceUpdateFramesMod8() > 2;
        AdvanceItemTeresaPath(teresa);
    } else {
        if (nextState < 7) {
            teresa->mOffsetVelocityY += 0x133;
            fadeStartFrame = 0x1c;
            fadeStep = 6;
        } else {
            fadeStartFrame = 0x14;
            fadeStep = 2;
            if (teresa->mOffsetVelocityY < 0) {
                teresa->mOffsetVelocityY += 0x2cd;
            } else {
                teresa->mOffsetVelocityY += 0x8f;
            }
        }
        teresa->mOffsetY += teresa->mOffsetVelocityY;
    }
    PlaceItemTeresaAtKart(teresa, shiftAlongCameraSide);
    if (stateFrames > fadeStartFrame) {
        if (teresa->mItemObject.mAlpha > 0) {
            teresa->mItemObject.mAlpha -= fadeStep;
        }
        if (stateFrames >= (teresa->mFollowsPath != FALSE ? 0x37 : 0x28)) {
            if (nextState < 7) {
                if (teresa->mStateMachine.mState == 0) {
                    teresa->mSavedOffsetY = teresa->mOffsetY;
                    teresa->mSavedOffsetVelocityY = teresa->mOffsetVelocityY;
                }
                teresa->mStateMachine.mNextState = nextState;
                teresa->mStateMachine.mNextStateRequested = 1;
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 AdvanceItemTeresaFadeIn(ItemTeresa *teresa, s32 shiftAlongCameraSide, s32 nextState) {
    s32 stateFrames;
    u16 factor;

    stateFrames = teresa->mStateMachine.mStateFrames;
    if (teresa->mFollowsPath != FALSE) {
        AdvanceItemTeresaPath(teresa);
    } else if (teresa->mStalled != FALSE) {
        factor = gItemTeresaFrameScales[stateFrames];
        teresa->mOffsetX = MUL_FIXED12_NO_ROUND(teresa->mOffsetX, factor);
        teresa->mOffsetZ = MUL_FIXED12_NO_ROUND(teresa->mOffsetZ, factor);
    } else {
        teresa->mOffsetY += teresa->mOffsetVelocityY;
        teresa->mOffsetVelocityY += 0x133;
        factor = gItemTeresaFrameScales[stateFrames];
        teresa->mOffsetX = MUL_FIXED12_NO_ROUND(teresa->mOffsetX, factor);
        teresa->mOffsetZ = MUL_FIXED12_NO_ROUND(teresa->mOffsetZ, factor);
    }
    PlaceItemTeresaAtKart(teresa, shiftAlongCameraSide);
    if (stateFrames > 7) {
        if (teresa->mItemObject.mAlpha < 0x1f) {
            teresa->mItemObject.mAlpha += 6;
        }
        if (stateFrames == 0x27) {
            if (teresa->mFollowsPath == FALSE) {
                teresa->mOffsetVelocityX = teresa->mOffsetX;
                teresa->mOffsetVelocityZ = teresa->mOffsetZ;
            }
        } else if (stateFrames == 0x28) {
            if (teresa->mFollowsPath == FALSE) {
                teresa->mOffsetVelocityX = teresa->mOffsetX - teresa->mOffsetVelocityX;
                teresa->mOffsetVelocityZ = teresa->mOffsetZ - teresa->mOffsetVelocityZ;
            }
            teresa->mStateMachine.mNextState = nextState;
            teresa->mStateMachine.mNextStateRequested = 1;
            teresa->mStalled = FALSE;
        }
    }
    return stateFrames;
}

void UpdateItemTeresaState0(ItemTeresa *teresa) {
    AdvanceItemTeresaFadeOut(teresa, 0, (teresa->mItemObject.mFlags & 0x8000000) ? 1 : 2);
    if (!(teresa->mItemObject.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->mUnk_24c != FALSE) {
        return;
    }
    if (teresa->mFollowEnded != FALSE) {
        return;
    }
    if (teresa->mReportedState == 0xffffffff) {
        return;
    }
    if (teresa->mReportedState == 0 || teresa->mReportedState == 7) {
        teresa->mFollowEnded = TRUE;
        teresa->mReportedState = -1;
    }
}

void EnterItemTeresaState1(ItemTeresa *teresa) {
    if (teresa->mUnk_24c == FALSE) {
        return;
    }
    PickItemTeresaKartByRank(teresa, -1);
    AddItemDataItemIdAndBytes(0xb, teresa->mItemObject.mId, 0, teresa->mPickedKartIndex & 0xff);
    teresa->mPendingPickedKartIndex = teresa->mPickedKartIndex;
    teresa->mUnk_24c = FALSE;
}

void UpdateItemTeresaState1(ItemTeresa *teresa) {
    s32 stateFrames;

    if (teresa->mPendingPickedKartIndex == 0xffffffff) {
        return;
    }
    stateFrames = teresa->mStateMachine.mStateFrames;
    if (teresa->mUnk_24c == FALSE && stateFrames < 0x28) {
        return;
    }
    teresa->mDelayTimer = stateFrames - 0x28;
    teresa->mPickedKartIndex = teresa->mPendingPickedKartIndex;
    teresa->mStateMachine.mNextState = 2;
    teresa->mStateMachine.mNextStateRequested = 1;
}

void EnterItemTeresaState2(ItemTeresa *teresa) {
    s32 *offset;
    Camera *camera;
    RaceSetup *raceSetup;
    void (*pickFunction)(ItemTeresa *, s32);
    int ownerKartIndex;

    offset = &teresa->mOffsetX;
    camera = GetCurrentCamera();
    if (!(teresa->mItemObject.mFlags & 0x8000000)) {
        raceSetup = gRaceSetup;
        pickFunction = (raceSetup->mMode == MODE_BATTLE) ? PickItemTeresaKartBattle : PickItemTeresaKartByRank;
        if (raceSetup->mUseTeams != 0) {
            if ((teresa->mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0) {
                ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~0xff00);
            } else {
                ownerKartIndex = 8;
            }
            pickFunction(teresa, GetCurrentEntry(ownerKartIndex)->mPlayer.mTeamIndex);
            if (teresa->mPickedKartIndex == 8) {
                pickFunction(teresa, -1);
            }
        } else {
            pickFunction(teresa, -1);
        }
    }
    if (teresa->mItemObject.mPosPointer == &teresa->mItemObject.mDrawPos) {
        teresa->mItemObject.mPos = teresa->mItemObject.mDrawPos;
        teresa->mItemObject.mPosPointer = &teresa->mItemObject.mPos;
    }
    if (teresa->mPickedKartIndex < 8) {
        teresa->mKart = GetKart(teresa->mPickedKartIndex);
        teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
        teresa->mKartVelocity = teresa->mKart->mVelocity;
        teresa->mFollowEnded = FALSE;
        StartEntryKartSound(teresa->mKart, 0xf4);
        if (teresa->mKart->mUnk_48 & KART_48_ON_BOOST_SURFACE) {
            teresa->mItemObject.mPosPointer = &teresa->mItemObject.mDrawPos;
        }
    }
    offset[0] = MUL_FIXED12_NO_ROUND(camera->mSide.x, -0xa000);
    offset[2] = MUL_FIXED12_NO_ROUND(camera->mSide.z, -0xa000);
    offset[0] += MUL_FIXED12_NO_ROUND(camera->mForward.x, -0x11000);
    offset[2] += MUL_FIXED12_NO_ROUND(camera->mForward.z, -0x11000);
    teresa->mOffsetVelocityY = -teresa->mOffsetVelocityY;
    teresa->mStallFrames = 0;
}

s32 RemoveItemTeresaPickedKartItem(ItemTeresa *teresa) {
    KartItems *pickedKartItems;
    Kart *kart;
    HeldItem *heldItem;
    s32 a;
    s32 b;
    enum { K0 } itemInfoIndex;

    pickedKartItems = &gKartItems[(u16) teresa->mPickedKartIndex];
    kart = pickedKartItems->mKart;
    heldItem = &pickedKartItems->mHeldItem;
    if (heldItem->mItemInfoIndex == 0x13 || heldItem->mObjectStartFramesLeft != 0) {
        return 0xf;
    }
    if (heldItem->mItemInfoIndex == 0x10) {
        return 0xf;
    }
    if (teresa->mFollowEnded != FALSE) {
        return 0xf;
    }
    a = b = 1;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->mUnk_7c & 0x400020) == 0) {
        a = 0;
    }
    if (a == 0 && (kart->mUnk_4c & 0x10000800) == 0) {
        b = 0;
    }
    if (b | ((kart->mUnk_4c & 0x40) ? 1 : 0)) {
        return 0xf;
    }
    if (teresa->mItemObject.mFlags & 0x8000000) {
        teresa->mItemInfoIndex = heldItem->mItemInfoIndex;
        teresa->mItemCount = heldItem->mObjectCount;
        ResetParticipantHeldItem(((u8 *) gParticipantKartMap)[teresa->mPickedKartIndex & 0xff]);
    } else {
        RemoveHeldItem(heldItem, &teresa->mItemInfoIndex, &teresa->mItemCount);
    }
    StartKartHitReaction(kart);
    itemInfoIndex = teresa->mItemInfoIndex;
    return gItemInfos[itemInfoIndex].mObjectKind;
}

void UpdateItemTeresaState2(ItemTeresa *teresa) {
    u32 framesLeft;
    BOOL receivedItem;

    if (teresa->mPickedKartIndex == 8) {
        if (teresa->mStateMachine.mStateFrames > 0x6e) {
            teresa->mItemObjectKind = 0xf;
            teresa->mStateMachine.mNextState = (teresa->mItemObject.mFlags & 0x8000000) ? 4 : 5;
            teresa->mStateMachine.mNextStateRequested = 1;
        }
    } else {
        framesLeft = 0x28 - AdvanceItemTeresaFadeIn(teresa, 1, 3);
        if (teresa->mItemObjectKind == 0xe) {
            if (teresa->mUnk_24c != FALSE) {
                if (framesLeft == 0xa) {
                    teresa->mItemObjectKind = RemoveItemTeresaPickedKartItem(teresa);
                    teresa->mItemModelAlpha = 0;
                    if (teresa->mItemObject.mFlags & 0x8000000) {
                        AddItemDataItemIdAndBytes(0xb, teresa->mItemObject.mId, 2,
                                                  ((teresa->mItemInfoIndex << 2) | teresa->mItemCount) & 0xff);
                    }
                }
            } else if (framesLeft <= 0xa) {
                if (teresa->mTakenItemCount != -1) {
                    teresa->mItemInfoIndex = teresa->mTakenItemInfoIndex;
                    teresa->mItemCount = teresa->mTakenItemCount;
                    teresa->mTakenItemInfoIndex = 0x12;
                    teresa->mTakenItemCount = -1;
                    if (teresa->mItemInfoIndex == 0x13) {
                        teresa->mItemObjectKind = 0xf;
                    } else {
                        teresa->mItemObjectKind = gItemInfos[teresa->mItemInfoIndex].mObjectKind;
                        ResetParticipantHeldItem(((u8 *) gParticipantKartMap)[teresa->mPickedKartIndex & 0xff]);
                    }
                    teresa->mItemModelAlpha = 0;
                    receivedItem = TRUE;
                } else {
                    receivedItem = FALSE;
                }
                if (receivedItem == FALSE && framesLeft == 1) {
                    teresa->mStateMachine.mStateFrames--;
                    teresa->mStalled = TRUE;
                    teresa->mStallFrames++;
                    if (teresa->mStallFrames > 0x3c) {
                        teresa->mTakenItemInfoIndex = 0x13;
                        teresa->mTakenItemCount = 0;
                    }
                }
            }
        }
    }
    if (!(teresa->mItemObject.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->mUnk_24c != FALSE) {
        return;
    }
    if (teresa->mFollowEnded != FALSE) {
        return;
    }
    if (teresa->mReportedState == 0xffffffff) {
        return;
    }
    if (teresa->mReportedState == 2 || teresa->mReportedState == 7) {
        teresa->mFollowEnded = TRUE;
        teresa->mReportedState = -1;
    }
}

void EnterItemTeresaState3(ItemTeresa *teresa) {
    teresa->mOffsetAccelerationY = 0x0u;
}

void UpdateItemTeresaState3(ItemTeresa *teresa) {
    if (teresa->mItemModelAlpha < 0x1f) {
        teresa->mItemModelAlpha += 5;
    }
    teresa->mOffsetVelocityX = MUL_FIXED12_NO_ROUND(teresa->mOffsetVelocityX, 0xf85);
    teresa->mOffsetVelocityZ = MUL_FIXED12_NO_ROUND(teresa->mOffsetVelocityZ, 0xf85);
    if (teresa->mStateMachine.mStateFrames == 0x12) {
        if (teresa->mOffsetAccelerationY == 0) {
            teresa->mOffsetAccelerationY = -0x1ae;
            teresa->mStartOffsetVelocityY = teresa->mOffsetVelocityY;
        }
        teresa->mOffsetVelocityY += teresa->mOffsetAccelerationY;
        teresa->mOffsetY += teresa->mOffsetVelocityY;
        PlaceItemTeresaAtKart(teresa, 1);
        if (teresa->mOffsetAccelerationY >= 0 && teresa->mOffsetVelocityY >= teresa->mStartOffsetVelocityY) {
            return;
        }
        teresa->mStateMachine.mStateFrames--;
        if (teresa->mOffsetAccelerationY >= 0) {
            return;
        }
        if (teresa->mOffsetVelocityY < -0xc00) {
            teresa->mOffsetAccelerationY = 0x133;
            return;
        }
        if (teresa->mOffsetVelocityY <= 0) {
            return;
        }
        if (teresa->mOffsetVelocityY >= -teresa->mOffsetAccelerationY) {
            return;
        }
        StartEntryKartSound(teresa->mKart, 0xf5);
    } else {
        teresa->mOffsetX += teresa->mOffsetVelocityX;
        teresa->mOffsetZ += teresa->mOffsetVelocityZ;
        AdvanceItemTeresaFadeOut(teresa, 1, (teresa->mItemObject.mFlags & 0x8000000) ? 4 : 5);
        if (!(teresa->mItemObject.mFlags & 0x8000000)) {
            return;
        }
        if (teresa->mUnk_24c != FALSE) {
            return;
        }
        if (teresa->mFollowEnded != FALSE) {
            return;
        }
        if (teresa->mReportedState == 0xffffffff) {
            return;
        }
        if (teresa->mReportedState - 2 <= 1) {
            teresa->mFollowEnded = TRUE;
            teresa->mReportedState = -1;
        }
    }
}

void EnterItemTeresaState4(ItemTeresa *teresa) {
    teresa->mDelayTimer = ((teresa->mItemObject.mFlags & 0x10000000) ? 0xf : 0) - teresa->mDelayTimer;
    teresa->mUnk_24c = FALSE;
}

void UpdateItemTeresaState4(ItemTeresa *teresa) {
    teresa->mDelayTimer--;
    if (teresa->mDelayTimer >= 0) {
        return;
    }
    teresa->mUnk_24c = (teresa->mItemObject.mFlags & 0x10000000) == 0;
    teresa->mStateMachine.mNextState = 5;
    teresa->mStateMachine.mNextStateRequested = 1;
}

void SetItemTeresaPosPointerToDrawPos(ItemTeresa *teresa) {
    teresa->mItemObject.mPosPointer = &teresa->mItemObject.mDrawPos;
}

void RestoreItemTeresaPosPointer(ItemTeresa *teresa) {
    if (teresa->mItemObject.mPosPointer == &teresa->mItemObject.mDrawPos) {
        teresa->mItemObject.mPos = teresa->mItemObject.mDrawPos;
        teresa->mItemObject.mPosPointer = &teresa->mItemObject.mPos;
    }
}

void EnterItemTeresaState5(ItemTeresa *teresa) {
    int ownerKartIndex;
    KartItems *ownerKartItems;
    void (*positionFunction)(ItemTeresa *);

    if ((teresa->mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    ownerKartItems = GetKartItems(ownerKartIndex);
    teresa->mKart = ownerKartItems->mKart;
    teresa->mFollowEnded = FALSE;
    if (teresa->mUnk_24c != FALSE) {
        if (ownerKartItems->mActiveItem == 0x10) {
            teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
            teresa->mKartVelocity = teresa->mKart->mVelocity;
            teresa->mOffsetX = 0;
            teresa->mOffsetZ = 0;
        } else {
            teresa->mFollowEnded = TRUE;
            if (teresa->mItemObject.mFlags & 0x8000000) {
                AddItemDataItemIdAndBytes(0xb, teresa->mItemObject.mId, 1, 5);
            }
            teresa->mOffsetX = 0;
            teresa->mOffsetZ = 0;
        }
    }
    if (teresa->mItemObjectKind == 0xf) {
        InitSegmentPoints(&teresa->mPathSegmentPoints, gItemTeresaPathPoints, gItemTeresaPathPoints[0].y);
        teresa->mPointIndex = 3;
        teresa->mFollowsPath = TRUE;
    } else {
        teresa->mOffsetVelocityY = -teresa->mSavedOffsetVelocityY;
        teresa->mOffsetY = teresa->mSavedOffsetY;
    }
    if (teresa->mFollowEnded == FALSE) {
        StartEntryKartSound(teresa->mKart, 0xf7);
    }
    teresa->mStallFrames = 0;
    positionFunction = (teresa->mKart->mUnk_48 & KART_48_ON_BOOST_SURFACE) ? SetItemTeresaPosPointerToDrawPos
                                                                           : RestoreItemTeresaPosPointer;
    positionFunction(teresa);
}

void UpdateItemTeresaState5(ItemTeresa *teresa) {
    s32 ownerKartIndex;
    KartItems *ownerKartItems;
    u32 framesLeft;
    BOOL receivedItem;
    s32 startOffsetX;
    s32 startOffsetZ;

    if ((teresa->mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    ownerKartItems = GetKartItems(ownerKartIndex);
    if (teresa->mUnk_24c != FALSE && ownerKartItems->mActiveItem != 0x10 && teresa->mItemCount != -0x40) {
        teresa->mFollowEnded = TRUE;
        if (teresa->mItemObject.mFlags & 0x8000000) {
            AddItemDataItemIdAndBytes(0xb, teresa->mItemObject.mId, 1, 5);
        }
    } else {
        framesLeft = 0x28 - AdvanceItemTeresaFadeIn(teresa, teresa->mFollowsPath == FALSE ? 1 : 0, 6);
        if (framesLeft < 7) {
            if (teresa->mItemModelAlpha > 0) {
                teresa->mItemModelAlpha -= 5;
            }
            if (framesLeft == 1) {
                if (teresa->mUnk_24c == FALSE) {
                    if (teresa->mGivenItemCount == -1) {
                        receivedItem = FALSE;
                    } else {
                        teresa->mItemInfoIndex = teresa->mGivenItemInfoIndex;
                        teresa->mItemCount = teresa->mGivenItemCount;
                        teresa->mGivenItemInfoIndex = 0x12;
                        teresa->mGivenItemCount = -1;
                        receivedItem = TRUE;
                    }
                    if (receivedItem == FALSE) {
                        teresa->mStateMachine.mStateFrames--;
                        teresa->mStalled = TRUE;
                        teresa->mStallFrames++;
                        if (teresa->mStallFrames > 0x3c) {
                            teresa->mGivenItemInfoIndex = 0x13;
                            teresa->mGivenItemCount = -0x40;
                            teresa->mItemObjectKind = 0xe;
                        }
                        goto skip;
                    }
                }
                ownerKartItems->mActiveItem = 0x13;
                if (teresa->mItemInfoIndex != 0x13) {
                    if (teresa->mUnk_24c == FALSE) {
                        SetParticipantHeldItem(((u8 *) gParticipantKartMap)[ownerKartItems->mKartIndex & 0xff],
                                               teresa->mItemInfoIndex, teresa->mItemCount);
                    } else {
                        SetHeldItemWithCount(&ownerKartItems->mHeldItem, teresa->mItemInfoIndex, teresa->mItemCount);
                    }
                    teresa->mItemInfoIndex = 0x13;
                    teresa->mItemCount = -0x40;
                    teresa->mItemObjectKind = 0xe;
                    StartEntryKartSound(ownerKartItems->mKart, 0xf8);
                } else {
                    teresa->mItemCount = -0x40;
                    teresa->mItemObjectKind = 0xe;
                }
                if ((teresa->mItemObject.mFlags & 0x8000000) && teresa->mUnk_24c != FALSE) {
                    AddItemDataItemIdAndBytes(
                        0xb, teresa->mItemObject.mId, 3,
                        ((ownerKartItems->mHeldItem.mItemInfoIndex << 2) | ownerKartItems->mHeldItem.mObjectCount) &
                            0xff);
                }
            }
        }
    }
skip:
    if (teresa->mFollowsPath == FALSE && teresa->mFollowEnded != FALSE) {
        startOffsetX = teresa->mOffsetX;
        startOffsetZ = teresa->mOffsetZ;
        AdvanceItemTeresaFadeIn(teresa, 1, 6);
        teresa->mOffsetVelocityX = teresa->mOffsetX - startOffsetX;
        teresa->mOffsetVelocityZ = teresa->mOffsetZ - startOffsetZ;
        teresa->mStateMachine.mNextState = 6;
        teresa->mStateMachine.mNextStateRequested = 1;
        teresa->mStalled = FALSE;
    }
    if (!(teresa->mItemObject.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->mUnk_24c != FALSE) {
        return;
    }
    if (teresa->mFollowEnded != FALSE) {
        return;
    }
    if (teresa->mReportedState == 0xffffffff) {
        return;
    }
    if (teresa->mReportedState == 5 || teresa->mReportedState == 7) {
        teresa->mFollowEnded = TRUE;
        teresa->mReportedState = -1;
    }
}

u32 EnterItemTeresaState6(u32 value) {
    return value;
}

void UpdateItemTeresaState6(ItemTeresa *teresa) {
    BOOL hasItem;
    s32 ownerKartIndex;

    hasItem = teresa->mItemInfoIndex != 0x13;
    if (teresa->mFollowsPath == FALSE) {
        teresa->mOffsetVelocityX = MUL_FIXED12_NO_ROUND(teresa->mOffsetVelocityX, 0xf85);
        teresa->mOffsetVelocityZ = MUL_FIXED12_NO_ROUND(teresa->mOffsetVelocityZ, 0xf85);
        teresa->mOffsetX += teresa->mOffsetVelocityX;
        teresa->mOffsetZ += teresa->mOffsetVelocityZ;
    }
    if (hasItem != FALSE) {
        if (teresa->mItemModelAlpha < 0x1f) {
            teresa->mItemModelAlpha += 8;
        }
    }
    if (AdvanceItemTeresaFadeOut(teresa, teresa->mFollowsPath == FALSE ? 1 : 0, 7) != FALSE) {
        if (hasItem != FALSE) {
            if ((teresa->mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0) {
                ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~0xff00);
            } else {
                ownerKartIndex = 8;
            }
            ((void (*)(s32 param_1, s32 param_2, s32 param_3)) RemoveReservedItemObjects)(
                teresa->mItemInfoIndex, teresa->mItemCount, (u16) ownerKartIndex);
        }
        ReleaseItemPoolObject(gItemPools + teresa->mItemObject.mKind, &teresa->mItemObject);
    }
    if (!(teresa->mItemObject.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->mUnk_24c != FALSE) {
        return;
    }
    if (teresa->mFollowEnded != FALSE) {
        return;
    }
    if (teresa->mReportedState == 0xffffffff) {
        return;
    }
    if (teresa->mReportedState - 5 <= 1) {
        teresa->mFollowEnded = TRUE;
        teresa->mReportedState = -1;
    }
}

void ResetItemTeresaOwnerActiveItem(ItemTeresa *teresa) {
    int ownerKartIndex;
    KartItems *ownerKartItems;

    if ((teresa->mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    ownerKartItems = GetKartItems(ownerKartIndex);
    if (ownerKartItems->mActiveItem != 0x10) {
        return;
    }
    if (teresa->mItemCount != -0x40) {
        ownerKartItems->mActiveItem = 0x13;
    }
}

void CopyItemTeresaData(void *cursor, ItemTeresa *teresa, void *toData) {
    CopyItemObjectData(cursor, teresa, toData);
    if (teresa == NULL) {
        return;
    }
    if (toData == NULL) {
        return;
    }
    AddItemDataSizedByKind(teresa->mItemObject.mKind);
}

void InitItemTeresaFromData(ItemTeresa *teresa) {
    int ownerKartIndex;

    SetupItemObjectFromData(&teresa->mItemObject);
    InitCourseColorBlend(&teresa->mItemObject.mColorBlend, 1);
    SetStateMachineState(&teresa->mStateMachine, 0);
    if ((teresa->mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->mItemObject.mOwnerKartIndexAndFlags & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    SetActiveItem(GetKartItems(ownerKartIndex), 0x10);
}

// Selectors: 0 picked kart, 1 reported state, 2 item taken, 3 item given (item index << 2 | count).
void SetItemTeresaFromPacket(ItemTeresa *teresa, u32 sel, s32 value) {
    switch (sel) {
        case 0:
            teresa->mPendingPickedKartIndex = value;
            if (teresa->mPendingPickedKartIndex == gRaceSetup->mEntryIndex) {
                teresa->mUnk_24c = TRUE;
            }
            break;
        case 1:
            teresa->mReportedState = value;
            break;
        case 2:
            teresa->mTakenItemInfoIndex = value >> 2;
            teresa->mTakenItemCount = value & 3;
            break;
        case 3:
            teresa->mGivenItemInfoIndex = value >> 2;
            teresa->mGivenItemCount = value & 3;
            break;
    }
}

void DrawItemTeresa(ItemTeresa *teresa, s32 c, NsbmdModel *model) {
    s32 a;
    s32 itemModelAlpha;
    s32 b;
    s32 polygonId;
    u16 drawAlpha;
    s32 scale[3];
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    NsbmdModel *itemModel;
    s32 index;
    s32 itemCount;

    if (teresa->mItemObject.mAlpha <= 0) {
        return;
    }
    a = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &a, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(teresa->mItemObject.mPosPointer), 0xc);
    scaleZ = teresa->mItemObject.mScale.z;
    scaleY = teresa->mItemObject.mScale.y;
    scaleX = teresa->mItemObject.mScale.x;
    scale[0] = scaleX;
    scale[1] = scaleY;
    scale[2] = scaleZ;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    if (teresa->mItemObjectKind < 0xe && teresa->mStateMachine.mState >= 3) {
        itemModel = GetItemModel(teresa->mItemObjectKind);
        itemModelAlpha = teresa->mItemModelAlpha;
        itemCount = teresa->mItemCount;
        if (teresa->mItemObject.mAlpha < 0x1f) {
            if (teresa->mItemObject.mAlpha < itemModelAlpha) {
                itemModelAlpha = teresa->mItemObject.mAlpha;
            }
        }
        if (itemModelAlpha > 0x1f) {
            itemModelAlpha = 0x1f;
        }
        if (itemModelAlpha < 1) {
            itemModelAlpha = 1;
        }
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        itemModel->mPolygonAttributes = itemModel->mPolygonAttributes & ~0x1f0000;
        itemModel->mPolygonAttributes = itemModel->mPolygonAttributes | ((u16) itemModelAlpha << 16);
        QueueNsbmdModelMaterial(itemModel);
        index = 0;
        itemModel->mFrameIndex = 0;
        while (index < itemCount) {
            NNS_G3dGeBufferOP_N(0x1c, &gItemTeresaItemOffsets[itemCount == 2 ? 1 - index : index + 1], 3);
            polygonId = AllocPolygonIdWrapping();
            itemModel->mPolygonAttributes = itemModel->mPolygonAttributes & ~0x3f000000;
            itemModel->mPolygonAttributes = itemModel->mPolygonAttributes | (polygonId << 24);
            DrawNsbmdModelWithMaxAlpha(itemModel, &teresa->mItemObject.mPos, 1, 0x1f);
            index++;
        }
        b = 1;
        NNS_G3dGeBufferOP_N(0x12, &b, 1);
        if (itemModelAlpha != 0x1f) {
            itemModel->mPolygonAttributes = itemModel->mPolygonAttributes & ~0x1f0000;
            itemModel->mPolygonAttributes = itemModel->mPolygonAttributes | 0x1f0000;
        }
    }
    polygonId = AllocPolygonIdWrapping();
    model->mPolygonAttributes = model->mPolygonAttributes & ~0x3f000000;
    model->mPolygonAttributes = model->mPolygonAttributes | (polygonId << 24);
    drawAlpha = teresa->mItemObject.mAlpha;
    model->mPolygonAttributes = model->mPolygonAttributes & ~0x1f0000;
    model->mPolygonAttributes = model->mPolygonAttributes | (drawAlpha << 16);
    DrawItemModelAtObjectPos(&teresa->mItemObject, model);
}
