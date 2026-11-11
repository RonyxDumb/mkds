#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020401ac.h"
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

#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02109000.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02108ea0.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_0212bcac.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "code_0212df7c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02089d14.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210a588.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210b564.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_0210cf20.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02036820.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_020681f0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_02081338.h"
#include "Main/Unknown/code_020810e4.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208c4e8.h"
#include "Main/Unknown/code_02089f9c.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

void AdvanceKartScaleFactor(Kart *kart) {
    s32 frameIndex;
    enum { K0 } entryIndex;

    entryIndex = kart->mEntryIndex;
    gInputSlots[entryIndex].mBitMask = 0xff7;
    if (kart->mUnk_7c & KART_7C_REMOVED) {
        AdvanceKartRemovalShrink(kart);
        return;
    }
    kart->mFramesSinceRemovalOrReset = kart->mFramesSinceRemovalOrReset + 1;
    frameIndex = kart->mFramesSinceRemovalOrReset;
    if (frameIndex >= 0x19) {
        kart->mUnk_7c &= ~0x80;
        return;
    }
    kart->mScaleFactor.x = gKartScaleFactorXTable[frameIndex];
    kart->mScaleFactor.y = gKartScaleFactorYTable[frameIndex];
    kart->mScaleFactor.z = gKartScaleFactorZTable[frameIndex];
    kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
    kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
    kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
    kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
}

