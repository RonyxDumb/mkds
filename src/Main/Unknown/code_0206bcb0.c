#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_0218155c.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Kart/KartAiCallbacks.h"
#include "Main/Kart/KartTurnEffects.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Kart/KartStates.h"
#include "Main/Unknown/code_0206d020.h"
#include "ITCM/code_01ffba68.h"
#include "Main/Unknown/code_020681f0.h"

void driver_handleBoost(s32 *acceleration, Kart *kart) {
    int secondArgument;
    u32 flags;
    KartItemEffectState *q;
    u16 diffColor;
    u16 emiColor;
    u16 ambColor;

    kart->mBoostTimer = kart->mBoostTimer - 1;
    if (kart->mBoostTimer <= 0) {
        kart->field48 &= 0xdfff7fdf;
        kart->mBoostTimer = 0;
        if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            return;
        }
        if (!(kart->field4C & 0x10000000)) {
            cam_resetPlayerCameraTargetFov();
        }
        dce_stopBlur();
        return;
    }
    *acceleration = 0x1000;
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        secondArgument = (kart->field48 & 0x8000) ? 0xa0 : 0x9e;
        AddSoundRequest(data_0217d26c, GetKartCameraDistanceSquared(kart->mIndex), func_020718c8, kart, secondArgument);
    }
    if (!(kart->field48 & 0x20000000)) {
        return;
    }
    cspl_speedClearSplashes(kart->mIndex);
    flags = kart->field4C;
    if (flags & 0x20000) {
        return;
    }
    if (!(flags & 0x8000000)) {
        return;
    }
    q = &kart->field538;
    if (q->field1C > 400) {
        return;
    }
    q->field1C = 400;
    kart->field4C |= 0x20000;
    diffColor = chkrt_getKartCrsMatDiffuse();
    emiColor = chkrt_getKartCrsMatEmission();
    ambColor = chkrt_getKartCrsMatAmbient();
    chkrt_setTargetColors(kart->mKartModelsEntry, diffColor, emiColor, ambColor);
}

void driver_endDrift(Kart *kart) {
    if (!(kart->field44 & KART_44_ON_GROUND)) {
        kart->field44 |= 0x8000;
    }
    if (kart->mDriftCharge == 4) {
        driver_addBoost(kart, KART_BOOST_MINI_TURBO, kart->mPhysicalParam->fieldE);
        kart->field48 |= KART_48_MINI_TURBO;
        kart->mMiniTurboTimer = kart->mPhysicalParam->fieldE;
        if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            driver_getPlayerStatistics()->field4++;
            // placeholder: the same test twice gives the original's two loads and compares
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN && gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                mrcnt_notifyPowerSlide();
            }
        }
    }
    kart->field44 &= 0xfffff7f4;
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    dptc_208C534(dptc_getControllerForDriver(kart->mIndex));
}

void driver_handleDrifting(Kart *kart, int fromLowSpeedTurn) {
    if (kart->mTurnDirection > 0) {
        if (kart->mTurnAngle > 11000) {
            kart->mTurnAngle = kart->mTurnAngle - 200;
            if (kart->mTurnAngle < 11000) {
                kart->mTurnAngle = 11000;
            }
        } else if (kart->mTurnAngle < 11000) {
            kart->mTurnAngle += 375;
            if (kart->mTurnAngle > 11000) {
                kart->mTurnAngle = 11000;
            }
        }
    } else {
        if (kart->mTurnAngle < -11000) {
            kart->mTurnAngle = kart->mTurnAngle + 200;
            if (kart->mTurnAngle > -11000) {
                kart->mTurnAngle = -11000;
            }
        } else if (kart->mTurnAngle > -11000) {
            kart->mTurnAngle -= 375;
            if (kart->mTurnAngle < -11000) {
                kart->mTurnAngle = -11000;
            }
        }
    }
    if (fromLowSpeedTurn != 0) {
        return;
    }
    if (kart->field38A <= 50) {
        kart->field38A = 50;
    } else {
        kart->field38A = (s32) (((s64) kart->field38A * 0xf33) >> 12);
    }
    driver_handleDriftingPhases(kart);
    if (!(kart->field44 & KART_44_ON_GROUND)) {
        return;
    }
    func_01ffc9e8(kart, 1);
    kart->field4C |= 0x2;
    if (kart->mDriftCharge < 3) {
        return;
    }
    if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    StartSoundWhileRequested(&kart->mSoundSource, 0xd1, 0x7f, 0);
}

