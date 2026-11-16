#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Item/ItemInUse.h"
#include "Main/System/SoundFalloff.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0207b000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020f9334.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"
#include "Main/Kart/KartStates.h"
#include "Main/Unknown/code_02077bc0.h"

static inline s32 func_0206dbf8_inline(Kart *kart) {
    BOOL c;
    BOOL t;
    BOOL u;
    int v;
    u32 bits4c;

    bits4c = kart->field4C;
    if (bits4c & 0x400000) {
        c = FALSE;
    } else if (kart->field7C & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->field48 & 0x1800) && !(bits4c & 0x10000040)) {
            c = TRUE;
        } else {
            c = FALSE;
        }
    } else {
        t = TRUE;
        if (!(bits4c & 0x10000040) && !(kart->field48 & 0x1800)) {
            u = FALSE;
            v = kart->mState;
            if (v != KART_STATE_NORMAL && v != KART_STATE_1 && v != KART_STATE_SPIN) {
                u = TRUE;
            }
            if (u == FALSE) {
                t = FALSE;
            }
        }
        c = t == FALSE;
    }
    return c;
}

BOOL TryStartKartPushFlip(Kart *starKart, Kart *hitKart, const Vec3 *v) {
    BOOL r;
    s32 canStart;
    u32 w;

    r = FALSE;
    canStart = func_0206dbf8_inline(hitKart);
    if (canStart != 0) {
        driver_startBackwardFlip(hitKart, v, 1);
        sfx_21090C4(&hitKart->mSoundSource, 0xe8, 0x7f, 0);
        if (hitKart->field7C & 0x200) {
            hitKart->field514->field2C ^= 0x80;
        }
        r = TRUE;
        w = starKart->field7C & 0x200;
        if (w != 0) {
            switch (hitKart->mIndex) {
                case 0:
                    if (w) {
                        starKart->field514->field2C ^= 0x200;
                    }
                    break;
                case 1:
                    if (w) {
                        starKart->field514->field2C ^= 0x400;
                    }
                    break;
                case 2:
                    if (w) {
                        starKart->field514->field2C ^= 0x800;
                    }
                    break;
                case 3:
                    if (w) {
                        starKart->field514->field2C ^= 0x1000;
                    }
                    break;
            }
        }
    }
    return r;
}

BOOL TryStartKartPushDoubleFlip(Kart *killerKart, Kart *hitKart) {
    Vec3 a;
    Vec3 b;
    Vec3 v1;
    BOOL r;
    s32 canStart;
    u32 w;

    r = FALSE;
    canStart = func_0206dbf8_inline(hitKart);
    if (canStart != 0) {
        a = killerKart->field120;
        VEC_Subtract(&hitKart->mPos, &killerKart->mPos, &b);
        VEC_CrossProduct(&killerKart->field138, &b, &v1);
        if (VEC_DotProduct(&v1, &killerKart->field12C) < 0) {
            a.x = -a.x;
            a.y = -a.y;
            a.z = -a.z;
        }
        driver_startDoubleBackwardFlip(hitKart, &a, 1);
        sfx_21090C4(&hitKart->mSoundSource, 0xe8, 0x7f, 0);
        if (hitKart->field7C & 0x200) {
            hitKart->field514->field2C ^= 0x80;
        }
        r = TRUE;
        w = killerKart->field7C & 0x200;
        if (w != 0) {
            switch (hitKart->mIndex) {
                case 0:
                    if (w) {
                        killerKart->field514->field2C ^= 0x400000;
                    }
                    break;
                case 1:
                    if (w) {
                        killerKart->field514->field2C ^= 0x800000;
                    }
                    break;
                case 2:
                    if (w) {
                        killerKart->field514->field2C ^= 0x1000000;
                    }
                    break;
                case 3:
                    if (w) {
                        killerKart->field514->field2C ^= 0x2000000;
                    }
                    break;
            }
        }
    }
    return r;
}

