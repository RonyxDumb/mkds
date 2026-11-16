#include "ITCM/code_01ffb130.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffb930.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_0206dfd0.h"
#include "Main/Unknown/code_0206e000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a74c.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Kart/KartStates.h"
#include "Main/Unknown/code_0206e874.h"
#include "Main/Unknown/code_020681f0.h"

void driver_handleRegularDriving(Kart *p) {
    s32 k;
    s32 a;
    s32 b;
    Vec3 v1;
    Vec3 v2;
    MtxFx33 m1;
    MtxFx33 m2;
    Vec3 v3;
    Vec3 v4;
    KartItemEffectState *q;
    s32 d;
    s32 f;
    u32 w;

    b = p->field3F8;
    if (p->field4C & 0x8000000) {
        driver_updateGessoInk(p);
    }
    w = p->field4C;
    if (w & 0x10000000) {
        driver_updateKillerMode(p);
    } else {
        if (w & KART_4C_THUNDER_SHRINK) {
            driver_updateThunderShrinkEffect(p);
        }
        if (p->field4C & 0x10000) {
            driver_updateDossunFlatEffect(p);
        }
        if (p->field7C & 0x402000) {
            driver_updateTeresaEffect(p);
        }
    }
    if (p->field4C & 0x2000) {
        q = &p->field538;
        if (p->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            AddSoundRequest(data_0217d26c, GetKartCameraDistanceSquared(p->mIndex), func_020718c8, p, 0xa3);
        }
        q->fieldA++;
        if (q->fieldA > 0xb4 && (p->field4C & 0x2000)) {
            p->field4C &= ~0x2000;
            p->fieldD8 = 0x1000;
            if (!(p->field4C & 0x8000000)) {
                driver_disableSlipStreamToonMode(p);
            }
            rptc_stopSlipstreamEffect(p);
        }
    }
    if (p->field4C & 0x40) {
        q = &p->field538;
        rptc_updateRainbowEffect(p->mIndex);
        if ((p->field7C & KART_7C_MODELS_ENTRY_008_SET) && p->mKartModelsEntry->mCharacterAnimation->field1A == 0) {
            driver_2068A64(p, 2, 1);
        }
        q->field6++;
        if (q->field6 > 0x1c2) {
            p->field4C &= ~0x40;
            driver_disableStarToonMode(p);
            p->mItemEffect = 0;
            rptc_stopRainbowEffect(p->mIndex);
            driver_2068A64(p, 0, 1);
            if ((p->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
                snd_stopStarMusic();
            }
            if (p->field4C & 0x2000) {
                driver_enableSlipStreamToonMode(p);
            }
        }
    }
    if ((p->field48 & 0x800) && driver_handlePreRespawn(p, &b) != 0) {
        return;
    }
    if (p->field7C & 0x20) {
        return;
    }
    driver_sReactionUpdateFuncs[p->mState](p);
    driver_applyDeceleration(p);
    if (p->field48 & 0x40) {
        p->mSinkFrames++;
        if (p->mSinkFrames > 0x41) {
            p->field48 &= ~0x240;
            if (p->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                jg_finishRespawning();
            }
        } else {
            p->mPos.y -= 0x19a;
        }
    } else {
        driver_1FFB9CC(p);
    }
    if (p->field44 & KART_44_ON_GROUND) {
        driver_getShadowZDirection(p, &v2);
        if (!(p->field48 & 6) && p->mGroundNormal.y > 0 && (v2.y > 0 ? v2.y : -v2.y) > 0xcd &&
            p->mSpeedLimitHitFactor <= 0) {
            p->mForwardSpeed += (s32) (((s64) -v2.y * 0x19a) >> 12);
        }
    }
    if ((p->field44 & KART_44_ON_GROUND) || (p->field4C & 0x10000000)) {
        MTX_RotAxis33((MtxFx43 *) &m1, &p->mGroundNormal, FX_SinCosTable_[((u16) p->mTurnAngle >> 4) * 2],
                      FX_SinCosTable_[((u16) p->mTurnAngle >> 4) * 2 + 1]);
        if (p->field48 & 1) {
            MTX_RotAxis33((MtxFx43 *) &m2, &p->field120, FX_SinCosTable_[0xba], FX_SinCosTable_[0xbb]);
            MTX_Concat33(m2.field0, m1.field0, m1.field0);
        }
        MTX_MultVec33(&p->mForward, m1.field0, &p->mTurnedForward);
        d = VEC_DotProduct(&p->mGroundNormal, &p->mTurnedForward);
        v3.x = p->mTurnedForward.x - (s32) (((s64) p->mGroundNormal.x * d) >> 12);
        v3.y = p->mTurnedForward.y - (s32) (((s64) p->mGroundNormal.y * d) >> 12);
        v3.z = p->mTurnedForward.z - (s32) (((s64) p->mGroundNormal.z * d) >> 12);
        p->fieldD4 = VEC_Mag(&v3);
    } else {
        d = vec_dotProduct(&p->mForward, &p->mGroundNormal);
        p->mTurnedForward = p->mForward;
        if (p->field3E8 > 0) {
            p->fieldD4 = 0x1000;
        } else if (d < 0) {
            p->fieldD4 = 0x1000 - d;
        } else {
            p->fieldD4 = 0x1000;
        }
    }
    a = driver_1FFAF18(p);
    driver_applyTurningSpeedLose(&a, p);
    if ((p->field44 & 0x90) || (p->field4C & 0x10000000)) {
        k = p->mTurnedForwardEaseFactor;
        VEC_Subtract(&p->mTurnedForward, &p->mEasedTurnedForward, &v4);
        v4.x = ((s64) v4.x * k) >> 12;
        v4.y = ((s64) v4.y * k) >> 12;
        v4.z = ((s64) v4.z * k) >> 12;
        VEC_Add(&p->mEasedTurnedForward, &v4, &p->mEasedTurnedForward);
        p->mEasedTurnedForward.y = p->mTurnedForward.y;
    }
    v1.x = ((s64) p->mEasedTurnedForward.x * a) >> 12;
    v1.y = ((s64) p->mEasedTurnedForward.y * a) >> 12;
    v1.z = ((s64) p->mEasedTurnedForward.z * a) >> 12;
    if (a >= 0) {
        p->mSignedTurnedForward = p->mTurnedForward;
    } else {
        p->mSignedTurnedForward.x = -p->mTurnedForward.x;
        p->mSignedTurnedForward.y = -p->mTurnedForward.y;
        p->mSignedTurnedForward.z = -p->mTurnedForward.z;
    }
    if (p->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
        v1.y = 0;
    }
    p->mVelocity = v1;
    VEC_Add(&p->mVelocity, &p->field374, &p->mVelocity);
    p->mVelocity.y += p->mVerticalSpeed;
    VEC_MultAdd(p->field274, &p->field268, &p->mVelocity, &p->mVelocity);
    if (!(p->field44 & KART_44_ON_GROUND) && p->mAirborneFrames > 5 && p->mVelocity.y < -0x6000) {
        p->mVelocity.y = -0x6000;
    }
    VEC_Add(&p->mVelocity, &p->field2F0, &p->mVelocity);
    VEC_Add(&p->mVelocity, &p->field1FC, &p->mVelocity);
    AdvanceKartHop(p);
    driver_multiplyDeltaPos(p, b);
    if (p->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetKartForwardSpeedRatio(vec_dotProduct(&p->mVelocity, &p->mTurnedForward));
        if ((p->field44 & 0x1000000) && p->field4D4 != 0) {
            p->field4D4 = ((s64) p->field4D4 * 0xfae) >> 12;
            if (p->field4D4 < 0xcd) {
                p->field4D4 = 0;
            }
        }
    }
    if (!(p->field7C & 0x20)) {
        VEC_Add(&p->mPos, &p->mVelocity, &p->mPos);
        p->mSpeedLimitHitFactor = 0x1000;
    }
    f = (p->field44 & KART_44_ON_GROUND) ? 0xee1 : 0xfae;
    p->mHitVelocity.x = ((s64) p->mHitVelocity.x * f) >> 12;
    p->mHitVelocity.y = ((s64) p->mHitVelocity.y * f) >> 12;
    p->mHitVelocity.z = ((s64) p->mHitVelocity.z * f) >> 12;
    if ((s64) p->mHitVelocity.x * p->mHitVelocity.x + (s64) p->mHitVelocity.y * p->mHitVelocity.y +
            (s64) p->mHitVelocity.z * p->mHitVelocity.z >=
        0xa429) {
        p->field44 |= 0x2000;
    } else {
        p->mHitVelocity = driverCore_sZeroVec;
        p->field44 &= ~0x2000;
    }
    col_queryByColEntry(p->mCollisionSlot, 0xe800);
    driver_handleMapObjCollision(p);
    if (p->field7C & 0x8000000) {
        return;
    }
    ComputeKartPointAlongUp(&p->mPointAlongUp, p->field510, p->mPhysicalParam->field4, p);
    driver_handleItems(p);
    driver_handleDriverCollision(p);
    driver_handleSlipstream(p);
}