// Drift step: the hop, the turn held after it, the charge, and the release with the mini-turbo.
void driver_handleJumpAndDrift(Kart *kart) {
    u32 bits44 = kart->field44;
    BOOL hasB = (bits44 & 2) != 0;
    u32 g;
    KartTurnEffects *turnEffects;
    int distanceSquared;
    enum { K0 } entryIndex;

    if (kart->field7C & 0x400) {
        return;
    }
    if (kart->mAirborneFrames >= 5 && !(bits44 & 0x1a)) {
        entryIndex = kart->mEntryIndex;
        if ((u16) (gInputUnits[entryIndex].mBits & PAD_KEY_R)) {
            if (bits44 & 1) {
                goto recheck;
            }
            if (kart->mTurnDirection != 0) {
                goto recheck;
            }
            g = kart->field48;
            if (g & KART_48_TURN_RIGHT) {
                kart->mTurnDirection = 1;
                kart->field44 |= 1;
            } else if (g & KART_48_TURN_LEFT) {
                kart->mTurnDirection = -1;
                kart->field44 |= 1;
            }
        } else {
            kart->field44 &= ~1;
        }
    }
recheck:
    if (kart->field44 & 2) {
        if (kart->mTurnDirection == 0) {
            g = kart->field48;
            if (g & KART_48_TURN_RIGHT) {
                kart->mTurnDirection = 1;
            } else if (g & KART_48_TURN_LEFT) {
                kart->mTurnDirection = -1;
            }
        }
    }
    bits44 = kart->field44;
    g = kart->mTurnDirection;
    if (!(bits44 & KART_44_DRIFTING) && (bits44 & KART_44_ON_GROUND)) {
        if ((bits44 & 3) &&
            kart->mVelocityLength > (s32) (((s64) kart->mPhysicalParam->mBaseSpeedLimit * 0x8cd) >> 12) && g != 0 &&
            (u16) (gInputUnits[entryIndex = kart->mEntryIndex].mBits & PAD_KEY_R)) {
            kart->field44 |= KART_44_DRIFTING;
            kart->mDriftCharge = 1;
            if (kart->mTurnDirection > 0) {
                kart->mAwayTurnCounter = &kart->mLeftTurnCount;
                kart->mTowardTurnCounter = &kart->mRightTurnCount;
            } else {
                kart->mAwayTurnCounter = &kart->mRightTurnCount;
                kart->mTowardTurnCounter = &kart->mLeftTurnCount;
            }
            if (kart->field4C & KART_4C_NEAR_PLAYER_RANK) {
                turnEffects = dptc_getControllerForDriver(kart->mIndex);
                dptc_killContRedSparks(turnEffects);
                dptc_startDustClouds(turnEffects);
            }
        } else {
            kart->mTurnDirection = 0;
        }
        kart->field44 &= 0xfffff7fc;
    }
    bits44 = kart->field44;
    if (bits44 & KART_44_DRIFTING) {
        entryIndex = kart->mEntryIndex;
        if (!((u16) (gInputUnits[entryIndex].mBits & PAD_KEY_R) && (kart->field48 & 2) &&
              kart->mVelocityLength >= kart->mPhysicalParam->mBaseSpeedLimit / 2 && !(bits44 & 0x2000c0))) {
            if (!(bits44 & KART_44_ON_GROUND)) {
                kart->field44 |= 0x8000;
            }
            if (kart->mDriftCharge == 4) {
                driver_addBoost(kart, KART_BOOST_MINI_TURBO, kart->mPhysicalParam->fieldE);
                kart->field48 |= KART_48_MINI_TURBO;
                kart->mMiniTurboTimer = kart->mPhysicalParam->fieldE;
                if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    driver_getPlayerStatistics()->field4++;
                    // placeholder: the same test twice gives the original's two loads and compares
                    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN && gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                        mrcnt_notifyPowerSlide();
                    }
                }
            }
            kart->field44 &= 0xfffff7f4;
            kart->mTurnDirection = 0;
            kart->mDriftCharge = 0;
            kart->mRightTurnCount = 0;
            kart->mLeftTurnCount = kart->mRightTurnCount;
            kart->mTurnCountTimer = 0;
            dptc_208C534(dptc_getControllerForDriver(kart->mIndex));
        } else if (bits44 & KART_44_ON_GROUND) {
            driver_handleDrifting(kart, 0);
        }
    }
    if (hasB && (kart->field44 & KART_44_ON_GROUND)) {
        int turn = 0;
        int dot;
        int ang;
        int len;
        Vec3 v;
        Vec3 w;
        Vec3 *q = &kart->field138;

        dot = VEC_DotProduct(&kart->mHopStartUp, q);
        v.x = kart->field138.x - (s32) (((s64) kart->mHopStartUp.x * dot) >> 12);
        v.y = q->y - (s32) (((s64) kart->mHopStartUp.y * dot) >> 12);
        v.z = q->z - (s32) (((s64) kart->mHopStartUp.z * dot) >> 12);
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 16 ? vec_normalize(&v, &v)
                                                                      : 0) {
            vec_crossProduct(&kart->mHopStartForward, &v, &w);
            len = VEC_Mag(&w);
            ang = FX_Atan2(len, vec_dotProduct(&kart->mHopStartForward, &v));
            turn = (s16) (((s64) ang * 0x28be60db9391LL + 0x80000000LL) >> 44);
        }
        if (kart->mForwardSpeed < 0) {
            g = -g;
        }
        kart->mTurnAngle += (s16) (turn * g);
        if (kart->mTurnAngle > 0x2af8) {
            kart->mTurnAngle = 0x2af8;
        } else if (kart->mTurnAngle < -0x2af8) {
            kart->mTurnAngle = -0x2af8;
        }
        if (!(kart->field44 & KART_44_DRIFTING)) {
            return;
        }
        kart->field38A = (s32) (((s64) kart->mVelocityLength * 0x1a) >> 12);
        return;
    }
    entryIndex = kart->mEntryIndex;
    if (!(u16) (gInputUnits[entryIndex].mPressedBits & PAD_KEY_R)) {
        if (!(kart->field44 & 0x20000000)) {
            return;
        }
    }
    if (kart->field4C & 0x10000000) {
        return;
    }
    if (!(kart->field44 & KART_44_ON_GROUND)) {
        return;
    }
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        distanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
        AddSoundRequest(&data_0217d284, distanceSquared + func_0210a578(), driver_emitSfx3, kart, 0xcf);
    }
    kart->field44 |= 0x806;
    kart->field44 &= 0xffff7ff7;
    kart->mHopSpeed = 0x1405;
    kart->mVerticalSpeed += 0x21a2;
    kart->mHopHeight = 0;
    kart->mTurnDirection = 0;
    kart->field38A = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    driver_getShadowZDirection(kart, &kart->mHopStartForward);
    driver_getShadowYDirection(kart, &kart->mHopStartUp);
    if (kart->field208->field0 != FALSE) {
        kart->field208->field0 = FALSE;
    }
    if (kart->field7C & 0x200) {
        kart->field514->field2C ^= 0x1;
    }
}