void OtherKartCollide(Kart *pushingKart, Kart *pushedKart, const Vec3 *v, s32 c, Vec3 *v1) {
    s32 a;
    s32 b;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 t;
    s32 v5 = -1;
    s32 v6;
    s32 v7;
    s32 v8;
    Vec3 s;
    Vec3 v9;
    Vec3 d;
    Vec3 n;
    Vec3 m;
    Vec3 v10;

    a = pushingKart->mPhysicalParam->mWeight + pushingKart->mCharPhysicalParam[1];
    b = pushedKart->mPhysicalParam->mWeight + pushedKart->mCharPhysicalParam[1];
    v2 = pushingKart->mVelocityLengthRatio;
    if (pushingKart->field7C & 0x600) {
        if (v2 > 4.8828125e-05f) {
            v2 = 0x333;
        }
    } else if (v2 > 0x800) {
        v2 = 0x1000;
    } else {
        v2 = v2 * 2;
        if (v2 < 0x333) {
            v2 = 0x333;
        }
    }
    t = pushingKart->field4C & KART_4C_THUNDER_SHRINK;
    if (t) {
        a >>= 3;
    }
    if (t) {
        b >>= 3;
    }
    if (pushingKart->field48 & 0x100000) {
        a <<= 1;
    }
    if (pushedKart->field48 & 0x100000) {
        a >>= 2;
    }
    t = FX_Div(a, b);
    if (t > 0x5000) {
        t = 0x5000;
    }
    b = ((s64) a * t) >> 12;
    v2 = ((s64) b * v2) >> 12;
    d = pushedKart->mTurnedForward;
    if (pushedKart->field44 & 0x100) {
        d.x = -d.x;
        d.y = -d.y;
        d.z = -d.z;
    }
    s.x = ((s64) v->x * v2) >> 12;
    s.y = ((s64) v->y * v2) >> 12;
    s.z = ((s64) v->z * v2) >> 12;
    v3 = VEC_DotProduct(&d, &s);
    v9.x = s.x - (s32) (((s64) d.x * v3) >> 12);
    v9.y = s.y - (s32) (((s64) d.y * v3) >> 12);
    v9.z = s.z - (s32) (((s64) d.z * v3) >> 12);
    v4 = 0;
    if ((s64) v9.x * v9.x + (s64) v9.y * v9.y + (s64) v9.z * v9.z >= 16) {
        v4 = vec_normalize(&v9, &n);
    }
    if (v4 <= 0) {
        return;
    }
    if (c != 0) {
        *v1 = n;
    } else if (v1->x != 0 || v1->y != 0 || v1->z != 0) {
        if (VEC_DotProduct(&n, v1) > 0x19a) {
            n = driverCore_sZeroVec;
        }
    }
    m.x = ((s64) n.x * v2) >> 12;
    m.y = ((s64) n.y * v2) >> 12;
    m.z = ((s64) n.z * v2) >> 12;
    if (m.y > 0) {
        m.y = 0;
    }
    v3 = VEC_DotProduct(&pushedKart->mGroundNormal, &m);
    v6 = m.x - (s32) (((s64) pushedKart->mGroundNormal.x * v3) >> 12);
    v8 = m.y - (s32) (((s64) pushedKart->mGroundNormal.y * v3) >> 12);
    v7 = m.z - (s32) (((s64) pushedKart->mGroundNormal.z * v3) >> 12);
    pushedKart->mHitVelocity.x += v6;
    pushedKart->mHitVelocity.z += v7;
    pushedKart->mVerticalSpeed += v8;
    v2 = ((s64) v2 * 0xaab + 0x800) >> 12;
    if (v2 > 0x1000) {
        v2 = 0x1000;
    }
    VEC_CrossProduct(&n, &pushedKart->mForward, &v10);
    if (v10.y < 0) {
        v2 = v2 * v5;
    }
    if (pushedKart->mKartModelsEntry->field58 != 0) {
        return;
    }
    t = pushedKart->mForwardSpeed;
    if (t <= 0) {
        t = -t;
    }
    if (t <= 0x3000) {
        return;
    }
    if (v2 > 0) {
        t = v2;
    } else {
        t = -v2;
    }
    pushedKart->field4C |= 0x2000000;
    if (t <= pushedKart->mWobbleAmplitude) {
        return;
    }
    pushedKart->mWobbleAmplitude = t;
    if (v2 > 0) {
        t = 1;
    } else {
        t = -1;
    }
    pushedKart->mWobbleDirection = t;
}

