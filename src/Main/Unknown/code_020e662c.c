#include "Main/Unknown/code_020e662c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020d3b10.h"

#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6b58.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_021471bc.h"

// Copies the view matrix and builds its transposed rotation and three more matrices from it.
void bbm_updateBaseMatrices(MtxFx43 *viewMatrix) {
    data_0217b850->mUnk_00[0].x = 0x1000;
    data_0217b850->mUnk_00[0].y = 0;
    data_0217b850->mUnk_00[0].z = 0;
    data_0217b850->mUnk_00[1].x = 0;
    data_0217b850->mUnk_00[1].y = viewMatrix->mUnk_00[1].y;
    data_0217b850->mUnk_00[1].z = viewMatrix->mUnk_00[1].z;
    data_0217b850->mUnk_00[2].x = 0;
    data_0217b850->mUnk_00[2].y = -viewMatrix->mUnk_00[1].z;
    data_0217b850->mUnk_00[2].z = viewMatrix->mUnk_00[1].y;
    MTX_Transpose33_(viewMatrix, bbm_sBillboardMtx);
    MTX_Concat33((const s32 *) data_0217b850, (const s32 *) bbm_sBillboardMtx, (s32 *) bbm_sYBillboardMtx);
    {
        MtxFx43 *matrix;
        Vec3 *axis2;
        s32 axis2X;
        s32 axis2Z;

        matrix = data_0217b85c;
        axis2 = &matrix->mUnk_00[2];
        *axis2 = bbm_sBillboardMtx->mUnk_00[2];
        axis2X = matrix->mUnk_00[2].x;
        axis2Z = axis2->z;
        matrix->mUnk_00[0].z = -axis2X;
        matrix->mUnk_00[0].x = axis2Z;
        matrix->mUnk_00[0].y = 0;
    }
    if ((s64) data_0217b85c->mUnk_00[0].x * data_0217b85c->mUnk_00[0].x +
            (s64) data_0217b85c->mUnk_00[0].y * data_0217b85c->mUnk_00[0].y +
            (s64) data_0217b85c->mUnk_00[0].z * data_0217b85c->mUnk_00[0].z >=
        0x10) {
        vec_normalize(&data_0217b85c->mUnk_00[0], &data_0217b85c->mUnk_00[0]);
    }
    vec_crossProduct(&data_0217b85c->mUnk_00[2], &data_0217b85c->mUnk_00[0], &data_0217b85c->mUnk_00[1]);
    *bbm_sCameraMtx = *viewMatrix;
}

s32 bbm_setupCustomUpAxisBillboard(Vec3 *yAxis) {
    bbm_sCustomUpAxisBillboardMtx->mUnk_00[1] = *yAxis;
    bbm_sCustomUpAxisBillboardMtx->mUnk_00[2] = bbm_sYBillboardMtx->mUnk_00[2];
    vec_crossProduct(&bbm_sCustomUpAxisBillboardMtx->mUnk_00[1], &bbm_sCustomUpAxisBillboardMtx->mUnk_00[2], &bbm_sCustomUpAxisBillboardMtx->mUnk_00[0]);
    return vec_normalize(&bbm_sCustomUpAxisBillboardMtx->mUnk_00[0], &bbm_sCustomUpAxisBillboardMtx->mUnk_00[0]);
}

s32 bbm_20E6D34(Vec3 *yAxis, MtxFx43 *matrix) {
    matrix->mUnk_00[1] = *yAxis;
    matrix->mUnk_00[2] = bbm_sYBillboardMtx->mUnk_00[2];
    vec_crossProduct(&matrix->mUnk_00[1], &matrix->mUnk_00[2], &matrix->mUnk_00[0]);
    return vec_normalize(&matrix->mUnk_00[0], &matrix->mUnk_00[0]);
}

// Sets the position of bbm_sBillboardMtx to each component of a >> 4 and returns the matrix.
MtxFx43 *bbm_getBillboardAtPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = bbm_sBillboardMtx;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return bbm_sBillboardMtx;
}

MtxFx43 *bbm_getYBillboardAtPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = bbm_sYBillboardMtx;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return bbm_sYBillboardMtx;
}