// At low speed, with the A and B keys held and no boost running, steers the kart with the left and right keys; TRUE
// when it acts.
int driver_handleWheelSpin(Kart *kart) {
    BOOL result = FALSE;
    BOOL pending = TRUE;
    BOOL dir = FALSE;
    int delta;
    u16 bits;
    KartTurnEffects *turnEffects;
    enum { K0 } entryIndex;

    if (kart->mVelocityLength < 0x1800 && (kart->field48 & 0x80)) {
        kart->mTurnDirection = 0;
        result = TRUE;
        pending = FALSE;
        entryIndex = kart->mEntryIndex;
        bits = gInputUnits[entryIndex].mBits;
        if ((u16) (bits & PAD_KEY_LEFT)) {
            dir = TRUE;
            kart->mTurnDirection = -1;
            delta = 500;
        } else if ((u16) (bits & PAD_KEY_RIGHT)) {
            dir = TRUE;
            kart->mTurnDirection = 1;
            delta = -500;
        }
        if (kart->field44 & KART_44_ON_GROUND) {
            if (dptc_getControllerForDriver(kart->mIndex)->mTurnStartPresent == 0 &&
                (kart->field4C & KART_4C_NEAR_PLAYER_RANK)) {
                turnEffects = dptc_getControllerForDriver(kart->mIndex);
                dptc_killContRedSparks(turnEffects);
                dptc_startDustClouds(turnEffects);
            }
            kart->field48 |= 0x100;
            if (kart->mTurnDirection != 0) {
                kart->field44 |= 0x8000000;
                kart->mHeadingAngle += delta;
                driver_handleDrifting(kart, 1);
            }
        }
        sfx_emitWheelSpinSfx(kart, dir, kart->mSurfaceKind, kart->mSurfaceVariant);
    }
    if (pending) {
        dptc_stopDustClouds(dptc_getControllerForDriver(kart->mIndex));
    }
    return result;
}

