#include "Main/MapObjects/view_matrices.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/view_frustum.h"

#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/MapObjects/pendulum.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "model_material_set.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "matrix_3x3_basic.h"
#include "Main/Kart/kart_drift.h"
#include "matrix_4x3_basic.h"
#include "fixed_vector_math.h"

MtxFx43 *gViewRotatedMatrix;
MtxFx43 *gTranslationMatrix;
MtxFx43 *gViewTransposeMatrix;
MtxFx43 *gYAxisMatrix;
MtxFx43 *gViewRotationXMatrix;
MtxFx43 *gViewMatrix;
MtxFx33 *gRotationZMatrix;
MtxFx43 *gViewAxis2Matrix;

// Copies the view matrix and builds its transposed rotation and three more matrices from it.
void SetViewMatrices(MtxFx43 *viewMatrix) {
    gViewRotationXMatrix->mRows[0].x = 0x1000;
    gViewRotationXMatrix->mRows[0].y = 0;
    gViewRotationXMatrix->mRows[0].z = 0;
    gViewRotationXMatrix->mRows[1].x = 0;
    gViewRotationXMatrix->mRows[1].y = viewMatrix->mRows[1].y;
    gViewRotationXMatrix->mRows[1].z = viewMatrix->mRows[1].z;
    gViewRotationXMatrix->mRows[2].x = 0;
    gViewRotationXMatrix->mRows[2].y = -viewMatrix->mRows[1].z;
    gViewRotationXMatrix->mRows[2].z = viewMatrix->mRows[1].y;
    MTX_Transpose33_(viewMatrix, gViewTransposeMatrix);
    MTX_Concat33(&gViewRotationXMatrix->mAxes, &gViewTransposeMatrix->mAxes, &gViewRotatedMatrix->mAxes);
    {
        MtxFx43 *matrix;
        Vec3 *axis2;
        s32 axis2X;
        s32 axis2Z;

        matrix = gViewAxis2Matrix;
        axis2 = &matrix->mRows[2];
        *axis2 = gViewTransposeMatrix->mRows[2];
        axis2X = matrix->mRows[2].x;
        axis2Z = axis2->z;
        matrix->mRows[0].z = -axis2X;
        matrix->mRows[0].x = axis2Z;
        matrix->mRows[0].y = 0;
    }
    if ((s64) gViewAxis2Matrix->mRows[0].x * gViewAxis2Matrix->mRows[0].x +
            (s64) gViewAxis2Matrix->mRows[0].y * gViewAxis2Matrix->mRows[0].y +
            (s64) gViewAxis2Matrix->mRows[0].z * gViewAxis2Matrix->mRows[0].z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&gViewAxis2Matrix->mRows[0], &gViewAxis2Matrix->mRows[0]);
    }
    Vec3CrossUnrounded(&gViewAxis2Matrix->mRows[2], &gViewAxis2Matrix->mRows[0], &gViewAxis2Matrix->mRows[1]);
    *gViewMatrix = *viewMatrix;
}

s32 BuildYAxisMatrix(Vec3 *yAxis) {
    gYAxisMatrix->mRows[1] = *yAxis;
    gYAxisMatrix->mRows[2] = gViewRotatedMatrix->mRows[2];
    Vec3CrossUnrounded(&gYAxisMatrix->mRows[1], &gYAxisMatrix->mRows[2], &gYAxisMatrix->mRows[0]);
    return Vec3NormalizeAndGetLengthUnchecked(&gYAxisMatrix->mRows[0], &gYAxisMatrix->mRows[0]);
}

s32 BuildMatrixFromYAxis(Vec3 *yAxis, MtxFx43 *matrix) {
    matrix->mRows[1] = *yAxis;
    matrix->mRows[2] = gViewRotatedMatrix->mRows[2];
    Vec3CrossUnrounded(&matrix->mRows[1], &matrix->mRows[2], &matrix->mRows[0]);
    return Vec3NormalizeAndGetLengthUnchecked(&matrix->mRows[0], &matrix->mRows[0]);
}

// Sets the position of gViewTransposeMatrix to each component of a >> 4 and returns the matrix.
MtxFx43 *SetViewTransposeMatrixPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gViewTransposeMatrix;
    translation = &matrix->mRows[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gViewTransposeMatrix;
}

MtxFx43 *SetViewRotatedMatrixPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gViewRotatedMatrix;
    translation = &matrix->mRows[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gViewRotatedMatrix;
}

