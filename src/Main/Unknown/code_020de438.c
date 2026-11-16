#include "Main/Unknown/code_020de438.h"
#include "Main/Unknown/code_020467d0.h"

#include "Main/Unknown/code_020de488.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020de4d4.h"
#include "Main/Unknown/code_020de4e4.h"
#include "Main/Unknown/unk_0216b000.h"

void epipe_render(u32 unused0, Unk020e43a8 *pipe, u32 unused1, u16 d) {
    MtxFx43 *matrix;
    if (pipe->field0.mStateMachine.mState == 0) {
        matrix = bbm_getYBillboardAtPos(&pipe->field0.mPos);
        bbm_renderTransformedScaled(epipe_sModel1, matrix, &pipe->field0.mScale, 0, d);
        return;
    }
    bbm_applyMaterial(epipe_sModel2);
    matrix = bbm_getYBillboardAtPos(&pipe->field0.mPos);
    bbm_renderTransformedRotatedScaled(epipe_sModel2, matrix, *(u16 *) &pipe->fieldA0.fieldC.x, &pipe->field0.mScale, 0, d);
    bbm_applyMaterial(epipe_sModel1);
}

void epipe_update(u32 unused, u32 object) {
    u32 stateMachineAddress;
    u32 objectCopy = object;
    u32 unused12;
    stateMachineAddress = (objectCopy) + (0x80u);
    sm_execute((void *) stateMachineAddress);
}

u8 epipe_onDriverCollide(Unk020e43a8 *pipe, void *kart, u8 *c, u8 *d) {
    if (rdmo_onDriverCollide(pipe, kart, c) != FALSE) {
        mobj_tryDestroyByDriver(&pipe->field0, kart);
    }
    return *d;
}

u8 epipe_onItemCollide(Unk020e43a8 *pipe, void *kart, u8 *c, u8 *d) {
    rdmo_onItemCollide(pipe, kart, c);
    return *d;
}

#pragma thumb on

void epipe_loadModels(void) {
    void *nsbmdFile;
    nsbmdFile = mobj_getMapObjFile(aEarthen_pipe1_);
    bbm_createFromNsbmd((NsbmdModel **) (((u32 *) &epipe_sModel1)), nsbmdFile, 0, 0);
    nsbmdFile = mobj_getMapObjFile(aEarthen_pipe2_);
    bbm_createFromNsbmd((NsbmdModel **) (((u32 *) &epipe_sModel2)), nsbmdFile, 0, 0);
    bbm_setDefaultMatParams(epipe_sModel1);
    bbm_setDefaultMatParams(epipe_sModel2);
}

#pragma thumb off