void ResetKartToRespawnPoint(Kart *kart) {
    Vec3 respawnPos;
    Vec3 respawnForward;
    Vec3 respawnAngles;
    Vec3 sideDirection;
    MtxFx33 rotationMatrix;
    PointLink *respawnLink;
    s32 x;
    s32 forwardOffset;
    s32 i;
    KartItems *kartItems;
    s64 l;

    if (kart->mRespawnSlot == -1) {
        i = kart->mIndex;
        if (gRaceSetup->mMode == MODE_BATTLE) {
            i = GetCourseMapRespawnSlot(0);
        } else {
            i = GetCourseMapRespawnSlot(gRaceProgress->mKarts[i].mCheckpoint);
        }
        kart->mRespawnSlot = i;
    }
    i = (u16) kart->mRespawnSlot;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        respawnLink = GetCourseMapRespawnBattlePointLink(i, &respawnPos, &respawnAngles);
    } else {
        respawnLink = GetCourseMapRespawnRacePointLink(i, &respawnPos, &respawnAngles);
    }
    i = ((u16) ((s32) (((s64) respawnAngles.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
    MTX_RotY33_(&rotationMatrix, FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
    MTX_MultVec33(&data_02154f70, &rotationMatrix, &respawnForward);
    if (gRaceSetup->mMode != MODE_BATTLE && gCourseMap->mItemRouteCount != 0) {
        (kartItems = &gKartItems[kart->mIndex])->mItemLink.mLink =
            GetCourseMapRespawnItemPointLink((u16) kart->mRespawnSlot);
        kartItems->mItemLink.mNextLinksUsed = 1;
    }
    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        x = data_usa_02154d4c[kart->mIndex][0];
        forwardOffset = data_usa_02154d50[kart->mIndex][0];
        Vec3CrossUnrounded(&gKartVec3UnitY, &respawnForward, &sideDirection);
        VEC_MultAdd(MUL_FIXED12_NO_ROUND(data_usa_02165504, x), &sideDirection, &respawnPos, &respawnPos);
        VEC_MultAdd(MUL_FIXED12_NO_ROUND(data_usa_02165504, forwardOffset), &respawnForward, &respawnPos, &respawnPos);
        if (respawnAngles.x != 0 && forwardOffset != 0) {
            i = ((u16) ((s32) (((s64) respawnAngles.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = FX_SinCosTable_[i * 2];
            i = (l * -forwardOffset + 0x800) >> 12;
            respawnPos.y += MUL_FIXED12_ROUNDED(i, data_usa_02165504);
        }
        if (respawnAngles.z != 0 && x != 0) {
            i = ((u16) ((s32) (((s64) respawnAngles.z * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = FX_SinCosTable_[i * 2];
            i = (l * x + 0x800) >> 12;
            respawnPos.y += MUL_FIXED12_ROUNDED(i, data_usa_02165504);
        }
    }
    respawnPos.y += 0x28000;
    x = kart->mUnk_48;
    if (x & 0x800000) {
        SetupKartFollowEffect(StartEffect(0x71, &respawnPos), kart->mIndex, 0x32);
    } else if (x & 0x1000000) {
        SetupKartFollowEffect(StartEffect(0x70, &respawnPos), kart->mIndex, 0x32);
    }
    ResetKartAndSetPos(kart, &respawnPos, &respawnForward, respawnLink);
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        GetEntryKartCounters()->mRespawnCount++;
    } else {
        ResetSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange);
    }
    kart->mUnk_4c |= 0xc00;
    kart->mUnk_48 |= 0x2000000;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        StartDispCapFadeToClear(0x3c);
        SetEntryCameraUpdateHold(0);
    }
}

s32 AdvanceKartRespawnWait(Kart *kart, s32 *a) {
    BOOL finished;
    u32 flags;

    flags = kart->mUnk_4c;
    finished = FALSE;
    if (flags & 0x4000000) {
        if (kart->mRespawnWaitVelocityScale > 0x19a) {
            kart->mRespawnWaitVelocityScale = MUL_FIXED12_NO_ROUND(kart->mRespawnWaitVelocityScale, 0xe66LL);
        }
        *a = kart->mRespawnWaitVelocityScale;
    } else if (flags & 0x200000) {
        if (kart->mRespawnWaitVelocityScale > 0x666) {
            kart->mRespawnWaitVelocityScale = MUL_FIXED12_NO_ROUND(kart->mRespawnWaitVelocityScale, 0xe66LL);
        }
        *a = kart->mRespawnWaitVelocityScale;
    }
    kart->mRespawnFrames = kart->mRespawnFrames + 1;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (kart->mRespawnFrames == 0x16) {
            SetDispCapFadeFlag();
        } else if (kart->mRespawnFrames == 0x19) {
            StartDispCapFadeToFaded(0x3c);
        }
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && kart->mRespawnFrames == 0x55) {
        SetJgState4();
    } else if (kart->mRespawnFrames > 0x78) {
        CallKartSlot6AndToggleFlag(kart);
        finished = TRUE;
    }
    return finished;
}

void ResetKartAndSetPos(Kart *kart, const Vec3 *position, const Vec3 *forward, PointLink *link) {
    ParticipantKartRecordState *recordState;
    Vec3 axis;

    StopKartItemsAndEffects(kart);
    SetKartModelsEntryCourseColors(kart->mKartModelsEntry);
    kart->mSlotFunctions[1](kart);
    kart->mUnk_7c &= ~0xe000;
    StopOrthoQuads(kart->mIndex);
    kart->mUnk_48 |= KART_48_SINKING | KART_48_OBJECTS_SKIP;
    kart->mPos = *position;
    if (kart->mUnk_7c & 0x400) {
        recordState = kart->mParticipantRecordData;
        recordState->mSmoothedPos = kart->mPos;
        recordState->mSmoothedDrawPos = recordState->mSmoothedPos;
        recordState->mSmoothedRotation = kart->mUnk_110_q;
        recordState->mPosOffset = gKartVec3Zero;
        recordState->mPosOffsetIndex = 0;
    }
    if (forward != NULL) {
        kart->mHeadingAngle = MUL_FIXED12_NO_ROUND(FX_Atan2(forward->x, forward->z), 0x28be60dLL) >> 12;
        axis = data_02165524;
        QuaternionFromAxisAngle(&axis, kart->mHeadingAngle, &kart->mUnk_e0_m);
    }
    Matrix4x3FromQuaternion(&kart->mUnk_120_m, &kart->mUnk_e0_m);
    GetKartForward(kart, &kart->mForward);
    kart->mTurnedForward = kart->mForward;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mPrevCollisionCenter = kart->mPos;
    kart->mCollisionCenter = kart->mPos;
    kart->mLastGroundY = kart->mPos.y;
    if (kart->mUnk_7c & 2) {
        if (link != NULL) {
            CallKartAiReset(kart->mAi, link);
        } else {
            CallKartAiSetup(kart->mAi, kart->mIndex);
        }
    }
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        ResetCameraBehind(position, &kart->mUnk_e0_m);
        ReturnArgument(((u32(*)(void)) ResetCameraHalfFovAngle)());
        SetCameraHeightHold(0);
    }
}

void StopKartItemsAndEffects(Kart *kart) {
    s32 i;
    KartFollowEffectIds effectIds;

    ReleaseKartItems(&gKartItems[kart->mIndex]);
    ReleaseKartSurfaceEffects(kart);
    ReleaseKartStarEffects(kart->mIndex);
    ReleaseKartKillerEffect(kart->mIndex);
    ReleaseKartContactEffect(kart->mIndex);
    ReleaseKartSpinFollowEffect(kart->mIndex);
    ReleaseKartAheadEffect(kart);
    ReleaseKartNearRankEffect(kart);
    ReleaseKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    InitKartSoundParams(kart);
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        SetThunderShrinkSoundFlag(0);
    }
    ResetKartTrackParamsFunction(kart);
    if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
        ResetKartModelsCourseColors(kart);
    }
    if (kart->mUnk_4c & 0x40) {
        kart->mUnk_4c &= ~0x40;
        StopKartStarModels(kart);
        kart->mItemEffect = 0;
        StopKartStarEffects(kart->mIndex);
        SetKartCharacterAnimation(kart, 0, 1);
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
            StopKartStarSeq();
        }
        if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
            SetKartModelsGrayColors(kart);
        }
    }
    if (kart->mUnk_4c & 0x10000000) {
        kart->mUnk_4c &= ~0x10000000;
        ResetKartActiveItemAfterKiller(kart->mIndex);
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            ResetCameraHalfFovAngleGoal();
        }
        kart->mRadiusFactor = 0x1000;
        kart->mSurfaceGroup = -1;
        i = 0;
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->mKartModelHidden == 0) {
            effectIds = gKartFollowEffectIds;
            for (i = 0; i < 3; i++) {
                SetupKartFollowEffect(StartEffect(effectIds.mEffectIds[i], &kart->mPos), kart->mIndex, 0x14);
            }
        }
        StopKartKillerEffect(kart->mIndex);
        StartSound(&kart->mSoundSource, 0xfd, 0x7f, 0);
    }
    if (kart->mUnk_7c & KART_7C_TERESA) {
        kart->mUnk_7c &= ~KART_7C_TERESA;
        kart->mUnk_7c &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            ShowKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else {
            StartSound(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        SetTeresaSoundFlag(0, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
}

void ResetKartToStartPlacement(Kart *kart) {
    Vec3 startPos;
    Vec3 forward;
    Vec3 startAngles;
    Vec3 *collisionPos;

    if (!(kart->mUnk_7c & KART_7C_REMOVED)) {
        return;
    }
    GetCourseMapKartStartPlacement(&startPos, &startAngles, kart->mIndex);
    kart->mHeadingAngle = (u32) (startAngles.y * 0xb6) >> 12;
    QuaternionFromAxisAngle(&gKartVec3UnitY, kart->mHeadingAngle, &kart->mUnk_e0_m);
    Matrix4x3FromQuaternion(&kart->mUnk_120_m, &kart->mUnk_e0_m);
    GetKartForward(kart, &forward);
    ResetKartAndSetPos(kart, &startPos, &forward, NULL);
    if (gRaceSetup->mMode == MODE_WIFI) {
        collisionPos = &kart->mPointAlongUp;
    } else {
        collisionPos = &kart->mCollisionCenter;
    }
    if (kart->mCollisionSlot == -1) {
        kart->mCollisionSlot = CreateCollisionSlot(collisionPos, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
    }
    if (kart->mSecondCollisionSlot == -1) {
        kart->mSecondCollisionSlot = CreateCollisionSlot(
            &kart->mSecondCollisionCenter, ((s64) kart->mPhysicalParam->mRadius << 15) >> 12, 0x800, kart);
    }
    kart->mUnk_7c |= 0x80;
    kart->mUnk_7c &= ~0x60;
    kart->mScale = gKartVec3Zero;
}

void InitKartPhysicalParams(Kart *kart) {
    s32 a;
    s32 b;
    s16 i;
    KartPhysicalParam *physicalParam;
    s32 *charPhysicalParam;

    kart->mPhysicalParam = GetKartPhysicalParam(kart->mIndex);
    a = 0x1000;
    b = 0;
    if (IsRaceAwardOrStaffRoll() == 0) {
        switch (gRaceSetup->mEngineIndex) {
            case 0:
                a = 0xb33;
                b = -0x28;
                break;
            case 1:
                a = 0xd9a;
                b = -0x14;
                break;
        }
    }
    kart->mPhysicalParam->mBaseSpeedLimit = MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mBaseSpeedLimit, a);
    kart->mPhysicalParam->mUnk_32 = kart->mPhysicalParam->mUnk_32 + b;
    kart->mSpeedLimitFactorPerDepth = 0x1000 - kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4];
    kart->mSpeedLimitFactorPerDepth = FX_Div(kart->mSpeedLimitFactorPerDepth, kart->mPhysicalParam->mRadius << 1);
    kart->mCharPhysicalParam = GetCharPhysicalParam(kart->mIndex);
    physicalParam = kart->mPhysicalParam;
    charPhysicalParam = kart->mCharPhysicalParam;
    for (i = 0; i < 12; i++) {
        a = physicalParam->mSurfaceSpeedLimitFactors[i];
        if (a < 0x1000) {
            physicalParam->mSurfaceSpeedLimitFactors[i] = MUL_FIXED12_ROUNDED(a, *charPhysicalParam);
        }
    }
}

void ResetKartMotionVectorsAndFactors(Kart *kart) {
    Vec3 zeroVector;

    kart->mSpeedLimitGroundFactor = 0x1000;
    kart->mAheadSpeedLimitFactor = 0x1000;
    kart->mSpeedLimitFactor = 0x1000;
    kart->mSpeedLimitHitFactor = 0x1000;
    zeroVector = gKartVec3Zero;
    kart->mUnk_25c = zeroVector;
    kart->mAttractorPullDirection = zeroVector;
    kart->mAttractorPullSpeed = 0;
    kart->mForward = zeroVector;
    kart->mHopStartForward = zeroVector;
    kart->mHitVelocity = zeroVector;
    kart->mPrevHitVelocity = zeroVector;
    kart->mPrevPrevHitVelocity = zeroVector;
    kart->mUnk_25c = zeroVector;
    kart->mAirborneFrames = 0;
    kart->mTurnAngle = 0;
    kart->mDriftHeadingAnglePerFrame = 0;
    kart->mTurnedForwardEaseFactor = 0x1000;
    kart->mHeadingAnglePerFrame = 0;
}

void ResetKart(Kart *kart) {
    Vec3 zeroVector;
    u16 i;

    ClearCharacterTurnAndNextAnimation(kart->mKartModelsEntry);
    kart->mUnk_44 = 0;
    kart->mUnk_48 = 0;
    kart->mUnk_4c = 0;
    zeroVector = gKartVec3Zero;
    kart->mDrawMatrixPos = zeroVector;
    kart->mPrevPos = kart->mDrawMatrixPos;
    kart->mPos = kart->mPrevPos;
    kart->mVelocity = zeroVector;
    kart->mVelocityDirection = zeroVector;
    kart->mScale.x = 0x1000;
    kart->mScale.y = 0x1000;
    kart->mScale.z = 0x1000;
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    kart->mScaleBase.x = 0x1000;
    kart->mScaleBase.y = 0x1000;
    kart->mScaleBase.z = 0x1000;
    kart->mScaleYFactor = 0x1000;
    kart->mGravity = -0x2b9;
    kart->mSpeedLimitGoal = 0;
    kart->mSpeedLimit = 0xd000;
    kart->mSpeedLimitGroundFactor = 0x1000;
    kart->mAheadSpeedLimitFactor = 0x1000;
    kart->mState = KART_STATE_NORMAL;
    ClearKartItemEffectState(&kart->mItemEffectData);
    MTX_Identity43_(&kart->mUnk_120_m);
    MTX_Identity43_(&kart->mUnk_150_m);
    MTX_Identity43_(&kart->mWobbleMatrix);
    kart->mPointAlongUp = zeroVector;
    kart->mPrevPointAlongUp = kart->mPointAlongUp;
    kart->mPrevCollisionCenter = kart->mPrevPointAlongUp;
    kart->mCollisionCenter = kart->mPrevCollisionCenter;
    kart->mSecondCollisionCenter = zeroVector;
    kart->mPointMotion = zeroVector;
    kart->mSpeedLimitFactor = 0x1000;
    kart->mUnk_e0_m = data_usa_02154f14;
    kart->mUnk_f0_q = data_usa_02154f24;
    kart->mUnk_100_q = data_usa_02154f34;
    kart->mUnk_110_q = data_usa_02154f44;
    kart->mAirTiltAngle = 0;
    kart->mHeadingAngle = 0;
    kart->mBoostTimer = 0;
    kart->mStateEndTimer = 0;
    kart->mMiniTurboTimer = 0;
    kart->mTurnedForwardEaseFactor = 0x1000;
    kart->mGroundNormal = gKartVec3UnitY;
    kart->mCourseContactNormal = zeroVector;
    kart->mUnk_25c = zeroVector;
    kart->mAttractorPullDirection = zeroVector;
    kart->mAttractorPullSpeed = 0;
    kart->mForward = zeroVector;
    kart->mHopStartForward = zeroVector;
    kart->mTurnedForward = zeroVector;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mVelocityLengthRatio = 0;
    kart->mVelocityLength = 0;
    kart->mForwardSpeed = 0;
    kart->mLastGroundY = 0;
    kart->mTestedKartMask = 0;
    kart->mNearKartMask = 0;
    kart->mPrevNearKartMask = 0;
    kart->mItemEffect = 0;
    kart->mHopSpeed = 0;
    kart->mHopHeight = 0;
    kart->mHopTiltAngle = 0;
    kart->mTurnDirection = 0;
    kart->mTurnRatio = 0;
    kart->mHitVelocity = zeroVector;
    kart->mLaunchAxisSwing = 0;
    kart->mLaunchAxisSwingAngle = 0;
    kart->mLaunchAxisSwingAngleSum = 0;
    kart->mUnk_344 = 0;
    kart->mLaunchStartY = kart->mPos.y;
    kart->mLaunchFrames = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTowardTurnCounter = NULL;
    kart->mAwayTurnCounter = kart->mTowardTurnCounter;
    kart->mTurnCountTimer = 0;
    kart->mRotationAngle = 0;
    kart->mRotationAngleSum = 0;
    kart->mRotationAxis = zeroVector;
    kart->mRotationQuaternion = data_usa_02154f54;
    kart->mRotationEndFrames = 0;
    kart->mRotationAnglePerFrame = 0;
    kart->mYRotationAngle = 0;
    kart->mYRotationAnglePerFrame = 0;
    kart->mYRotationCount = 0;
    kart->mYRotationAngleSum = 0;
    kart->mVerticalSpeedStepCount = 0;
    kart->mCollisionPushVelocity = zeroVector;
    kart->mAirborneFrames = 0;
    kart->mVisible = 0xffff;
    kart->mHeadingAnglePerFrame = 0;
    kart->mTurnAngle = 0;
    kart->mDriftHeadingAnglePerFrame = 0;
    kart->mSpeedLimitHitFactor = 0x1000;
    kart->mShrinkFactor = 0x1000;
    kart->mMapObjectVectorLength = 0;
    kart->mMapObjectVectorForwardDot = 0;
    kart->mTireSpinAngle = 0;
    kart->mQuaternionBlendFactor = 0x1ec;
    kart->mSinkFrames = 0;
    kart->mVelocity = zeroVector;
    kart->mUnk_3bc = 0;
    kart->mRaceStartFrameCount = 0;
    kart->mRespawnFrames = 0;
    kart->mRespawnSlot = -1;
    kart->mFramesSinceRemovalOrReset = 0;
    kart->mKartCollisionTimer = 0;
    kart->mKartCollisionDelayTimer = 0;
    kart->mSurfaceGroup = -1;
    kart->mSurfaceKind = 0;
    kart->mSurfaceVariant = 0;
    kart->mAirTiltAngleOffset = 0;
    kart->mTurnHeadingAnglePerFrameGoal = 0;
    kart->mTurnHeadingAnglePerFrame = 0;
    kart->mVelocityScaleFactor = 0x1000;
    kart->mModelScaleKind = 0;
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = 0;
    kart->mModelScaleY = 0x1000;
    kart->mModelScaleX = 0x1000;
    kart->mModelScaleZ = 0x1000;
    for (i = 0; i < 2; i++) {
        kart->mPrevTouchingMapObjects[i] = NULL;
        kart->mMapObjectSoundFrames[i] = 0;
        kart->mMapObjectSoundPlayed[i] = 0;
    }
    kart->mScaleEffectMapObject = NULL;
    kart->mModelOffsetY = 0;
    kart->mRespawnLandRaceFrame = 0;
    kart->mRespawnPressRaceFrame = 0;
    kart->mRespawnWaitVelocityScale = 0;
    kart->mCourseHitAttributeBit = 0;
    kart->mSurfaceSpeedLimitGoal = 0;
    kart->mRadiusFactor = 0x1000;
    kart->mCollisionStepFrames = 0;
    kart->mRevLevel = 0;
    kart->mAttractorIndex = -1;
    kart->mLandingTimer = 0;
    kart->mCourseHitTimer = 0;
    kart->mHeadingAngleOffset = 0;
    kart->mHeadingAngleOffsetPerFrame = 0;
    kart->mHeadingAngleOffsetDirection = 1;
    kart->mHeadingAngleOffsetCount = 0;
    kart->mOffsetCyclePhase = 0;
    kart->mOffsetCyclePhaseStep = 0x1000;
    kart->mOffsetCycleAmount = data_usa_02154f64;
    kart->mOffsetCycleAmount.z = 0;
    kart->mOffsetCycleIndex = 0;
    kart->mWaterDepth = 0;
    kart->mBlinkCycleFrames = 0;
    kart->mBlinkFrames = kart->mBlinkCycleFrames;
    kart->mWobbleEasedAmplitude = 0;
    kart->mWobbleAmplitude = kart->mWobbleEasedAmplitude;
    kart->mWobbleAngle = 0;
    kart->mRank = 0;
    SetKartCharacterAnimation(kart, 0, 0);
    kart->mTireTurnAngle = 0;
}

void InitParticipantKartRecordState(Kart *kart, void *heap) {
    ParticipantKartRecordState *recordState;
    Vec3 zeroVector;
    u16 i;
    u8 *entries;

    recordState = kart->mParticipantRecordData;
    if (recordState == NULL) {
        return;
    }
    recordState->mSmoothedPos = kart->mPos;
    recordState->mSmoothedDrawPos = recordState->mSmoothedPos;
    recordState->mSmoothedHeadingAngle = kart->mHeadingAngle;
    recordState->mUnk_0c = recordState->mSmoothedHeadingAngle;
    recordState->mUnk_1c = 0;
    recordState->mLastSyncCount = 0;
    recordState->mPosBlendFactor = 0;
    recordState->mUnk_28 = 0;
    recordState->mAppliedFlags = 0;
    recordState->mEventToggleFlags = recordState->mAppliedFlags;
    zeroVector = gKartVec3Zero;
    recordState->mUnk_34 = zeroVector;
    recordState->mRecordBits = 0;
    recordState->mRecordKartBits = 0;
    recordState->mTargetTurnAngle = 0;
    recordState->mEasedTurnAngle = 0;
    recordState->mHopHeight = 0;
    recordState->mHopSpeed = 0;
    recordState->mPushDirection = zeroVector;
    recordState->mPosOffset = zeroVector;
    recordState->mPosOffsetIndex = 0;
    NNS_FndInitList(&recordState->mPendingRecords, 0);
    NNS_FndInitList(&recordState->mFreeRecords, 0);
    entries = HeapAlloc(heap, 0x438);
    for (i = 0; i < 0x1e; i++) {
        NNS_FndAppendListObject(&recordState->mFreeRecords, entries + i * 0x24);
    }
}

void ResetParticipantKartRecordPos(Kart *kart) {
    ParticipantKartRecordState *recordState;

    if (!(kart->mUnk_7c & 0x400)) {
        return;
    }
    recordState = kart->mParticipantRecordData;
    recordState->mSmoothedPos = kart->mPos;
    recordState->mSmoothedDrawPos = recordState->mSmoothedPos;
    recordState->mSmoothedRotation = kart->mUnk_110_q;
    recordState->mPosOffset = gKartVec3Zero;
    recordState->mPosOffsetIndex = 0;
}

void InitKartFlags(Kart *kart) {
    kart->mUnk_7c = 0;
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        kart->mUnk_7c |= KART_7C_INDEX_IS_SELECTED_ENTRY;
        if (gRaceSetup->mMode == MODE_WIFI) {
            kart->mUnk_7c |= 0x200;
            if (GetEntryRaceEnded() != 0) {
                kart->mUnk_7c &= ~0x200;
                kart->mUnk_7c |= 0x400;
            }
        }
    } else if (gRaceSetup->mMode == MODE_WIFI) {
        kart->mUnk_7c |= 0x400;
    }
    if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
        kart->mUnk_7c |= KART_7C_ENTRY_IS_GHOST;
        kart->mVisible = 0;
    }
    if (kart->mKartModelsEntry->mCharacterAnimation != NULL) {
        kart->mUnk_7c |= KART_7C_MODELS_ENTRY_008_SET;
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK || IsRaceAwardOrStaffRoll() != 0) {
        kart->mUnk_7c |= 0x8000000;
    }
}

void ClearKartItemEffectState(KartItemEffectState *itemEffectState) {
    itemEffectState->mKinokoBoostTimer = 0;
    itemEffectState->mThunderShrinkTimer = 0;
    itemEffectState->mThunderShrinkFrameIndex = 0;
    itemEffectState->mStarFrames = 0;
    itemEffectState->mAheadCount = 0;
    itemEffectState->mAheadBoostFrames = 0;
    itemEffectState->mScaleTableIndex = 0;
    itemEffectState->mScaleEffectTimer = 0;
    itemEffectState->mTeresaToggleDivisor = 0;
    itemEffectState->mTeresaStepFrames = 0;
    itemEffectState->mTeresaToggleFrames = 0;
    itemEffectState->mTeresaStepLimit = 0;
    itemEffectState->mGessoFrames = 0;
    itemEffectState->mKillerFrames = 0;
    itemEffectState->mUnk_20 = 0;
    itemEffectState->mKillerEnding = FALSE;
    itemEffectState->mKillerEndRank = 0;
}

void InitKartSound(Kart *kart) {
    InitSoundSource(&kart->mSoundSource, 0, kart->mPosSource);
    InitKartSoundCallbacks(kart, &kart->mSound);
    InitKartSoundParams(kart);
    switch (kart->mKartModelsEntry->mCharacterIndex) {
        case 0:
            kart->mSoundIndex = 4;
            break;
        case 1:
            kart->mSoundIndex = 0;
            break;
        case 2:
            kart->mSoundIndex = 1;
            break;
        case 3:
            kart->mSoundIndex = 2;
            break;
        case 4:
            kart->mSoundIndex = 5;
            break;
        case 5:
            kart->mSoundIndex = 6;
            break;
        case 6:
            kart->mSoundIndex = 7;
            break;
        case 7:
            kart->mSoundIndex = 3;
            break;
        case 8:
            kart->mSoundIndex = 10;
            break;
        case 9:
            kart->mSoundIndex = 8;
            break;
        case 10:
            kart->mSoundIndex = 9;
            break;
        case 11:
            kart->mSoundIndex = 11;
            break;
        case 12:
            kart->mSoundIndex = 12;
            break;
    }
    kart->mUnk_3d0 = kart->mKartModelsEntry->mKartIndex % 3;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(kart->mSoundSource.mSourceFlags & 1)) {
            SetSoundSourceFlagBit(&kart->mSoundSource, 2, 1);
        }
        if (gRaceSetup->mRaceKind == RACE_KIND_REPLAY) {
            ResetSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange);
        }
    } else {
        if (kart->mSoundSource.mSourceFlags & 1) {
            SetSoundSourceFlagBit(&kart->mSoundSource, 2, 1);
        }
        ResetSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange);
    }
}

