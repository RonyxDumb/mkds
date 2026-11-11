#include "Main/Unknown/code_02063b70.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02079b9c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02010c84.h"
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
    AdvanceSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange, GetKartCameraDistanceSquared(kart->mIndex));
}

static inline void SendGxCommandOneValue(u32 command, s32 value) {
    NNS_G3dGeBufferOP_N(command, &value, 1);
}

static inline void SendGxCommandThreeValues(u32 command, s32 valueX, s32 valueY, s32 valueZ) {
    Vec3 vector;

    vector.x = valueX;
    vector.y = valueY;
    vector.z = valueZ;
    NNS_G3dGeBufferOP_N(command, &vector, 3);
}

static inline void ShiftVec3RightByFour(Vec3 *destination, const Vec3 *source) {
    destination->x = source->x >> 4;
    destination->y = source->y >> 4;
    destination->z = source->z >> 4;
}

void DrawKart(Kart *kart) {
    u32 b;
    u32 c;
    u32 d;
    KartModelsEntry *modelsEntry;
    KartTireTranslations *f;
    s32 killerItemShown;
    s32 h;
    MtxFx33 spinMatrix;
    MtxFx33 k;
    Vec3 translation;
    s32 pairIndex;

    c = kart->mUnk_4c;
    b = (c & 0x10) != 0;
    d = kart->mUnk_7c;
    modelsEntry = kart->mKartModelsEntry;
    if ((d & 0x1008040) != 0 || (c & (0x10000000 | KART_4C_OUT_OF_VIEW | KART_4C_BLINK_HIDDEN)) != 0) {
        killerItemShown = 0;
        if ((d & 0x1008040) == 0 && (c & (KART_4C_OUT_OF_VIEW | KART_4C_BLINK_HIDDEN)) == 0) {
            killerItemShown = DrawKartKillerItem(kart);
        }
        SetKartKillerEffectShown(kart->mIndex, killerItemShown);
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
    SendGxCommandOneValue(0x14, 0x1e);
    if (b != 0) {
        ShiftVec3RightByFour(&kart->mUnk_144, kart->mPosSource);
        NNS_G3dGeBufferOP_N(0x19, &kart->mUnk_120, 0xc);
        NNS_G3dGeBufferOP_N(0x1b, &kart->mScale, 3);
        SendGxCommandThreeValues(0x1b, kart->mModelScaleX, kart->mModelScaleY, kart->mModelScaleZ);
        DrawShadowWithoutMatrix(modelsEntry->mShadowModel);
        SendGxCommandOneValue(0x14, 0x1e);
    }
    NNS_G3dGeBufferOP_N(0x19, kart->mDrawMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &kart->mScale, 3);
    SendGxCommandOneValue(0x13, 0x1d);
    SendGxCommandThreeValues(0x1b, kart->mModelScaleX, kart->mModelScaleY, kart->mModelScaleZ);
    if (b == 0) {
        DrawShadowWithoutMatrix(modelsEntry->mShadowModel);
    }
    SendLight01Color(&modelsEntry->mCourseColorBlend.mColor);
    if (modelsEntry->mKartModelHidden == 0) {
        SetKartModelTireAlpha(modelsEntry, modelsEntry->mFarFromCamera == FALSE);
        SendGxCommandOneValue(0x13, 0x1c);
        SendGxCommandThreeValues(0x1b, kart->mOffsetCycleAmount.x, kart->mOffsetCycleAmount.y, 0x1000);
        DrawNsbmd(modelsEntry->mModels[1]);
        if (modelsEntry->mModels[2] != NULL) {
            f = kart->mKartModelsEntry->mTireTranslations;
            h = kart->mKartModelsEntry->mKartOffsetData->mFirstTiresScale;
            SendGxCommandOneValue(0x14, 0x1c);
            NNS_G3dGeBufferOP_N(0x1c, &f->mThirdTireX, 3);
            MTX_RotX33_(&spinMatrix, SIN_OF_ANGLE(kart->mTireSpinAngle), COS_OF_ANGLE(kart->mTireSpinAngle));
            NNS_G3dGeBufferOP_N(0x1a, &spinMatrix, 9);
            DrawNsbmd(modelsEntry->mModels[2]);
            if (f->mThirdTireX != 0) {
                SendGxCommandThreeValues(0x1c, f->mFourthTireX, 0, 0);
                DrawNsbmd(modelsEntry->mModels[2]);
            }
            SendGxCommandOneValue(0x14, 0x1c);
            NNS_G3dGeBufferOP_N(0x1c, f, 3);
            SendGxCommandThreeValues(0x1b, h, h, h);
            NNS_G3dGeBufferOP_N(0x11, NULL, 0);
            pairIndex = (kart->mTireTurnAngle >> 4) * 2;
            MTX_RotY33_(&k, FX_SinCosTable_[pairIndex], FX_SinCosTable_[pairIndex + 1]);
            NNS_G3dGeBufferOP_N(0x1a, &k, 9);
            NNS_G3dGeBufferOP_N(0x1a, &spinMatrix, 9);
            DrawNsbmd(modelsEntry->mModels[2]);
            if (f->mFirstTireX != 0) {
                SendGxCommandOneValue(0x12, 1);
                SendGxCommandThreeValues(0x1c, f->mSecondTireX, 0, 0);
                NNS_G3dGeBufferOP_N(0x1a, &k, 9);
                NNS_G3dGeBufferOP_N(0x1a, &spinMatrix, 9);
                DrawNsbmd(modelsEntry->mModels[2]);
            }
        }
    }
    if (modelsEntry->mCharacterHidden != 0) {
        return;
    }
    translation = modelsEntry->mKartOffsetData->mCharacterOffsets[modelsEntry->mCharacterIndex];
    translation.y = translation.y + (kart->mModelOffsetY + kart->mOffsetCycleAmount.z);
    SendGxCommandOneValue(0x14, 0x1d);
    NNS_G3dGeBufferOP_N(0x1c, &translation, 3);
    DrawNsbmd(modelsEntry->mModels[0]);
}

BOOL DrawKartKillerItem(Kart *kart) {
    KartModelsEntry *modelsEntry;
    ModelAnimation *killerItemNsbca;
    BOOL drawn;
    s32 frame;
    s32 f;
    s32 t;
    s32 radiusFactor;
    Vec3 position;
    Vec3 scale;
    MtxFx43 matrix;

    modelsEntry = kart->mKartModelsEntry;
    drawn = modelsEntry->mKartModelHidden == 0;
    if (drawn != FALSE) {
        t = kart->mRadius + 0x5000;
        matrix = *kart->mDrawMatrix;
        VEC_MultAdd(t, &kart->mUnk_12c, kart->mPosSource, &position);
        matrix.mRows[3].x = position.x >> 4;
        matrix.mRows[3].y = position.y >> 4;
        matrix.mRows[3].z = position.z >> 4;
        radiusFactor = kart->mRadiusFactor;
        scale.x = MUL_FIXED12_NO_ROUND(kart->mScale.x, radiusFactor);
        scale.y = MUL_FIXED12_NO_ROUND(kart->mScale.y, radiusFactor);
        scale.z = MUL_FIXED12_NO_ROUND(kart->mScale.z, radiusFactor);
        f = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &f, 1);
        NNS_G3dGeBufferOP_N(0x19, &matrix, 0xc);
        NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
        SendLight01Color(&modelsEntry->mCourseColorBlend.mColor);
        SetKillerItemKartIndex(kart->mIndex);
        frame = kart->mKartModelsEntry->mKillerItemAnimation.mFrameIndex;
        killerItemNsbca = GetKillerItemNsbca();
        killerItemNsbca->mHead.mFrameIndex = frame;
        killerItemNsbca->mAnmObjs[killerItemNsbca->mCurrentIndex]->mFrame = killerItemNsbca->mHead.mFrameIndex;
        DrawNsbmd(GetKillerItem());
        DrawShadowWithoutMatrix(GetKillerItemS());
    }
    return drawn;
}
