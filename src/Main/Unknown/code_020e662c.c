#include "Main/Unknown/code_020e662c.h"
#include "Main/Unknown/code_02036820.h"
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
void SetViewMatrices(MtxFx43 *viewMatrix) {
    gViewRotationXMatrix->mUnk_00[0].x = 0x1000;
    gViewRotationXMatrix->mUnk_00[0].y = 0;
    gViewRotationXMatrix->mUnk_00[0].z = 0;
    gViewRotationXMatrix->mUnk_00[1].x = 0;
    gViewRotationXMatrix->mUnk_00[1].y = viewMatrix->mUnk_00[1].y;
    gViewRotationXMatrix->mUnk_00[1].z = viewMatrix->mUnk_00[1].z;
    gViewRotationXMatrix->mUnk_00[2].x = 0;
    gViewRotationXMatrix->mUnk_00[2].y = -viewMatrix->mUnk_00[1].z;
    gViewRotationXMatrix->mUnk_00[2].z = viewMatrix->mUnk_00[1].y;
    MTX_Transpose33_(viewMatrix, gViewTransposeMatrix);
    MTX_Concat33(&gViewRotationXMatrix->mUnk_00_m, &gViewTransposeMatrix->mUnk_00_m, &gViewRotatedMatrix->mUnk_00_m);
    {
        MtxFx43 *matrix;
        Vec3 *axis2;
        s32 axis2X;
        s32 axis2Z;

        matrix = gViewAxis2Matrix;
        axis2 = &matrix->mUnk_00[2];
        *axis2 = gViewTransposeMatrix->mUnk_00[2];
        axis2X = matrix->mUnk_00[2].x;
        axis2Z = axis2->z;
        matrix->mUnk_00[0].z = -axis2X;
        matrix->mUnk_00[0].x = axis2Z;
        matrix->mUnk_00[0].y = 0;
    }
    if ((s64) gViewAxis2Matrix->mUnk_00[0].x * gViewAxis2Matrix->mUnk_00[0].x +
            (s64) gViewAxis2Matrix->mUnk_00[0].y * gViewAxis2Matrix->mUnk_00[0].y +
            (s64) gViewAxis2Matrix->mUnk_00[0].z * gViewAxis2Matrix->mUnk_00[0].z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewAxis2Matrix->mUnk_00[0], &gViewAxis2Matrix->mUnk_00[0]);
    }
    Vec3CrossUnrounded(&gViewAxis2Matrix->mUnk_00[2], &gViewAxis2Matrix->mUnk_00[0], &gViewAxis2Matrix->mUnk_00[1]);
    *gViewMatrix = *viewMatrix;
}

s32 BuildYAxisMatrix(Vec3 *yAxis) {
    gYAxisMatrix->mUnk_00[1] = *yAxis;
    gYAxisMatrix->mUnk_00[2] = gViewRotatedMatrix->mUnk_00[2];
    Vec3CrossUnrounded(&gYAxisMatrix->mUnk_00[1], &gYAxisMatrix->mUnk_00[2], &gYAxisMatrix->mUnk_00[0]);
    return Vec3NormalizeAndGetLengthUnchecked(&gYAxisMatrix->mUnk_00[0], &gYAxisMatrix->mUnk_00[0]);
}

s32 BuildMatrixFromYAxis(Vec3 *yAxis, MtxFx43 *matrix) {
    matrix->mUnk_00[1] = *yAxis;
    matrix->mUnk_00[2] = gViewRotatedMatrix->mUnk_00[2];
    Vec3CrossUnrounded(&matrix->mUnk_00[1], &matrix->mUnk_00[2], &matrix->mUnk_00[0]);
    return Vec3NormalizeAndGetLengthUnchecked(&matrix->mUnk_00[0], &matrix->mUnk_00[0]);
}

// Sets the position of gViewTransposeMatrix to each component of a >> 4 and returns the matrix.
MtxFx43 *SetViewTransposeMatrixPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gViewTransposeMatrix;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gViewTransposeMatrix;
}

MtxFx43 *SetViewRotatedMatrixPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gViewRotatedMatrix;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gViewRotatedMatrix;
}

MtxFx43 *TiltViewRotatedMatrix(Vec3 *position, s32 horizontalFactor, s32 yOffset) {
    Vec3 *translation;

    gViewRotatedMatrix->mUnk_00[1].x = (horizontalFactor * gViewRotatedMatrix->mUnk_00[0].x) >> 12;
    gViewRotatedMatrix->mUnk_00[1].y = yOffset + 0x1000;
    gViewRotatedMatrix->mUnk_00[1].z = (horizontalFactor * gViewRotatedMatrix->mUnk_00[0].z) >> 12;
    translation = &gViewRotatedMatrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gViewRotatedMatrix;
}

void ResetViewRotatedMatrixAxis1(void) {
    gViewRotatedMatrix->mUnk_00[1].z = 0;
    gViewRotatedMatrix->mUnk_00[1].x = gViewRotatedMatrix->mUnk_00[1].z;
    gViewRotatedMatrix->mUnk_00[1].y = 0x1000;
}

MtxFx43 *SetYAxisMatrixPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gYAxisMatrix;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gYAxisMatrix;
}

MtxFx43 *SetViewAxis2MatrixPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gViewAxis2Matrix;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gViewAxis2Matrix;
}

// Sets the position of the translation-only matrix to each component of a >> 4 and returns the matrix.
MtxFx43 *SetTranslationMatrixPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gTranslationMatrix;
    translation = &matrix->mUnk_00[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gTranslationMatrix;
}

MtxFx43 *GetViewRotatedMatrix(void) {
    return gViewRotatedMatrix;
}

void *GetViewTransposeMatrix(void) {
    return gViewTransposeMatrix;
}

