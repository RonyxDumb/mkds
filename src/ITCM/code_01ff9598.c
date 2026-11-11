#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02061654.h"
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
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02171000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_0206f04c.h"

#pragma opt_arithtransformation off

BOOL IsLowestOffsetFarOnHitBit(Kart *kart, u32 collisionBits, Vec3 *lowestOffset) {
    BOOL farEnough = FALSE;

    if (collisionBits & 0x2000000) {
        if (HORIZONTAL_LENGTH_SQUARED(*lowestOffset) > 0x1000000) {
            farEnough = TRUE;
        }
    }
    return farEnough != FALSE;
}

BOOL IsLowestOffsetFarOnHitBitOrKartBit(Kart *kart, u32 collisionBits, Vec3 *lowestOffset) {
    BOOL result = TRUE;
    BOOL farEnough = FALSE;

    if (collisionBits & 0x2000000) {
        if (HORIZONTAL_LENGTH_SQUARED(*lowestOffset) > 0x1000000) {
            farEnough = TRUE;
        }
    }
    if (farEnough == FALSE) {
        if (!(kart->mUnk_44 & 0x4000000)) {
            result = FALSE;
        }
    }
    return result != FALSE;
}

BOOL IsLowestOffsetFarOnHitBitOrYAbove(Kart *kart, u32 collisionBits, Vec3 *lowestOffset) {
    BOOL result = TRUE;
    BOOL farEnough = FALSE;

    if (collisionBits & 0x2000000) {
        if (HORIZONTAL_LENGTH_SQUARED(*lowestOffset) > 0x1000000) {
            farEnough = TRUE;
        }
    }
    if (farEnough == FALSE) {
        if (lowestOffset->y <= MUL_FIXED12_ROUNDED(kart->mRadius, -0xb33)) {
            result = FALSE;
        }
    }
    return result != FALSE;
}

void ClearKartGroundContact(Kart *kart, u32 clearedBits) {
    kart->mUnk_44 = kart->mUnk_44 & ~clearedBits;
    kart->mCollisionHitLink->mObject = NULL;
    kart->mSurfaceGroup = -1;
    StopKartCurrentEffects(kart);
}

// Returns TRUE while the kart is below y = 0 and starts the respawn wait once; at y >= 0 it clears kart flag bits and
// returns FALSE.
BOOL StartKartRespawnWaitIfBelowZero(Kart *kart) {
    void *soundHandleEntry;
    u32 kartIndex;
    u32 respawnSlot;

    if (kart->mPos.y < 0) {
        if (!(kart->mUnk_7c & 0x400) && !(kart->mUnk_48 & KART_48_RESPAWN_WAIT)) {
            kart->mUnk_48 = kart->mUnk_48 | KART_48_RESPAWN_WAIT;
            kartIndex = kart->mIndex;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                respawnSlot = GetCourseMapRespawnSlot(0);
            } else {
                respawnSlot = GetCourseMapRespawnSlot(gRaceProgress->mKarts[kartIndex].mCheckpoint);
            }
            kart->mRespawnSlot = respawnSlot;
            if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW && (data_0217c780 & 1)) {
                    soundHandleEntry = TakeSoundHandleEntry(GetSoundHandlePool(0));
                    if (data_0217d084.mSeqStartEnabled != 0) {
                        if (*(u32 *) soundHandleEntry != 0) {
                            NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                        }
                        if (*(u32 *) soundHandleEntry != 0) {
                            NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(soundHandleEntry, 0, 0x1b7);
                    }
                }
            }
        }
        return TRUE;
    }
    kart->mUnk_44 = kart->mUnk_44 & 0xbbceffff;
    kart->mUnk_48 = kart->mUnk_48 & 0xff9ffbfe;
    return FALSE;
}

