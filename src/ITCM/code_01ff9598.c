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
#include "Main/Kart/KartTurnEffects.h"
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

BOOL func_01ffa478(Kart *p, u32 a, Vec3 *b) {
    BOOL t = FALSE;

    if (a & 0x2000000) {
        if ((s64) b->x * b->x + (s64) b->z * b->z > 0x1000000) {
            t = TRUE;
        }
    }
    return t != FALSE;
}

BOOL func_01ffa41c(Kart *p, u32 a, Vec3 *b) {
    BOOL r = TRUE;
    BOOL t = FALSE;

    if (a & 0x2000000) {
        if ((s64) b->x * b->x + (s64) b->z * b->z > 0x1000000) {
            t = TRUE;
        }
    }
    if (t == FALSE) {
        if (!(p->field44 & 0x4000000)) {
            r = FALSE;
        }
    }
    return r != FALSE;
}

BOOL func_01ffa380(Kart *p, u32 a, Vec3 *b) {
    BOOL r = TRUE;
    BOOL t = FALSE;

    if (a & 0x2000000) {
        if ((s64) b->x * b->x + (s64) b->z * b->z > 0x1000000) {
            t = TRUE;
        }
    }
    if (t == FALSE) {
        if (b->y <= (s32) (((s64) p->mRadius * -0xb33 + 0x800) >> 12)) {
            r = FALSE;
        }
    }
    return r != FALSE;
}

void driver_1FFA350(Kart *p, u32 a) {
    p->field44 = p->field44 & ~a;
    p->field208->field0 = FALSE;
    p->mSurfaceGroup = -1;
    rptc_killDriverEffects_copy(p);
}

