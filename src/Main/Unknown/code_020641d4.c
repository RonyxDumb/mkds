#include "Main/Unknown/code_020641d4.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02066000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_0207a7ec.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02147000.h"
#include "code_02147288.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Kart/KartTimes.h"
#include "code_021471bc.h"

void func_020641f0(Kart *kart) {
    KartModelsEntry *modelsEntry;
    KartModelAnimationView *characterAnimation;
    Vec3 m;
    MtxFx43 d;
    MtxFx43 e;
    MtxFx43 rotationMatrix;
    MtxFx43 g;
    MtxFx43 h;
    s32 pairIndex;
    s32 j;
    s32 k;
    u16 l;
    u32 n;
    MtxFx43 *drawMatrix;
    Vec3 *q;
    Vec4 *r;
    enum { K0 } o;

    qrtn_toMtx43(&kart->field120, kart->field50C);
    n = kart->field4C;
    if ((n & 0x10) != 0) {
        drawMatrix = &kart->mUnk_150_m;
        MTX_Identity43_(&d);
        e = d;
        qrtn_toMtx43(&rotationMatrix, &kart->mRotationQuaternion);
        q = &kart->field12C;
        m.x = (s64) q->x * -0x5000 >> 12;
        m.y = (s64) q->y * -0x5000 >> 12;
        m.z = (s64) q->z * -0x5000 >> 12;
        d.field0[3] = m;
        m.x = -m.x;
        m.y = -m.y;
        m.z = -m.z;
        e.field0[3] = m;
        MTX_Concat43(&kart->mUnk_120_m, &d, drawMatrix);
        MTX_Concat43(drawMatrix, &rotationMatrix, drawMatrix);
        MTX_Concat43(drawMatrix, &e, drawMatrix);
        if ((kart->field4C & 0x20) != 0) {
            pairIndex = (kart->mYRotationAngle >> 4) * 2;
            MTX_RotY43_(&g, FX_SinCosTable_[pairIndex], FX_SinCosTable_[pairIndex + 1]);
            MTX_Concat43(drawMatrix, &g, drawMatrix);
        }
        drawMatrix->field0[3].x = drawMatrix->field0[3].x + kart->mPosSource->x;
        drawMatrix->field0[3].y = drawMatrix->field0[3].y + kart->mPosSource->y;
        drawMatrix->field0[3].z = drawMatrix->field0[3].z + kart->mPosSource->z;
    } else if ((n & 0x20) != 0) {
        pairIndex = (kart->mYRotationAngle >> 4) * 2;
        MTX_RotY43_(&h, FX_SinCosTable_[pairIndex], FX_SinCosTable_[pairIndex + 1]);
        MTX_Concat43(&h, &kart->mUnk_120_m, &kart->mUnk_150_m);
        q = kart->mPosSource;
        kart->field174.x = q->x;
        kart->field174.y = q->y;
        kart->field174.z = q->z;
    } else {
        kart->mUnk_150_m = kart->mUnk_120_m;
        q = kart->mPosSource;
        kart->field174.x = q->x;
        kart->field174.y = q->y;
        kart->field174.z = q->z;
    }
    kart->mDrawMatrixPos = kart->field174;
    kart->field174.x = kart->field174.x >> 4;
    kart->field174.y = kart->field174.y >> 4;
    kart->field174.z = kart->field174.z >> 4;
    if ((kart->field4C & 0x2000000) == 0) {
        kart->mDrawMatrix = &kart->mUnk_150_m;
    } else {
        AdvanceKartWobble(kart);
        kart->mDrawMatrix = &kart->mWobbleMatrix;
    }
    modelsEntry = kart->mKartModelsEntry;
    if (modelsEntry->mModels[2] != NULL) {
        r = (Vec4 *) &modelsEntry->mTurnFrameOffset;
        j = (s64) r->w * r->x >> 12;
        l = (s64) j * 0xce4 >> 12;
        k = kart->mVelocityLengthRatio;
        if (kart->field4D4 > k) {
            kart->mTireSpinAngle = kart->mTireSpinAngle + (u16) ((s64) kart->field4D4 * 0x7d0 >> 12);
        } else {
            k = (s64) k * 0xfa0 >> 12;
            if (math_abs(GetKartForwardSpeedRatio()) < 0x29) {
                k = 0;
                if ((u16) (data_0217562a[o = kart->mEntryIndex].mBits & (PAD_KEY_A | PAD_KEY_B)) != 0 &&
                    race_getState() == 1) {
                    k = k + 0x190;
                }
            } else if ((kart->field44 & 0x100) != 0) {
                k *= -1;
            }
            if (k > 0xfa0) {
                k = 0xfa0;
            }
            kart->mTireSpinAngle = kart->mTireSpinAngle + (u16) k;
        }
        kart->field4CC = l;
    }
    characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
    if (characterAnimation != NULL && characterAnimation->field18 != 0) {
        AdvanceKartCharacterAnimation(kart);
        if (rstat_hasDriverFinished(kart->mIndex) != 0) {
            AdvanceKartAnimationChangeTimer(kart);
        }
        characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
        *characterAnimation->field1C[characterAnimation->field1A] = characterAnimation->fieldC;
    }
    if ((kart->field4C & 0x400000) != 0) {
        kart->field504 = kart->field504 + 1;
        kart->field506 = kart->field506 + 1;
        if (kart->field506 > 8) {
            kart->field506 = 0;
        }
        if (kart->field506 >= 4) {
            kart->field4C = kart->field4C | 0x1000000;
        } else {
            kart->field4C = kart->field4C & ~0x1000000;
        }
        if (kart->field504 > 0x5a) {
            kart->field4C = kart->field4C & ~0x1400000;
        }
    }
    driver_updateDriftEffects(kart);
}

void func_020641d4(Kart *kart) {
    AdvanceKartCollision(kart);
    func_020641f0(kart);
}
