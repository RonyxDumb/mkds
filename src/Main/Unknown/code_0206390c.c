#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02077bc0.h"

// Copies row 1 of the matrix at 0x120 (mUnk_120_m), the kart's up direction, to the out vector. The camera takes it as
// its up while bit 0x40000000 of mUnk_48 is set and the world up (0, 0x1000, 0) otherwise; the steering code removes
// this component from vectors. The kart has two more matrices (0x150 and 0x184), built from this one for drawing.
void GetKartUp(const Kart *kart, Vec3 *upDirection) {
    const MtxFx43 *matrix;

    matrix = &kart->mUnk_120_m;
    upDirection->x = matrix->mRows[1].x;
    upDirection->y = matrix->mRows[1].y;
    upDirection->z = matrix->mRows[1].z;
}

// Copies row 2 of the matrix at 0x120 (mUnk_120_m), the kart's forward direction, to the out vector. The camera follows
// it, and its mSavedKartForward holds a copy taken when the camera is set up. The kart has two more matrices (0x150 and
// 0x184), built from this one for drawing.
void GetKartForward(const Kart *kart, Vec3 *forward) {
    const MtxFx43 *matrix;

    matrix = &kart->mUnk_120_m;
    forward->x = matrix->mRows[2].x;
    forward->y = matrix->mRows[2].y;
    forward->z = matrix->mRows[2].z;
}

void CallKartSlot6AndToggleFlag(Kart *kart) {
    if ((kart->mUnk_7c & 0x400) != 0) {
        return;
    }
    kart->mSlotFunctions[6](kart);
    if ((kart->mUnk_7c & 0x200) != 0) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x10000;
    }
}

void KartAiCallKartSlot6AndToggleFlag(Kart *kart) {
    u32 flagBits;

    flagBits = kart->mUnk_7c & 0x400;
    if (flagBits != 0) {
        return;
    }
    if (flagBits == 0) {
        kart->mSlotFunctions[6](kart);
        if ((kart->mUnk_7c & 0x200) != 0) {
            kart->mParticipantRecordData->mEventToggleFlags ^= 0x10000;
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        kart->mUnk_48 &= ~KART_48_OBJECTS_SKIP;
    }
}

void PlaceKartKillerEffectCallback(Unk0206390c *renderState) {
    u32 killerItemKartIndex;
    MtxFx33 rotationMatrix;
    MtxFx43 positionMatrix;
    Vec3 effectPosition;
    Vec3 offset;
    MtxFx43 inverseViewMatrix;
    s32 offsetScale;
    MtxFx43 *currentViewMatrix;
    Kart *kart;
    s32 killerItemDictIndex;

    killerItemKartIndex = GetKillerItemKartIndex();
    killerItemDictIndex = NNS_G3dGetResDictIdxByName(renderState->mUnk_04->mUnk_04 + 0x40, data_02154a2c);
    if (killerItemDictIndex != ((renderState->mUnk_08 & 0x10) != 0 ? renderState->mUnk_ae : -1)) {
        return;
    }
    currentViewMatrix = GetCurrentViewMatrix();
    NNS_G3dGetCurrentMtx(&positionMatrix, &rotationMatrix);
    MTX_Inverse43(currentViewMatrix, &inverseViewMatrix);
    MTX_Concat43(&positionMatrix, &inverseViewMatrix, &positionMatrix);
    MTX_Concat33(&rotationMatrix, &inverseViewMatrix.mAxes, &rotationMatrix);
    effectPosition = positionMatrix.mRows[3];
    offset = rotationMatrix.mRows[2];
    kart = GetKart(killerItemKartIndex);
    offsetScale = MUL_FIXED12_ROUNDED(kart->mRadiusFactor, -0xd000) >> 4;
    offset.x = MUL_FIXED12_NO_ROUND(offset.x, offsetScale);
    offset.y = MUL_FIXED12_NO_ROUND(offset.y, offsetScale);
    offset.z = MUL_FIXED12_NO_ROUND(offset.z, offsetScale);
    VEC_Add(&effectPosition, &offset, &effectPosition);
    PlaceKartKillerEffect(killerItemKartIndex, &effectPosition);
    renderState->mUnk_24 = 0;
    renderState->mUnk_92 = 0;
}