void InitKartSoundParams(Kart *kart) {
    KartSound *kartSound;
    KartSoundRow soundRow;
    s32 soundRowIndex;
    s32 soundIndex;
    s32 rowOffset;
    s32 firstSoundColumn;
    s32 secondSoundColumn;
    s32 thirdSoundColumn;
    s32 highRatioSoundId;
    s32 midRatioSoundId;
    s32 lowRatioSoundId;
    s32 lastSoundColumn;

    kart->mSound.mSoundId = 0xa5;
    kartSound = &kart->mSound;
    kartSound->mVolume = 0x64;
    kartSound->mPitch = -1;
    kartSound->mTargetPitch = 0;
    kartSound->mPitchPerCall = 0;
    kartSound->mPrevKeyADown = 0;
    kartSound->mPitchPerSpeedOverLimit = FX_Div(0x300000, 0xd000 - kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mPitchPerSpeedKeyA = FX_Div(0x580000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mPitchPerSpeedNoKeyA = FX_Div(0x480000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mPitchPerSpeedKeyB = FX_Div(0x280000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mLapProgressAtLastSound = 0;
    kartSound->mLapProgressSoundCount = 0;
    kartSound->mLastSeqArcSoundRaceFrame = 0;
    kartSound->mThunderShrinkRaceFrame = -1;
    kartSound->mWhileRequestedSoundId = -1;
    switch (kart->mKartModelsEntry->mKartIndex / 3) {
        case 0:
            soundIndex = 4;
            break;
        case 1:
            soundIndex = 0;
            break;
        case 2:
            soundIndex = 1;
            break;
        case 3:
            soundIndex = 2;
            break;
        case 4:
            soundIndex = 5;
            break;
        case 5:
            soundIndex = 6;
            break;
        case 6:
            soundIndex = 7;
            break;
        case 7:
            soundIndex = 3;
            break;
        case 8:
            soundIndex = 10;
            break;
        case 9:
            soundIndex = 8;
            break;
        case 10:
            soundIndex = 9;
            break;
        case 11:
            soundIndex = 11;
            break;
        case 12:
            soundIndex = 12;
            break;
    }
    kartSound->mSoundIndex = soundIndex;
    soundRowIndex = GetKartSoundTableRow(kart->mKartModelsEntry->mKartIndex);
    rowOffset = soundRowIndex * 0x1c;
    firstSoundColumn = *(s32 *) (data_02161ae8 + rowOffset);
    secondSoundColumn = *(s32 *) (data_02161aec + rowOffset);
    thirdSoundColumn = *(s32 *) (data_02161af0 + rowOffset);
    highRatioSoundId = *(s32 *) (data_02161af4 + rowOffset);
    midRatioSoundId = *(s32 *) (data_02161af8 + rowOffset);
    lowRatioSoundId = *(s32 *) (data_02161afc + rowOffset);
    lastSoundColumn = *(s32 *) (data_02161b00 + rowOffset);
    soundRow.mSoundRowIndex = soundRowIndex;
    soundRow.mUnk_04 = firstSoundColumn;
    soundRow.mUnk_08 = secondSoundColumn;
    soundRow.mUnk_0c = thirdSoundColumn;
    soundRow.mHighRatioSoundId = highRatioSoundId;
    soundRow.mMidRatioSoundId = midRatioSoundId;
    soundRow.mLowRatioSoundId = lowRatioSoundId;
    soundRow.mClampedPitchSoundId = lastSoundColumn;
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
        secondSoundColumn = thirdSoundColumn;
    }
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
        firstSoundColumn = thirdSoundColumn;
    }
    soundRow.mKeyAHighRatioSoundId = secondSoundColumn;
    soundRow.mKeyALowRatioSoundId = firstSoundColumn;
    kartSound->mSoundRow = soundRow;
}

PlayingSound *StartSoundFullVolume(SoundSource *soundSource, u32 soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    volume = 0x7fu;
    pitch = 0u;
    return StartSound(sourceCopy, soundIdCopy, volume, pitch);
}

void StartSoundWhileRequestedFullVolume(SoundSource *soundSource, u32 soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 value12;
    volume = 0x7fu;
    pitch = 0u;
    StartSoundWhileRequested(sourceCopy, soundIdCopy, volume, pitch);
}

void StartKartSurfaceSoundWhileRequestedFromKart(void *kart, int entryIndex) {
    StartKartSurfaceSoundWhileRequested(kart, entryIndex, ((Kart *) kart)->mSurfaceKind,
                                        ((Kart *) kart)->mSurfaceVariant, ((Kart *) kart)->mWaterDepth);
}

void StartSurfaceSoundFromKart(Kart *kart, s32 entryIndex) {
    StartSurfaceSound(&kart->mSoundSource, entryIndex, kart->mSurfaceKind, kart->mSurfaceVariant, kart->mWaterDepth);
}

void KartStartSoundFullVolume(void *soundSource, int soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 v6;
    volume = 0x7fu;
    pitch = 0u;
    StartSound(sourceCopy, soundIdCopy, volume, pitch);
}

void StartKartSoundWhileRequested(void *kart, int soundId) {
    if (StartSoundWhileRequested(kart, soundId, 0x7f, 0) != NULL) {
        ((Kart *) kart)->mSound.mWhileRequestedSoundId = soundId;
    }
}

void RequestKartSound(void *kart, int soundId) {
    int sortKeyBase;

    sortKeyBase = GetKartCameraDistanceSquared(((Kart *) kart)->mIndex);
    AddSoundRequest(&data_0217d284, sortKeyBase + GetKartSoundRequestSortOffset(), StartKartSoundWhileRequested, kart,
                    soundId);
}

void StartKartSeqArcSoundOffset7(Kart *kart) {
    if (kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT)) {
        return;
    }
    StartKartSeqArcSound(kart, kart->mSoundIndex, 7);
}

void AdvanceKartModelScaleAnimation(Kart *kart) {
    kart->mModelScaleFrameIndex++;
    if (kart->mModelScaleFrameIndex >= kart->mModelScaleFrameCount) {
        kart->mModelScaleFrameIndex = 0;
        kart->mUnk_4c &= ~8;
        return;
    }
    if (kart->mModelScaleKind == 0) {
        kart->mModelScaleY = gKartModelScaleYKind0Table[kart->mModelScaleFrameIndex];
        kart->mModelOffsetY = gKartModelOffsetYKind0And2Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = 0x1000;
        kart->mModelScaleX = kart->mModelScaleZ;
    } else if (kart->mModelScaleKind == 1) {
        kart->mModelScaleY = gKartModelScaleYKind1Table[kart->mModelScaleFrameIndex];
        kart->mModelOffsetY = gKartModelOffsetYKind1Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = 0x1000;
        kart->mModelScaleX = kart->mModelScaleZ;
    } else if (kart->mModelScaleKind == 2) {
        kart->mModelScaleY = 0x1000;
        kart->mModelOffsetY = gKartModelOffsetYKind0And2Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleX = gKartModelScaleXKind2Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = gKartModelScaleZKind2Table[kart->mModelScaleFrameIndex];
    }
}

void AdvanceKartOffsetCycle(Kart *kart) {
    s32 fraction;
    u16 tableIndex;
    u16 nextTableIndex;
    s32 keyALevel;
    s32 amountScale;
    s32 t;

    kart->mOffsetCyclePhase = kart->mOffsetCyclePhase + kart->mOffsetCyclePhaseStep;
    t = kart->mOffsetCyclePhase - 0x8000;
    if (t >= 0) {
        kart->mOffsetCyclePhase = t;
    }
    fraction = kart->mOffsetCyclePhase & 0xfff;
    tableIndex = kart->mOffsetCyclePhase >> 12;
    nextTableIndex = tableIndex + 1;
    if (nextTableIndex >= 8) {
        nextTableIndex = 0;
    }
    kart->mOffsetCycleAmount.x =
        gKartOffsetCycleX[tableIndex] +
        MUL_FIXED12_NO_ROUND((gKartOffsetCycleX[nextTableIndex] - gKartOffsetCycleX[tableIndex]) >> 1, fraction);
    kart->mOffsetCycleAmount.y =
        gKartOffsetCycleY[tableIndex] +
        MUL_FIXED12_NO_ROUND((gKartOffsetCycleY[nextTableIndex] - gKartOffsetCycleY[tableIndex]) >> 1, fraction);
    kart->mOffsetCycleAmount.z =
        gKartOffsetCycleZ[tableIndex] +
        MUL_FIXED12_NO_ROUND((gKartOffsetCycleZ[nextTableIndex] - gKartOffsetCycleZ[tableIndex]) >> 1, fraction);
    keyALevel = kart->mRevLevel;
    amountScale = MUL_FIXED12_NO_ROUND(keyALevel, 0x333);
    if (keyALevel > 0xf33) {
        t = MUL_FIXED12_NO_ROUND((keyALevel - 0xf33) * 0x32, 0x19a);
        if (t > 0x19a) {
            t = 0x19a;
        }
        t = t + 0x333;
        amountScale = MUL_FIXED12_NO_ROUND(keyALevel, t);
    } else if (keyALevel > 0xd9a) {
        t = MUL_FIXED12_NO_ROUND((keyALevel - 0xd9a) * 0x32, 0x52);
        if (t > 0x52) {
            t = 0x52;
        }
        t = t + 0x333;
        amountScale = MUL_FIXED12_NO_ROUND(keyALevel, t);
    }
    kart->mOffsetCycleAmount.x =
        kart->mOffsetCycleAmount.x + MUL_FIXED12_NO_ROUND(kart->mOffsetCycleAmount.x, amountScale);
    kart->mOffsetCycleAmount.y =
        kart->mOffsetCycleAmount.y + MUL_FIXED12_NO_ROUND(kart->mOffsetCycleAmount.y, amountScale);
    kart->mOffsetCycleAmount.z =
        kart->mOffsetCycleAmount.z + MUL_FIXED12_NO_ROUND(kart->mOffsetCycleAmount.z, amountScale);
}

void AdvanceKartHeadingSwing(Kart *kart) {
    s32 offset;

    if (kart->mHeadingAngleOffsetCount <= 2) {
        kart->mHeadingAngleOffsetPerFrame =
            kart->mHeadingAngleOffsetDirection * 0x3c + kart->mHeadingAngleOffsetPerFrame;
        if (kart->mHeadingAngleOffsetPerFrame > 0x17c) {
            kart->mHeadingAngleOffsetPerFrame = 0x17c;
        } else if (kart->mHeadingAngleOffsetPerFrame < -0x17c) {
            kart->mHeadingAngleOffsetPerFrame = -0x17c;
        }
        kart->mHeadingAngleOffset = kart->mHeadingAngleOffset + kart->mHeadingAngleOffsetPerFrame;
        offset = kart->mHeadingAngleOffset;
        if ((offset > 0 ? offset : -offset) > 0x1770) {
            if ((offset > 0 && kart->mHeadingAngleOffsetDirection > 0) ||
                (offset < 0 && kart->mHeadingAngleOffsetDirection < 0)) {
                kart->mHeadingAngleOffsetDirection *= -1;
                kart->mHeadingAngleOffsetCount = kart->mHeadingAngleOffsetCount + 1;
            }
        }
        kart->mRevLevel = 0x1000;
    } else {
        kart->mHeadingAngleOffsetPerFrame =
            kart->mHeadingAngleOffsetDirection * 0x3c + kart->mHeadingAngleOffsetPerFrame;
        if (kart->mHeadingAngleOffsetPerFrame > 0xd2) {
            kart->mHeadingAngleOffsetPerFrame = 0xd2;
        } else if (kart->mHeadingAngleOffsetPerFrame < -0xd2) {
            kart->mHeadingAngleOffsetPerFrame = -0xd2;
        }
        kart->mHeadingAngleOffset = kart->mHeadingAngleOffset + kart->mHeadingAngleOffsetPerFrame;
        kart->mRevLevel = MUL_FIXED12_NO_ROUND(kart->mRevLevel, 0xf5c);
        offset = kart->mHeadingAngleOffset;
        if ((offset > 0 && kart->mHeadingAngleOffsetDirection > 0) ||
            (offset < 0 && kart->mHeadingAngleOffsetDirection < 0)) {
            kart->mHeadingAngleOffset = 0;
            kart->mUnk_4c &= ~KART_4C_HEADING_SWING;
            SetKartCharacterAnimation(kart, 0, 1);
            kart->mUnk_44 |= 0x1000000;
        }
    }
}

void StartKartModelScaleAnimation(Kart *kart, s32 a) {
    s32 state;

    state = kart->mState;
    if (state != KART_STATE_NORMAL && state != KART_STATE_LAUNCH_DOUBLE_FLIP) {
        return;
    }
    if (a == 2) {
        kart->mModelScaleKind = 2;
    } else if (kart->mUnk_44 & 2) {
        kart->mModelScaleKind = 1;
    } else if (kart->mAirborneFrames > 0xa) {
        kart->mModelScaleKind = 1;
    } else {
        kart->mModelScaleKind = 0;
    }
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = 0xf;
    kart->mUnk_4c |= 8;
}

void ResetKartMotionState(Kart *kart, s32 b) {
    NNSSndSeqPlayer **sndHandleSlot;
    PlayingSound *playingSound;

    if (b == 0) {
        kart->mUnk_48 |= KART_48_INPUT_LOCKED;
        kart->mUnk_44 &= ~KART_44_ON_GROUND;
    }
    kart->mUnk_48 &= 0xdfe77fdf;
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(kart->mUnk_4c & 0x10000000) && !(kart->mUnk_48 & 0x4000000)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
        kart->mUnk_4c &= ~KART_4C_AHEAD_BOOST;
        kart->mAheadSpeedLimitFactor = 0x1000;
        if (!(kart->mUnk_4c & 0x8000000)) {
            ResetKartModelsCourseColors(kart);
        }
        StopKartNearRankEffect(kart);
    }
    ReleaseKartAheadEffect(kart);
    kart->mUnk_44 &= 0xfffff7f4;
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    kart->mState = KART_STATE_NORMAL;
    kart->mUnk_4c &= ~0x30;
    kart->mUnk_48 &= ~0x20000;
    SetKartCharacterAnimation(kart, 0, 1);
    kart->mUnk_44 |= 0x80000000;
    ResetKartMotionVectorsAndFactors(kart);
    StartFixedPositionEffects(kart);
    if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    StartCameraWobbleByCourse();
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_AIRSHIP:
            StartTimedQuadFromTable(0);
            playingSound = StartSound(&kart->mSoundSource, 0x15c, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= 0x10;
            }
            sndHandleSlot = GetSndHandleSlot(7);
            if (!(gRaceSoundKind & 1)) {
                return;
            }
            if (gSoundModeHolder.mSeqStartEnabled == 0) {
                return;
            }
            if (sndHandleSlot[0] != NULL) {
                NNS_SndPlayerStopSeq(sndHandleSlot, 0);
            }
            if (sndHandleSlot[0] != NULL) {
                NNS_SndPlayerStopSeq(sndHandleSlot, 0);
            }
            NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x1d2);
            break;
        case COURSE_ID_PINBALL:
            playingSound = StartSound(&kart->mSoundSource, 0x15b, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= 0x10;
            }
            break;
    }
}