MtxFx43 *bbm_getYBillboardAtPosTransformed(Vec3 *position, s32 horizontalFactor, s32 yOffset) {
    Vec3 *translation;

    bbm_sYBillboardMtx->mUnk_00[1].x = (horizontalFactor * bbm_sYBillboardMtx->mUnk_00[0].x) >> 12;
    bbm_sYBillboardMtx->mUnk_00[1].y = yOffset + 0x1000;
    bbm_sYBillboardMtx->mUnk_00[1].z = (horizontalFactor * bbm_sYBillboardMtx->mUnk_00[0].z) >> 12;
    translation = &bbm_sYBillboardMtx->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return bbm_sYBillboardMtx;
}

void bbm_20E6C0C(void) {
    bbm_sYBillboardMtx->mUnk_00[1].z = 0;
    bbm_sYBillboardMtx->mUnk_00[1].x = bbm_sYBillboardMtx->mUnk_00[1].z;
    bbm_sYBillboardMtx->mUnk_00[1].y = 0x1000;
}

MtxFx43 *bbm_getCustomUpAxisBillboardAtPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = bbm_sCustomUpAxisBillboardMtx;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return bbm_sCustomUpAxisBillboardMtx;
}

MtxFx43 *bbm_20E6B94(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = data_0217b85c;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return data_0217b85c;
}

// Sets the position of the translation-only matrix to each component of a >> 4 and returns the matrix.
MtxFx43 *bbm_20E6B58(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gTranslationMatrix;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gTranslationMatrix;
}

MtxFx43 *bbm_getYBillboardMtx(void) {
    return bbm_sYBillboardMtx;
}

void *bbm_getBillboardMtx(void) {
    return bbm_sBillboardMtx;
}

Vec3 *bbm_getBillboardRightVec(void) {
    return &bbm_sBillboardMtx->mUnk_00[0];
}

Vec3 *bbm_getBillboardForwardVec(void) {
    return &bbm_sBillboardMtx->mUnk_00[2];
}

void bbm_setDefaultMatParams(NsbmdModel *model) {
    model->mUnk_10 = (u32) ((((model->mUnk_10)) & (0x8000ffffu)));
    model->mUnk_10 = (u32) ((((model->mUnk_10)) | (0x294a0000u)));
    model->mUnk_14 = (model->mUnk_14 & ~(0x3f000000u));
    model->mUnk_14 = (model->mUnk_14 | (0x3f000000u));
    model->mUnk_14 = (model->mUnk_14 & ~(0xfu));
    model->mUnk_14 = (model->mUnk_14 | (0x2u));
}

void bbm_restoreCameraMtx(void) {
    u32 commandArg[1];
    NNS_G3dGeBufferOP_N(0x17, bbm_sCameraMtx, 0xc);
    commandArg[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x13, (void *) ((u32) commandArg), 1);
}

void bbm_applyMaterial(NsbmdModel *model) {
    if (model->mFrameCount == 1) {
        NNS_G3dGeBufferOP_N(0x2b, model->mUnk_20, 1);
        NNS_G3dGeBufferOP_N(0x2a, model->mUnk_1c, 1);
    }
    NNS_G3dGeBufferOP_N(0x30, &model->mUnk_0c, 1);
    NNS_G3dGeBufferOP_N(0x31, &model->mUnk_10, 1);
}

s32 bbm_calcDistanceAlpha(Vec3 *position) {
    MtxFx43 *viewMatrix;
    s64 zDot;

    viewMatrix = bbm_sCameraMtx;
    zDot = (s64) position->x * viewMatrix->mUnk_00[0].z + (s64) position->y * viewMatrix->mUnk_00[1].z +
           (s64) position->z * viewMatrix->mUnk_00[2].z;
    return -(viewMatrix->mUnk_00[3].z + (s32) (zDot >> 12)) >> 9;
}

