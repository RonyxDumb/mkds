#include "Main/Unknown/code_020a23a0.h"
#include "registers.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0204984c.h"
#include "code_02010c84.h"
#include "code_02146cbc.h"
#include "code_0214a748.h"
#include "Main/Item/ItemInUse.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02147cd8.h"
#include "code_0214a390.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b200.h"
#include "Main/Unknown/code_02093ff0.h"
#include "code_021471bc.h"

void trophy_init3d(void) {
    s32 x;
    s32 y;
    s32 v;
    Trophy *trophy;
    TeresaWobble *wobble;

    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 1, 0x1f, 0x10, 0x10);
    NNS_G3dGlbLightVector(0, trophy_sState->mLight0X, trophy_sState->mLight0Y, trophy_sState->mLight0Z);
    NNS_G3dGlbLightVector(1, trophy_sState->mLight1X, trophy_sState->mLight1Y, trophy_sState->mLight1Z);
    NNS_G3dGlbLightColor(0, 0x7fff);
    NNS_G3dGlbLightColor(1, 0x7fff);
    x = ((s64) FX_Div(data_0215d6b4[0x54], data_0215d6b4[0x55]) * 0x19a) >> 12;
    y = ((s64) -x * 0x1555) >> 12;
    if (gRaceMultiConfig->mMirrorMode != 0) {
        G3i_FrustumW_(x, -x, -y, y, 0x19a, 0x1388000, 0x200, 0, (Unk0214ad4c *) NNS_G3dGlb.mProjMtx);
        NNS_G3dGlb.mFlag &= ~0x50;
    } else {
        G3i_FrustumW_(x, -x, y, -y, 0x19a, 0x1388000, 0x200, 0, (Unk0214ad4c *) NNS_G3dGlb.mProjMtx);
        NNS_G3dGlb.mFlag &= ~0x50;
    }
    {
        Vec3 v3;
        Vec3 v2;
        Vec3 v1 = {0, 0, 0};

        v2 = data_021676d0;
        v3 = data_021676c4;
        data_021704dc[0] = v3;
        data_021704dc[1] = v2;
        data_021704dc[2] = v1;
        G3i_LookAt_(&v3, &v2, &v1, 0, &NNS_G3dGlb.mCameraMtx);
        NNS_G3dGlb.mFlag &= ~0xe8;
        dc_set3DSwapConfig(gCurDisplayConfig, 1, 1);
        NNS_G3dGlb.mPrmViewPort = 0xbfff0000;
        NNS_G3dGlbFlushP();
        if (trophy_sState->mRankIndex >= 3) {
            return;
        }
        trophy_sState->mRotateYAngle = -scene_getFadeInLength() * 0x6d;
        v = -scene_getFadeInLength() * 0x36;
        trophy = trophy_sState;
        trophy->mRotateZWobble.mAngle = v;
        wobble = &trophy->mRotateZWobble;
        wobble->mMid = 0;
        wobble->mAmplitude = 0xaab;
        wobble->mAmplitudePerFrame = 0;
        wobble->mAnglePerFrame = 0x36;
        wobble->field1C = 0;
        MTX_Identity43_(&trophy_sState->mEffectMatrix);
        if (trophy_sState->mRankIndex == 0) {
            trophy_sState->mEffect0->field5C = trophy_sState->field114;
            trophy_sState->mEffect0->field28.x = trophy_sState->mEffectOffset.x + trophy_sState->mEffect0->field20->field0->field4.x;
            trophy_sState->mEffect0->field28.y = trophy_sState->mEffectOffset.y + trophy_sState->mEffect0->field20->field0->field4.y;
            trophy_sState->mEffect0->field28.z = trophy_sState->mEffectOffset.z + trophy_sState->mEffect0->field20->field0->field4.z;
            trophy_sState->mEffect4->field28.x = trophy_sState->mEffect4->field20->field0->field4.x;
            trophy_sState->mEffect4->field28.y = trophy_sState->mEffect4->field20->field0->field4.y - 0xcd;
            trophy_sState->mEffect4->field28.z = trophy_sState->mEffect4->field20->field0->field4.z - 0x21ec;
            trophy_sState->mEffect5->field28.x = trophy_sState->mEffect5->field20->field0->field4.x;
            trophy_sState->mEffect5->field28.y = trophy_sState->mEffect5->field20->field0->field4.y - 0xcd;
            trophy_sState->mEffect5->field28.z = trophy_sState->mEffect5->field20->field0->field4.z - 0x21ec;
        } else if (trophy_sState->mRankIndex == 1) {
            trophy_sState->mEffect0->field5C = trophy_sState->field114;
            trophy_sState->mEffect0->field28.x = trophy_sState->mEffectOffset.x + trophy_sState->mEffect0->field20->field0->field4.x;
            trophy_sState->mEffect0->field28.y = trophy_sState->mEffectOffset.y + trophy_sState->mEffect0->field20->field0->field4.y;
            trophy_sState->mEffect0->field28.z = trophy_sState->mEffectOffset.z + trophy_sState->mEffect0->field20->field0->field4.z;
        }
    }
}

