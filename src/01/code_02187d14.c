#include "01/code_02187d14.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020da628.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "01/code_021a2034.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020de9ec.h"
#include "Main/Unknown/code_020de588.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_021000d0.h"

void IncrementEntryGroupIndex(Unk02188950 *mapObject, s32 groupSpan) {
    s32 firstGroupIndex;
    s32 nextGroupIndex;

    firstGroupIndex = mapObject->mUnk_000.mCourseMapRow->mGroupIndex;
    nextGroupIndex = mapObject->mEntryGroupIndex + 1;
    if (nextGroupIndex >= firstGroupIndex + groupSpan) {
        nextGroupIndex = firstGroupIndex;
    }
    mapObject->mEntryGroupIndex = (u16) nextGroupIndex;
    mapObject->mEntryIndex = 0;
}

void *StartItemBombWithParkedItemBox(u16 forcedRow) {
    ItemBox *parkedMapObject;

    parkedMapObject = FindParkedMapObject(0xc9);
    if (parkedMapObject != NULL) {
        SetItemBoxFramesSinceHitMax(parkedMapObject);
        parkedMapObject->mForcedRowHumanGhostPeer = forcedRow;
        parkedMapObject->mForcedRowCpu = forcedRow;
        parkedMapObject->mShortSpin = 1;
        return StartItemBombWithMapObject(parkedMapObject, 0xa000);
    }
    return NULL;
}

void *StartItemBombWithParkedKuribo(void) {
    void *parkedMapObject;

    parkedMapObject = FindParkedMapObject(MAP_OBJECT_KIND_KURIBO);
    if (parkedMapObject != NULL) {
        ResetKuriboForItemBomb(parkedMapObject);
        return StartItemBombWithMapObject(parkedMapObject, 0);
    }
    return NULL;
}

void StoreNodePositionAndPlaceItemBomb(NNSG3dRS *renderState) {
    MtxFx43 currentMatrix;
    MtxFx43 inverseViewMatrix;
    Vec3 bombPosition;
    Unk02188950 *mapObject;
    Camera *currentCamera;

    mapObject = renderState->mRenderObj->mPtrUser;
    if (renderState->mC[1] == mapObject->mUnk_2e4) {
        currentCamera = GetCurrentCamera();
        NNS_G3dGetCurrentMtx(&currentMatrix, NULL);
        MTX_Inverse43(&currentCamera->mViewMatrix, &inverseViewMatrix);
        MTX_Concat43(&currentMatrix, &inverseViewMatrix, &currentMatrix);
        mapObject->mUnk_2e8.x = currentMatrix.mRows[3].x << 4;
        mapObject->mUnk_2e8.y = currentMatrix.mRows[3].y << 4;
        mapObject->mUnk_2e8.z = currentMatrix.mRows[3].z << 4;
        if (mapObject->mItemBomb != NULL) {
            bombPosition = mapObject->mUnk_2e8;
            VEC_MultAdd(mapObject->mUnk_2f4.x, &currentMatrix.mRows[0], &bombPosition, &bombPosition);
            VEC_MultAdd(mapObject->mUnk_2f4.y, &currentMatrix.mRows[1], &bombPosition, &bombPosition);
            VEC_MultAdd(mapObject->mUnk_2f4.z, &currentMatrix.mRows[2], &bombPosition, &bombPosition);
            PlaceItemBomb(mapObject->mItemBomb, &currentMatrix.mRows[0], &bombPosition);
        }
    }
}