void AdvanceKartQuaternionBlendFactor(Kart *kart, const Vec3 *a) {
    s32 d = Vec3DotUnrounded(&kart->mGroundNormal, a);
    s32 m;

    if (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE) {
        m = 0x4cd;
    } else {
        m = 0x1ec;
    }
    if (d < 0) {
        d = 0;
    }
    if (d >= 0xe66) {
        if (kart->mUnk_44 & 0x1000) {
            if (kart->mCollisionHitLink->mObject == NULL && kart->mPointMotion.x == 0 && kart->mPointMotion.y == 0 &&
                kart->mPointMotion.z == 0 && kart->mCollisionStepFrames > 100) {
                kart->mQuaternionBlendFactor = 0;
                return;
            }
        }
        if (kart->mQuaternionBlendFactor >= m) {
            return;
        }
        kart->mQuaternionBlendFactor = kart->mQuaternionBlendFactor + 0x14;
        if (kart->mQuaternionBlendFactor > m) {
            kart->mQuaternionBlendFactor = m;
        }
    } else {
        kart->mQuaternionBlendFactor = MUL_FIXED12_NO_ROUND(m, kart->mVelocityLengthRatio);
    }
}

// Counts mAirborneFrames, also clears mUnk_234, sets or clears bit 0x4000 and stores mLastGroundY. Not run while the
// kart is below y = 0.
void UpdateKartAirborne(Kart *p) {
    if (p->mUnk_44 & KART_44_ON_GROUND) {
        p->mAirborneFrames = 0;
        p->mAirTiltAngle = 0;
        p->mUnk_44 = p->mUnk_44 & ~0x4000;
        p->mLastGroundY = p->mPos.y;
        return;
    }
    p->mAirborneFrames = p->mAirborneFrames + 1;
    if (p->mAirborneFrames > 5) {
        p->mUnk_44 = p->mUnk_44 | 0x4000;
    }
}

void AdvanceKartOrientation(Kart *p, Vec3 *a) {
    Vec4 v;
    u32 t;

    p->mVelocityScaleFactor = 0x1000;
    if (p->mAirborneFrames > 5) {
        p->mQuaternionBlendFactor = 0xf6;
        ComputeKartAirTiltQuaternion(p, &p->mUnk_100_q);
    } else {
        AdvanceKartQuaternionFromVector(p, a);
    }
    QuaternionBlend(&p->mUnk_f0_q, &p->mUnk_100_q, &p->mUnk_f0_q, p->mQuaternionBlendFactor);
    QuaternionFromAxisAngle(&data_02154f7c, (u16) (p->mHeadingAngle + p->mHeadingAngleOffset), &p->mUnk_e0_m);
    QuaternionMultiply(&p->mUnk_f0_q, &p->mUnk_e0_m, &p->mUnk_110_q);
    if (p->mUnk_44 & 2) {
        if (p->mHopSpeed > 0) {
            p->mHopTiltAngle = 0x9c4 - (u16) MUL_FIXED12_NO_ROUND(p->mHopHeight, 500);
            if (p->mHopTiltAngle > 0x6a4) {
                p->mHopTiltAngle = 0x352;
            }
        } else {
            p->mHopTiltAngle = 0;
        }
        QuaternionFromAxisAngle(&data_02154f88, (u16) -p->mHopTiltAngle, &v);
        QuaternionMultiply(&p->mUnk_110_q, &v, &p->mUnk_110_q);
    } else {
        p->mHopTiltAngle = 0;
    }
    QuaternionNormalize(&p->mUnk_110_q, &p->mUnk_110_q);
}

