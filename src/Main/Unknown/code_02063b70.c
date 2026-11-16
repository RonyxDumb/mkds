#include "Main/Unknown/code_02063b70.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02079b9c.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_02079b60.h"
#include "Main/Unknown/code_02079000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0215d000.h"

void SetKartSoundDistanceSquaredAndChange(Kart *kart) {
    kart->mSoundSource.mDistanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
    AdvanceSoundDistanceSquaredChange(&kart->field518, GetKartCameraDistanceSquared(kart->mIndex));
}

static inline void func_02063cc4_inline(u32 command, s32 value) {
    NNS_G3dGeBufferOP_N(command, &value, 1);
}

static inline void func_02063cc4_inline2(u32 command, s32 valueX, s32 valueY, s32 valueZ) {
    Vec3 vector;

    vector.x = valueX;
    vector.y = valueY;
    vector.z = valueZ;
    NNS_G3dGeBufferOP_N(command, &vector, 3);
}

static inline void func_02063cc4_inline3(Vec3 *destination, const Vec3 *source) {
    destination->x = source->x >> 4;
    destination->y = source->y >> 4;
    destination->z = source->z >> 4;
}

void driver_render(Kart *kart) {
    u32 b;
    u32 c;
    u32 d;
    KartModelsEntry *modelsEntry;
    Unk0206bcb0_590_54 *f;
    s32 killerItemShown;
    s32 h;
    s32 spinMatrix[9];
    s32 k[9];
    Vec3 translation;
    s32 pairIndex;

    c = kart->field4C;
    b = (c & 0x10) != 0;
    d = kart->field7C;
    modelsEntry = kart->mKartModelsEntry;
    if ((d & 0x1008040) != 0 || (c & 0x11800000) != 0) {
        killerItemShown = 0;
        if ((d & 0x1008040) == 0 && (c & 0x1800000) == 0) {
            killerItemShown = driver_renderKillerItem(kart);
        }
        rptc_setBulletBillEffectVisibility(kart->mIndex, killerItemShown);
        kart->mVisible = 0;
        return;
    }
    if ((d & 0x404004) != 0) {
        kart->mVisible = ~kart->mVisible;
        if (kart->mVisible == 0) {
            return;
        }
    } else {
        kart->mVisible = 0xffff;
    }
    func_02063cc4_inline(0x14, 0x1e);
    if (b != 0) {
        func_02063cc4_inline3(&kart->field144, kart->mPosSource);
        NNS_G3dGeBufferOP_N(0x19, &kart->field120, 0xc);
        NNS_G3dGeBufferOP_N(0x1b, &kart->mScale, 3);
        func_02063cc4_inline2(0x1b, kart->mModelScaleX, kart->mModelScaleY, kart->mModelScaleZ);
        driver_renderShadow(modelsEntry->mShadowModel);
        func_02063cc4_inline(0x14, 0x1e);
    }
    NNS_G3dGeBufferOP_N(0x19, kart->mDrawMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &kart->mScale, 3);
    func_02063cc4_inline(0x13, 0x1d);
    func_02063cc4_inline2(0x1b, kart->mModelScaleX, kart->mModelScaleY, kart->mModelScaleZ);
    if (b == 0) {
        driver_renderShadow(modelsEntry->mShadowModel);
    }
    light_apply(&modelsEntry->field40);
    if (modelsEntry->field58 == 0) {
        chkrt_setKartTireVisibility(modelsEntry, modelsEntry->field60 == FALSE);
        func_02063cc4_inline(0x13, 0x1c);
        func_02063cc4_inline2(0x1b, kart->field4F0.x, kart->field4F0.y, 0x1000);
        model_render(modelsEntry->mModels[1]);
        if (modelsEntry->mModels[2] != NULL) {
            f = kart->mKartModelsEntry->field54;
            h = kart->mKartModelsEntry->mKartOffsetData->field10;
            func_02063cc4_inline(0x14, 0x1c);
            NNS_G3dGeBufferOP_N(0x1c, &f->field18, 3);
            pairIndex = (kart->mTireSpinAngle >> 4) * 2;
            MTX_RotX33_(spinMatrix, FX_SinCosTable_[pairIndex], FX_SinCosTable_[pairIndex + 1]);
            NNS_G3dGeBufferOP_N(0x1a, spinMatrix, 9);
            model_render(modelsEntry->mModels[2]);
            if (f->field18 != 0) {
                func_02063cc4_inline2(0x1c, f->field24, 0, 0);
                model_render(modelsEntry->mModels[2]);
            }
            func_02063cc4_inline(0x14, 0x1c);
            NNS_G3dGeBufferOP_N(0x1c, f, 3);
            func_02063cc4_inline2(0x1b, h, h, h);
            NNS_G3dGeBufferOP_N(0x11, NULL, 0);
            pairIndex = (kart->field4CC >> 4) * 2;
            MTX_RotY33_(k, FX_SinCosTable_[pairIndex], FX_SinCosTable_[pairIndex + 1]);
            NNS_G3dGeBufferOP_N(0x1a, k, 9);
            NNS_G3dGeBufferOP_N(0x1a, spinMatrix, 9);
            model_render(modelsEntry->mModels[2]);
            if (f->field0 != 0) {
                func_02063cc4_inline(0x12, 1);
                func_02063cc4_inline2(0x1c, f->fieldC, 0, 0);
                NNS_G3dGeBufferOP_N(0x1a, k, 9);
                NNS_G3dGeBufferOP_N(0x1a, spinMatrix, 9);
                model_render(modelsEntry->mModels[2]);
            }
        }
    }
    if (modelsEntry->field5C != 0) {
        return;
    }
    translation = ((Vec3 *) &modelsEntry->mKartOffsetData->field44)[modelsEntry->mCharacterIndex];
    translation.y = translation.y + (kart->mModelOffsetY + kart->field4F0.z);
    func_02063cc4_inline(0x14, 0x1d);
    NNS_G3dGeBufferOP_N(0x1c, &translation, 3);
    model_render(modelsEntry->mModels[0]);
}

