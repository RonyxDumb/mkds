#include "Main/Unknown/code_0206f04c.h"
#include "Main/Unknown/code_0206d000.h"
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
#include "Main/Unknown/code_02081374.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020e73a0.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0208c16c.h"
#include "Main/Race/RaceStartSequence.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffb000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02040de0.h"
#include "code_0212df7c.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02077bc0.h"

#pragma opt_arithtransformation off

void driver_handleOobFallCannonPipe(Kart *kart, u32 collisionFlags) {
    u32 b;
    u32 respawnSlot;
    NNSSndSeqPlayer **soundHandleEntry;
    s32 f;
    s32 mode;
    u16 kartIndex;
    Vec3 g;
    KartFollowEffectIds e;

    if (kart->field7C & 0x400) {
        return;
    }
    if (collisionFlags & 0x8000) {
        if (kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
            return;
        }
        b = (u16) ((col_findResponsePrismAttribute(0x8000) & 0xe0) >> 5);
        mode = gRaceMultiConfig->mMode;
        if (mode == MODE_BATTLE || mode == MODE_MISSION_RUN) {
            driver_pipeTeleport(kart, b);
            return;
        }
        kart->field48 |= 0x10000;
        driver_cannonLaunch(kart, 0);
        return;
    }
    if (!(kart->field48 & 0x800)) {
        kart->field48 |= 0x800;
        kartIndex = kart->mIndex;
        if (gRaceMultiConfig->mMode == MODE_BATTLE) {
            respawnSlot = mdat_getRespawnId(0);
        } else {
            respawnSlot = mdat_getRespawnId(gRaceStatus->field0[kartIndex].mCheckpoint);
        }
        kart->mRespawnSlot = respawnSlot;
        if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mCourseId == COURSE_ID_RAINBOW &&
            (data_0217c780 & 1)) {
            soundHandleEntry = sp_acquireElement(sound_getPoolById(0));
            if (SoundHandle_217D084.fieldC != 0) {
                if (soundHandleEntry[0] != NULL) {
                    NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                }
                if (soundHandleEntry[0] != NULL) {
                    NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                }
                NNS_SndArcPlayerStartSeqArc(soundHandleEntry, 0, 0x1b7);
            }
        }
    }
    if (!(collisionFlags & 0xc00)) {
        return;
    }
    if (kart->field48 & 0x1000) {
        return;
    }
    r2d_hideMapPathForDriver(kart->mIndex);
    kart->field48 |= 0x41000;
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
    if (kart->field4C & 0x10000000) {
        kart->field4C &= ~0x10000000;
        sub_210515C(kart->mIndex);
        if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            cam_resetPlayerCameraTargetFov();
        }
        kart->mRadiusFactor = 0x1000;
        kart->mSurfaceGroup = -1;
        f = 0;
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->field58 == 0) {
            e = gKartFollowEffectIds;
            for (f = 0; f < 3; f++) {
                rptc_2081F10(ptcm_createEmitter(e.mEffectIds[f], &kart->mPos), kart->mIndex, 0x14);
            }
        }
        rptc_stopBulletBillEffect(kart->mIndex);
        sfx_21090C4(&kart->mSoundSource, 0xfd, 0x7f, 0);
    }
    sub_20F00F0(&(it_sDriverItemStatus)[kart->mIndex]);
    if (collisionFlags & 0x400) {
        b = col_findResponsePrismAttribute(0x400);
        kart->field48 |= 0x2000;
        if ((u16) ((b & 0xe0) >> 5) == 4) {
            kart->field48 |= 0x800000;
        }
        return;
    }
    b = (u16) ((col_findResponsePrismAttribute(0x800) & 0xe0) >> 5);
    kart->field4BC = kart->field3F8;
    kart->field4C |= 0x200000;
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        cam_2075D08(1);
    }
    if ((u16) (b + 0xffff) <= 1) {
        g = kart->mPos;
        if (b == 1) {
            kart->field48 |= 0x800000;
            b = 0xce;
        } else {
            kart->field48 |= 0x1000000;
            b = 0x15d;
        }
        g.y = kart->mPos.y - mobj_getWaterPlaneDistance1(kart->mPos.y);
        expl_spawnSplash(&g, (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0);
        kart->field4C |= 0x4000000;
        sfx_21090C4(&kart->mSoundSource, b, 0x7f, 0);
        kart->mGravity = 0;
    }
    sfx_emitDriverVoice(kart, kart->mSoundIndex, 0);
}