Vec3 *GetViewTransposeMatrixAxis0(void) {
    return &gViewTransposeMatrix->mUnk_00[0];
}

Vec3 *GetViewTransposeMatrixAxis2(void) {
    return &gViewTransposeMatrix->mUnk_00[2];
}

void SetNsbmdModelFixedAttributes(NsbmdModel *model) {
    model->mUnk_10 = (u32) ((((model->mUnk_10)) & (0x8000ffffu)));
    model->mUnk_10 = (u32) ((((model->mUnk_10)) | (0x294a0000u)));
    model->mPolygonAttributes = (model->mPolygonAttributes & ~(0x3f000000u));
    model->mPolygonAttributes = (model->mPolygonAttributes | (0x3f000000u));
    model->mPolygonAttributes = (model->mPolygonAttributes & ~(0xfu));
    model->mPolygonAttributes = (model->mPolygonAttributes | (0x2u));
}

void QueueViewMatrix(void) {
    u32 commandArg[1];
    NNS_G3dGeBufferOP_N(0x17, gViewMatrix, 0xc);
    commandArg[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x13, (void *) ((u32) commandArg), 1);
}

void QueueNsbmdModelMaterial(NsbmdModel *model) {
    if (model->mFrameCount == 1) {
        NNS_G3dGeBufferOP_N(0x2b, model->mUnk_20, 1);
        NNS_G3dGeBufferOP_N(0x2a, model->mUnk_1c, 1);
    }
    NNS_G3dGeBufferOP_N(0x30, &model->mUnk_0c, 1);
    NNS_G3dGeBufferOP_N(0x31, &model->mUnk_10, 1);
}

s32 ComputeViewDepthAlpha(Vec3 *position) {
    MtxFx43 *viewMatrix;
    s64 zDot;

    viewMatrix = gViewMatrix;
    zDot = (s64) position->x * viewMatrix->mUnk_00[0].z + (s64) position->y * viewMatrix->mUnk_00[1].z +
           (s64) position->z * viewMatrix->mUnk_00[2].z;
    return -(viewMatrix->mUnk_00[3].z + (s32) (zDot >> 12)) >> 9;
}

void DrawNsbmdModelWithMaxAlpha(NsbmdModel *model, Vec3 *position, s32 usePosition, u32 maxAlpha) {
    u32 scale[3];
    u32 attributes;
    u32 currentAlpha;
    MtxFx43 *viewMatrix;
    s32 depthAlpha;
    u32 polygonId;
    s64 zDot;

    scale[0] = model->mScale;
    scale[1] = scale[0];
    scale[2] = scale[0];
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    attributes = model->mPolygonAttributes;
    currentAlpha = (attributes & 0x1f0000) >> 16;
    if (maxAlpha < currentAlpha) {
        attributes &= ~0x1f0000;
        attributes |= maxAlpha << 16;
        polygonId = AllocPolygonIdWrapping();
        attributes &= 0xc0ffffff;
        attributes |= polygonId << 24;
    } else if (usePosition != 0) {
        viewMatrix = gViewMatrix;
        zDot = (s64) position->x * viewMatrix->mUnk_00[0].z + (s64) position->y * viewMatrix->mUnk_00[1].z +
               (s64) position->z * viewMatrix->mUnk_00[2].z;
        depthAlpha = -(viewMatrix->mUnk_00[3].z + (s32) (zDot >> 12)) >> 9;
        if (depthAlpha < currentAlpha) {
            if (depthAlpha == 0) {
                depthAlpha = 1;
            }
            attributes &= ~0x1f0000;
            attributes |= depthAlpha << 16;
            polygonId = AllocPolygonIdWrapping();
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

void DrawNsbmdModelWithMatrixAndMaxAlpha(NsbmdModel *model, MtxFx43 *matrix, Vec3 *scale, s32 usePosition,
                                         u16 maxAlpha) {
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
    DrawNsbmdModelWithMaxAlpha(model, &matrix->mUnk_00[3], usePosition, maxAlpha);
}

void DrawNsbmdModelWithMatrixAndAngle(NsbmdModel *model, MtxFx43 *matrix, s32 angle, Vec3 *scale, s32 usePosition,
                                      u16 maxAlpha) {
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
        MTX_RotZ33_(gRotationZMatrix, gPairsByAngle[angleIndex * 2], gPairsByAngle[angleIndex * 2 + 1]);
        NNS_G3dGeBufferOP_N(0x1a, gRotationZMatrix, 9);
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
    DrawNsbmdModelWithMaxAlpha(model, &matrix->mUnk_00[3], usePosition, maxAlpha);
}

#pragma thumb on

void InitMatrices(void) {
    void *matrix;
    matrix = HeapAlloc(data_021759d0->mHeap, 0x30);
    gViewTransposeMatrix = matrix;
    matrix = HeapAlloc(data_021759d0->mHeap, 0x30);
    gViewRotatedMatrix = matrix;
    matrix = HeapAlloc(data_021759d0->mHeap, 0x30);
    gViewRotationXMatrix = matrix;
    matrix = HeapAlloc(data_021759d0->mHeap, 0x30);
    gYAxisMatrix = matrix;
    matrix = HeapAlloc(data_021759d0->mHeap, 0x30);
    gViewAxis2Matrix = matrix;
    matrix = HeapAlloc(data_021759d0->mHeap, 0x30);
    gTranslationMatrix = matrix;
    matrix = HeapAlloc(data_021759d0->mHeap, 0x30);
    gViewMatrix = matrix;
    matrix = HeapAlloc(data_021759d0->mHeap, 0x24);
    gRotationZMatrix = matrix;
    MTX_Identity43_(gTranslationMatrix);
}

#pragma thumb off