// Runs only on a step with a ground hit (non-zero normal).
void RefreshKartSurface(Kart *p) {
    s32 r = PickCollisionHitValue(0x1e34ef);
    s32 k;
    s32 a;
    s32 b;
    s32 c;

    p->mSurfaceKind = (r & 0x1f00) >> 8;
    p->mSurfaceVariant = (u32) ((r & 0xe0) << 11) >> 16;
    a = 0x1000;
    k = gKartSurfaceFunctions[p->mSurfaceKind](p);
    if (k != 0) {
        a = p->mPhysicalParam->mSurfaceSpeedLimitFactors[k];
    }
    b = p->mSpeedLimitFactor;
    if (a >= b) {
        p->mSpeedLimitFactor = a;
    } else {
        p->mSpeedLimitFactor = b + MUL_FIXED12_ROUNDED(a - b, 0x4cd);
    }
    if (p->mUnk_4c & 0x10000040) {
        c = 0;
    } else {
        c = k;
    }
    p->mTurnedForwardEaseFactor = p->mPhysicalParam->mUnk_38[c];
    if (p->mUnk_48 & 0x40000000) {
        if (p->mUnk_44 & KART_44_ON_GROUND) {
            if (k != 0xb) {
                p->mUnk_48 = p->mUnk_48 & ~0x40000000;
            }
        }
    }
    p->mSurfaceGroup = k;
}

void AdvanceKartBoosts(Kart *kart) {
    u32 raceUpdateFrames;
    s32 frameDifference;
    enum { K0 } entryIndex;

    if (kart->mUnk_48 & KART_48_MINI_TURBO) {
        kart->mMiniTurboTimer = kart->mMiniTurboTimer - 1;
        if (kart->mMiniTurboTimer <= 0) {
            kart->mUnk_48 = kart->mUnk_48 & ~KART_48_MINI_TURBO;
            kart->mMiniTurboTimer = 0;
        }
    }
    if (kart->mUnk_48 & 0x100000) {
        kart->mItemEffectData.mKinokoBoostTimer = kart->mItemEffectData.mKinokoBoostTimer - 1;
        if (kart->mItemEffectData.mKinokoBoostTimer <= 0) {
            kart->mUnk_48 = kart->mUnk_48 & ~0x20100000;
            kart->mItemEffectData.mKinokoBoostTimer = 0;
        }
    }
    if (!(kart->mUnk_44 & 0x1000000) && !(kart->mUnk_7c & 0x400)) {
        AdvanceKartRaceStartBoost(kart);
    }
    if (!(kart->mUnk_4c & 0x400)) {
        return;
    }
    raceUpdateFrames = GetRaceUpdateFrames();
    if (kart->mRespawnPressRaceFrame == 0) {
        entryIndex = kart->mEntryIndex;
        if ((u16) (gInputSlots[entryIndex].mPressedBits & PAD_KEY_A) != 0) {
            kart->mRespawnPressRaceFrame = raceUpdateFrames;
        }
    }
    if (kart->mRespawnLandRaceFrame == 0) {
        return;
    }
    if (kart->mRespawnPressRaceFrame == 0) {
        return;
    }
    frameDifference = kart->mRespawnPressRaceFrame - kart->mRespawnLandRaceFrame;
    if (frameDifference <= 0) {
        frameDifference = -frameDifference;
    }
    if (frameDifference <= 2) {
        StartKartBoost(kart, KART_BOOST_RESPAWN, 10);
    }
    kart->mUnk_4c = kart->mUnk_4c & ~0x400;
}

// Ends the hold TryHoldKartStill started: clears the hold bit and, if the hit link holds an object, moves mPos to the
// link position; also requests surface sound entry 0 while the race runs.
void StopKartStillHold(Kart *kart) {
    if (!(kart->mUnk_4c & 2)) {
        if (IsRaceStarted() == 1) {
            AddKartSurfaceSoundRequest(kart, 0);
        }
    }
    kart->mUnk_44 = kart->mUnk_44 & ~0x1000;
    if (kart->mCollisionHitLink->mObject == NULL) {
        return;
    }
    GetCollisionHitLinkPosition(kart->mCollisionHitLink, &kart->mPos);
    kart->mCollisionHitLink->mObject = NULL;
}

void SetKartCourseHitAttributeBit(Kart *kart, u32 hitValue) {
    u32 attributeBit = hitValue & 0x1000000;

    if (attributeBit != kart->mCourseHitAttributeBit) {
        kart->mCourseHitAttributeBit = attributeBit;
    }
}