void driver_handleWaterDive(Kart *kart) {
    BOOL b;
    s32 heightAboveWater;
    s32 scaledFactorPerDepth;
    Vec3 waterSurfacePoint;

    heightAboveWater = mobj_getWaterPlaneDistance1(kart->mPos.y);
    if (heightAboveWater < 0 && !(kart->field4C & 0x4000000)) {
        b = FALSE;
        scaledFactorPerDepth = ((s64) kart->mSpeedLimitFactorPerDepth * kart->mScale.z) >> 12;
        kart->mSpeedLimitFactor = (s32) (((s64) scaledFactorPerDepth * heightAboveWater) >> 12) + 0x1000;
        if (kart->mSpeedLimitFactor < kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4]) {
            kart->mSpeedLimitFactor = kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4];
        }
        driver_notifyOffRoad(kart);
        kart->mWaterDepth = -heightAboveWater;
        if (mobj_getWaterPlaneDistance1(kart->mPos.y) <= -0xa000 &&
            mobj_getWaterPlaneDistance1(kart->mPrevPos.y) > -0xa000 && kart->mVelocity.y < -0x2000) {
            waterSurfacePoint = kart->mPos;
            waterSurfacePoint.y = kart->mPos.y - heightAboveWater;
            expl_spawnSplash(&waterSurfacePoint, (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0);
            b = FALSE;
        }
        if (b != FALSE) {
            return;
        }
        if (kart->field4C & 0x4000000) {
            return;
        }
        rptc_2083EC4(kart);
    } else {
        kart->mWaterDepth = 0;
        rptc_20838DC(kart);
    }
}

