#include "01/code_02187d14.h"
#include "Main/Course/ShineBalloon.h"
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

    firstGroupIndex = mapObject->field0.mCourseMapRow->field26;
    nextGroupIndex = mapObject->mEntryGroupIndex + 1;
    if (nextGroupIndex >= firstGroupIndex + groupSpan) {
        nextGroupIndex = firstGroupIndex;
    }
    mapObject->mEntryGroupIndex = (u16) nextGroupIndex;
    mapObject->mEntryIndex = 0;
}

void *StartItemBombWithParkedItemBox(u16 a) {
    ItemBox *parkedMapObject;

    parkedMapObject = FindParkedMapObject(0xc9);
    if (parkedMapObject != NULL) {
        func_020de9ec(parkedMapObject);
        parkedMapObject->fieldF2 = a;
        parkedMapObject->fieldF4 = a;
        parkedMapObject->fieldAC = 1;
        return itbomb_20FD338(parkedMapObject, 0xa000);
    }
    return NULL;
}

void *StartItemBombWithParkedKuribo(void) {
    void *parkedMapObject;

    parkedMapObject = FindParkedMapObject(MAP_OBJECT_KIND_KURIBO);
    if (parkedMapObject != NULL) {
        kuribo_resetRoaming(parkedMapObject);
        return itbomb_20FD338(parkedMapObject, 0);
    }
    return NULL;
}

void func_ov001_02187d14(NNSG3dRS *renderState) {
    MtxFx43 currentMatrix;
    MtxFx43 inverseViewMatrix;
    Vec3 bombPosition;
    Unk02188950 *mapObject;
    Camera *currentCamera;

    mapObject = renderState->mRenderObj->mPtrUser;
    if (renderState->mC[1] == mapObject->field2E4) {
        currentCamera = race_getCamera();
        NNS_G3dGetCurrentMtx(&currentMatrix, NULL);
        MTX_Inverse43(&currentCamera->mViewMatrix, &inverseViewMatrix);
        MTX_Concat43(&currentMatrix, &inverseViewMatrix, &currentMatrix);
        mapObject->field2E8.x = currentMatrix.field0[3].x << 4;
        mapObject->field2E8.y = currentMatrix.field0[3].y << 4;
        mapObject->field2E8.z = currentMatrix.field0[3].z << 4;
        if (mapObject->mItemBomb != NULL) {
            bombPosition = mapObject->field2E8;
            VEC_MultAdd(mapObject->field2F4.x, &currentMatrix.field0[0], &bombPosition, &bombPosition);
            VEC_MultAdd(mapObject->field2F4.y, &currentMatrix.field0[1], &bombPosition, &bombPosition);
            VEC_MultAdd(mapObject->field2F4.z, &currentMatrix.field0[2], &bombPosition, &bombPosition);
            func_020fd684(mapObject->mItemBomb, &currentMatrix.field0[0], &bombPosition);
        }
    }
}