void StartFixedPositionEffects(Kart *kart) {
    s32 effectIdsOther[2];
    Vec3 effectPos;
    Vec3 effectIdsSelected;
    Camera *currentCamera;
    Vec3 *cameraPos;
    BOOL cameraOutsideBox;
    s32 effectCount;
    s32 i;
    s32 *nextEffectId;
    s32 *effectIdsOtherPtr;

    effectPos = data_0216553c;
    cameraOutsideBox = TRUE;
    currentCamera = GetCurrentCamera();
    cameraPos = &currentCamera->mPos;
    if (cameraPos->x > -0x64f000) {
        if (cameraPos->x < -0x3cb000) {
            if (cameraPos->z > -0x1ad7000) {
                if (cameraPos->z < -0x164d000) {
                    cameraOutsideBox = FALSE;
                }
            }
        }
    }
    if (cameraOutsideBox != FALSE) {
        effectIdsSelected = data_02165548;
        effectIdsOtherPtr = effectIdsOther;
        effectIdsOther[0] = data_02165510[0];
        effectIdsOther[1] = data_02165510[1];
        effectCount = 3;
        nextEffectId = (s32 *) &effectIdsSelected;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            effectCount = 2;
            nextEffectId = effectIdsOtherPtr;
        }
        for (i = 0; i < effectCount; i++) {
            StartEffect(*nextEffectId, &effectPos);
            nextEffectId++;
        }
    } else {
        StartEffect((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 0x47 : 0x52, &effectPos);
    }
}

