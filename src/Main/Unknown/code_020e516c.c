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

void SendObjShadowMaterial(void) {
    u32 plttBase;
    plttBase = gObjShadowMaterial->mUnk_01c;
    NNS_G3dGeBufferOP_N(0x2b, &plttBase, 1);
    NNS_G3dGeBufferOP_N(0x2a, &gObjShadowMaterial->mUnk_014, 1);
    NNS_G3dGeBufferOP_N(0x30, &gObjShadowMaterial->mUnk_004, 1);
    NNS_G3dGeBufferOP_N(0x31, &gObjShadowMaterial->mUnk_008, 1);
}

void DrawObjShadowAfterMaterial(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha) {
    u32 polygonAttributes;
    u32 value;
    u32 threeWords[3];

    value = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &value, 1);
    NNS_G3dGeBufferOP_N(0x19, shadow, 0xc);
    if (wordPointer != NULL) {
        u32 firstWord;
        firstWord = *(u32 *) wordPointer;
        threeWords[0] = firstWord;
        threeWords[1] = firstWord;
        threeWords[2] = firstWord;
        NNS_G3dGeBufferOP_N(0x1b, threeWords, 3);
    }
    polygonAttributes = gObjShadowMaterial->mUnk_00c;
    alpha = alpha < shadow->mAlphaCap ? alpha : shadow->mAlphaCap;
    polygonAttributes = polygonAttributes & ~0x1f0000;
    polygonAttributes = polygonAttributes | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &polygonAttributes, 1);
    NNS_G3dGeSendDL(&gObjShadowShape->mUnk_000[gObjShadowShape->mUnk_008], gObjShadowShape->mUnk_00c);
}

void DrawObjShadow(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha) {
    u32 plttBase;
    u32 polygonAttributes;
    u32 value;
    u32 threeWords[3];

    plttBase = gObjShadowMaterial->mUnk_01c;
    NNS_G3dGeBufferOP_N(0x2b, &plttBase, 1);
    NNS_G3dGeBufferOP_N(0x2a, &gObjShadowMaterial->mUnk_014, 1);
    NNS_G3dGeBufferOP_N(0x30, &gObjShadowMaterial->mUnk_004, 1);
    NNS_G3dGeBufferOP_N(0x31, &gObjShadowMaterial->mUnk_008, 1);
    value = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &value, 1);
    NNS_G3dGeBufferOP_N(0x19, shadow, 0xc);
    if (wordPointer != NULL) {
        u32 wordCopy;
        wordCopy = *(u32 *) wordPointer;
        threeWords[0] = wordCopy;
        threeWords[1] = wordCopy;
        threeWords[2] = wordCopy;
        NNS_G3dGeBufferOP_N(0x1b, threeWords, 3);
    }
    polygonAttributes = gObjShadowMaterial->mUnk_00c;
    alpha = alpha < shadow->mAlphaCap ? alpha : shadow->mAlphaCap;
    polygonAttributes = polygonAttributes & ~0x1f0000;
    polygonAttributes = polygonAttributes | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &polygonAttributes, 1);
    NNS_G3dGeSendDL(&gObjShadowShape->mUnk_000[gObjShadowShape->mUnk_008], gObjShadowShape->mUnk_00c);
}

void DrawJgShadowWithMatrix(Vec3 *scale, MtxFx43 *matrix, u32 alphaCap, u32 maxAlpha) {
    gJgShadow->mAlpha = alphaCap < maxAlpha ? alphaCap : maxAlpha;
    DrawShadowWithMatrix(gJgShadow, matrix, scale);
}

void DrawJgShadow(u32 alphaCap, u32 maxAlpha) {
    gJgShadow->mAlpha = alphaCap < maxAlpha ? alphaCap : maxAlpha;
    DrawShadowModelIfDrawFlag(gJgShadow);
}

#pragma thumb on