MtxFx43 *TiltViewRotatedMatrix(Vec3 *position, s32 horizontalFactor, s32 yOffset) {
    Vec3 *translation;

    gViewRotatedMatrix->mRows[1].x = (horizontalFactor * gViewRotatedMatrix->mRows[0].x) >> 12;
    gViewRotatedMatrix->mRows[1].y = yOffset + 0x1000;
    gViewRotatedMatrix->mRows[1].z = (horizontalFactor * gViewRotatedMatrix->mRows[0].z) >> 12;
    translation = &gViewRotatedMatrix->mRows[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gViewRotatedMatrix;
}

void ResetViewRotatedMatrixAxis1(void) {
    gViewRotatedMatrix->mRows[1].z = 0;
    gViewRotatedMatrix->mRows[1].x = gViewRotatedMatrix->mRows[1].z;
    gViewRotatedMatrix->mRows[1].y = 0x1000;
}

MtxFx43 *SetYAxisMatrixPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gYAxisMatrix;
    translation = &matrix->mRows[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gYAxisMatrix;
}

MtxFx43 *SetViewAxis2MatrixPos(Vec3 *position) {
    MtxFx43 *matrix;
    Vec3 *translation;

    matrix = gViewAxis2Matrix;
    translation = &matrix->mRows[3];
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
    translation = &matrix->mRows[3];
    translation->x = position->x >> 4;
    translation->y = position->y >> 4;
    translation->z = position->z >> 4;
    return gTranslationMatrix;
}

MtxFx43 *GetViewRotatedMatrix(void) {
    return gViewRotatedMatrix;
}

MtxFx43 *GetViewTransposeMatrix(void) {
    return gViewTransposeMatrix;
}

Vec3 *GetViewTransposeMatrixAxis0(void) {
    return &gViewTransposeMatrix->mRows[0];
}

Vec3 *GetViewTransposeMatrixAxis2(void) {
    return &gViewTransposeMatrix->mRows[2];
}

void SetNsbmdModelFixedAttributes(NsbmdModel *model) {
    model->mSpecEmi = (u32) ((((model->mSpecEmi)) & (0x8000ffffu)));
    model->mSpecEmi = (u32) ((((model->mSpecEmi)) | (0x294a0000u)));
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
        NNS_G3dGeBufferOP_N(0x2b, model->mTexPlttBases, 1);
        NNS_G3dGeBufferOP_N(0x2a, model->mTexImageParams, 1);
    }
    NNS_G3dGeBufferOP_N(0x30, &model->mDiffAmb, 1);
    NNS_G3dGeBufferOP_N(0x31, &model->mSpecEmi, 1);
}

s32 ComputeViewDepthAlpha(Vec3 *position) {
    MtxFx43 *viewMatrix;
    s64 zDot;

    viewMatrix = gViewMatrix;
    zDot = (s64) position->x * viewMatrix->mRows[0].z + (s64) position->y * viewMatrix->mRows[1].z +
           (s64) position->z * viewMatrix->mRows[2].z;
    return -(viewMatrix->mRows[3].z + (s32) FROM_FIXED12(zDot)) >> 9;
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
        zDot = (s64) position->x * viewMatrix->mRows[0].z + (s64) position->y * viewMatrix->mRows[1].z +
               (s64) position->z * viewMatrix->mRows[2].z;
        depthAlpha = -(viewMatrix->mRows[3].z + (s32) FROM_FIXED12(zDot)) >> 9;
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
        NNS_G3dGeBufferOP_N(0x2b, model->mTexPlttBases + frameIndex, 1);
        NNS_G3dGeBufferOP_N(0x2a, model->mTexImageParams + frameIndex, 1);
    }
    NNS_G3dGeSendDL(model->mDisplayList, model->mDisplayListSize);
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
    DrawNsbmdModelWithMaxAlpha(model, &matrix->mRows[3], usePosition, maxAlpha);
}

void DrawNsbmdModelWithMatrixAndAngle(NsbmdModel *model, MtxFx43 *matrix, s32 angle, Vec3 *scale, s32 usePosition,
                                      u16 maxAlpha) {
    u32 commandArg;
    Vec3 scaleCopy;
    s32 scaleX;
    s32 scaleZ;
    s32 scaleY;

    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    if (angle != 0) {
        MTX_RotZ33_(gRotationZMatrix, SIN_OF_ANGLE(angle), COS_OF_ANGLE(angle));
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
    DrawNsbmdModelWithMaxAlpha(model, &matrix->mRows[3], usePosition, maxAlpha);
}

#pragma thumb on

void InitMatrices(void) {
    void *matrix;
    matrix = HeapAlloc(gStartupWork->mHeap, sizeof(MtxFx43));
    gViewTransposeMatrix = matrix;
    matrix = HeapAlloc(gStartupWork->mHeap, sizeof(MtxFx43));
    gViewRotatedMatrix = matrix;
    matrix = HeapAlloc(gStartupWork->mHeap, sizeof(MtxFx43));
    gViewRotationXMatrix = matrix;
    matrix = HeapAlloc(gStartupWork->mHeap, sizeof(MtxFx43));
    gYAxisMatrix = matrix;
    matrix = HeapAlloc(gStartupWork->mHeap, sizeof(MtxFx43));
    gViewAxis2Matrix = matrix;
    matrix = HeapAlloc(gStartupWork->mHeap, sizeof(MtxFx43));
    gTranslationMatrix = matrix;
    matrix = HeapAlloc(gStartupWork->mHeap, sizeof(MtxFx43));
    gViewMatrix = matrix;
    matrix = HeapAlloc(gStartupWork->mHeap, sizeof(MtxFx33));
    gRotationZMatrix = matrix;
    MTX_Identity43_(gTranslationMatrix);
}

#pragma thumb off