void driver_handleSlipstream(Kart *kart) {
    s32 distance;
    BOOL v1;
    s32 i;
    Kart *otherKart;
    Vec3 offset;

    distance = 0;
    v1 = FALSE;
    ComputeKartPointAlongUp(&kart->field1F0, kart->field510, 0x400, kart);
    VEC_MultAdd(((s64) kart->mRadius * -0x4000) >> 12, &kart->mTurnedForward, &kart->field1F0, &kart->field1F0);
    if (kart->mIndex == race_getFrameCounterModulo8() && !(kart->field4C & 0x10002000)) {
        if (kart->mVelocityLength > 0x4000 && kart->mState == KART_STATE_NORMAL) {
            for (i = 0; i < gColQueryResultCount; i++) {
                otherKart = gColQueryResultObjects[i];
                if (otherKart->mVelocityLength >= 0x2000 && (gColQueryResultFlags[i] & 0x800) &&
                    otherKart != kart && !(otherKart->field7C & 0x402000)) {
                    VEC_Subtract(&otherKart->mPos, &kart->mPos, &offset);
                    distance = VEC_Mag(&offset);
                    if (vec_dotProduct(&otherKart->mTurnedForward, &offset) >
                        (s32) (((s64) distance * 0xe7f) >> 12)) {
                        v1 = TRUE;
                        kart->field538.field8++;
                        break;
                    }
                }
            }
        }
        if (!(kart->field7C & 0x400)) {
            if (v1 != FALSE) {
                kart->field4C |= 0x4000;
                rptc_startSlipstreamBeginEffect(kart);
                if (kart->field538.field8 > 0xf && distance < 0x3c000) {
                    driver_startSlipstream(kart);
                }
            } else {
                kart->field538.field8 = 0;
                kart->field4C &= ~0x4000;
                if (!(kart->field4C & 0x2000)) {
                    kart->fieldD8 = 0x1000;
                }
                rptc_stopSlipstreamBeginEffect(kart);
            }
        }
    }
    if (kart->field4C & 0x4000) {
        kart->fieldD8 += 7;
        if (kart->fieldD8 > 0x1333) {
            kart->fieldD8 = 0x1333;
        }
    }
}