void AdvanceKartHop(Kart *p) {
    if (!(p->mUnk_44 & 4)) {
        return;
    }
    p->mHopSpeed = p->mHopSpeed + p->mGravity;
    p->mHopHeight = p->mHopHeight + p->mHopSpeed;
    if (p->mHopHeight < 0) {
        p->mHopHeight = 0;
        p->mHopSpeed = 0;
        p->mUnk_44 = p->mUnk_44 & ~0x804;
    }
}

void AdvanceKartEffects(Kart *p) {
    KartTurnEffects *a;
    KartEffects *b;
    u32 f;

    if (p->mUnk_4c & KART_4C_NEAR_PLAYER_RANK) {
        a = GetKartTurnEffects(p->mIndex);
        b = GetKartEffects(p->mIndex);
        AdvanceKartLevel4Effects(a, p);
        AdvanceKartTurnStartEffects(a, p);
        AdvanceKartLevel3Effects(a, b->mSideDirections, b->mSidePositions);
        AdvanceKartLevel2Effects(a, b->mSideDirections, b->mSidePositions);
    } else {
        StopKartTurnEffects(GetKartTurnEffects(p->mIndex));
    }
    p->mEffectVelocity = p->mVelocity;
    f = p->mUnk_44;
    if (f & KART_44_ON_GROUND) {
        if (!(f & 0x1000)) {
            p->mEffectVelocity.y = p->mEffectVelocity.y - p->mVerticalSpeed;
        }
    }
    p->mEffectVelocity.x = p->mEffectVelocity.x >> 4;
    p->mEffectVelocity.y = p->mEffectVelocity.y >> 4;
    p->mEffectVelocity.z = p->mEffectVelocity.z >> 4;
}

void NNSi_G3dSendJointSRTMaya(Unk01ff9940 *jntAnmResult) {
    BOOL translationPending;
    u32 resultFlags = jntAnmResult->mUnk_00;

    translationPending = FALSE;
    if ((resultFlags & 4) == 0) {
        translationPending = TRUE;
    }
    if ((resultFlags & 0x20) && !(resultFlags & 8)) {
        if (translationPending) {
            NNS_G3dGeBufferOP_N(0x1c, &jntAnmResult->mUnk_4c, 3);
            translationPending = FALSE;
        }
        NNS_G3dGeBufferOP_N(0x1b, &jntAnmResult->mUnk_10, 3);
    }
    if (!(jntAnmResult->mUnk_00 & 2)) {
        if (translationPending) {
            NNS_G3dGeBufferOP_N(0x19, &jntAnmResult->mUnk_28, 0xc);
        } else {
            NNS_G3dGeBufferOP_N(0x1a, &jntAnmResult->mUnk_28, 9);
        }
    } else if (translationPending) {
        NNS_G3dGeBufferOP_N(0x1c, &jntAnmResult->mUnk_4c, 3);
    }
    if (!(jntAnmResult->mUnk_00 & 1)) {
        NNS_G3dGeBufferOP_N(0x1b, &jntAnmResult->mUnk_04, 3);
    }
}