static inline s32 NormalizeLengthOrZero(Vec3 *src, Vec3 *dst) {
    if (LENGTH_SQUARED(*src) < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(src, dst);
}

void AdvanceKartToKeyedPlacement(Kart *kart) {
    KartItemEffectState *itemEffectState;
    u16 placementIndex;
    s32 distance;
    s32 angleIndex;
    s32 t;
    u32 flags;
    Vec3 placementPos;
    Vec3 placementAngles;
    Vec3 groundNormal;
    Vec3 toTarget;
    Vec3 placementForward;
    Vec3 side;
    Vec3 toKart;
    Vec3 flatForward;
    Vec3 sideVector;
    MtxFx43 m2;
    MtxFx33 rotationMatrix;
    Vec3 axis;

    placementAngles = gKartVec3Zero;
    placementIndex = *gCourseMap->mKeyedPlacementIndexByKey;
    placementPos.x = gCourseMap->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = gCourseMap->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = gCourseMap->mKeyedPlacements[placementIndex].mPos.z;
    placementAngles.x = gCourseMap->mKeyedPlacements[*gCourseMap->mKeyedPlacementIndexByKey].mRotation.x;
    placementAngles.y = gCourseMap->mKeyedPlacements[*gCourseMap->mKeyedPlacementIndexByKey].mRotation.y;
    placementAngles.z = gCourseMap->mKeyedPlacements[*gCourseMap->mKeyedPlacementIndexByKey].mRotation.z;
    angleIndex = (u16) (((s64) placementAngles.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >> 4;
    MTX_RotY33_(&rotationMatrix, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
    MTX_MultVec33(&data_02154f70, &rotationMatrix, &placementForward);
    SkipOrthoQuadsHoldAndSetVelocities(kart->mIndex);

    flags = kart->mUnk_4c;
    if (!(flags & 0x20000) && (flags & 0x8000000)) {
        itemEffectState = &kart->mItemEffectData;
        if (itemEffectState->mGessoFrames <= 0x190) {
            itemEffectState->mGessoFrames = 0x190;
            kart->mUnk_4c |= 0x20000;
            StartKartModelColorBlend(kart->mKartModelsEntry, GetKartCourseDiffColor(), GetKartCourseEmiColor(),
                                     GetKartCourseAmbColor());
        }
    }
    if (kart->mUnk_4c & 0x8000000) {
        AdvanceKartGesso(kart);
    }
    flags = kart->mUnk_4c;
    if (flags & 0x10000000) {
        AdvanceKartKiller(kart);
    } else {
        if (flags & KART_4C_THUNDER_SHRINK) {
            AdvanceKartThunderShrink(kart);
        }
        if (kart->mUnk_4c & 0x10000) {
            AdvanceKartScaleTableEffect(kart);
        }
        if (kart->mUnk_7c & 0x402000) {
            AdvanceKartTeresa(kart);
        }
    }

    if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
        itemEffectState = &kart->mItemEffectData;
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            AddSoundRequest(gSoundRequestQueues, GetKartCameraDistanceSquared(kart->mIndex), RequestKartSound, kart,
                            0xa3);
        }
        itemEffectState->mAheadBoostFrames++;
        if (itemEffectState->mAheadBoostFrames > KART_KILLER_RANK_END_FRAMES && (kart->mUnk_4c & KART_4C_AHEAD_BOOST)) {
            kart->mUnk_4c &= ~KART_4C_AHEAD_BOOST;
            kart->mAheadSpeedLimitFactor = 0x1000;
            if (!(kart->mUnk_4c & 0x8000000)) {
                ResetKartModelsCourseColors(kart);
            }
            StopKartNearRankEffect(kart);
        }
    }

    if (kart->mUnk_4c & 0x40) {
        itemEffectState = &kart->mItemEffectData;
        AdvanceKartStarEffects(kart->mIndex);
        if ((kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) &&
            kart->mKartModelsEntry->mCharacterAnimation->mCurrentIndex == 0) {
            SetKartCharacterAnimation(kart, 2, 1);
        }
        itemEffectState->mStarFrames++;
        if (itemEffectState->mStarFrames > KART_TERESA_MAX_FRAMES) {
            kart->mUnk_4c &= ~0x40;
            StopKartStarModels(kart);
            kart->mItemEffect = 0;
            StopKartStarEffects(kart->mIndex);
            SetKartCharacterAnimation(kart, 0, 1);
            if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                StopKartStarSeq();
            }
            if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
                SetKartModelsGrayColors(kart);
            }
        }
    }

    gInputSlots[kart->mEntryIndex].mBitMask = 0xe04;
    Vec3CrossUnrounded(&gKartVec3UnitY, &placementForward, &side);
    VEC_Subtract(&kart->mPos, &placementPos, &toKart);
    toKart.y = 0;
    VEC_MultAdd(Vec3DotUnrounded(&side, &toKart), &side, &placementPos, &placementPos);
    Vec3DotUnrounded(&side, &toKart);
    VEC_Subtract(&placementPos, &kart->mPos, &toTarget);
    distance = NormalizeLengthOrZero(&toTarget, &toTarget);

    if (Vec3DotUnrounded(&toTarget, &placementForward) <= 0) {
        StopDispCapBlend();
        kart->mUnk_48 &= ~0x10000;
        AdvanceKartQuaternionBlendFactor(kart, &kart->mGroundNormal);
        kart->mUnk_48 &= ~KART_48_INPUT_LOCKED;
        kart->mAirTiltAngleOffset = (s16) (MUL_FIXED12_NO_ROUND(placementAngles.x, 0x4000) >> 12) + 0x32;
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mCourseId == COURSE_ID_AIRSHIP) {
            NNS_SndPlayerStopSeq(GetSndHandleSlot(7), 0x14);
        }
    } else {
        if (distance > 0x64000) {
            kart->mTurnedForward = toTarget;
        }
        flatForward = kart->mTurnedForward;
        flatForward.y = 0;
        kart->mQuaternionBlendFactor = 0x1000;
        NormalizeLengthOrZero(&flatForward, &flatForward);
        kart->mHeadingAngle = MUL_FIXED12_NO_ROUND(FX_Atan2(flatForward.x, flatForward.z), 0x28be60d) >> 12;
        axis = data_02165524;
        QuaternionFromAxisAngle(&axis, kart->mHeadingAngle, &kart->mUnk_e0_m);
        Vec3CrossUnrounded(&gKartVec3UnitY, &kart->mTurnedForward, &sideVector);
        Vec3CrossUnrounded(&kart->mTurnedForward, &sideVector, &groundNormal);
        if (kart->mAirTiltAngle > -5000) {
            kart->mAirTiltAngle -= 300;
            if (kart->mAirTiltAngle < -5000) {
                kart->mAirTiltAngle = -5000;
            }
        }
        MTX_RotAxis33(&m2.mAxes, &kart->mUnk_120, FX_SinIdx((u16) kart->mAirTiltAngle),
                      FX_CosIdx((u16) kart->mAirTiltAngle));
        MTX_MultVec33(&groundNormal, &m2.mAxes, &groundNormal);
        kart->mGroundNormal = groundNormal;
        AdvanceKartOrientation(kart, &groundNormal);
    }

    kart->mForwardSpeed = 0x1e000;
    t = kart->mForwardSpeed;
    m2.mRows[3].x = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.x, t);
    m2.mRows[3].y = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.y, t);
    m2.mRows[3].z = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.z, t);
    kart->mEasedTurnedForward = kart->mTurnedForward;
    if (distance < 0x3e8000) {
        t = MUL_FIXED12_NO_ROUND(distance, 0x29) + 0x14000;
        if (kart->mForwardSpeed > t) {
            kart->mForwardSpeed = t;
        }
    }
    kart->mVelocity = m2.mRows[3];
    VEC_Add(&kart->mPos, &kart->mVelocity, &kart->mPos);
}

