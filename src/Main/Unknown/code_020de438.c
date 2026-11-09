#include "Main/Unknown/code_020de438.h"
#include "Main/Unknown/code_020467d0.h"

#include "Main/Unknown/code_020de488.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020de4d4.h"
#include "Main/Unknown/code_020de4e4.h"
#include "Main/Unknown/unk_0216b000.h"

void DrawEarthenPipe(u32 unused0, PushedObject *pipe, u32 unused1, u16 maxAlpha) {
    MtxFx43 *matrix;
    if (pipe->mMapObject.mStateMachine.mState == 0) {
        matrix = SetViewRotatedMatrixPos(&pipe->mMapObject.mPos);
        DrawNsbmdModelWithMatrixAndMaxAlpha(gEarthenPipe1, matrix, &pipe->mMapObject.mScale, 0, maxAlpha);
        return;
    }
    QueueNsbmdModelMaterial(gEarthenPipe2);
    matrix = SetViewRotatedMatrixPos(&pipe->mMapObject.mPos);
    DrawNsbmdModelWithMatrixAndAngle(gEarthenPipe2, matrix, pipe->mMotion.mAngle, &pipe->mMapObject.mScale, 0,
                                     maxAlpha);
    QueueNsbmdModelMaterial(gEarthenPipe1);
}

void UpdateEarthenPipe(u32 unused, PushedObject *pipe) {
    AdvanceStateMachine(&pipe->mMapObject.mStateMachine);
}

u8 CollideKartWithEarthenPipe(PushedObject *pipe, void *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (HitPushedObjectByKart(pipe, kart, firstResponsePtr) != FALSE) {
        StartSoundIfKartStarOrKiller(&pipe->mMapObject, kart);
    }
    return *secondResponsePtr;
}

u8 CollideItemObjectWithEarthenPipe(PushedObject *pipe, void *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    HitPushedObjectByItemObject(pipe, itemObject, firstResponsePtr);
    return *secondResponsePtr;
}

#pragma thumb on

void CreateEarthenPipe1AndEarthenPipe2(void) {
    void *nsbmdFile;
    nsbmdFile = FindCourseMapObjFile(gEarthenPipe1NsbmdName);
    CreateNsbmdModel(&gEarthenPipe1, nsbmdFile, 0, 0);
    nsbmdFile = FindCourseMapObjFile(gEarthenPipe2NsbmdName);
    CreateNsbmdModel(&gEarthenPipe2, nsbmdFile, 0, 0);
    SetNsbmdModelFixedAttributes(gEarthenPipe1);
    SetNsbmdModelFixedAttributes(gEarthenPipe2);
}

#pragma thumb off