void driver_handleStartBoost(Kart *kart) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u32 bits7c;
    Vec3 e;
    Vec3 f;
    Unk02165608 g;
    Unk02165608 h;

    if (kart->field48 & 2) {
        a = kart->field4D4;
        if (a < 0) {
            b = 0x52;
        } else if (a > 0x1000) {
            b = 8;
        } else {
            b = FX_Div(0x4a, 0x1000);
            b = 0x52 - (s32) (((s64) b * a) >> 12);
        }
        kart->field4D4 = kart->field4D4 + b;
        if (kart->field4D4 > 0x1000) {
            kart->field4D4 = 0x1000;
        }
    } else {
        kart->field4D4 = ((s64) kart->field4D4 * 0xf5c) >> 12;
    }
    if (!(kart->field4C & KART_4C_HEADING_SWING)) {
        if (GetRaceStartSequenceFrames() - 0xaf > 0) {
            kart->field44 |= 0x1000000;
        }
    }
    if (GetRaceStartSequenceFrames() - 0xaf == 0) {
        if (kart->field7C & 2) {
            if (sub_208C180(kart->mAi) != 0) {
                if (!(kart->field4C & KART_4C_HEADING_SWING)) {
                    kart->field4C |= KART_4C_HEADING_SWING;
                    kart->mRaceStartFrameCount = 0x78;
                    driver_2068A64(kart, 1, 1);
                    g = data_02165608;
                    bits7c = kart->field7C;
                    if ((bits7c & 0x10) && kart->mKartModelsEntry->field58 == 0) {
                        if ((bits7c & 1) || !(bits7c & 0x402000)) {
                            VEC_MultAdd(g.field0[kart->mKartModelsEntry->mKartIndex] << 4, &kart->field138,
                                        &kart->mPos, &e);
                            ptcm_createEmitterNoUpdateSkip(0x72, &e, kart, func_0206c1ac);
                            ptcm_createEmitterNoUpdateSkip(0x73, &e, kart, func_0206c1ac);
                        }
                    }
                    if (!(kart->field48 & 0x840)) {
                        sfx_emitDriverVoice(kart, kart->mSoundIndex, 3);
                    }
                    StartKartModelScaleAnimation(kart, 1);
                    kart->mModelScaleKind = 1;
                }
            } else if (GetKartAiBoostsAtRaceStart(kart->mAi) != 0) {
                d = GetKartAiRaceStartBoostChoice(kart->mAi);
                kart->mRaceStartFrameCount = driver_sStartBoostFrameCount[d - 1];
                kart->field44 |= 0x1800000;
                driver_addBoost(kart, KART_BOOST_RACE_START, (s16) kart->mRaceStartFrameCount);
                if (!(kart->field48 & 0x840)) {
                    sfx_emitDriverVoice(kart, kart->mSoundIndex, 5);
                }
                kart->field48 |= 0x8000;
                if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    driver_getPlayerStatistics()->field0 = 1;
                } else {
                    sfx_21090C4(&kart->mSoundSource, 0xa1, 0x7f, 0);
                }
            }
        } else if (kart->field48 & 2) {
            c = kart->field4D4;
            if (c > 0xf34) {
                if (!(kart->field4C & KART_4C_HEADING_SWING)) {
                    kart->field4C |= KART_4C_HEADING_SWING;
                    kart->mRaceStartFrameCount = 0x78;
                    driver_2068A64(kart, 1, 1);
                    h = data_02165608;
                    bits7c = kart->field7C;
                    if ((bits7c & 0x10) && kart->mKartModelsEntry->field58 == 0) {
                        if ((bits7c & 1) || !(bits7c & 0x402000)) {
                            VEC_MultAdd(h.field0[kart->mKartModelsEntry->mKartIndex] << 4, &kart->field138,
                                        &kart->mPos, &f);
                            ptcm_createEmitterNoUpdateSkip(0x72, &f, kart, func_0206c1ac);
                            ptcm_createEmitterNoUpdateSkip(0x73, &f, kart, func_0206c1ac);
                        }
                    }
                    if (!(kart->field48 & 0x840)) {
                        sfx_emitDriverVoice(kart, kart->mSoundIndex, 3);
                    }
                    StartKartModelScaleAnimation(kart, 1);
                    kart->mModelScaleKind = 1;
                }
            } else if (c > 0xd9a) {
                d = 5;
                if (c < 0xe14) {
                    d = 1;
                } else if (c < 0xe7b) {
                    d = 2;
                } else if (c < 0xecd) {
                    d = 3;
                } else if (c < 0xf0a) {
                    d = 4;
                }
                kart->mRaceStartFrameCount = driver_sStartBoostFrameCount[d - 1];
                kart->field44 |= 0x1800000;
                driver_addBoost(kart, KART_BOOST_RACE_START, (s16) kart->mRaceStartFrameCount);
                if (!(kart->field48 & 0x840)) {
                    sfx_emitDriverVoice(kart, kart->mSoundIndex, 5);
                }
                kart->field48 |= 0x8000;
                if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    driver_getPlayerStatistics()->field0 = 1;
                } else {
                    sfx_21090C4(&kart->mSoundSource, 0xa1, 0x7f, 0);
                }
            }
        }
        kart->field230 = driver_1FFB0CC;
        if (!(kart->field4C & KART_4C_HEADING_SWING)) {
            kart->field44 |= 0x1000000;
        }
    }
    kart->field4E8 = kart->field4D4 + 0x1000;
}

void driver_handleFallsWater(Kart *kart, Vec3 *groundNormal, s32 bit100000WasSet) {
    Vec3 *mapObjectPosition;
    s32 limit;
    s32 step;
    Vec3 f;
    Vec3 g;

    mapObjectPosition = fwdst_getPosition((u16) kart->field4D8);
    limit = fwdst_getCCDependentSetting((u16) kart->field4D8) * 150;
    step = 0x333;
    if (kart->field7C & 2) {
        limit >>= 1;
        step >>= 1;
    }
    if (bit100000WasSet == 0) {
        VEC_Subtract(mapObjectPosition, &kart->mPos, &g);
        vec_crossProduct(groundNormal, &g, &f);
        vec_crossProduct(&f, groundNormal, &g);
        if (!((s64) g.x * g.x + (s64) g.y * g.y + (s64) g.z * g.z < 0x10)) {
            vec_normalize(&g, &kart->field268);
        }
    }
    kart->field44 |= 0x100000;
    kart->field274 = kart->field274 + step;
    if (kart->field274 > limit) {
        kart->field274 = limit;
    }
}