void PlaceKartAtKeyedPlacement(Kart *kart, u32 key) {
    Vec3 placementPos;
    Vec3 placementForward;
    MtxFx33 rotationMatrix;
    Vec3 offset;
    Vec3 axis;
    NNSSndSeqPlayer **sndHandle;
    u16 placementIndex;
    s32 angleIndex;

    ResetKartMotionState(kart, 1);
    kart->mVerticalSpeed = 0x3000;
    placementIndex = gCourseMap->mKeyedPlacementIndexByKey[key];
    placementPos.x = gCourseMap->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = gCourseMap->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = gCourseMap->mKeyedPlacements[placementIndex].mPos.z;
    angleIndex = (u16) (((s64) gCourseMap->mKeyedPlacements[gCourseMap->mKeyedPlacementIndexByKey[key]].mRotation.y *
                             0xb60b60b60bLL +
                         0x80000000LL) >>
                        44) >>
                 4;
    MTX_RotY33_(&rotationMatrix, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
    MTX_MultVec33(&data_02154f70, &rotationMatrix, &placementForward);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        VEC_Subtract(&placementPos, &kart->mPos, &offset);
        CallStandingsKartOffsetCallback(kart->mIndex, &offset);
    }
    kart->mPos = placementPos;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mForwardSpeed = 0x5000;
    kart->mTurnedForward = placementForward;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mHeadingAngle = MUL_FIXED12_NO_ROUND(FX_Atan2(placementForward.x, placementForward.z), 0x28be60dLL) >> 12;
    axis = data_02165524;
    QuaternionFromAxisAngle(&axis, kart->mHeadingAngle, &kart->mUnk_e0_m);
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetupCameraBehindKart();
        if (gRaceSoundKind & 1) {
            sndHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (sndHandle[0] != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                if (sndHandle[0] != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(sndHandle, 0, 0x159);
            }
        }
    }
    if (!(kart->mUnk_7c & 2)) {
        return;
    }
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    ResetBattleKartAiAtPointLink(kart->mAi, GetKeyedPlacementBattlePointLink(key));
}

