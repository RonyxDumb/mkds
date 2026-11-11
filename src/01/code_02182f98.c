#include "01/code_02182f98.h"
#include "01/code_02181bd0.h"

#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "ITCM/code_01ff8000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"

void ResetCoinShadowRotationIndex(void) {
    data_ov001_021a9b94 = 0;
}

void AdvanceCoinShadowRotationIndex(void) {
    s32 nextIndex = data_ov001_021a9b94 + 1;
    if (nextIndex >= 3) {
        nextIndex = 0;
    }
    data_ov001_021a9b94 = nextIndex;
}

void DrawCoinShadow(void *mapObjectList, Coin *coin, void *viewMatrix, u32 mapObjectAlpha) {
    s32 gxArgument;
    s32 scaleFactor;
    Vec3 shadowPosition;
    MtxFx33 rotationMatrix;
    Vec3 scale;
    Vec3 shadowScale;

    if (coin->mScaleFactor > 0 && coin->mModelAlpha != 0 && (coin->mUnk_000.mFlags & 1) == 0 &&
        (s32) (coin->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0) < 0x3d090) {
        shadowPosition.x = coin->mUnk_000.mPos.x;
        shadowPosition.y = coin->mUnk_000.mPos.y - 0x16000;
        shadowPosition.z = coin->mUnk_000.mPos.z;
        gxArgument = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &gxArgument, 1);
        NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&shadowPosition), 0xc);
        scaleFactor = coin->mScaleFactor;
        if (scaleFactor < 0x1000) {
            scale.x = scaleFactor;
            scale.y = scaleFactor;
            scale.z = scaleFactor;
            NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
        }
        NNS_G3dGeBufferOP_N(0x1b, &coin->mUnk_000.mScale, 3);
        MTX_RotY33_(&rotationMatrix, FX_CosIdx(data_ov001_021a656c[data_ov001_021a9b94]),
                    FX_SinIdx(data_ov001_021a656c[data_ov001_021a9b94]));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
        shadowScale.x = 0x199a;
        shadowScale.y = 0x2000;
        shadowScale.z = 0x199a;
        NNS_G3dGeBufferOP_N(0x1b, &shadowScale, 3);
        DrawJgShadow(8, mapObjectAlpha);
    }
}