BOOL driver_renderKillerItem(Kart *kart) {
    KartModelsEntry *modelsEntry;
    KartModelAnimationView *killerItemNsbca;
    BOOL drawn;
    s32 frame;
    s32 f;
    s32 t;
    s32 radiusFactor;
    Vec3 position;
    Vec3 scale;
    MtxFx43 matrix;

    modelsEntry = kart->mKartModelsEntry;
    drawn = modelsEntry->field58 == 0;
    if (drawn != FALSE) {
        t = kart->mRadius + 0x5000;
        matrix = *kart->mDrawMatrix;
        VEC_MultAdd(t, &kart->field12C, kart->mPosSource, &position);
        matrix.field0[3].x = position.x >> 4;
        matrix.field0[3].y = position.y >> 4;
        matrix.field0[3].z = position.z >> 4;
        radiusFactor = kart->mRadiusFactor;
        scale.x = (s64) kart->mScale.x * radiusFactor >> 12;
        scale.y = (s64) kart->mScale.y * radiusFactor >> 12;
        scale.z = (s64) kart->mScale.z * radiusFactor >> 12;
        f = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &f, 1);
        NNS_G3dGeBufferOP_N(0x19, &matrix, 0xc);
        NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
        light_apply(&modelsEntry->field40);
        SetKillerItemKartIndex(kart->mIndex);
        frame = kart->mKartModelsEntry->fieldA4;
        killerItemNsbca = chkrt_getKillerItemAnim();
        killerItemNsbca->fieldC = frame;
        *killerItemNsbca->field1C[killerItemNsbca->field1A] = killerItemNsbca->fieldC;
        model_render(chkrt_getKillerItemModel());
        driver_renderShadow(chkrt_getKillerItemShadowModel());
    }
    return drawn;
}
