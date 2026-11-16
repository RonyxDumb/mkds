#include "Main/Unknown/code_02070398.h"
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
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Kart/KartTurnEffects.h"
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
#include "Main/System/Heap.h"
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
#include "Main/Kart/KartAiCallbacks.h"
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
#include "Main/Kart/KartStates.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

void AdvanceKartScaleFactor(Kart *kart) {
    s32 frameIndex;
    enum { K0 } entryIndex;

    entryIndex = kart->mEntryIndex;
    data_0217566a[entryIndex].mBitMask = 0xff7;
    if (kart->field7C & 0x20) {
        StructMQRacerEntry_SomeFn_53(kart);
        return;
    }
    kart->field3C8 = kart->field3C8 + 1;
    frameIndex = kart->field3C8;
    if (frameIndex >= 0x19) {
        kart->field7C &= ~0x80;
        return;
    }
    kart->mScaleFactor.x = gKartScaleFactorXTable[frameIndex];
    kart->mScaleFactor.y = gKartScaleFactorYTable[frameIndex];
    kart->mScaleFactor.z = gKartScaleFactorZTable[frameIndex];
    kart->mScale.x = ((s64) kart->mScaleBase.x * kart->mScaleFactor.x) >> 12;
    kart->mScale.y = ((s64) kart->mScaleBase.y * kart->mScaleFactor.y) >> 12;
    kart->mScale.z = ((s64) kart->mScaleBase.z * kart->mScaleFactor.z) >> 12;
    kart->mScale.y = ((s64) kart->mScaleYFactor * kart->mScale.y) >> 12;
}