void CreateObjShadowAndJgShadow(void) {
    NNSG3dResMdl *resMdl;
    NNSG3dResMat *resMat;
    NNSG3dResShp *resShp;

    CreateNsbmd(&gObjShadow, FindMainRaceOrMainEffectMapObjFile(gObjShadowNsbmdName), NULL);
    SetNsbmdPolygonIdAll(gObjShadow, 0x3f);
    SetNsbmdLightEnableFlagAll(gObjShadow, 0);
    resMdl = gObjShadow->mResMdl;
    resMat = OFFSET_PTR(NNSG3dResMat, resMdl, resMdl->mOfsMat);
    gObjShadowMaterial = OFFSET_PTR(Unk020e53ac, resMat, ((u32 *) OFFSET_PTR(u8, resMat, resMat->mDict.mOfsEntry))[2]);
    resMdl = gObjShadow->mResMdl;
    resShp = OFFSET_PTR(NNSG3dResShp, resMdl, resMdl->mOfsShp);
    gObjShadowShape = OFFSET_PTR(Unk020e54e4, resShp, ((u32 *) OFFSET_PTR(u8, resShp, resShp->mDict.mOfsEntry))[1]);
    if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        CreateShadowModel(&gJgShadow, FindSceneFile(gJgShadowNsbmdName), 0x3f);
    }
}

s32 RefreshShadowMatrix(ShadowMatrix *shadowCopy, Vec3 *position, s32 scale, u32 alphaCap) {
    Quaternion rotation;
    Vec3 direction;
    Vec3 raisedPosition;
    s32 scaleTenth;
    BOOL hit;

    raisedPosition = *position;
    hit = FALSE;
    raisedPosition.y = raisedPosition.y + 0x1999;
    if (CollideSphereWithCourse(&raisedPosition, NULL, 0, 0xa000, 8, -2, NULL, &direction, NULL, NULL, NULL, NULL, NULL,
                                NULL) != 0) {
        hit = TRUE;
        QuaternionFromYAxisToVec3(&direction, &rotation);
        Matrix3x3FromQuaternion(&shadowCopy->mMatrix.mUnk_00_m, &rotation);
        scaleTenth = scale / 10;
        shadowCopy->mMatrix.mUnk_00[0].x = ((s64) shadowCopy->mMatrix.mUnk_00[0].x * scaleTenth) >> 12;
        shadowCopy->mMatrix.mUnk_00[0].y = ((s64) shadowCopy->mMatrix.mUnk_00[0].y * scaleTenth) >> 12;
        shadowCopy->mMatrix.mUnk_00[0].z = ((s64) shadowCopy->mMatrix.mUnk_00[0].z * scaleTenth) >> 12;
        shadowCopy->mMatrix.mUnk_00[1].x = ((s64) shadowCopy->mMatrix.mUnk_00[1].x * scaleTenth) >> 12;
        shadowCopy->mMatrix.mUnk_00[1].y = ((s64) shadowCopy->mMatrix.mUnk_00[1].y * scaleTenth) >> 12;
        shadowCopy->mMatrix.mUnk_00[1].z = ((s64) shadowCopy->mMatrix.mUnk_00[1].z * scaleTenth) >> 12;
        shadowCopy->mMatrix.mUnk_00[2].x = ((s64) shadowCopy->mMatrix.mUnk_00[2].x * scaleTenth) >> 12;
        shadowCopy->mMatrix.mUnk_00[2].y = ((s64) shadowCopy->mMatrix.mUnk_00[2].y * scaleTenth) >> 12;
        shadowCopy->mMatrix.mUnk_00[2].z = ((s64) shadowCopy->mMatrix.mUnk_00[2].z * scaleTenth) >> 12;
    } else {
        MTX_Identity33_(&shadowCopy->mMatrix.mUnk_00_m);
    }
    shadowCopy->mMatrix.mUnk_00[3].x = raisedPosition.x >> 4;
    shadowCopy->mMatrix.mUnk_00[3].y = raisedPosition.y >> 4;
    shadowCopy->mMatrix.mUnk_00[3].z = raisedPosition.z >> 4;
    shadowCopy->mAlphaCap = alphaCap;
    return hit;
}

#pragma thumb off
