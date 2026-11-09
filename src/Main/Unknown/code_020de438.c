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

void DrawEarthenPipe(u32 unused0, PushedObject *pipe, u32 unused1, u16 d) {
    MtxFx43 *matrix;
    if (pipe->mMapObject.mStateMachine.mState == 0) {
        matrix = SetViewRotatedMatrixPos(&pipe->mMapObject.mPos);
        DrawNsbmdModelWithMatrixAndMaxAlpha(gEarthenPipe1, matrix, &pipe->mMapObject.mScale, 0, d);
        return;
    }
    QueueNsbmdModelMaterial(gEarthenPipe2);
    matrix = SetViewRotatedMatrixPos(&pipe->mMapObject.mPos);
    DrawNsbmdModelWithMatrixAndAngle(gEarthenPipe2, matrix, pipe->mMotion.mAngle, &pipe->mMapObject.mScale, 0, d);
    QueueNsbmdModelMaterial(gEarthenPipe1);
}

void func_020de4d4(u32 unused, u32 object) {
    u32 stateMachineAddress;
    u32 objectCopy = object;
    u32 unused12;
    stateMachineAddress = (objectCopy) + (0x80u);
    AdvanceStateMachine((void *) stateMachineAddress);
}

u8 func_020de4a0(PushedObject *pipe, void *kart, u8 *c, u8 *d) {
    if (func_020ec450(pipe, kart, c) != FALSE) {
        StartSoundIfKartStarOrKiller(&pipe->mMapObject, kart);
    }
    return *d;
}

u8 func_020de488(PushedObject *pipe, void *kart, u8 *c, u8 *d) {
    func_020ec41c(pipe, kart, c);
    return *d;
}

#pragma thumb on

void CreateEarthenPipe1AndEarthenPipe2(void) {
    void *nsbmdFile;
    nsbmdFile = FindCourseMapObjFile(gEarthenPipe1NsbmdName);
    func_020e6488(&gEarthenPipe1, nsbmdFile, 0, 0);
    nsbmdFile = FindCourseMapObjFile(gEarthenPipe2NsbmdName);
    func_020e6488(&gEarthenPipe2, nsbmdFile, 0, 0);
    SetNsbmdModelFixedAttributes(gEarthenPipe1);
    SetNsbmdModelFixedAttributes(gEarthenPipe2);
}

#pragma thumb off