void func_0206c488(Unk0201ca6c *emitter, Kart *kart) {
    func_02080e88(emitter, kart);
}

void func_0206c450(Unk0201ca6c *emitter, Kart *kart) {
    emitter->field40 = kart->mEffectVelocity;
    func_02080e88(emitter, kart);
}

// Starts the effects of a kart-kart hit at the contact point; flag picks the four-effect set.
BOOL driver_206C354(Kart *kart, const Vec3 *overlapDirection, int flag) {
    if (kart->field7C & KART_7C_MODELS_ENTRY_008_SET) {
        int fourEffectIds[4] = {0x77, 0x76, 0x78, 0x79};
        u16 i = 0;
        u32 effectCount = 1;
        int *effectIds = data_02154f10;
        Vec3 contactPoint;

        if (flag) {
            effectIds = fourEffectIds;
            effectCount = 4;
        }
        VEC_MultAdd(-kart->mRadius, overlapDirection, &kart->mPos, &contactPoint);
        VEC_MultAdd(((s64) kart->mScale.y * 0x8000 + 0x800) >> 12, &kart->field12C, &contactPoint, &contactPoint);
        for (; i < effectCount; i++) {
            ptcm_createEmitterNoUpdateSkip(effectIds[i], &contactPoint, kart, func_0206c450);
        }
        return TRUE;
    }
    return FALSE;
}

void func_0206c2b4(Unk0201ca6c *emitter, Kart *kart) {
    Vec3 velocity = kart->mEffectVelocity;

    velocity.y = 0;
    velocity.x = ((s64) velocity.x * 0xe66) >> 12;
    velocity.y = ((s64) velocity.y * 0xe66) >> 12;
    velocity.z = ((s64) velocity.z * 0xe66) >> 12;
    emitter->field40 = velocity;
}

void func_0206c1ac(Unk0201ca6c *emitter, Kart *kart) {
    Vec3 position = kart->mPos;
    Vec3s16 rot;
    Vec3 *q;

    VEC_MultAdd(((s64) kart->mRadius * -0x1333 + 0x800) >> 12, &kart->field138, &position, &position);
    position.x >>= 4;
    position.y >>= 4;
    position.z >>= 4;
    emitter->field28.x = emitter->field20->field0->field4.x + position.x;
    emitter->field28.y = position.y + emitter->field20->field0->field4.y;
    emitter->field28.z = position.z + emitter->field20->field0->field4.z;
    q = &kart->field138;
    rot.x = q->x;
    rot.y = q->y;
    rot.z = q->z;
    emitter->field50 = rot;
}

void func_0206c17c(Kart *kart) {
    if (kart->field7C & 0x40000) {
        return;
    }
    kart->field4C |= 0x400000;
    kart->field506 = 0;
    kart->field504 = kart->field506;
}

void driver_notifySlotItemChanged(Kart *kart) {
    if (kart->field7C & 0x2) {
        enmy_notifySlotItemChanged(kart->mAi);
    }
}

void driver_notifyDragItemChanged(Kart *kart) {
    if (kart->field7C & 0x2) {
        enmy_notifyDragItemChanged(kart->mAi);
    }
}