void driver_handleItems(Kart *kart) {
    s32 r;
    ItemObject *itemObject;
    Kart *ownerKart;
    u32 i;
    u32 t;
    u32 f;

    if (kart->field7C & 0x400400) {
        return;
    }
    if (it_20FA4C8(kart) == 0) {
        return;
    }
    if (kart->field7C & 0x402020) {
        return;
    }
    if (kart->field4C & 0x800) {
        return;
    }
    itemObject = GetCollidedItemObject(0);
    r = 0;
    switch (itemObject->mKind) {
        case 0:
        case 1:
        case 7:
            r = driver_tryStartForwardFlip(kart);
            break;
        case 2:
            r = driver_tryStartSpinOut(kart, 1, r);
            if (r != 0 && kart->mKartModelsEntry->field58 == 0) {
                ptcm_createEmitter(0xc, &kart->mPos);
                ptcm_createEmitter(0xd, &kart->mPos);
                ptcm_createEmitter(0xe, &kart->mPos);
            }
            break;
        case 3:
            // r is still 0 here, KART_BOOST_ITEM_OR_SURFACE.
            driver_addBoost(kart, r, 0x5a);
            kart->field48 |= 0x100000;
            kart->field538.field0 = 0x5a;
            if (gRaceMultiConfig->mMode == MODE_BATTLE) {
                mgcnt_20A1DDC(kart->mIndex);
            }
            break;
        case 4:
            driver_startStarInvincibility(kart);
            break;
        case 5:
            if (((ItemKouraW *) itemObject)->mHitSpinsKart != 0) {
                r = driver_tryStartSpinOut(kart, 2, r);
            } else {
                r = driver_tryThrowUp(kart);
            }
            break;
        case 9:
            if (((ItemKouraW *) itemObject)->field16C != 0) {
                r = driver_tryStartSpinOut(kart, 2, r);
            } else {
                r = driver_tryThrowUp(kart);
            }
            break;
        case 6:
            i = r;
            race_startDarkening();
            StartEffectsAtOtherKarts(kart->mIndex);
            t = kart->field7C & 0x200;
            if (t) {
                if (t) {
                    kart->field514->field2C ^= 0x4000;
                }
            } else {
                while (i < gRaceMultiConfig->mKartCount) {
                    if (i != kart->mIndex) {
                        driver_startThunderShrinkEffect(driver_getById(i));
                    }
                    i = (u16) (i + 1);
                }
            }
            break;
        case 8:
            CollideKartWithBouncingItemBox((BouncingItemBox *) itemObject, kart);
            break;
    }
    if (r != 0 && gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        driver_notifyItemHit(kart->mIndex);
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        mgcnt_20A1E40(kart->mIndex, itemObject);
    }
    if (func_020f9880(itemObject) == 0) {
        return;
    }
    if (kart->field4C & 0x10000040) {
        if (itemObject->field128 & (u8) (1 << kart->mIndex)) {
            return;
        }
        itemObject->field128 |= (u8) (1 << kart->mIndex);
        sfx_21090C4(&kart->mSoundSource, 0xe9, 0x7f, 0);
        return;
    }
    i = (u16) ((itemObject->field78 & 0x8000) == 0 ? (u16) (itemObject->field78 & ~0xff00) : 8);
    if (i >= gRaceMultiConfig->mKartCount) {
        return;
    }
    ownerKart = driver_getById(i);
    if (ownerKart->mIndex != kart->mIndex && r != 0) {
        if (gRaceMultiConfig->mMode != MODE_MISSION_RUN) {
            driver_notifyItemHit(i);
        }
        if (!(ownerKart->field48 & 0x840)) {
            sfx_emitDriverVoice(ownerKart, ownerKart->mSoundIndex, 8);
        }
        f = ownerKart->field7C;
        if ((f & 0x10) && !(f & 0x30000)) {
            driver_setAnimation(ownerKart, 2, 0);
        }
    }
    if (kart->field7C & 0x200) {
        kart->field514->field2C &= ~0x60000000;
        kart->field514->field2C |= (i & 3) << 0x1d;
    }
}

void func_0206d138(Kart *kart) {
    u32 f;

    if (!(kart->field48 & 0x840)) {
        sfx_emitDriverVoice(kart, kart->mSoundIndex, 8);
    }
    f = kart->field7C;
    if (!(f & 0x10)) {
        return;
    }
    if (f & 0x30000) {
        return;
    }
    driver_setAnimation(kart, 2, 0);
}

void driver_addBoost(Kart *kart, KartBoostKind boostKind, int boostFrames) {
    s32 c;
    u32 d;
    s16 currentTimer;
    enum { K0 } f;
    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    d = kart->field48 & 0x1000;
    if (d) {
        return;
    }
    if (kart->field4C & 0x10000000) {
        return;
    }
    kart->field48 |= KART_48_BOOST;
    currentTimer = kart->mBoostTimer;
    if (boostFrames > currentTimer) {
        kart->mBoostTimer = boostFrames;
    }
    if (boostKind != KART_BOOST_MINI_TURBO && boostKind != KART_BOOST_RESPAWN) {
        kart->field48 |= 0x20000000;
    }
    StopKartSoundWhileRequested(kart);
    c = ~0x8000;
    kart->field48 &= c;
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!boostKind) {
            f = 0;
        } else {
            f = 1;
        }
        rptc_startBoostEffect(f, kart);
        cam_setPlayerCameraTargetFov(0x1770);
        dce_startBlur(5);
        if (boostKind != KART_BOOST_RESPAWN) {
            return;
        }
        sfx_21090C4(&kart->mSoundSource, 0xa2, 0x7f, 0);
        return;
    }
    sfx_21090C4(&kart->mSoundSource, 0x9f, 0x7f, 0);
}