void NNSi_G3dGetJointScaleMaya(Unk01ff9940 *jntAnmResult, Unk01ff9940_B *scaleValues, Unk01ff9940_C *command,
                               u32 srtFlags) {
    u8 optionFlags = command->mUnk_03;
    u32 nodeIndex;

    if (srtFlags & 4) {
        jntAnmResult->mUnk_00 |= 1;
        if (optionFlags & 2) {
            nodeIndex = command->mUnk_01;
            NNS_G3dRS->mIsScaleCacheOne[nodeIndex >> 5] |= 1 << (nodeIndex & 0x1f);
        }
    } else {
        jntAnmResult->mUnk_04.x = scaleValues->mUnk_00.x;
        jntAnmResult->mUnk_04.y = scaleValues->mUnk_00.y;
        jntAnmResult->mUnk_04.z = scaleValues->mUnk_00.z;
        if (optionFlags & 2) {
            nodeIndex = command->mUnk_01;
            NNS_G3dRS->mIsScaleCacheOne[nodeIndex >> 5] &= ~(1 << (nodeIndex & 0x1f));
            data_usa_021712f0[nodeIndex].mUnk_00.x = scaleValues->mUnk_0c.x;
            data_usa_021712f0[nodeIndex].mUnk_00.y = scaleValues->mUnk_0c.y;
            data_usa_021712f0[nodeIndex].mUnk_00.z = scaleValues->mUnk_0c.z;
        }
    }
    if (optionFlags & 1) {
        nodeIndex = command->mUnk_02;
        jntAnmResult->mUnk_00 |= 0x20;
        if (NNS_G3dRS->mIsScaleCacheOne[nodeIndex >> 5] & (1 << (nodeIndex & 0x1f))) {
            jntAnmResult->mUnk_00 |= 8;
        } else {
            jntAnmResult->mUnk_10 = data_usa_021712f0[nodeIndex].mUnk_00;
        }
    }
    jntAnmResult->mUnk_00 |= 0x10;
}

void texmtxCalc_flag_(Unk01ff9598_A *matrix, Unk01ff9598 *matAnmResult) {
    s32 widthFixed = matAnmResult->mUnk_2c << 12;
    s32 heightFixed = matAnmResult->mUnk_2e << 12;
    s32 cosR;
    s32 scaleS;
    s32 sinR;
    s32 scaleT;
    s32 scaleSCos;
    s32 scaleSSin;
    s32 scaleTSin;
    s32 scaleTCos;

    FX_DivAsync(heightFixed, widthFixed);
    cosR = matAnmResult->mUnk_22;
    scaleS = matAnmResult->mUnk_18;
    sinR = matAnmResult->mUnk_20;
    scaleT = matAnmResult->mUnk_1c;
    scaleSSin = MUL_FIXED12_NO_ROUND(scaleS, sinR);
    scaleSCos = MUL_FIXED12_NO_ROUND(scaleS, cosR);
    scaleTSin = MUL_FIXED12_NO_ROUND(scaleT, sinR);
    scaleTCos = MUL_FIXED12_NO_ROUND(scaleT, cosR);
    matrix->mUnk_00 = scaleSCos;
    matrix->mUnk_14 = scaleTCos;
    matrix->mUnk_04 = -scaleTSin * FX_GetDivResult() >> 12;
    FX_DivAsync(widthFixed, heightFixed);
    matrix->mUnk_30 = (matAnmResult->mUnk_2c * (matAnmResult->mUnk_18 - (scaleSSin + scaleSCos)) << 3) -
                      matAnmResult->mUnk_2c * (s32) ((s64) matAnmResult->mUnk_18 * matAnmResult->mUnk_24 >> 8);
    matrix->mUnk_34 = matAnmResult->mUnk_2e * (s32) ((s64) matAnmResult->mUnk_1c * matAnmResult->mUnk_28 >> 8) +
                      (matAnmResult->mUnk_2e * (scaleTSin - scaleTCos - matAnmResult->mUnk_1c + 0x2000) << 3);
    matrix->mUnk_10 = scaleSSin * FX_GetDivResult() >> 12;
}