BOOL func_0206c0e0(Kart *kart) {
    if ((kart->field7C & 0x402020) || (kart->field4C & 0x800) || kart->mState != KART_STATE_NORMAL) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_0206c0b0(Kart *kart) {
    if ((kart->field7C & 0x400020) || (kart->field4C & 0x800)) {
        return TRUE;
    }
    return FALSE;
}

int func_0206c0a8(Kart *kart) {
    return kart->field4C0;
}

BOOL func_0206c094(Kart *kart) {
    return (kart->field4C & KART_4C_OUT_OF_VIEW) != 0;
}

void driver_beginColReaction(Kart *kart, KartState mode) {
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
    driver_2068A64(kart, 1, 0);
    kart->mState = mode;
    kart->field44 &= 0xfffff7f4;
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    dptc_208C534(dptc_getControllerForDriver(kart->mIndex));
    if (kart->field4C & 0x2000) {
        kart->field4C &= ~0x2000;
        kart->fieldD8 = 0x1000;
        if (!(kart->field4C & 0x8000000)) {
            driver_disableSlipStreamToonMode(kart);
        }
        rptc_stopSlipstreamEffect(kart);
    }
}

BOOL TryStartKartState(Kart *kart, KartState newState) {
    BOOL ok;
    BOOL res;
    BOOL t;
    int currentState;
    u32 bits4c = kart->field4C;

    if (bits4c & 0x400000) {
        ok = FALSE;
    } else if (kart->field7C & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->field48 & 0x1800) && !(bits4c & 0x10000040)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        switch (newState) {
            case KART_STATE_1:
            case KART_STATE_SPIN:
                res = TRUE;
                if (!(bits4c & 0x10000040) && !(kart->field48 & 0x1800)) {
                    currentState = kart->mState;
                    t = FALSE;
                    if (currentState != KART_STATE_NORMAL && currentState != KART_STATE_1 &&
                        currentState != KART_STATE_SPIN) {
                        t = TRUE;
                    }
                    if (t == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
            default:
                res = TRUE;
                if (!(bits4c & 0x10000040) && !(kart->field48 & 0x1800)) {
                    currentState = kart->mState;
                    t = FALSE;
                    if (currentState != KART_STATE_NORMAL && currentState != KART_STATE_1 &&
                        currentState != KART_STATE_SPIN) {
                        t = TRUE;
                    }
                    if (t == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
        }
    }
    if (!ok) {
        return FALSE;
    }
    driver_beginColReaction(kart, newState);
    return TRUE;
}

// Starts a spin, or adds a turn to the spin already running.
BOOL driver_tryStartSpinOut(Kart *kart, int rotationCount, int b) {
    int currentState = kart->mState;
    BOOL x;
    BOOL ok;
    BOOL res;
    BOOL t;
    int v;
    u32 bits4c;

    x = currentState != KART_STATE_1 && currentState != KART_STATE_SPIN;
    if (x == FALSE) {
        if (kart->mYRotationCount * 0xffff - kart->mYRotationAngleSum > 0xffff || (kart->field7C & 0x200)) {
            return FALSE;
        }
    }
    bits4c = kart->field4C;
    if (bits4c & 0x400000) {
        ok = FALSE;
    } else if (kart->field7C & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->field48 & 0x1800) && !(bits4c & 0x10000040)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        res = TRUE;
        if (!(bits4c & 0x10000040) && !(kart->field48 & 0x1800)) {
            v = kart->mState;
            t = FALSE;
            if (v != KART_STATE_NORMAL && currentState != KART_STATE_1 && currentState != KART_STATE_SPIN) {
                t = TRUE;
            }
            if (t == FALSE) {
                res = FALSE;
            }
        }
        ok = res == FALSE;
    }
    if (!ok) {
        return FALSE;
    }
    if (x) {
        driver_startSpinOut(kart, rotationCount, b);
        if (b == 0) {
            if (rotationCount == 1) {
                if (kart->field7C & 0x200) {
                    kart->field514->field2C ^= 0x4;
                }
            } else if (rotationCount == 2) {
                if (kart->field7C & 0x200) {
                    kart->field514->field2C ^= 0x8;
                }
            }
        }
    } else {
        kart->mYRotationCount++;
    }
    return TRUE;
}
