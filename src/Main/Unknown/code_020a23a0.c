#include "Main/Unknown/code_020a23a0.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204984c.h"
#include "code_02010c84.h"
#include "code_02146cbc.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_020ed5c0.h"
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

void SetupTrophy(void) {
    s32 frustumTop;
    s32 frustumRight;
    s32 angle;
    Trophy *trophy;
    TeresaWobble *wobble;

    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 1, 0x1f, 0x10, 0x10);
    NNS_G3dGlbLightVector(0, gTrophy->mLight0X, gTrophy->mLight0Y, gTrophy->mLight0Z);
    NNS_G3dGlbLightVector(1, gTrophy->mLight1X, gTrophy->mLight1Y, gTrophy->mLight1Z);
    NNS_G3dGlbLightColor(0, 0x7fff);
    NNS_G3dGlbLightColor(1, 0x7fff);
    frustumTop = MUL_FIXED12_NO_ROUND(FX_Div(data_0215d6b4[0x54], data_0215d6b4[0x55]), 0x19a);
    frustumRight = MUL_FIXED12_NO_ROUND(-frustumTop, 0x1555);
    if (gRaceSetup->mMirrorMode != 0) {
        G3i_FrustumW_(frustumTop, -frustumTop, -frustumRight, frustumRight, 0x19a, 0x1388000, 0x200, 0,
                      &NNS_G3dGlb.mProjMtx);
        NNS_G3dGlb.mFlag &= ~0x50;
    } else {
        G3i_FrustumW_(frustumTop, -frustumTop, frustumRight, -frustumRight, 0x19a, 0x1388000, 0x200, 0,
                      &NNS_G3dGlb.mProjMtx);
        NNS_G3dGlb.mFlag &= ~0x50;
    }
    {
        Vec3 cameraPos;
        Vec3 cameraTarget;
        Vec3 cameraUp = {0, 0, 0};

        cameraTarget = data_021676d0;
        cameraPos = data_021676c4;
        data_021704dc[0] = cameraPos;
        data_021704dc[1] = cameraTarget;
        data_021704dc[2] = cameraUp;
        G3i_LookAt_(&cameraPos, &cameraTarget, &cameraUp, 0, &NNS_G3dGlb.mCameraMtx);
        NNS_G3dGlb.mFlag &= ~0xe8;
        SetG3xSwapBits(gDisplaySettings, 1, 1);
        NNS_G3dGlb.mPrmViewPort = 0xbfff0000;
        NNS_G3dGlbFlushP();
        if (gTrophy->mRankIndex >= 3) {
            return;
        }
        gTrophy->mRotateYAngle = -GetSceneFadeToClearFrameCount() * 0x6d;
        angle = -GetSceneFadeToClearFrameCount() * 0x36;
        trophy = gTrophy;
        trophy->mRotateZWobble.mAngle = angle;
        wobble = &trophy->mRotateZWobble;
        wobble->mMid = 0;
        wobble->mAmplitude = 0xaab;
        wobble->mAmplitudePerFrame = 0;
        wobble->mAnglePerFrame = 0x36;
        wobble->mUnk_1c = 0;
        MTX_Identity43_(&gTrophy->mEffectMatrix);
        if (gTrophy->mRankIndex == 0) {
            gTrophy->mEffect0->mRadius = gTrophy->mUnk_114;
            gTrophy->mEffect0->mUnk_28.x = gTrophy->mEffectOffset.x + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.x;
            gTrophy->mEffect0->mUnk_28.y = gTrophy->mEffectOffset.y + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.y;
            gTrophy->mEffect0->mUnk_28.z = gTrophy->mEffectOffset.z + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.z;
            gTrophy->mEffect4->mUnk_28.x = gTrophy->mEffect4->mUnk_20->mUnk_00->mUnk_04.x;
            gTrophy->mEffect4->mUnk_28.y = gTrophy->mEffect4->mUnk_20->mUnk_00->mUnk_04.y - 0xcd;
            gTrophy->mEffect4->mUnk_28.z = gTrophy->mEffect4->mUnk_20->mUnk_00->mUnk_04.z - 0x21ec;
            gTrophy->mEffect5->mUnk_28.x = gTrophy->mEffect5->mUnk_20->mUnk_00->mUnk_04.x;
            gTrophy->mEffect5->mUnk_28.y = gTrophy->mEffect5->mUnk_20->mUnk_00->mUnk_04.y - 0xcd;
            gTrophy->mEffect5->mUnk_28.z = gTrophy->mEffect5->mUnk_20->mUnk_00->mUnk_04.z - 0x21ec;
        } else if (gTrophy->mRankIndex == 1) {
            gTrophy->mEffect0->mRadius = gTrophy->mUnk_114;
            gTrophy->mEffect0->mUnk_28.x = gTrophy->mEffectOffset.x + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.x;
            gTrophy->mEffect0->mUnk_28.y = gTrophy->mEffectOffset.y + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.y;
            gTrophy->mEffect0->mUnk_28.z = gTrophy->mEffectOffset.z + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.z;
        }
    }
}