void trophy_init(s32 modelIndex, u32 rankIndex) {
    void *modelFile;
    void *animationFile;
    void *heap;
    float f;
    s32 x;
    ModelAnimationView *modelAnimation;

    trophy_sState = heap_alloc(proc_getHeap(proc_getCurrent()), 0x124);
    trophy_sState->mRankIndex = rankIndex;
    trophy_sState->mModelIndex = modelIndex;
    if (modelIndex < 9 && rankIndex < 3) {
        modelFile = arc_getSceneArcFile(trophy_sNsbmdNames[modelIndex]);
        animationFile = arc_getSceneArcFile(trophy_sNsbtpNames[modelIndex]);
        trophy_sState->mLight0X = trophy_sLight0DirX[modelIndex];
        trophy_sState->mLight0Y = trophy_sLight0DirY[modelIndex];
        trophy_sState->mLight0Z = trophy_sLight0DirZ[modelIndex];
        trophy_sState->mLight1X = trophy_sLight1DirX[modelIndex];
        trophy_sState->mLight1Y = trophy_sLight1DirY[modelIndex];
        trophy_sState->mLight1Z = trophy_sLight1DirZ[modelIndex];
        trophy_sState->mEffectOffset.x = 0;
        trophy_sState->mEffectOffset.y = trophy_sSparkleEmitterY[modelIndex];
        trophy_sState->mEffectOffset.z = -0x2000;
        trophy_sState->field114 = trophy_sSparkleEmitterRadius[modelIndex];
        model_initFromNsbmd(&trophy_sState->mModel, modelFile);
        model_setLightEnableFlag(&trophy_sState->mModel, 3);
        if (gRaceMultiConfig->mMirrorMode != 0) {
            model_setCullMode(&trophy_sState->mModel, 1);
        } else {
            model_setCullMode(&trophy_sState->mModel, 2);
        }
        heap = proc_getHeap(proc_getCurrent());
        anim_initManager(2, &trophy_sState->mModelAnimation, &trophy_sState->mModel, 1, heap, modelFile);
        anim_registerAllAnims(&trophy_sState->mModelAnimation, animationFile, proc_getHeap(proc_getCurrent()));
        anim_setAnim(&trophy_sState->mModelAnimation, 0);
        x = trophy_sState->mRankIndex;
        if (x != 0) {
            f = 0.5f + (x << 12);
        } else {
            f = (x << 12) - 0.5f;
        }
        modelAnimation = &trophy_sState->mModelAnimation;
        modelAnimation->fieldC = f;
        *modelAnimation->field1C[modelAnimation->field1A] = modelAnimation->fieldC;
        ptcm_init(proc_getHeap(proc_getCurrent()));
        if (rankIndex == 0) {
            Vec3 w0 = {0, 0, 0};

            trophy_sState->mEffect0 = ptcm_createEmitter(0, &w0);
            {
                Vec3 w1 = {0, 0, 0};

                trophy_sState->mEffect4 = ptcm_createEmitter(4, &w1);
                {
                    Vec3 w2 = {0, 0, 0};

                    trophy_sState->mEffect5 = ptcm_createEmitter(5, &w2);
                }
            }
        } else if (rankIndex == 1) {
            Vec3 w3 = {0, 0, 0};

            trophy_sState->mEffect0 = ptcm_createEmitter(0, &w3);
        }
    }
    trophy_init3d();
}