void ComputeKartAirTiltQuaternion(Kart *kart, Vec4 *quaternion) {
    MtxFx43 headingMatrix;
    MtxFx43 tiltMatrix;
    Vec3 tiltAxis;
    Vec3 tiltedUp;
    s32 dot;
    u16 headingAngle;
    u16 airTiltAngle;

    if (kart->mVelocityLength < 0x1000) {
        return;
    }
    if (Vec3DotUnrounded(&kart->mUnk_12c, &gKartVec3UnitY) <= 0) {
        return;
    }
    kart->mAirTiltAngle = kart->mAirTiltAngle + kart->mAirTiltAngleOffset;
    headingAngle = kart->mHeadingAngle;
    airTiltAngle = kart->mAirTiltAngle;
    MTX_RotY43_(&headingMatrix, FX_SinIdx(headingAngle), FX_CosIdx(headingAngle));
    MTX_MultVec43(&data_02154f88, &headingMatrix, &tiltAxis);
    MTX_RotAxis43(&tiltMatrix, &tiltAxis, FX_SinIdx(airTiltAngle), FX_CosIdx(airTiltAngle));
    MTX_MultVec43(&gKartVec3UnitY, &tiltMatrix, &tiltedUp);
    TryQuaternionFromVectors(quaternion, &gKartVec3UnitY, &tiltedUp);
    if (kart->mUnk_48 & 0x80000000) {
        quaternion->x = -quaternion->x;
        quaternion->y = -quaternion->y;
        quaternion->z = -quaternion->z;
        quaternion->w = -quaternion->w;
    }
    if (kart->mUnk_44 & 2) {
        return;
    }
    dot = Vec3DotUnrounded(&kart->mVelocityDirection, &kart->mUnk_138);
    if (dot <= 0) {
        dot = -dot;
    }
    kart->mVelocityScaleFactor = dot;
    if (kart->mVelocityScaleFactor < 0xb33) {
        kart->mVelocityScaleFactor = 0xb33;
    }
}

BOOL TryHoldKartStill(Kart *kart, u32 b, void *c) {
    u32 flags;

    flags = kart->mUnk_44;
    if (!(flags & 0xc2200) && !(kart->mUnk_7c & 0x400)) {
        if (!(flags & 0xc0000) && !(kart->mUnk_4c & 0x100) && kart->mPointMotion.x == 0 && kart->mPointMotion.y == 0 &&
            kart->mPointMotion.z == 0 && kart->mAttractorPullSpeed == 0 && kart->mCollisionStepFrames >= 0x64) {
            kart->mPos.x = kart->mPrevPos.x;
            kart->mPos.z = kart->mPrevPos.z;
        } else {
            UpdateCollisionHitLink(c, b, kart->mCollisionHitLink, &kart->mPos, NULL);
        }
        kart->mVelocity = gKartVec3Zero;
        kart->mVelocityLength = 0;
        kart->mUnk_44 |= 0x1000;
        return TRUE;
    }
    return FALSE;
}