void InitTrophy(s32 modelIndex, u32 rankIndex) {
    void *modelFile;
    void *animationFile;
    void *heap;
    float frameIndex;
    s32 storedRankIndex;
    ModelAnimation *modelAnimation;

    gTrophy = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x124);
    gTrophy->mRankIndex = rankIndex;
    gTrophy->mModelIndex = modelIndex;
    if (modelIndex < 9 && rankIndex < 3) {
        modelFile = FindSceneFile(data_021677fc[modelIndex]);
        animationFile = FindSceneFile(data_02167820[modelIndex]);
        gTrophy->mLight0X = data_02156640[modelIndex];
        gTrophy->mLight0Y = data_02156654[modelIndex];
        gTrophy->mLight0Z = data_02156668[modelIndex];
        gTrophy->mLight1X = data_0215667c[modelIndex];
        gTrophy->mLight1Y = data_02156690[modelIndex];
        gTrophy->mLight1Z = data_021566a4[modelIndex];
        gTrophy->mEffectOffset.x = 0;
        gTrophy->mEffectOffset.y = data_021566dc[modelIndex];
        gTrophy->mEffectOffset.z = -0x2000;
        gTrophy->mUnk_114 = data_021566b8[modelIndex];
        InitNsbmd(&gTrophy->mModel, modelFile);
        SetNsbmdLightEnableFlagAll(&gTrophy->mModel, 3);
        if (gRaceSetup->mMirrorMode != 0) {
            SetNsbmdCullModeAll(&gTrophy->mModel, 1);
        } else {
            SetNsbmdCullModeAll(&gTrophy->mModel, 2);
        }
        heap = GetHeap(GetCurrentHeapCall());
        InitModelAnimation(2, &gTrophy->mModelAnimation, &gTrophy->mModel, 1, heap, modelFile);
        InitModelAnimationEntries(&gTrophy->mModelAnimation, animationFile, GetHeap(GetCurrentHeapCall()));
        SetModelAnimation(&gTrophy->mModelAnimation, 0);
        storedRankIndex = gTrophy->mRankIndex;
        if (storedRankIndex != 0) {
            frameIndex = 0.5f + TO_FIXED12(storedRankIndex);
        } else {
            frameIndex = TO_FIXED12(storedRankIndex) - 0.5f;
        }
        modelAnimation = &gTrophy->mModelAnimation;
        modelAnimation->mHead.mFrameIndex = frameIndex;
        modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mFrame = modelAnimation->mHead.mFrameIndex;
        InitEffects(GetHeap(GetCurrentHeapCall()));
        if (rankIndex == 0) {
            Vec3 effectPos0 = {0, 0, 0};

            gTrophy->mEffect0 = StartEffect(0, &effectPos0);
            {
                Vec3 effectPos1 = {0, 0, 0};

                gTrophy->mEffect4 = StartEffect(4, &effectPos1);
                {
                    Vec3 effectPos2 = {0, 0, 0};

                    gTrophy->mEffect5 = StartEffect(5, &effectPos2);
                }
            }
        } else if (rankIndex == 1) {
            Vec3 effectPos3 = {0, 0, 0};

            gTrophy->mEffect0 = StartEffect(0, &effectPos3);
        }
    }
    SetupTrophy();
}