void driver_respawn(Kart *kart) {
    Vec3 respawnPos;
    Vec3 respawnForward;
    Vec3 respawnAngles;
    Vec3 sideDirection;
    s32 rotationMatrix[9];
    PointLink *respawnLink;
    s32 x;
    s32 forwardOffset;
    s32 i;
    KartItems *kartItems;
    s64 l;

    if (kart->mRespawnSlot == -1) {
        i = kart->mIndex;
        if (gRaceMultiConfig->mMode == MODE_BATTLE) {
            i = mdat_getRespawnId(0);
        } else {
            i = mdat_getRespawnId(gRaceStatus->field0[i].mCheckpoint);
        }
        kart->mRespawnSlot = i;
    }
    i = (u16) kart->mRespawnSlot;
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        respawnLink = mdat_getMgRespawnData(i, &respawnPos, &respawnAngles);
    } else {
        respawnLink = mdat_getRespawnData(i, &respawnPos, &respawnAngles);
    }
    i = ((u16) ((s32) (((s64) respawnAngles.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
    MTX_RotY33_(rotationMatrix, FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
    MTX_MultVec33(&driverCore_sForwardVec, rotationMatrix, &respawnForward);
    if (gRaceMultiConfig->mMode != MODE_BATTLE && gMapData->mItemRouteCount != 0) {
        (kartItems = &it_sDriverItemStatus[kart->mIndex])->field1F0.mLink =
            mdat_getItemPointForRespawn((u16) kart->mRespawnSlot);
        kartItems->field1F0.mNextLinksUsed = 1;
    }
    if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
        x = driver_sRespawnOffsets[kart->mIndex][0];
        forwardOffset = data_02154d50[kart->mIndex][0];
        vec_crossProduct(&driverCore_sUpVec, &respawnForward, &sideDirection);
        VEC_MultAdd(((s64) data_02165504 * x) >> 12, &sideDirection, &respawnPos, &respawnPos);
        VEC_MultAdd(((s64) data_02165504 * forwardOffset) >> 12, &respawnForward, &respawnPos, &respawnPos);
        if (respawnAngles.x != 0 && forwardOffset != 0) {
            i = ((u16) ((s32) (((s64) respawnAngles.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = FX_SinCosTable_[i * 2];
            i = (l * -forwardOffset + 0x800) >> 12;
            respawnPos.y += (s32) (((s64) i * data_02165504 + 0x800) >> 12);
        }
        if (respawnAngles.z != 0 && x != 0) {
            i = ((u16) ((s32) (((s64) respawnAngles.z * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = FX_SinCosTable_[i * 2];
            i = (l * x + 0x800) >> 12;
            respawnPos.y += (s32) (((s64) i * data_02165504 + 0x800) >> 12);
        }
    }
    respawnPos.y += 0x28000;
    x = kart->field48;
    if (x & 0x800000) {
        rptc_2081F10(ptcm_createEmitter(0x71, &respawnPos), kart->mIndex, 0x32);
    } else if (x & 0x1000000) {
        rptc_2081F10(ptcm_createEmitter(0x70, &respawnPos), kart->mIndex, 0x32);
    }
    driver_2072B94(kart, &respawnPos, &respawnForward, respawnLink);
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        driver_getPlayerStatistics()->field18++;
    } else {
        sfx_210B850(&kart->field518);
    }
    kart->field4C |= 0xc00;
    kart->field48 |= 0x2000000;
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        dce_fadeOutToBlack(0x3c);
        cam_2075D08(0);
    }
}

s32 driver_handlePreRespawn(Kart *kart, s32 *a) {
    BOOL finished;
    u32 flags;

    flags = kart->field4C;
    finished = FALSE;
    if (flags & 0x4000000) {
        if (kart->field4BC > 0x19a) {
            kart->field4BC = ((s64) kart->field4BC * 0xe66LL) >> 12;
        }
        *a = kart->field4BC;
    } else if (flags & 0x200000) {
        if (kart->field4BC > 0x666) {
            kart->field4BC = ((s64) kart->field4BC * 0xe66LL) >> 12;
        }
        *a = kart->field4BC;
    }
    kart->mRespawnFrames = kart->mRespawnFrames + 1;
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (kart->mRespawnFrames == 0x16) {
            dce_2055A94();
        } else if (kart->mRespawnFrames == 0x19) {
            dce_fadeInFromBlack(0x3c);
        }
    }
    if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && kart->mRespawnFrames == 0x55) {
        jg_startRespawning();
    } else if (kart->mRespawnFrames > 0x78) {
        sub_2063AD0(kart);
        finished = TRUE;
    }
    return finished;
}

void driver_2072B94(Kart *kart, const Vec3 *position, const Vec3 *forward, PointLink *link) {
    ParticipantKartRecordState *q;
    Vec3 axis;

    driver_reset(kart);
    chkrt_applyKartCrsMat(kart->mKartModelsEntry);
    kart->mSlotFunctions[1](kart);
    kart->field7C &= ~0xe000;
    cspl_killSplashes(kart->mIndex);
    kart->field48 |= 0x240;
    kart->mPos = *position;
    if (kart->field7C & 0x400) {
        q = kart->field514;
        q->field0 = kart->mPos;
        q->field10 = q->field0;
        q->field4C = *(Vec4 *) &kart->field108.z;
        q->fieldA8 = driverCore_sZeroVec;
        q->fieldB4 = 0;
    }
    if (forward != NULL) {
        kart->mHeadingAngle = (s32) (((s64) FX_Atan2(forward->x, forward->z) * 0x28be60dLL) >> 12) >> 12;
        axis = data_02165524;
        qrtn_fromAxisAngle(&axis, kart->mHeadingAngle, &kart->mUnk_e0_m);
    }
    qrtn_toMtx43(&kart->field120, &kart->mUnk_e0_m);
    driver_getShadowZDirection(kart, &kart->mForward);
    kart->mTurnedForward = kart->mForward;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mPrevCollisionCenter = kart->mPos;
    kart->mCollisionCenter = kart->mPos;
    kart->mLastGroundY = kart->mPos.y;
    if (kart->field7C & 2) {
        if (link != NULL) {
            enmy_208C23C(kart->mAi, link);
        } else {
            enmy_init(kart->mAi, kart->mIndex);
        }
    }
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        cam_setPlayerCameraPosRot(position, &kart->mUnk_e0_m);
        nullsub_7(((u32(*)(void)) cam_resetPlayerCameraFov)());
        cam_20747F4(0);
    }
}

void driver_reset(Kart *kart) {
    s32 i;
    KartFollowEffectIds effectIds;

    ReleaseKartItems(&it_sDriverItemStatus[kart->mIndex]);
    rptc_2083834(kart);
    rptc_stopRainbowEffectDirect(kart->mIndex);
    rptc_stopBulletBillEffectDirect(kart->mIndex);
    rptc_stopWallLeafEffect(kart->mIndex);
    rptc_stopElectricEffect(kart->mIndex);
    rptc_stopSlipstreamBeginEffectDirect(kart);
    rptc_stopSlipstreamEffectDirect(kart);
    dptc_killAll(dptc_getControllerForDriver(kart->mIndex));
    driver_initField450(kart);
    if (kart->mIndex == gRaceMultiConfig->mEntryIndex) {
        sub_210FA74(0);
    }
    sub_210A664(kart);
    if (kart->field4C & 0x2000) {
        driver_disableSlipStreamToonMode(kart);
    }
    if (kart->field4C & 0x40) {
        kart->field4C &= ~0x40;
        driver_disableStarToonMode(kart);
        kart->mItemEffect = 0;
        rptc_stopRainbowEffect(kart->mIndex);
        driver_2068A64(kart, 0, 1);
        if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
            snd_stopStarMusic();
        }
        if (kart->field4C & 0x2000) {
            driver_enableSlipStreamToonMode(kart);
        }
    }
    if (kart->field4C & 0x10000000) {
        kart->field4C &= ~0x10000000;
        sub_210515C(kart->mIndex);
        if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            cam_resetPlayerCameraTargetFov();
        }
        kart->mRadiusFactor = 0x1000;
        kart->mSurfaceGroup = -1;
        i = 0;
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->field58 == 0) {
            effectIds = gKartFollowEffectIds;
            for (i = 0; i < 3; i++) {
                rptc_2081F10(ptcm_createEmitter(effectIds.mEffectIds[i], &kart->mPos), kart->mIndex, 0x14);
            }
        }
        rptc_stopBulletBillEffect(kart->mIndex);
        sfx_21090C4(&kart->mSoundSource, 0xfd, 0x7f, 0);
    }
    if (kart->field7C & 0x2000) {
        kart->field7C &= ~0x2000;
        kart->field7C &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            dptc_showAll(dptc_getControllerForDriver(kart->mIndex));
        } else {
            sfx_21090C4(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        sub_210FA40(0, (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
}

void ResetKartToStartPlacement(Kart *kart) {
    Vec3 startPos;
    Vec3 forward;
    Vec3 startAngles;
    Vec3 *collisionPos;

    if (!(kart->field7C & 0x20)) {
        return;
    }
    mdat_getStartPosition(&startPos, &startAngles, kart->mIndex);
    kart->mHeadingAngle = (u32) (startAngles.y * 0xb6) >> 12;
    qrtn_fromAxisAngle(&driverCore_sUpVec, kart->mHeadingAngle, &kart->mUnk_e0_m);
    qrtn_toMtx43(&kart->field120, &kart->mUnk_e0_m);
    driver_getShadowZDirection(kart, &forward);
    driver_2072B94(kart, &startPos, &forward, NULL);
    if (gRaceMultiConfig->mMode == 5) {
        collisionPos = &kart->mPointAlongUp;
    } else {
        collisionPos = &kart->mCollisionCenter;
    }
    if (kart->mCollisionSlot == -1) {
        kart->mCollisionSlot = col_createColEntry(collisionPos, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
    }
    if (kart->field2CA == -1) {
        kart->field2CA =
            col_createColEntry(&kart->field1F0, ((s64) kart->mPhysicalParam->mRadius << 15) >> 12, 0x800, kart);
    }
    kart->field7C |= 0x80;
    kart->field7C &= ~0x60;
    kart->mScale = driverCore_sZeroVec;
}

void driver_initPhysicalParams(Kart *kart) {
    s32 a;
    s32 b;
    s16 i;
    KartPhysicalParam *physicalParam;
    s32 *charPhysicalParam;

    kart->mPhysicalParam = physp_getDriverKartPhysicalParams(kart->mIndex);
    a = 0x1000;
    b = 0;
    if (race_isAwardStaffRoll() == 0) {
        switch (gRaceMultiConfig->mEngineIndex) {
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
    kart->mPhysicalParam->mBaseSpeedLimit = ((s64) kart->mPhysicalParam->mBaseSpeedLimit * a) >> 12;
    kart->mPhysicalParam->field32 = kart->mPhysicalParam->field32 + b;
    kart->mSpeedLimitFactorPerDepth = 0x1000 - kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4];
    kart->mSpeedLimitFactorPerDepth = FX_Div(kart->mSpeedLimitFactorPerDepth, kart->mPhysicalParam->mRadius << 1);
    kart->mCharPhysicalParam = physp_getDriverCharPhysicalParams(kart->mIndex);
    physicalParam = kart->mPhysicalParam;
    charPhysicalParam = kart->mCharPhysicalParam;
    for (i = 0; i < 12; i++) {
        a = physicalParam->mSurfaceSpeedLimitFactors[i];
        if (a < 0x1000) {
            physicalParam->mSurfaceSpeedLimitFactors[i] = ((s64) a * *charPhysicalParam + 0x800) >> 12;
        }
    }
}

void StructMQRacerEntry_SomeFn_11(Kart *kart) {
    Vec3 zeroVector;

    kart->fieldD4 = 0x1000;
    kart->fieldD8 = 0x1000;
    kart->mSpeedLimitFactor = 0x1000;
    kart->mSpeedLimitHitFactor = 0x1000;
    zeroVector = driverCore_sZeroVec;
    *(Vec3 *) &kart->field25C = zeroVector;
    kart->field268 = zeroVector;
    kart->field274 = 0;
    kart->mForward = zeroVector;
    kart->mHopStartForward = zeroVector;
    kart->mHitVelocity = zeroVector;
    kart->mPrevHitVelocity = zeroVector;
    kart->field2F0 = zeroVector;
    *(Vec3 *) &kart->field25C = zeroVector;
    kart->mAirborneFrames = 0;
    kart->mTurnAngle = 0;
    kart->field38A = 0;
    kart->mTurnedForwardEaseFactor = 0x1000;
    kart->mHeadingAnglePerFrame = 0;
}

void ResetKart(Kart *kart) {
    Vec3 zeroVector;
    u16 i;

    ClearCharacterTurnAndNextAnimation(kart->mKartModelsEntry);
    kart->field44 = 0;
    kart->field48 = 0;
    kart->field4C = 0;
    zeroVector = driverCore_sZeroVec;
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
    kart->fieldD4 = 0x1000;
    kart->fieldD8 = 0x1000;
    kart->mState = KART_STATE_NORMAL;
    driver_initTimers(&kart->field538);
    MTX_Identity43_(&kart->mUnk_120_m);
    MTX_Identity43_(&kart->mUnk_150_m);
    MTX_Identity43_(&kart->mWobbleMatrix);
    kart->mPointAlongUp = zeroVector;
    kart->mPrevPointAlongUp = kart->mPointAlongUp;
    kart->mPrevCollisionCenter = kart->mPrevPointAlongUp;
    kart->mCollisionCenter = kart->mPrevCollisionCenter;
    kart->field1F0 = zeroVector;
    kart->field1FC = zeroVector;
    kart->mSpeedLimitFactor = 0x1000;
    kart->mUnk_e0_m = data_02154f14;
    *(Vec4 *) &kart->fieldF0 = data_02154f24;
    *(Vec4 *) &kart->field100 = data_02154f34;
    *(Vec4 *) &kart->field108.z = data_02154f44;
    kart->mAirTiltAngle = 0;
    kart->mHeadingAngle = 0;
    kart->mBoostTimer = 0;
    kart->field23A = 0;
    kart->mMiniTurboTimer = 0;
    kart->mTurnedForwardEaseFactor = 0x1000;
    kart->mGroundNormal = driverCore_sUpVec;
    kart->field250 = zeroVector;
    *(Vec3 *) &kart->field25C = zeroVector;
    kart->field268 = zeroVector;
    kart->field274 = 0;
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
    kart->field334 = 0;
    kart->field338 = 0;
    kart->field33C = 0;
    kart->field344 = 0;
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
    kart->mRotationQuaternion = data_02154f54;
    kart->mRotationEndFrames = 0;
    kart->mRotationAnglePerFrame = 0;
    kart->mYRotationAngle = 0;
    kart->mYRotationAnglePerFrame = 0;
    kart->mYRotationCount = 0;
    kart->mYRotationAngleSum = 0;
    kart->field370 = 0;
    kart->field374 = zeroVector;
    kart->mAirborneFrames = 0;
    kart->mVisible = 0xffff;
    kart->mHeadingAnglePerFrame = 0;
    kart->mTurnAngle = 0;
    kart->field38A = 0;
    kart->mSpeedLimitHitFactor = 0x1000;
    kart->field394 = 0x1000;
    kart->mMapObjectVectorLength = 0;
    kart->mMapObjectVectorForwardDot = 0;
    kart->mTireSpinAngle = 0;
    kart->mQuaternionBlendFactor = 0x1ec;
    kart->mSinkFrames = 0;
    kart->mVelocity = zeroVector;
    kart->field3BC = 0;
    kart->mRaceStartFrameCount = 0;
    kart->mRespawnFrames = 0;
    kart->mRespawnSlot = -1;
    kart->field3C8 = 0;
    kart->mKartCollisionTimer = 0;
    kart->mKartCollisionDelayTimer = 0;
    kart->mSurfaceGroup = -1;
    kart->mSurfaceKind = 0;
    kart->mSurfaceVariant = 0;
    kart->field3E8 = 0;
    kart->mTurnHeadingAnglePerFrameGoal = 0;
    kart->mTurnHeadingAnglePerFrame = 0;
    kart->field3F8 = 0x1000;
    kart->mModelScaleKind = 0;
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = 0;
    kart->mModelScaleY = 0x1000;
    kart->mModelScaleX = 0x1000;
    kart->mModelScaleZ = 0x1000;
    for (i = 0; i < 2; i++) {
        kart->mPrevTouchingMapObjects[i] = NULL;
        kart->field440[i] = 0;
        kart->field444[i] = 0;
    }
    kart->field44C = NULL;
    kart->mModelOffsetY = 0;
    kart->field40C = 0;
    kart->field410 = 0;
    kart->field4BC = 0;
    kart->field4C0 = 0;
    kart->field4C4 = 0;
    kart->mRadiusFactor = 0x1000;
    kart->field4D0 = 0;
    kart->field4D4 = 0;
    kart->field4D8 = -1;
    kart->mLandingTimer = 0;
    kart->field4DA = 0;
    kart->mHeadingAngleOffset = 0;
    kart->mHeadingAngleOffsetPerFrame = 0;
    kart->mHeadingAngleOffsetDirection = 1;
    kart->mHeadingAngleOffsetCount = 0;
    kart->field4EC = 0;
    kart->field4E8 = 0x1000;
    kart->field4F0 = driverCore_sOneVec;
    kart->field4F0.z = 0;
    kart->field4FC = 0;
    kart->mWaterDepth = 0;
    kart->field506 = 0;
    kart->field504 = kart->field506;
    kart->mWobbleEasedAmplitude = 0;
    kart->mWobbleAmplitude = kart->mWobbleEasedAmplitude;
    kart->mWobbleAngle = 0;
    kart->mRank = 0;
    driver_2068A64(kart, 0, 0);
    kart->field4CC = 0;
}

void driver_initField514(Kart *kart, void *heap) {
    ParticipantKartRecordState *q;
    Vec3 zeroVector;
    u16 i;
    u8 *entries;

    q = kart->field514;
    if (q == NULL) {
        return;
    }
    q->field0 = kart->mPos;
    q->field10 = q->field0;
    q->fieldE = kart->mHeadingAngle;
    q->fieldC = q->fieldE;
    q->field1C = 0;
    q->field20 = 0;
    q->field24 = 0;
    q->field28 = 0;
    q->mAppliedFlags = 0;
    q->field2C = q->mAppliedFlags;
    zeroVector = driverCore_sZeroVec;
    q->field34 = zeroVector;
    q->field44 = 0;
    q->field48 = 0;
    q->mTargetTurnAngle = 0;
    q->mEasedTurnAngle = 0;
    q->field60 = 0;
    q->field64 = 0;
    q->mPushDirection = zeroVector;
    q->fieldA8 = zeroVector;
    q->fieldB4 = 0;
    NNS_FndInitList(&q->mPendingRecords, 0);
    NNS_FndInitList(&q->mFreeRecords, 0);
    entries = heap_alloc(heap, 0x438);
    for (i = 0; i < 0x1e; i++) {
        NNS_FndAppendListObject(&q->mFreeRecords, entries + i * 0x24);
    }
}

void StructMQRacerEntry_SomeFn_48(Kart *kart) {
    ParticipantKartRecordState *q;

    if (!(kart->field7C & 0x400)) {
        return;
    }
    q = kart->field514;
    q->field0 = kart->mPos;
    q->field10 = q->field0;
    q->field4C = *(Vec4 *) &kart->field108.z;
    q->fieldA8 = driverCore_sZeroVec;
    q->fieldB4 = 0;
}

void driver_initField7C(Kart *kart) {
    kart->field7C = 0;
    if (kart->mIndex == gRaceMultiConfig->mEntryIndex) {
        kart->field7C |= KART_7C_INDEX_IS_SELECTED_ENTRY;
        if (gRaceMultiConfig->mMode == 5) {
            kart->field7C |= 0x200;
            if (rstat_getUncontrollable() != 0) {
                kart->field7C &= ~0x200;
                kart->field7C |= 0x400;
            }
        }
    } else if (gRaceMultiConfig->mMode == 5) {
        kart->field7C |= 0x400;
    }
    if (gRaceMultiConfig->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
        kart->field7C |= KART_7C_ENTRY_KIND_2;
        kart->mVisible = 0;
    }
    if (kart->mKartModelsEntry->mCharacterAnimation != NULL) {
        kart->field7C |= KART_7C_MODELS_ENTRY_008_SET;
    }
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK || race_isAwardStaffRoll() != 0) {
        kart->field7C |= 0x8000000;
    }
}

void driver_initTimers(KartItemEffectState *itemEffectState) {
    itemEffectState->field0 = 0;
    itemEffectState->field2 = 0;
    itemEffectState->field4 = 0;
    itemEffectState->field6 = 0;
    itemEffectState->field8 = 0;
    itemEffectState->fieldA = 0;
    itemEffectState->fieldC = 0;
    itemEffectState->fieldE = 0;
    itemEffectState->field12 = 0;
    itemEffectState->field14 = 0;
    itemEffectState->field16 = 0;
    itemEffectState->field18 = 0;
    itemEffectState->field1C = 0;
    itemEffectState->mKillerFrames = 0;
    itemEffectState->field20 = 0;
    itemEffectState->mKillerEnding = FALSE;
    itemEffectState->mKillerEndRank = 0;
}

void driver_initSound(Kart *kart) {
    InitSoundSource(&kart->mSoundSource, 0, kart->mPosSource);
    InitKartSoundCallbacks(kart, (Unk0210a5a8 *) &kart->field450);
    driver_initField450(kart);
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
    kart->field3D0 = kart->mKartModelsEntry->mKartIndex % 3;
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(kart->mSoundSource.mSourceFlags & 1)) {
            SetSoundSourceFlagBit(&kart->mSoundSource, 2, 1);
        }
        if (gRaceMultiConfig->mRaceKind == 2) {
            sfx_210B850(&kart->field518);
        }
    } else {
        if (kart->mSoundSource.mSourceFlags & 1) {
            SetSoundSourceFlagBit(&kart->mSoundSource, 2, 1);
        }
        sfx_210B850(&kart->field518);
    }
}

void driver_initField450(Kart *kart) {
    KartSound *kartSound;
    Unk02024eec_40 t;
    s32 i;
    s32 k;
    s32 rowOffset;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;

    kart->field450.field0 = 0xa5;
    kartSound = (KartSound *) &kart->field450;
    kartSound->field4 = 0x64;
    kartSound->field8 = -1;
    kartSound->fieldC = 0;
    kartSound->field10 = 0;
    kartSound->field14 = 0;
    kartSound->field18 = FX_Div(0x300000, 0xd000 - kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->field1C = FX_Div(0x580000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->field20 = FX_Div(0x480000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->field24 = FX_Div(0x280000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->field28 = 0;
    kartSound->field2C = 0;
    kartSound->field30 = 0;
    kartSound->field34 = -1;
    kartSound->field38 = -1;
    switch (kart->mKartModelsEntry->mKartIndex / 3) {
        case 0:
            k = 4;
            break;
        case 1:
            k = 0;
            break;
        case 2:
            k = 1;
            break;
        case 3:
            k = 2;
            break;
        case 4:
            k = 5;
            break;
        case 5:
            k = 6;
            break;
        case 6:
            k = 7;
            break;
        case 7:
            k = 3;
            break;
        case 8:
            k = 10;
            break;
        case 9:
            k = 8;
            break;
        case 10:
            k = 9;
            break;
        case 11:
            k = 11;
            break;
        case 12:
            k = 12;
            break;
    }
    kartSound->field68 = k;
    i = sub_202578C(kart->mKartModelsEntry->mKartIndex);
    rowOffset = i * 0x1c;
    a = *(s32 *) (data_02161ae8 + rowOffset);
    b = *(s32 *) (data_02161aec + rowOffset);
    c = *(s32 *) (data_02161af0 + rowOffset);
    d = *(s32 *) (data_02161af4 + rowOffset);
    e = *(s32 *) (data_02161af8 + rowOffset);
    f = *(s32 *) (data_02161afc + rowOffset);
    g = *(s32 *) (data_02161b00 + rowOffset);
    t.field0 = i;
    t.field4 = a;
    t.field8 = b;
    t.fieldC = c;
    t.field10 = d;
    t.field14 = e;
    t.field18 = f;
    t.field1C = g;
    if (kart->mIndex != gRaceMultiConfig->mEntryIndex) {
        b = c;
    }
    if (kart->mIndex != gRaceMultiConfig->mEntryIndex) {
        a = c;
    }
    t.field20 = b;
    t.field24 = a;
    kartSound->mUnk_40_m = t;
}

PlayingSound *driver_emitSfx2(SoundSource *soundSource, u32 soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 value12;
    value12 = (u32) &sfx_21090C4;
    volume = 0x7fu;
    pitch = 0u;
    return sfx_21090C4(sourceCopy, soundIdCopy, volume, pitch);
}

void driver_emitSfx(u32 soundSource, u32 soundId) {
    u32 sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 value12;
    volume = 0x7fu;
    pitch = 0u;
    StartSoundWhileRequested((SoundSource *) sourceCopy, soundIdCopy, volume, pitch);
}

void driver_emitFloorSfx(void *kart, int entryIndex) {
    sfx_emitFloorSfx(kart, entryIndex, ((Kart *) kart)->mSurfaceKind,
                                        ((Kart *) kart)->mSurfaceVariant, ((Kart *) kart)->mWaterDepth);
}

void driver_emitFloorSfx2(Kart *kart, s32 entryIndex) {
    sfx_emitFloorSfx2(&kart->mSoundSource, entryIndex, kart->mSurfaceKind, kart->mSurfaceVariant, kart->mWaterDepth);
}

void driver_emitSfx3(void *soundSource, int soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 v6;
    volume = 0x7fu;
    pitch = 0u;
    sfx_21090C4(sourceCopy, soundIdCopy, volume, pitch);
}

void func_02071914(void *kart, int soundId) {
    if (StartSoundWhileRequested(kart, soundId, 0x7f, 0) != NULL) {
        ((Kart *) kart)->field488 = soundId;
    }
}

void func_020718c8(void *kart, int soundId) {
    int sortKeyBase;

    sortKeyBase = GetKartCameraDistanceSquared(((Kart *) kart)->mIndex);
    AddSoundRequest(&data_0217d284, sortKeyBase + sub_210A588(), func_02071914, kart, soundId);
}

void driver_tryEmitItemUseVoice(Kart *kart) {
    if (kart->field48 & 0x840) {
        return;
    }
    sfx_emitDriverVoice(kart, kart->mSoundIndex, 7);
}

void AdvanceKartModelScaleAnimation(Kart *kart) {
    kart->mModelScaleFrameIndex++;
    if (kart->mModelScaleFrameIndex >= kart->mModelScaleFrameCount) {
        kart->mModelScaleFrameIndex = 0;
        kart->field4C &= ~8;
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

void sub_2071568(Kart *kart) {
    s32 fraction;
    u16 tableIndex;
    u16 nextTableIndex;
    s32 v;
    s32 s;
    s32 t;

    kart->field4EC = kart->field4EC + kart->field4E8;
    t = kart->field4EC - 0x8000;
    if (t >= 0) {
        kart->field4EC = t;
    }
    fraction = kart->field4EC & 0xfff;
    tableIndex = kart->field4EC >> 12;
    nextTableIndex = tableIndex + 1;
    if (nextTableIndex >= 8) {
        nextTableIndex = 0;
    }
    kart->field4F0.x =
        data_02154b64[tableIndex] +
        (s32) (((s64) ((data_02154b64[nextTableIndex] - data_02154b64[tableIndex]) >> 1) * fraction) >> 12);
    kart->field4F0.y =
        data_02154b84[tableIndex] +
        (s32) (((s64) ((data_02154b84[nextTableIndex] - data_02154b84[tableIndex]) >> 1) * fraction) >> 12);
    kart->field4F0.z =
        data_02154ba4[tableIndex] +
        (s32) (((s64) ((data_02154ba4[nextTableIndex] - data_02154ba4[tableIndex]) >> 1) * fraction) >> 12);
    v = kart->field4D4;
    s = ((s64) v * 0x333) >> 12;
    if (v > 0xf33) {
        t = ((s64) ((v - 0xf33) * 0x32) * 0x19a) >> 12;
        if (t > 0x19a) {
            t = 0x19a;
        }
        t = t + 0x333;
        s = ((s64) v * t) >> 12;
    } else if (v > 0xd9a) {
        t = ((s64) ((v - 0xd9a) * 0x32) * 0x52) >> 12;
        if (t > 0x52) {
            t = 0x52;
        }
        t = t + 0x333;
        s = ((s64) v * t) >> 12;
    }
    kart->field4F0.x = kart->field4F0.x + (s32) (((s64) kart->field4F0.x * s) >> 12);
    kart->field4F0.y = kart->field4F0.y + (s32) (((s64) kart->field4F0.y * s) >> 12);
    kart->field4F0.z = kart->field4F0.z + (s32) (((s64) kart->field4F0.z * s) >> 12);
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
        kart->field4D4 = 0x1000;
    } else {
        kart->mHeadingAngleOffsetPerFrame =
            kart->mHeadingAngleOffsetDirection * 0x3c + kart->mHeadingAngleOffsetPerFrame;
        if (kart->mHeadingAngleOffsetPerFrame > 0xd2) {
            kart->mHeadingAngleOffsetPerFrame = 0xd2;
        } else if (kart->mHeadingAngleOffsetPerFrame < -0xd2) {
            kart->mHeadingAngleOffsetPerFrame = -0xd2;
        }
        kart->mHeadingAngleOffset = kart->mHeadingAngleOffset + kart->mHeadingAngleOffsetPerFrame;
        kart->field4D4 = ((s64) kart->field4D4 * 0xf5c) >> 12;
        offset = kart->mHeadingAngleOffset;
        if ((offset > 0 && kart->mHeadingAngleOffsetDirection > 0) ||
            (offset < 0 && kart->mHeadingAngleOffsetDirection < 0)) {
            kart->mHeadingAngleOffset = 0;
            kart->field4C &= ~KART_4C_HEADING_SWING;
            driver_2068A64(kart, 0, 1);
            kart->field44 |= 0x1000000;
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
    } else if (kart->field44 & 2) {
        kart->mModelScaleKind = 1;
    } else if (kart->mAirborneFrames > 0xa) {
        kart->mModelScaleKind = 1;
    } else {
        kart->mModelScaleKind = 0;
    }
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = 0xf;
    kart->field4C |= 8;
}

void driver_cannonLaunch(Kart *kart, s32 b) {
    NNSSndSeqPlayer **sndHandleSlot;
    PlayingSound *playingSound;

    if (b == 0) {
        kart->field48 |= 0x40000;
        kart->field44 &= ~KART_44_ON_GROUND;
    }
    kart->field48 &= 0xdfe77fdf;
    kart->mBoostTimer = 0;
    kart->field538.field0 = 0;
    kart->mMiniTurboTimer = 0;
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(kart->field4C & 0x10000000) && !(kart->field48 & 0x4000000)) {
            cam_resetPlayerCameraTargetFov();
        }
        dce_stopBlur();
    }
    if (kart->field4C & 0x2000) {
        kart->field4C &= ~0x2000;
        kart->fieldD8 = 0x1000;
        if (!(kart->field4C & 0x8000000)) {
            driver_disableSlipStreamToonMode(kart);
        }
        rptc_stopSlipstreamEffect(kart);
    }
    rptc_stopSlipstreamBeginEffectDirect(kart);
    kart->field44 &= 0xfffff7f4;
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    dptc_208C534(dptc_getControllerForDriver(kart->mIndex));
    kart->mState = KART_STATE_NORMAL;
    kart->field4C &= ~0x30;
    kart->field48 &= ~0x20000;
    driver_2068A64(kart, 0, 1);
    kart->field44 |= 0x80000000;
    StructMQRacerEntry_SomeFn_11(kart);
    driver_emitCannonBlastEffect(kart);
    if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    cam_tryCannonShakePlayerCamera();
    switch (gRaceMultiConfig->mCourseId) {
        case COURSE_ID_AIRSHIP:
            rwrd_2089D14(0);
            playingSound = sfx_21090C4((SoundSource *) kart, 0x15c, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= 0x10;
            }
            sndHandleSlot = GetSndHandleSlot(7);
            if (!(data_0217c780 & 1)) {
                return;
            }
            if (SoundHandle_217D084.fieldC == 0) {
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
            playingSound = sfx_21090C4((SoundSource *) kart, 0x15b, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= 0x10;
            }
            break;
    }
}

void driver_emitCannonBlastEffect(Kart *kart) {
    s32 effectIdsOther[2];
    Vec3 effectPos;
    Vec3 effectIdsSelected;
    Camera *currentCamera;
    Vec3 *cameraPos;
    BOOL cameraOutsideBox;
    s32 effectCount;
    s32 i;
    s32 *nextEffectId;
    s32 *w;

    effectPos = data_0216553c;
    cameraOutsideBox = TRUE;
    currentCamera = race_getCamera();
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
        w = effectIdsOther;
        effectIdsOther[0] = data_02165510[0];
        effectIdsOther[1] = data_02165510[1];
        effectCount = 3;
        nextEffectId = (s32 *) &effectIdsSelected;
        if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            effectCount = 2;
            nextEffectId = w;
        }
        for (i = 0; i < effectCount; i++) {
            ptcm_createEmitter(*nextEffectId, &effectPos);
            nextEffectId++;
        }
    } else {
        ptcm_createEmitter((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 0x47 : 0x52, &effectPos);
    }
}

static inline s32 func_020708a4_inline(Vec3 *src, Vec3 *dst) {
    if ((s64) src->x * src->x + (s64) src->y * src->y + (s64) src->z * src->z < 0x10) {
        return 0;
    }
    return vec_normalize(src, dst);
}

void driver_handleCannon(Kart *kart) {
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
    Vec3 l;
    MtxFx43 m2;
    s32 rotationMatrix[9];
    Vec3 axis;

    placementAngles = driverCore_sZeroVec;
    placementIndex = *gMapData->mKeyedPlacementIndexByKey;
    placementPos.x = gMapData->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = gMapData->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = gMapData->mKeyedPlacements[placementIndex].mPos.z;
    placementAngles.x = gMapData->mKeyedPlacements[*gMapData->mKeyedPlacementIndexByKey].fieldC.x;
    placementAngles.y = gMapData->mKeyedPlacements[*gMapData->mKeyedPlacementIndexByKey].fieldC.y;
    placementAngles.z = gMapData->mKeyedPlacements[*gMapData->mKeyedPlacementIndexByKey].fieldC.z;
    angleIndex = (u16) (((s64) placementAngles.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >> 4;
    MTX_RotY33_(rotationMatrix, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
    MTX_MultVec33(&driverCore_sForwardVec, rotationMatrix, &placementForward);
    cspl_speedClearSplashes(kart->mIndex);

    flags = kart->field4C;
    if (!(flags & 0x20000) && (flags & 0x8000000)) {
        itemEffectState = &kart->field538;
        if (itemEffectState->field1C <= 0x190) {
            itemEffectState->field1C = 0x190;
            kart->field4C |= 0x20000;
            chkrt_setTargetColors(kart->mKartModelsEntry, chkrt_getKartCrsMatDiffuse(), chkrt_getKartCrsMatEmission(),
                                     chkrt_getKartCrsMatAmbient());
        }
    }
    if (kart->field4C & 0x8000000) {
        driver_updateGessoInk(kart);
    }
    flags = kart->field4C;
    if (flags & 0x10000000) {
        driver_updateKillerMode(kart);
    } else {
        if (flags & KART_4C_THUNDER_SHRINK) {
            driver_updateThunderShrinkEffect(kart);
        }
        if (kart->field4C & 0x10000) {
            driver_updateDossunFlatEffect(kart);
        }
        if (kart->field7C & 0x402000) {
            driver_updateTeresaEffect(kart);
        }
    }

    if (kart->field4C & 0x2000) {
        itemEffectState = &kart->field538;
        if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            AddSoundRequest(data_0217d26c, GetKartCameraDistanceSquared(kart->mIndex), func_020718c8, kart, 0xa3);
        }
        itemEffectState->fieldA++;
        if (itemEffectState->fieldA > KART_KILLER_RANK_END_FRAMES && (kart->field4C & 0x2000)) {
            kart->field4C &= ~0x2000;
            kart->fieldD8 = 0x1000;
            if (!(kart->field4C & 0x8000000)) {
                driver_disableSlipStreamToonMode(kart);
            }
            rptc_stopSlipstreamEffect(kart);
        }
    }

    if (kart->field4C & 0x40) {
        itemEffectState = &kart->field538;
        rptc_updateRainbowEffect(kart->mIndex);
        if ((kart->field7C & KART_7C_MODELS_ENTRY_008_SET) &&
            kart->mKartModelsEntry->mCharacterAnimation->field1A == 0) {
            driver_2068A64(kart, 2, 1);
        }
        itemEffectState->field6++;
        if (itemEffectState->field6 > KART_TERESA_MAX_FRAMES) {
            kart->field4C &= ~0x40;
            driver_disableStarToonMode(kart);
            kart->mItemEffect = 0;
            rptc_stopRainbowEffect(kart->mIndex);
            driver_2068A64(kart, 0, 1);
            if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
                snd_stopStarMusic();
            }
            if (kart->field4C & 0x2000) {
                driver_enableSlipStreamToonMode(kart);
            }
        }
    }

    data_0217566a[kart->mEntryIndex].mBitMask = 0xe04;
    vec_crossProduct(&driverCore_sUpVec, &placementForward, &side);
    VEC_Subtract(&kart->mPos, &placementPos, &toKart);
    toKart.y = 0;
    VEC_MultAdd(vec_dotProduct(&side, &toKart), &side, &placementPos, &placementPos);
    vec_dotProduct(&side, &toKart);
    VEC_Subtract(&placementPos, &kart->mPos, &toTarget);
    distance = func_020708a4_inline(&toTarget, &toTarget);

    if (vec_dotProduct(&toTarget, &placementForward) <= 0) {
        dce_stopBlur();
        kart->field48 &= ~0x10000;
        AdvanceKartQuaternionBlendFactor(kart, &kart->mGroundNormal);
        kart->field48 &= ~0x40000;
        kart->field3E8 = (s16) ((s32) (((s64) placementAngles.x * 0x4000) >> 12) >> 12) + 0x32;
        if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mCourseId == COURSE_ID_AIRSHIP) {
            NNS_SndPlayerStopSeq(GetSndHandleSlot(7), 0x14);
        }
    } else {
        if (distance > 0x64000) {
            kart->mTurnedForward = toTarget;
        }
        flatForward = kart->mTurnedForward;
        flatForward.y = 0;
        kart->mQuaternionBlendFactor = 0x1000;
        func_020708a4_inline(&flatForward, &flatForward);
        kart->mHeadingAngle = (s32) (((s64) FX_Atan2(flatForward.x, flatForward.z) * 0x28be60d) >> 12) >> 12;
        axis = data_02165524;
        qrtn_fromAxisAngle(&axis, kart->mHeadingAngle, (Vec4 *) &kart->fieldE0);
        vec_crossProduct(&driverCore_sUpVec, &kart->mTurnedForward, &l);
        vec_crossProduct(&kart->mTurnedForward, &l, &groundNormal);
        if (kart->mAirTiltAngle > -5000) {
            kart->mAirTiltAngle -= 300;
            if (kart->mAirTiltAngle < -5000) {
                kart->mAirTiltAngle = -5000;
            }
        }
        MTX_RotAxis33(&m2, &kart->field120, FX_SinCosTable_[((u16) kart->mAirTiltAngle >> 4) * 2],
                      FX_SinCosTable_[((u16) kart->mAirTiltAngle >> 4) * 2 + 1]);
        MTX_MultVec33(&groundNormal, &m2.field0[0].x, &groundNormal);
        kart->mGroundNormal = groundNormal;
        AdvanceKartOrientation(kart, &groundNormal);
    }

    kart->mForwardSpeed = 0x1e000;
    t = kart->mForwardSpeed;
    m2.field0[3].x = ((s64) kart->mTurnedForward.x * t) >> 12;
    m2.field0[3].y = ((s64) kart->mTurnedForward.y * t) >> 12;
    m2.field0[3].z = ((s64) kart->mTurnedForward.z * t) >> 12;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    if (distance < 0x3e8000) {
        t = (s32) (((s64) distance * 0x29) >> 12) + 0x14000;
        if (kart->mForwardSpeed > t) {
            kart->mForwardSpeed = t;
        }
    }
    kart->mVelocity = m2.field0[3];
    VEC_Add(&kart->mPos, &kart->mVelocity, &kart->mPos);
}

void driver_pipeTeleport(Kart *kart, u32 key) {
    Vec3 placementPos;
    Vec3 placementForward;
    s32 rotationMatrix[9];
    Vec3 offset;
    Vec3 axis;
    NNSSndSeqPlayer **sndHandle;
    u16 placementIndex;
    s32 angleIndex;

    driver_cannonLaunch(kart, 1);
    kart->mVerticalSpeed = 0x3000;
    placementIndex = gMapData->mKeyedPlacementIndexByKey[key];
    placementPos.x = gMapData->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = gMapData->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = gMapData->mKeyedPlacements[placementIndex].mPos.z;
    angleIndex = (u16) (((s64) gMapData->mKeyedPlacements[gMapData->mKeyedPlacementIndexByKey[key]].fieldC.y *
                             0xb60b60b60bLL +
                         0x80000000LL) >>
                        44) >>
                 4;
    MTX_RotY33_(rotationMatrix, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
    MTX_MultVec33(&driverCore_sForwardVec, rotationMatrix, &placementForward);
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        VEC_Subtract(&placementPos, &kart->mPos, &offset);
        mgcnt_applyForceToDriverBalloons(kart->mIndex, (s32) &offset);
    }
    kart->mPos = placementPos;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mForwardSpeed = 0x5000;
    kart->mTurnedForward = placementForward;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mHeadingAngle = (s32) (((s64) FX_Atan2(placementForward.x, placementForward.z) * 0x28be60dLL) >> 12) >> 12;
    axis = data_02165524;
    qrtn_fromAxisAngle(&axis, kart->mHeadingAngle, (Vec4 *) &kart->fieldE0);
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        cam_resetPlayerCamera();
        if (data_0217c780 & 1) {
            sndHandle = sp_acquireElement(sound_getPoolById(0));
            if (SoundHandle_217D084.fieldC != 0) {
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
    if (!(kart->field7C & 2)) {
        return;
    }
    if (gRaceMultiConfig->mMode != MODE_BATTLE) {
        return;
    }
    ResetBattleKartAiAtPointLink(kart->mAi, mdat_getNextMgEnemyPointForWarpPipe(key));
}

void StructMQRacerEntry_SomeFn_88(Kart *kart, Vec4 *quaternion) {
    MtxFx43 m1;
    MtxFx43 m2;
    Vec3 v1;
    Vec3 v2;
    s32 dot;
    u16 headingAngle;
    u16 airTiltAngle;

    if (kart->mVelocityLength < 0x1000) {
        return;
    }
    if (vec_dotProduct(&kart->field12C, &driverCore_sUpVec) <= 0) {
        return;
    }
    kart->mAirTiltAngle = kart->mAirTiltAngle + kart->field3E8;
    headingAngle = kart->mHeadingAngle;
    airTiltAngle = kart->mAirTiltAngle;
    MTX_RotY43_(&m1, FX_SinCosTable_[(headingAngle >> 4) * 2], FX_SinCosTable_[(headingAngle >> 4) * 2 + 1]);
    MTX_MultVec43(&driverCore_sRightVec, &m1, &v1);
    MTX_RotAxis43(&m2, &v1, FX_SinCosTable_[(airTiltAngle >> 4) * 2], FX_SinCosTable_[(airTiltAngle >> 4) * 2 + 1]);
    MTX_MultVec43(&driverCore_sUpVec, &m2, &v2);
    qrtn_lookAt(quaternion, &driverCore_sUpVec, &v2);
    if (kart->field48 & 0x80000000) {
        quaternion->x = -quaternion->x;
        quaternion->y = -quaternion->y;
        quaternion->z = -quaternion->z;
        quaternion->w = -quaternion->w;
    }
    if (kart->field44 & 2) {
        return;
    }
    dot = vec_dotProduct(&kart->mVelocityDirection, &kart->field138);
    if (dot <= 0) {
        dot = -dot;
    }
    kart->field3F8 = dot;
    if (kart->field3F8 < 0xb33) {
        kart->field3F8 = 0xb33;
    }
}

BOOL TryHoldKartStill(Kart *kart, u32 b, void *c) {
    u32 flags;

    flags = kart->field44;
    if (!(flags & 0xc2200) && !(kart->field7C & 0x400)) {
        if (!(flags & 0xc0000) && !(kart->field4C & 0x100) && kart->field1FC.x == 0 && kart->field1FC.y == 0 &&
            kart->field1FC.z == 0 && kart->field274 == 0 && kart->field4D0 >= 0x64) {
            kart->mPos.x = kart->mPrevPos.x;
            kart->mPos.z = kart->mPrevPos.z;
        } else {
            sub_20D5AA0(c, b, (Unk020e04b0 *) kart->field208, &kart->mPos, NULL);
        }
        kart->mVelocity = driverCore_sZeroVec;
        kart->mVelocityLength = 0;
        kart->field44 |= 0x1000;
        return TRUE;
    }
    return FALSE;
}