s16 trophy_FX_SinIdx(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

s32 trophy_FX_MulInline(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void trophy_update(void) {
    Trophy *trophy;
    TeresaWobble *wobble;
    s32 v;

    if (trophy_sState->mRankIndex >= 3) {
        return;
    }
    ptcm_update();
    trophy_sState->mRotateYAngle += 0x6d;
    trophy = trophy_sState;
    wobble = &trophy->mRotateZWobble;
    trophy->mRotateZWobble.mAngle += wobble->mAnglePerFrame;
    wobble->field8 =
        wobble->mMid + trophy_FX_MulInline(wobble->mAmplitude, trophy_FX_SinIdx(trophy->mRotateZWobble.mAngle)) - wobble->mValue;
    wobble->mValue += wobble->field8;
    if (wobble->mAmplitude > 0) {
        v = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (v <= 0) {
            v = 0;
        }
        wobble->mAmplitude = v;
    } else if (wobble->mAmplitude < 0) {
        v = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (v >= 0) {
            v = 0;
        }
        wobble->mAmplitude = v;
    }
    if (wobble->mAnglePerFrame > 0) {
        v = wobble->mAnglePerFrame + wobble->field1C;
        if (v <= 0) {
            v = 0;
        }
        wobble->mAnglePerFrame = v;
    } else if (wobble->mAnglePerFrame < 0) {
        v = wobble->mAnglePerFrame + wobble->field1C;
        if (v >= 0) {
            v = 0;
        }
        wobble->mAnglePerFrame = v;
    }
}

void trophy_render(void) {
    s32 rotateXMatrix[9];
    s32 rotateYMatrix[9];
    s32 rotateZMatrix[9];
    s32 scale[3];
    s32 translation[3];
    s32 v3[3];
    u16 rotateZAngle;

    if (trophy_sState->mRankIndex >= 3) {
        return;
    }
    ptcm_render(&trophy_sState->mEffectMatrix);
    NNS_G3dGlbFlushP();
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    scale[0] = 0x1000;
    scale[1] = 0x1000;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    translation[0] = 0;
    translation[1] = -0xcd;
    translation[2] = -0x2000;
    NNS_G3dGeBufferOP_N(0x1c, translation, 3);
    rotateZAngle = trophy_sState->mRotateZWobble.mValue;
    MTX_RotX33_(rotateXMatrix, data_0215d6b4[0x76], data_0215d6b4[0x77]);
    MTX_RotY33_(rotateYMatrix, FX_SinCosTable_[(trophy_sState->mRotateYAngle >> 4) * 2],
                FX_SinCosTable_[(trophy_sState->mRotateYAngle >> 4) * 2 + 1]);
    MTX_RotZ33_(rotateZMatrix, FX_SinCosTable_[(rotateZAngle >> 4) * 2], FX_SinCosTable_[(rotateZAngle >> 4) * 2 + 1]);
    NNS_G3dGeBufferOP_N(0x1a, rotateXMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1a, rotateYMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1a, rotateZMatrix, 9);
    v3[0] = 0;
    v3[1] = 0;
    v3[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, v3, 3);
    model_render(&trophy_sState->mModel);
    NNS_G3dGeFlushBuffer();
}

s32 mgcnt_20A23A0(Kart *kart) {
    KartModelsEntry *kartModelsEntry;

    kartModelsEntry = kart->mKartModelsEntry;
    return data_02156600[kartModelsEntry->mCharacterIndex] +
           kartModelsEntry->mKartOffsetData->field48[kartModelsEntry->mCharacterIndex].x;
}