void bbm_render(NsbmdModel *model, Vec3 *position, s32 usePosition, u32 maxAlpha) {
    u32 scale[3];
    u32 attributes;
    u32 currentAlpha;
    MtxFx43 *viewMatrix;
    s32 depthAlpha;
    u32 polygonId;
    s64 zDot;

    scale[0] = model->mUnk_08;
    scale[1] = scale[0];
    scale[2] = scale[0];
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    attributes = model->mUnk_14;
    currentAlpha = (attributes & 0x1f0000) >> 16;
    if (maxAlpha < currentAlpha) {
        attributes &= ~0x1f0000;
        attributes |= maxAlpha << 16;
        polygonId = mobj_getCyclicPolygonId();
        attributes &= 0xc0ffffff;
        attributes |= polygonId << 24;
    } else if (usePosition != 0) {
        viewMatrix = bbm_sCameraMtx;
        zDot = (s64) position->x * viewMatrix->mUnk_00[0].z + (s64) position->y * viewMatrix->mUnk_00[1].z +
               (s64) position->z * viewMatrix->mUnk_00[2].z;
        depthAlpha = -(viewMatrix->mUnk_00[3].z + (s32) (zDot >> 12)) >> 9;
        if (depthAlpha < currentAlpha) {
            if (depthAlpha == 0) {
                depthAlpha = 1;
            }
            attributes &= ~0x1f0000;
            attributes |= depthAlpha << 16;
            polygonId = mobj_getCyclicPolygonId();
            attributes &= 0xc0ffffff;
            attributes |= polygonId << 24;
        }
    }
    NNS_G3dGeBufferOP_N(0x29, &attributes, 1);
    if (model->mFrameCount != 1) {
        u16 frameIndex;

        frameIndex = model->mFrameIndex;
        NNS_G3dGeBufferOP_N(0x2b, model->mUnk_20 + frameIndex, 1);
        NNS_G3dGeBufferOP_N(0x2a, model->mUnk_1c + frameIndex, 1);
    }
    NNS_G3dGeSendDL(model->mUnk_00, model->mUnk_04);
}

void bbm_renderTransformedScaled(NsbmdModel *model, MtxFx43 *matrix, Vec3 *scale, s32 usePosition, u16 maxAlpha) {
    u32 commandArg;
    Vec3 scaleCopy;
    s32 scaleX;
    s32 scaleZ;
    s32 scaleY;

    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    if (scale != NULL) {
        scaleZ = scale->z;
        scaleY = scale->y;
        scaleX = scale->x;
        scaleCopy.x = scaleX;
        scaleCopy.y = scaleY;
        scaleCopy.z = scaleZ;
        NNS_G3dGeBufferOP_N(0x1b, &scaleCopy, 3);
    }
    bbm_render(model, &matrix->mUnk_00[3], usePosition, maxAlpha);
}

void bbm_renderTransformedRotatedScaled(NsbmdModel *model, MtxFx43 *matrix, s32 angle, Vec3 *scale, s32 usePosition, u16 maxAlpha) {
    u32 commandArg;
    Vec3 scaleCopy;
    s32 angleIndex;
    s32 scaleX;
    s32 scaleZ;
    s32 scaleY;

    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    if (angle != 0) {
        angleIndex = angle >> 4;
        MTX_RotZ33_(data_0217b858, FX_SinCosTable_[angleIndex * 2], FX_SinCosTable_[angleIndex * 2 + 1]);
        NNS_G3dGeBufferOP_N(0x1a, data_0217b858, 9);
    }
    if (scale != NULL) {
        scaleZ = scale->z;
        scaleY = scale->y;
        scaleX = scale->x;
        scaleCopy.x = scaleX;
        scaleCopy.y = scaleY;
        scaleCopy.z = scaleZ;
        NNS_G3dGeBufferOP_N(0x1b, &scaleCopy, 3);
    }
    bbm_render(model, &matrix->mUnk_00[3], usePosition, maxAlpha);
}

#pragma thumb on

void bbm_init(void) {
    void *matrix;
    matrix = heap_alloc(gSystemData->mHeap, 0x30);
    bbm_sBillboardMtx = matrix;
    matrix = heap_alloc(gSystemData->mHeap, 0x30);
    bbm_sYBillboardMtx = matrix;
    matrix = heap_alloc(gSystemData->mHeap, 0x30);
    data_0217b850 = matrix;
    matrix = heap_alloc(gSystemData->mHeap, 0x30);
    bbm_sCustomUpAxisBillboardMtx = matrix;
    matrix = heap_alloc(gSystemData->mHeap, 0x30);
    data_0217b85c = matrix;
    matrix = heap_alloc(gSystemData->mHeap, 0x30);
    gTranslationMatrix = matrix;
    matrix = heap_alloc(gSystemData->mHeap, 0x30);
    bbm_sCameraMtx = matrix;
    matrix = heap_alloc(gSystemData->mHeap, 0x24);
    data_0217b858 = matrix;
    MTX_Identity43_(gTranslationMatrix);
}

#pragma thumb off
