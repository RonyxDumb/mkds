#include "Main/Unknown/code_020e516c.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e55b4.h"
#include "code_02146cbc.h"

void oshd_applyMaterial(void) {
    u32 value;
    value = oshd_sModelMat->field1C;
    NNS_G3dGeBufferOP_N(0x2b, &value, 1);
    NNS_G3dGeBufferOP_N(0x2a, &oshd_sModelMat->field14, 1);
    NNS_G3dGeBufferOP_N(0x30, &oshd_sModelMat->field4, 1);
    NNS_G3dGeBufferOP_N(0x31, &oshd_sModelMat->field8, 1);
}

void oshd_render(void *shadowData, void *wordPointer, u32 unused, u32 alpha) {
    u32 word;
    u32 b;
    u32 threeWords[3];
    ShadowMatrix *shadow = shadowData;

    b = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &b, 1);
    NNS_G3dGeBufferOP_N(0x19, shadowData, 0xc);
    if (wordPointer != NULL) {
        u32 firstWord;
        firstWord = *(u32 *) wordPointer;
        threeWords[0] = firstWord;
        threeWords[1] = firstWord;
        threeWords[2] = firstWord;
        NNS_G3dGeBufferOP_N(0x1b, threeWords, 3);
    }
    word = oshd_sModelMat->fieldC;
    alpha = alpha < shadow->field30 ? alpha : shadow->field30;
    word = word & ~0x1f0000;
    word = word | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &word, 1);
    NNS_G3dGeSendDL(&oshd_sModelShp->field0[oshd_sModelShp->field8], oshd_sModelShp->fieldC);
}

void oshd_renderMat(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha) {
    u32 x;
    u32 word;
    u32 b;
    u32 threeWords[3];

    x = oshd_sModelMat->field1C;
    NNS_G3dGeBufferOP_N(0x2b, &x, 1);
    NNS_G3dGeBufferOP_N(0x2a, &oshd_sModelMat->field14, 1);
    NNS_G3dGeBufferOP_N(0x30, &oshd_sModelMat->field4, 1);
    NNS_G3dGeBufferOP_N(0x31, &oshd_sModelMat->field8, 1);
    b = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &b, 1);
    NNS_G3dGeBufferOP_N(0x19, shadow, 0xc);
    if (wordPointer != NULL) {
        u32 wordCopy;
        wordCopy = *(u32 *) wordPointer;
        threeWords[0] = wordCopy;
        threeWords[1] = wordCopy;
        threeWords[2] = wordCopy;
        NNS_G3dGeBufferOP_N(0x1b, threeWords, 3);
    }
    word = oshd_sModelMat->fieldC;
    alpha = alpha < shadow->field30 ? alpha : shadow->field30;
    word = word & ~0x1f0000;
    word = word | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &word, 1);
    NNS_G3dGeSendDL(&oshd_sModelShp->field0[oshd_sModelShp->field8], oshd_sModelShp->fieldC);
}

void oshd_renderJgShadowTransformed(Vec3 *scale, MtxFx43 *matrix, u32 c, u32 d) {
    oshd_sJgModel->field6E = c < d ? c : d;
    DrawShadowWithMatrix(oshd_sJgModel, matrix, scale);
}

void oshd_renderJgShadow(u32 a, u32 b) {
    oshd_sJgModel->field6E = a < b ? a : b;
    sub_207AD88(oshd_sJgModel);
}

#pragma thumb on

void oshd_init(void) {
    Unk020e52bc_4 *a;
    Unk020e52bc_8 *b;
    Unk020e52bc_c *c;

    model2_createFromNsbmd((void **) &oshd_sModel, mobj_getSharedMapObjFile(aObj_shadow_nsb), NULL);
    model_setPolygonId(oshd_sModel, 0x3f);
    model_setLightEnableFlag(oshd_sModel, 0);
    a = oshd_sModel->field4;
    b = (Unk020e52bc_8 *) &a->field0[a->field8];
    oshd_sModelMat = (Unk020e53ac *) &b->field0[((u32 *) &b->field0[b->fieldA])[2]];
    a = oshd_sModel->field4;
    c = (Unk020e52bc_c *) &a->field0[a->fieldC];
    oshd_sModelShp = (Unk020e54e4 *) &c->field0[((u32 *) &c->field0[c->field6])[1]];
    if (gRaceMultiConfig->mRaceKind != RACE_KIND_STAFF_ROLL) {
        model2_createShadowFromNsbmd((void **) &oshd_sJgModel, arc_getSceneArcFile(aJg_shadow_nsbm), 0x3f);
    }
}

s32 oshd_setParams(void *shadow, Vec3 *position, s32 scale, u32 alphaCap) {
    Quaternion rotation;
    Vec3 direction;
    Vec3 raisedPosition;
    s32 scaleTenth;
    BOOL hit;
    ShadowMatrix *shadowCopy = shadow;

    raisedPosition = *position;
    hit = FALSE;
    raisedPosition.y = raisedPosition.y + 0x1999;
    if (col_collide(&raisedPosition, NULL, 0, 0xa000, 8, -2, NULL, &direction, NULL, NULL, NULL, NULL, NULL, NULL) !=
        0) {
        hit = TRUE;
        qrtn_fromForwardVec(&direction, &rotation);
        qtrn_toMtx33(shadow, &rotation);
        scaleTenth = scale / 10;
        shadowCopy->field0[0] = ((s64) shadowCopy->field0[0] * scaleTenth) >> 12;
        shadowCopy->field0[1] = ((s64) shadowCopy->field0[1] * scaleTenth) >> 12;
        shadowCopy->field0[2] = ((s64) shadowCopy->field0[2] * scaleTenth) >> 12;
        shadowCopy->field0[3] = ((s64) shadowCopy->field0[3] * scaleTenth) >> 12;
        shadowCopy->field0[4] = ((s64) shadowCopy->field0[4] * scaleTenth) >> 12;
        shadowCopy->field0[5] = ((s64) shadowCopy->field0[5] * scaleTenth) >> 12;
        shadowCopy->field0[6] = ((s64) shadowCopy->field0[6] * scaleTenth) >> 12;
        shadowCopy->field0[7] = ((s64) shadowCopy->field0[7] * scaleTenth) >> 12;
        shadowCopy->field0[8] = ((s64) shadowCopy->field0[8] * scaleTenth) >> 12;
    } else {
        MTX_Identity33_(shadow);
    }
    shadowCopy->field0[9] = raisedPosition.x >> 4;
    shadowCopy->field0[10] = raisedPosition.y >> 4;
    shadowCopy->field0[11] = raisedPosition.z >> 4;
    shadowCopy->field30 = alphaCap;
    return hit;
}

#pragma thumb off