BOOL driver_handleFallBelow0(Kart *p) {
    void *q;
    u32 i;
    u32 r;

    if (p->mPos.y < 0) {
        if (!(p->field7C & 0x400) && !(p->field48 & 0x800)) {
            p->field48 = p->field48 | 0x800;
            i = p->mIndex;
            if (gRaceMultiConfig->mMode == MODE_BATTLE) {
                r = mdat_getRespawnId(0);
            } else {
                r = mdat_getRespawnId(gRaceStatus->field0[i].mCheckpoint);
            }
            p->mRespawnSlot = r;
            if (p->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                if (gRaceMultiConfig->mCourseId == COURSE_ID_RAINBOW && (data_0217c780 & 1)) {
                    q = sp_acquireElement(sound_getPoolById(0));
                    if (SoundHandle_217D084.fieldC != 0) {
                        if (*(u32 *) q != 0) {
                            NNS_SndPlayerStopSeq(q, 0);
                        }
                        if (*(u32 *) q != 0) {
                            NNS_SndPlayerStopSeq(q, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(q, 0, 0x1b7);
                    }
                }
            }
        }
        return TRUE;
    }
    p->field44 = p->field44 & 0xbbceffff;
    p->field48 = p->field48 & 0xff9ffbfe;
    return FALSE;
}

void AdvanceKartQuaternionBlendFactor(Kart *p, const Vec3 *a) {
    s32 d = vec_dotProduct(&p->mGroundNormal, a);
    s32 m;

    if (p->field48 & 1) {
        m = 0x4cd;
    } else {
        m = 0x1ec;
    }
    if (d < 0) {
        d = 0;
    }
    if (d >= 0xe66) {
        if (p->field44 & 0x1000) {
            if (p->field208->field0 == FALSE && p->field1FC.x == 0 && p->field1FC.y == 0 && p->field1FC.z == 0 &&
                p->field4D0 > 100) {
                p->mQuaternionBlendFactor = 0;
                return;
            }
        }
        if (p->mQuaternionBlendFactor >= m) {
            return;
        }
        p->mQuaternionBlendFactor = p->mQuaternionBlendFactor + 0x14;
        if (p->mQuaternionBlendFactor > m) {
            p->mQuaternionBlendFactor = m;
        }
    } else {
        p->mQuaternionBlendFactor = (s64) m * p->mVelocityLengthRatio >> 12;
    }
}

// Counts mAirborneFrames, also clears field234, sets or clears bit 0x4000 and stores mLastGroundY. Not run while the
// kart is below y = 0.
void UpdateKartAirborne(Kart *p) {
    if (p->field44 & KART_44_ON_GROUND) {
        p->mAirborneFrames = 0;
        p->mAirTiltAngle = 0;
        p->field44 = p->field44 & ~0x4000;
        p->mLastGroundY = p->mPos.y;
        return;
    }
    p->mAirborneFrames = p->mAirborneFrames + 1;
    if (p->mAirborneFrames > 5) {
        p->field44 = p->field44 | 0x4000;
    }
}

void AdvanceKartOrientation(Kart *p, Vec3 *a) {
    Vec4 v;
    u32 t;

    p->field3F8 = 0x1000;
    if (p->mAirborneFrames > 5) {
        p->mQuaternionBlendFactor = 0xf6;
        StructMQRacerEntry_SomeFn_88(p, &p->mUnk_100_q);
    } else {
        driver_1FFAD14(p, a);
    }
    qrtn_lerp(&p->mUnk_f0_q, &p->mUnk_100_q, &p->mUnk_f0_q, p->mQuaternionBlendFactor);
    qrtn_fromAxisAngle(&driverCore_sUpVec, (u16) (p->mHeadingAngle + p->mHeadingAngleOffset), &p->mUnk_e0_m);
    qrtn_mult(&p->mUnk_f0_q, &p->mUnk_e0_m, &p->mUnk_110_q);
    if (p->field44 & 2) {
        if (p->mHopSpeed > 0) {
            p->mHopTiltAngle = 0x9c4 - (u16) ((s64) p->mHopHeight * 500 >> 12);
            if (p->mHopTiltAngle > 0x6a4) {
                p->mHopTiltAngle = 0x352;
            }
        } else {
            p->mHopTiltAngle = 0;
        }
        qrtn_fromAxisAngle(&driverCore_sRightVec, (u16) -p->mHopTiltAngle, &v);
        qrtn_mult(&p->mUnk_110_q, &v, &p->mUnk_110_q);
    } else {
        p->mHopTiltAngle = 0;
    }
    qrtn_normalize(&p->mUnk_110_q, &p->mUnk_110_q);
}

// Runs only on a step with a ground hit (non-zero normal).
void driver_handleFloorCollision(Kart *p) {
    s32 r = col_findResponsePrismAttribute(0x1e34ef);
    s32 k;
    s32 a;
    s32 b;
    s32 c;

    p->mSurfaceKind = (r & 0x1f00) >> 8;
    p->mSurfaceVariant = (u32) ((r & 0xe0) << 11) >> 16;
    a = 0x1000;
    k = driver_sHandleFloorCollisionFuncs[p->mSurfaceKind](p);
    if (k != 0) {
        a = p->mPhysicalParam->mSurfaceSpeedLimitFactors[k];
    }
    b = p->mSpeedLimitFactor;
    if (a >= b) {
        p->mSpeedLimitFactor = a;
    } else {
        p->mSpeedLimitFactor = b + (s32) (((s64) (a - b) * 0x4cd + 0x800) >> 12);
    }
    if (p->field4C & 0x10000040) {
        c = 0;
    } else {
        c = k;
    }
    p->mTurnedForwardEaseFactor = p->mPhysicalParam->field38[c];
    if (p->field48 & 0x40000000) {
        if (p->field44 & KART_44_ON_GROUND) {
            if (k != 0xb) {
                p->field48 = p->field48 & ~0x40000000;
            }
        }
    }
    p->mSurfaceGroup = k;
}

void driver_handleSpecialBoosts(Kart *p) {
    u32 r;
    s32 d;
    enum { K0 } j;

    if (p->field48 & KART_48_MINI_TURBO) {
        p->mMiniTurboTimer = p->mMiniTurboTimer - 1;
        if (p->mMiniTurboTimer <= 0) {
            p->field48 = p->field48 & ~KART_48_MINI_TURBO;
            p->mMiniTurboTimer = 0;
        }
    }
    if (p->field48 & 0x100000) {
        p->field538.field0 = p->field538.field0 - 1;
        if (p->field538.field0 <= 0) {
            p->field48 = p->field48 & ~0x20100000;
            p->field538.field0 = 0;
        }
    }
    if (!(p->field44 & 0x1000000) && !(p->field7C & 0x400)) {
        driver_handleStartBoost(p);
    }
    if (!(p->field4C & 0x400)) {
        return;
    }
    r = race_getFrameCounter();
    if (p->field410 == 0) {
        j = p->mEntryIndex;
        if ((u16) (gInputUnits[j].mPressedBits & PAD_KEY_A) != 0) {
            p->field410 = r;
        }
    }
    if (p->field40C == 0) {
        return;
    }
    if (p->field410 == 0) {
        return;
    }
    d = p->field410 - p->field40C;
    if (d <= 0) {
        d = -d;
    }
    if (d <= 2) {
        driver_addBoost(p, KART_BOOST_RESPAWN, 10);
    }
    p->field4C = p->field4C & ~0x400;
}

void func_01ff9cb0(Kart *p) {
    if (!(p->field4C & 2)) {
        if (race_getState() == 1) {
            func_01ffc9e8(p, 0);
        }
    }
    p->field44 = p->field44 & ~0x1000;
    if (p->field208->field0 == FALSE) {
        return;
    }
    sub_20E0538((Unk020e04b0 *) p->field208, &p->mPos);
    p->field208->field0 = FALSE;
}

void driver_updateMap2DShadowFlag(Kart *p, u32 a) {
    u32 b = a & 0x1000000;

    if (b != p->field4C0) {
        p->field4C0 = b;
    }
}

void AdvanceKartHop(Kart *p) {
    if (!(p->field44 & 4)) {
        return;
    }
    p->mHopSpeed = p->mHopSpeed + p->mGravity;
    p->mHopHeight = p->mHopHeight + p->mHopSpeed;
    if (p->mHopHeight < 0) {
        p->mHopHeight = 0;
        p->mHopSpeed = 0;
        p->field44 = p->field44 & ~0x804;
    }
}

void driver_updateDriftEffects(Kart *p) {
    KartTurnEffects *a;
    KartEffects *b;
    u32 f;

    if (p->field4C & KART_4C_NEAR_PLAYER_RANK) {
        a = dptc_getControllerForDriver(p->mIndex);
        b = rptc_getEffectControllerForDriver(p->mIndex);
        dptc_updateContRedSparks(a, p);
        dptc_updateDustClouds(a, p);
        dptc_updateRedSparks(a, b->mSideDirections, b->mSidePositions);
        dptc_updateBlueSparks(a, b->mSideDirections, b->mSidePositions);
    } else {
        dptc_208C534(dptc_getControllerForDriver(p->mIndex));
    }
    p->mEffectVelocity = p->mVelocity;
    f = p->field44;
    if (f & KART_44_ON_GROUND) {
        if (!(f & 0x1000)) {
            p->mEffectVelocity.y = p->mEffectVelocity.y - p->mVerticalSpeed;
        }
    }
    p->mEffectVelocity.x = p->mEffectVelocity.x >> 4;
    p->mEffectVelocity.y = p->mEffectVelocity.y >> 4;
    p->mEffectVelocity.z = p->mEffectVelocity.z >> 4;
}

void NNSi_G3dSendJointSRTMaya(Unk01ff9940 *a) {
    BOOL r;
    u32 w = a->field0;

    r = FALSE;
    if ((w & 4) == 0) {
        r = TRUE;
    }
    if ((w & 0x20) && !(w & 8)) {
        if (r) {
            NNS_G3dGeBufferOP_N(0x1c, &a->field4C, 3);
            r = FALSE;
        }
        NNS_G3dGeBufferOP_N(0x1b, &a->field10, 3);
    }
    if (!(a->field0 & 2)) {
        if (r) {
            NNS_G3dGeBufferOP_N(0x19, &a->field28, 0xc);
        } else {
            NNS_G3dGeBufferOP_N(0x1a, &a->field28, 9);
        }
    } else if (r) {
        NNS_G3dGeBufferOP_N(0x1c, &a->field4C, 3);
    }
    if (!(a->field0 & 1)) {
        NNS_G3dGeBufferOP_N(0x1b, &a->field4, 3);
    }
}

void func_01ff9940(Unk01ff9940 *a, Unk01ff9940_B *b, Unk01ff9940_C *c, u32 d) {
    u8 t = c->field3;
    u32 i;

    if (d & 4) {
        a->field0 |= 1;
        if (t & 2) {
            i = c->field1;
            data_02170500->fieldC4[i >> 5] |= 1 << (i & 0x1f);
        }
    } else {
        a->field4.x = b->field0.x;
        a->field4.y = b->field0.y;
        a->field4.z = b->field0.z;
        if (t & 2) {
            i = c->field1;
            data_02170500->fieldC4[i >> 5] &= ~(1 << (i & 0x1f));
            data_02171310[i].field0.x = b->fieldC.x;
            data_02171310[i].field0.y = b->fieldC.y;
            data_02171310[i].field0.z = b->fieldC.z;
        }
    }
    if (t & 1) {
        i = c->field2;
        a->field0 |= 0x20;
        if (data_02170500->fieldC4[i >> 5] & (1 << (i & 0x1f))) {
            a->field0 |= 8;
        } else {
            a->field10 = data_02171310[i].field0;
        }
    }
    a->field0 |= 0x10;
}

void texmtxCalc_flag_(Unk01ff9598_A *a, Unk01ff9598 *b) {
    s32 w = b->field2C << 12;
    s32 h = b->field2E << 12;
    s32 k22;
    s32 k18;
    s32 k20;
    s32 v1;
    s32 c;
    s32 d;
    s32 e;
    s32 f;

    FX_DivAsync(h, w);
    k22 = b->field22;
    k18 = b->field18;
    k20 = b->field20;
    v1 = b->field1C;
    d = (s64) k18 * k20 >> 12;
    c = (s64) k18 * k22 >> 12;
    e = (s64) v1 * k20 >> 12;
    f = (s64) v1 * k22 >> 12;
    a->field0 = c;
    a->field14 = f;
    a->field4 = -e * FX_GetDivResult() >> 12;
    FX_DivAsync(w, h);
    a->field30 = (b->field2C * (b->field18 - (d + c)) << 3) - b->field2C * (s32) ((s64) b->field18 * b->field24 >> 8);
    a->field34 =
        b->field2E * (s32) ((s64) b->field1C * b->field28 >> 8) + (b->field2E * (e - f - b->field1C + 0x2000) << 3);
    a->field10 = d * FX_GetDivResult() >> 12;
}

void texmtxCalc_flagS_(Unk01ff9598_A *a, Unk01ff9598 *b) {
    s32 w = b->field2C << 12;
    s32 h = b->field2E << 12;
    s32 t;

    FX_DivAsync(h, w);
    a->field0 = b->field22;
    a->field14 = b->field22;
    a->field4 = -b->field20 * FX_GetDivResult() >> 12;
    FX_DivAsync(w, h);
    t = b->field20 + b->field22;
    a->field30 = (b->field2C * (-t + 0x1000) << 3) - (b->field24 * b->field2C << 4);
    a->field34 = (b->field2E * (b->field20 - b->field22 + 0x1000) << 3) + (b->field28 * b->field2E << 4);
    a->field10 = b->field20 * FX_GetDivResult() >> 12;
}

void texmtxCalc_flagR_(Unk01ff9598_A *a, Unk01ff9598 *b) {
    a->field0 = b->field18;
    a->field14 = b->field1C;
    a->field4 = 0;
    a->field30 = b->field2C * -(s32) ((s64) b->field18 * b->field24 >> 8);
    a->field34 =
        b->field2E * (s32) ((s64) b->field1C * b->field28 >> 8) + (b->field2E * (b->field1C * -2 + 0x2000) << 3);
    a->field10 = 0;
}

void texmtxCalc_flagRS_(Unk01ff9598_A *a, Unk01ff9598 *b) {
    a->field0 = 0x1000;
    a->field14 = 0x1000;
    a->field4 = 0;
    a->field30 = -(b->field24 * b->field2C) << 4;
    a->field34 = b->field28 * b->field2E << 4;
    a->field10 = 0;
}

void texmtxCalc_flagT_(Unk01ff9598_A *a, Unk01ff9598 *b) {
    s32 w = b->field2C << 12;
    s32 h = b->field2E << 12;
    s32 k22;
    s32 k18;
    s32 k20;
    s32 v1;
    s32 c;
    s32 d;
    s32 e;
    s32 f;

    FX_DivAsync(h, w);
    k22 = b->field22;
    k18 = b->field18;
    k20 = b->field20;
    v1 = b->field1C;
    d = (s64) k18 * k20 >> 12;
    c = (s64) k18 * k22 >> 12;
    e = (s64) v1 * k20 >> 12;
    f = (s64) v1 * k22 >> 12;
    a->field0 = c;
    a->field14 = f;
    a->field4 = -e * FX_GetDivResult() >> 12;
    FX_DivAsync(w, h);
    a->field30 = b->field2C * (b->field18 - (d + c)) << 3;
    a->field34 = b->field2E * (e - f - b->field1C + 0x2000) << 3;
    a->field10 = d * FX_GetDivResult() >> 12;
}