s16 TrophyFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 TrophyFX_MulInline(s32 lhs, s32 rhs) {
    return MUL_FIXED12_ROUNDED(lhs, rhs);
}

void AdvanceTrophy(void) {
    Trophy *trophy;
    TeresaWobble *wobble;
    s32 value;

    if (gTrophy->mRankIndex >= 3) {
        return;
    }
    UpdateEffects();
    gTrophy->mRotateYAngle += 0x6d;
    trophy = gTrophy;
    wobble = &trophy->mRotateZWobble;
    trophy->mRotateZWobble.mAngle += wobble->mAnglePerFrame;
    wobble->mValueDelta = wobble->mMid +
                          TrophyFX_MulInline(wobble->mAmplitude, TrophyFX_SinIdx(trophy->mRotateZWobble.mAngle)) -
                          wobble->mValue;
    wobble->mValue += wobble->mValueDelta;
    if (wobble->mAmplitude > 0) {
        value = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (value <= 0) {
            value = 0;
        }
        wobble->mAmplitude = value;
    } else if (wobble->mAmplitude < 0) {
        value = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (value >= 0) {
            value = 0;
        }
        wobble->mAmplitude = value;
    }
    if (wobble->mAnglePerFrame > 0) {
        value = wobble->mAnglePerFrame + wobble->mUnk_1c;
        if (value <= 0) {
            value = 0;
        }
        wobble->mAnglePerFrame = value;
    } else if (wobble->mAnglePerFrame < 0) {
        value = wobble->mAnglePerFrame + wobble->mUnk_1c;
        if (value >= 0) {
            value = 0;
        }
        wobble->mAnglePerFrame = value;
    }
}

void DrawTrophy(void) {
    MtxFx33 rotateXMatrix;
    MtxFx33 rotateYMatrix;
    MtxFx33 rotateZMatrix;
    s32 scale[3];
    s32 translation[3];
    s32 zeroTranslation[3];
    u16 rotateZAngle;

    if (gTrophy->mRankIndex >= 3) {
        return;
    }
    DrawEffects(&gTrophy->mEffectMatrix);
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
    rotateZAngle = gTrophy->mRotateZWobble.mValue;
    MTX_RotX33_(&rotateXMatrix, data_0215d6b4[0x76], data_0215d6b4[0x77]);
    MTX_RotY33_(&rotateYMatrix, FX_SinIdx(gTrophy->mRotateYAngle), FX_CosIdx(gTrophy->mRotateYAngle));
    MTX_RotZ33_(&rotateZMatrix, FX_SinIdx(rotateZAngle), FX_CosIdx(rotateZAngle));
    NNS_G3dGeBufferOP_N(0x1a, &rotateXMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1a, &rotateYMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1a, &rotateZMatrix, 9);
    zeroTranslation[0] = 0;
    zeroTranslation[1] = 0;
    zeroTranslation[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, zeroTranslation, 3);
    DrawNsbmd(&gTrophy->mModel);
    NNS_G3dGeFlushBuffer();
}

s32 GetKartBalloonOrShineHeight(Kart *kart) {
    KartModelsEntry *kartModelsEntry;

    kartModelsEntry = kart->mKartModelsEntry;
    return gCharacterBalloonOrShineHeights[kartModelsEntry->mCharacterIndex] +
           kartModelsEntry->mKartOffsetData->mCharacterOffsets[kartModelsEntry->mCharacterIndex].y;
}