void func_0206f694(Kart *kart, u32 collisionFlags, Vec3 *b, s32 headingDelta) {
    Vec3 d;
    Vec3 e;

    if (collisionFlags & 0x40000000) {
        kart->field44 |= 0x40000;
        kart->mHeadingAngle += headingDelta;
    } else if (collisionFlags & 0x1e34ef) {
        kart->field1FC.y = 0;
    }
    if (b->x | b->y | b->z) {
        VEC_Subtract(b, &kart->field1FC, &d);
        if ((s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < 0x1000000) {
            kart->field1FC = *b;
        } else {
            VEC_MultAdd(0x199, &d, &kart->field1FC, &kart->field1FC);
        }
        kart->mVerticalSpeed = kart->mVerticalSpeed + kart->field1FC.y;
        kart->field1FC.y = 0;
    } else {
        e = data_02165554;
        kart->field1FC.x = ((s64) kart->field1FC.x * e.x) >> 12;
        kart->field1FC.y = ((s64) kart->field1FC.y * e.y) >> 12;
        kart->field1FC.z = ((s64) kart->field1FC.z * e.z) >> 12;
        if ((s64) kart->field1FC.x * kart->field1FC.x + (s64) kart->field1FC.y * kart->field1FC.y +
                (s64) kart->field1FC.z * kart->field1FC.z <
            0xa429) {
            kart->field1FC = driverCore_sZeroVec;
        }
    }
}

void driver_handleWallCollision(Kart *kart, u32 collisionFlags, Vec3 *contactNormal) {
    s32 baseSpeedLimitHitFactor;
    s32 d;
    u32 hitValue;

    if (collisionFlags & 0x200000) {
        baseSpeedLimitHitFactor = 0x1000;
    } else {
        baseSpeedLimitHitFactor = 0xccd;
    }
    hitValue = col_findResponsePrismAttribute(0x214300);
    HandleWalls(kart, contactNormal, (kart->field44 & 0x80) != 0, baseSpeedLimitHitFactor,
                  (s32) (hitValue & 0x1f00) >> 8, ((hitValue & 0xe0) << 11) >> 16, 2);
    kart->field44 |= 0x80;
    kart->field250 = *contactNormal;
    if (kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP && contactNormal->y < -0x800 && kart->mVerticalSpeed > 0) {
        kart->mVerticalSpeed = -kart->mVerticalSpeed;
    }
    d = contactNormal->y;
    if (d <= 0) {
        d = -d;
    }
    if (d > 0x3e8) {
        kart->field44 |= 0x40000000;
    }
    if (!(collisionFlags & 0x2000000)) {
        return;
    }
    if (data_0217ac10 == 0) {
        return;
    }
    if (collisionFlags & 0x10000) {
        kart->field44 |= 0x4000000;
    }
}

s32 HandleWalls(Kart *kart, Vec3 *contactNormal, s32 wasTouching, s32 baseSpeedLimitHitFactor, s32 d, s32 e, s32 f) {
    BOOL j;
    s32 g;
    s32 h;
    s32 i;
    s32 k;
    s16 l;
    Vec3 m;
    Vec3 o;
    Vec3 n;

    j = FALSE;
    i = vec_dotProduct(&kart->mSignedTurnedForward, contactNormal) + 0x1000;
    if (i > 0x1000) {
        i = 0x1000;
    } else if (i < 0x29) {
        i = 0x29;
    }
    g = VEC_DotProduct(contactNormal, &kart->mHitVelocity);
    kart->mHitVelocity.x = kart->mHitVelocity.x - (s32) (((s64) contactNormal->x * g) >> 12);
    kart->mHitVelocity.y = kart->mHitVelocity.y - (s32) (((s64) contactNormal->y * g) >> 12);
    kart->mHitVelocity.z = kart->mHitVelocity.z - (s32) (((s64) contactNormal->z * g) >> 12);
    g = VEC_DotProduct(contactNormal, &kart->mPrevHitVelocity);
    kart->mPrevHitVelocity.x = kart->mPrevHitVelocity.x - (s32) (((s64) contactNormal->x * g) >> 12);
    kart->mPrevHitVelocity.y = kart->mPrevHitVelocity.y - (s32) (((s64) contactNormal->y * g) >> 12);
    k = ((s64) baseSpeedLimitHitFactor * i) >> 12;
    kart->mPrevHitVelocity.z = kart->mPrevHitVelocity.z - (s32) (((s64) contactNormal->z * g) >> 12);
    kart->mSpeedLimitHitFactor = k;
    if (vec_dotProduct(&kart->field1FC, contactNormal) < -0x800) {
        kart->field1FC = driverCore_sZeroVec;
    }
    if (wasTouching == 0) {
        h = vec_dotProduct(&kart->field138, contactNormal);
        j = TRUE;
        g = VEC_DotProduct(contactNormal, &kart->mVelocity);
        m.x = ((s64) contactNormal->x * g) >> 12;
        m.y = ((s64) contactNormal->y * g) >> 12;
        m.z = ((s64) contactNormal->z * g) >> 12;
        kart->mDriftCharge = 0;
        kart->mRightTurnCount = 0;
        kart->mLeftTurnCount = kart->mRightTurnCount;
        kart->mTurnCountTimer = 0;
        kart->mHeadingAnglePerFrame = 0;
        if (kart->mVelocityLength > 0x1800) {
            if (!(kart->field48 & KART_48_BOOST) && (m.x != 0 || m.y != 0 || m.z != 0) &&
                baseSpeedLimitHitFactor != 0x1000) {
                BounceVelocityOffSurface(&m, contactNormal, 0, 0x4cd, 0, &m);
                kart->mHitVelocity.x = m.x;
                kart->mHitVelocity.z = m.z;
                kart->mVerticalSpeed = kart->mVerticalSpeed + m.y;
            }
            if (kart->field4DA <= 0) {
                if (d >= 0) {
                    sfx_emitWallSfx(kart, 0, d, e, 0);
                }
                if (f == 2 && e != 5 && kart->mKartModelsEntry->field58 == 0) {
                    k = kart->field7C;
                    g = 0;
                    if (!(k & 1) && (k & 0x402000)) {
                        g = 1;
                    }
                    if (g == 0) {
                        n = kart->mPos;
                        g = 0x800;
                        if (kart->field4C & 0x10000) {
                            g = 0x4cd;
                        }
                        VEC_MultAdd(-kart->mRadius, contactNormal, &kart->mPos, &n);
                        VEC_MultAdd(((s64) kart->mScale.y * (g << 4) + 0x800) >> 12, &kart->field12C, &n, &n);
                        ptcm_createEmitterNoUpdateSkip(0x3b, &n, kart, func_0206c488);
                    }
                }
                StartKartModelScaleAnimation(kart, 2);
            }
        }
        if (h > 0) {
            kart->mSpeedLimitHitFactor = 0x4cd;
            if (kart->mSurfaceGroup != 0xb && kart->mSurfaceGroup != 8) {
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
            }
            if (kart->mVelocityLength > 0x2000 && baseSpeedLimitHitFactor != 0x1000) {
                l = (kart->mVelocityLength >> 12) * 100;
                if ((u16) kart->mTurnAngle > 0x7fff) {
                    l = l * -1;
                }
                kart->mHeadingAnglePerFrame = l;
            }
        } else if (kart->mVelocityLength > 0x2000 && baseSpeedLimitHitFactor != 0x1000) {
            k = 0x1000 - i;
            if (kart->mVelocityLength > 0x1800 && k > 0x19a) {
                l = ((s32) (((s64) kart->mVelocityLength * k) >> 12) >> 12) * 30;
                vec_crossProduct(&kart->mSignedTurnedForward, contactNormal, &o);
                if (vec_dotProduct(&o, &kart->field12C) < 0) {
                    l = l * -1;
                }
                kart->mHeadingAnglePerFrame = l;
            }
        }
        if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && kart->mVelocityLength > 0x3000 && f == 2) {
            driver_getPlayerStatistics()->field10++;
        }
        kart->mTurnAngle = 0;
    } else if (e == 4) {
        rptc_startWallLeafEffect(kart->mIndex, contactNormal);
    }
    if (kart->mState != KART_STATE_NORMAL) {
        kart->mHeadingAnglePerFrame = 0;
    }
    return j;
}