void texmtxCalc_flagS_(Unk01ff9598_A *matrix, Unk01ff9598 *matAnmResult) {
    s32 widthFixed = matAnmResult->mUnk_2c << 12;
    s32 heightFixed = matAnmResult->mUnk_2e << 12;
    s32 sinPlusCos;

    FX_DivAsync(heightFixed, widthFixed);
    matrix->mUnk_00 = matAnmResult->mUnk_22;
    matrix->mUnk_14 = matAnmResult->mUnk_22;
    matrix->mUnk_04 = -matAnmResult->mUnk_20 * FX_GetDivResult() >> 12;
    FX_DivAsync(widthFixed, heightFixed);
    sinPlusCos = matAnmResult->mUnk_20 + matAnmResult->mUnk_22;
    matrix->mUnk_30 =
        (matAnmResult->mUnk_2c * (-sinPlusCos + 0x1000) << 3) - (matAnmResult->mUnk_24 * matAnmResult->mUnk_2c << 4);
    matrix->mUnk_34 = (matAnmResult->mUnk_2e * (matAnmResult->mUnk_20 - matAnmResult->mUnk_22 + 0x1000) << 3) +
                      (matAnmResult->mUnk_28 * matAnmResult->mUnk_2e << 4);
    matrix->mUnk_10 = matAnmResult->mUnk_20 * FX_GetDivResult() >> 12;
}

void texmtxCalc_flagR_(Unk01ff9598_A *matrix, Unk01ff9598 *matAnmResult) {
    matrix->mUnk_00 = matAnmResult->mUnk_18;
    matrix->mUnk_14 = matAnmResult->mUnk_1c;
    matrix->mUnk_04 = 0;
    matrix->mUnk_30 = matAnmResult->mUnk_2c * -(s32) ((s64) matAnmResult->mUnk_18 * matAnmResult->mUnk_24 >> 8);
    matrix->mUnk_34 = matAnmResult->mUnk_2e * (s32) ((s64) matAnmResult->mUnk_1c * matAnmResult->mUnk_28 >> 8) +
                      (matAnmResult->mUnk_2e * (matAnmResult->mUnk_1c * -2 + 0x2000) << 3);
    matrix->mUnk_10 = 0;
}

void texmtxCalc_flagRS_(Unk01ff9598_A *matrix, Unk01ff9598 *matAnmResult) {
    matrix->mUnk_00 = 0x1000;
    matrix->mUnk_14 = 0x1000;
    matrix->mUnk_04 = 0;
    matrix->mUnk_30 = -(matAnmResult->mUnk_24 * matAnmResult->mUnk_2c) << 4;
    matrix->mUnk_34 = matAnmResult->mUnk_28 * matAnmResult->mUnk_2e << 4;
    matrix->mUnk_10 = 0;
}

void texmtxCalc_flagT_(Unk01ff9598_A *matrix, Unk01ff9598 *matAnmResult) {
    s32 widthFixed = matAnmResult->mUnk_2c << 12;
    s32 heightFixed = matAnmResult->mUnk_2e << 12;
    s32 cosR;
    s32 scaleS;
    s32 sinR;
    s32 scaleT;
    s32 scaleSCos;
    s32 scaleSSin;
    s32 scaleTSin;
    s32 scaleTCos;

    FX_DivAsync(heightFixed, widthFixed);
    cosR = matAnmResult->mUnk_22;
    scaleS = matAnmResult->mUnk_18;
    sinR = matAnmResult->mUnk_20;
    scaleT = matAnmResult->mUnk_1c;
    scaleSSin = MUL_FIXED12_NO_ROUND(scaleS, sinR);
    scaleSCos = MUL_FIXED12_NO_ROUND(scaleS, cosR);
    scaleTSin = MUL_FIXED12_NO_ROUND(scaleT, sinR);
    scaleTCos = MUL_FIXED12_NO_ROUND(scaleT, cosR);
    matrix->mUnk_00 = scaleSCos;
    matrix->mUnk_14 = scaleTCos;
    matrix->mUnk_04 = -scaleTSin * FX_GetDivResult() >> 12;
    FX_DivAsync(widthFixed, heightFixed);
    matrix->mUnk_30 = matAnmResult->mUnk_2c * (matAnmResult->mUnk_18 - (scaleSSin + scaleSCos)) << 3;
    matrix->mUnk_34 = matAnmResult->mUnk_2e * (scaleTSin - scaleTCos - matAnmResult->mUnk_1c + 0x2000) << 3;
    matrix->mUnk_10 = scaleSSin * FX_GetDivResult() >> 12;
}
