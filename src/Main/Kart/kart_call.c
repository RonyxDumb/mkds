#include "Main/Kart/kart_call.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "code_02010c84.h"
#include "code_02013740.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "Main/Kart/karts.h"

// Copies row 1 of the matrix at 0x120 (mUnk_120_m), the kart's up direction, to the out vector. The camera takes it as
// its up while KART_DRIVE_BOOST_SURFACE_HELD is set in mDriveFlags and the world up (0, 0x1000, 0) otherwise; the
// steering code removes this component from vectors. The kart has two more matrices (0x150 and 0x184), built from this
// one for drawing.
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
    if ((kart->mEntryFlags & KART_ENTRY_WIFI_PEER) != 0) {
        return;
    }
    kart->mSlotFunctions[6](kart);
    if ((kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) != 0) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x10000;
    }
}

void KartAiCallKartSlot6AndToggleFlag(Kart *kart) {
    u32 flagBits;

    flagBits = kart->mEntryFlags & KART_ENTRY_WIFI_PEER;
    if (flagBits != 0) {
        return;
    }
    if (flagBits == 0) {
        kart->mSlotFunctions[6](kart);
        if ((kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) != 0) {
            kart->mParticipantRecordData->mEventToggleFlags ^= 0x10000;
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        kart->mDriveFlags &= ~KART_DRIVE_OBJECTS_SKIP;
    }
}

void PlaceKartKillerEffectCallback(NNSG3dRS *renderState) {
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
    killerItemDictIndex = NNS_G3dGetResDictIdxByName(&renderState->mRenderObj->mResMdl->mNodeInfo, data_02154a2c);
    if (killerItemDictIndex != ((renderState->mFlag & 0x10) != 0 ? renderState->mCurrentNodeDesc : -1)) {
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
    renderState->mCbVecFunc[6] = NULL;
    renderState->mCbVecTiming[6] = 0;
}
