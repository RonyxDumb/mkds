#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d4c28.h"

#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_020ea000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "registers.h"
#include "Main/Unknown/code_020f9c6c.h"

#pragma thumb on

void FillNsbmdModel(Nsbmd *model, ModelAnimation *animation, NsbmdModel *record) {
    NNSG3dResMdl *resMdl;
    NNSG3dResMat *resMat;
    NNSG3dResShp *resShp;
    NNSG3dResMatData *matData;
    NNSG3dResShpData *shpData;
    Unk020e6514_8 frameWork;
    u16 frameCount;
    u16 frame;
    void *heap;
    enum { K0 } k;

    resMdl = model->mResMdl;
    resMat = OFFSET_PTR(NNSG3dResMat, resMdl, resMdl->mOfsMat);
    matData = OFFSET_PTR(NNSG3dResMatData, resMat, ((u32 *) OFFSET_PTR(u8, resMat, resMat->mDict.mOfsEntry))[2]);
    resShp = OFFSET_PTR(NNSG3dResShp, resMdl, resMdl->mOfsShp);
    shpData = OFFSET_PTR(NNSG3dResShpData, resShp, ((u32 *) OFFSET_PTR(u8, resShp, resShp->mDict.mOfsEntry))[1]);
    record->mDisplayList = (u8 *) shpData + shpData->mOfsDL;
    record->mDisplayListSize = shpData->mSizeDL;
    record->mScale = model->mResMdl->mInfo.mPosScale;
    record->mDiffAmb = matData->mDiffAmb;
    record->mSpecEmi = matData->mSpecEmi;
    record->mPolygonAttributes = matData->mPolyAttr & 0xfffffff0;
    record->mFrameIndex = 0;
    if (animation != NULL) {
        frameWork.mUnk_00 = matData->mTexImageParam;
        frameCount = GetModelAnimationFrameCountFixed(animation) >> 12;
        record->mFrameCount = frameCount;
        heap = GetHeap(GetCurrentHeapCall());
        record->mTexImageParams = HeapAlloc(heap, frameCount * 4);
        heap = GetHeap(GetCurrentHeapCall());
        record->mTexPlttBases = HeapAlloc(heap, frameCount * 4);
        frame = 0;
        if (frame < frameCount) {
            k = 0xc00f0000;
            frameWork.mUnk_00 &= k;
            frameWork.mUnk_04 = 0;
            do {
                animation->mHead.mFrameIndex = frame << 12;
                animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
                NNSi_G3dAnmCalcNsBtp(&frameWork.mUnk_08, animation->mAnmObjs[0], frameWork.mUnk_04);
                record->mTexImageParams[frame] = frameWork.mUnk_08.mUnk_10 & 0x3ff0ffff;
                record->mTexImageParams[frame] |= frameWork.mUnk_00;
                record->mTexPlttBases[frame] = frameWork.mUnk_08.mUnk_14;
                frame++;
            } while (frame < frameCount);
        }
    } else {
        record->mFrameCount = 1;
        record->mTexImageParams = HeapAlloc(GetHeap(GetCurrentHeapCall()), 4);
        record->mTexPlttBases = HeapAlloc(GetHeap(GetCurrentHeapCall()), 4);
        record->mTexImageParams[0] = matData->mTexImageParam;
        record->mTexPlttBases[0] = matData->mTexPlttBase;
    }
}

void InitNsbmdModel(NsbmdModel *record, void *nsbmdFile, void *nsbtpFile, s32 c) {
    record->mNsbmd = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x6c);
    InitNsbmd(record->mNsbmd, nsbmdFile);
    if (nsbtpFile != NULL) {
        record->mNsbtpAnimation = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
        InitModelAnimationWithEntries(2, record->mNsbmd, record->mNsbtpAnimation, nsbmdFile, nsbtpFile);
    } else {
        record->mNsbtpAnimation = NULL;
    }
    FillNsbmdModel(record->mNsbmd, record->mNsbtpAnimation, record);
}

void CreateNsbmdModel(NsbmdModel **recordSlot, void *nsbmdFile, void *nsbtpFile, u32 param_4) {
    *recordSlot = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    InitNsbmdModel(*recordSlot, nsbmdFile, nsbtpFile, param_4);
}

#pragma thumb off

MapObjectKindData *CreatePendulumKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_021592d0;
    return kindData;
}

MapObjectDrawList *CreatePendulumDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gPendulumDrawList = drawList;
    *drawList = data_021592a4;
    SetDrawListSlot(&gPendulumDrawList);
    return gPendulumDrawList;
}

MapObjectList *CreatePendulumUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gPendulumUpdateList = updateList;
    *updateList = data_0215927c;
    SetUpdateListSlot(&gPendulumUpdateList);
    return gPendulumUpdateList;
}

void DrawPendulum(u32 unused0, PendulumObject *pendulum, u32 unused1, u32 alpha) {
    pendulum->mMapObject.mMatrix.mRows[3].x = pendulum->mCourseRowPos.x >> 4;
    pendulum->mMapObject.mMatrix.mRows[3].y = pendulum->mCourseRowPos.y >> 4;
    pendulum->mMapObject.mMatrix.mRows[3].z = pendulum->mCourseRowPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gPendulum, &pendulum->mMapObject.mMatrix, &pendulum->mMapObject.mScale, alpha);
    DrawShadowWithMaxAlpha(gPendulumShadow, &pendulum->mShadowMatrix, &pendulum->mMapObject.mScale, alpha);
}

void UpdatePendulum(u32 list, PendulumObject *pendulum) {
    Quaternion swingRotation;
    SoundStartParams soundRequest;
    u32 previousAngle;
    u16 swingAngle;
    s32 falloffIndex;

    previousAngle = pendulum->mSwingAngle;
    pendulum->mSwingAngle = previousAngle + pendulum->mSwingAnglePerFrame;
    swingAngle = MUL_FIXED12_NO_ROUND((s32) pendulum->mSwingAmplitude, FX_SinIdx(pendulum->mSwingAngle));
    if ((previousAngle < 0x58f0 && pendulum->mSwingAngle >= 0x58f0) ||
        (previousAngle < 0xd8f0 && pendulum->mSwingAngle >= 0xd8f0)) {
        if ((pendulum->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
            if (pendulum->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                falloffIndex = 2;
            } else if (pendulum->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            soundRequest.mSoundId = 0x173;
            soundRequest.mPositionSource = &pendulum->mMapObject.mPos;
            soundRequest.mFalloffIndex = falloffIndex;
            soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&pendulum->mMapObject.mPos);
            StartSoundFromParams(&soundRequest);
        }
    }
    QuaternionMultiplyAngleAroundZ(&pendulum->mRotationQuaternion, swingAngle, &swingRotation);
    Matrix3x3FromQuaternion(&pendulum->mMapObject.mMatrix.mAxes, &swingRotation);
    VEC_MultAdd(-pendulum->mCourseRowDistance, &pendulum->mMapObject.mMatrix.mRows[1], &pendulum->mCourseRowPos,
                &pendulum->mMapObject.mPos);
    pendulum->mUnk_ec.x = pendulum->mMapObject.mPos.x >> 4;
    pendulum->mUnk_ec.y = pendulum->mMapObject.mPos.y >> 4;
    pendulum->mUnk_ec.z = pendulum->mMapObject.mPos.z >> 4;
    VEC_Subtract(&pendulum->mMapObject.mPos, &pendulum->mPrevPos, &pendulum->mMapObject.mPosStep);
    pendulum->mPrevPos = pendulum->mMapObject.mPos;
}

BOOL ComputeSphereHitOnPendulum(PendulumObject *pendulum, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *out) {
    Vec3 sphereOffset;
    s32 axisDistance;
    s32 axisOverlap;
    s32 d;
    s64 distanceSquared;

    VEC_Subtract(sphereCenter, &pendulum->mMapObject.mPos, &sphereOffset);
    axisDistance = Vec3DotUnrounded(&sphereOffset, &pendulum->mMapObject.mMatrix.mRows[2]);
    if (axisDistance > 0) {
        axisOverlap = pendulum->mHalfSizeZ + sphereRadius - axisDistance;
        if (axisOverlap < 0) {
            return FALSE;
        }
    } else {
        axisOverlap = -(pendulum->mHalfSizeZ + sphereRadius) - axisDistance;
        if (axisOverlap > 0) {
            return FALSE;
        }
    }
    d = sphereRadius + pendulum->mRadius;
    distanceSquared = (s64) sphereOffset.x * sphereOffset.x + (s64) sphereOffset.y * sphereOffset.y +
                      (s64) sphereOffset.z * sphereOffset.z;
    if (distanceSquared < (s64) d * d) {
        reg_CP_SQRTCNT = 1;
        reg_CP_SQRT_PARAM = distanceSquared;
        while (reg_CP_SQRTCNT & 0x8000) {
        }
        d -= reg_CP_SQRT_RESULT;
    } else {
        return FALSE;
    }
    if ((axisOverlap > 0 ? axisOverlap : -axisOverlap) < d) {
        out->x = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mMatrix.mRows[2].x, axisOverlap);
        out->y = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mMatrix.mRows[2].y, axisOverlap);
        out->z = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mMatrix.mRows[2].z, axisOverlap);
        pendulum->mUnk_10c = FALSE;
    } else {
        if (sphereOffset.y < 0) {
            sphereOffset.y = 0;
        }
        distanceSquared = (s64) sphereOffset.x * sphereOffset.x + (s64) sphereOffset.y * sphereOffset.y +
                          (s64) sphereOffset.z * sphereOffset.z;
        if (distanceSquared >= 16) {
            Vec3NormalizeAndGetLengthUnchecked(&sphereOffset, &sphereOffset);
        }
        out->x = MUL_FIXED12_NO_ROUND(sphereOffset.x, d);
        out->y = MUL_FIXED12_NO_ROUND(sphereOffset.y, d);
        out->z = MUL_FIXED12_NO_ROUND(sphereOffset.z, d);
        pendulum->mUnk_10c = TRUE;
    }
    return TRUE;
}

#pragma thumb on

void CreatePendulumAndPendulumShadow(void) {
    CreateNsbmd(&gPendulum, FindCourseMapObjFile(gPendulumNsbmdName), NULL);
    CreateShadowModel(&gPendulumShadow, FindCourseMapObjFile(gPendulumShadowNsbmdName), 0x3f);
    SetNsbmdPolygonIdLightEmiAll(gPendulum, 0x3f, 2, 0x294a);
}

void InitPendulum(PendulumObject *pendulum, CourseMapRow *courseRow) {
    s32 amplitudeSetting;

    pendulum->mMapObject.mExtent.y =
        MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mKindData->mUnk_10, courseRow->mUnk_18.z);
    QuaternionFromVec3Degrees(&courseRow->mUnk_0c, &pendulum->mRotationQuaternion);
    pendulum->mShadowMatrix = pendulum->mMapObject.mMatrix.mAxes;
    pendulum->mCourseRowDistance = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mScale.y, 0x1f4000);
    pendulum->mSwingAngle = 0;
    pendulum->mCourseRowPos.x = courseRow->mUnk_00.x;
    pendulum->mCourseRowPos.y = courseRow->mUnk_00.y;
    pendulum->mCourseRowPos.z = courseRow->mUnk_00.z;
    VEC_MultAdd(-pendulum->mCourseRowDistance, &pendulum->mMapObject.mMatrix.mRows[1], &pendulum->mCourseRowPos,
                &pendulum->mMapObject.mPos);
    pendulum->mPrevPos = pendulum->mMapObject.mPos;
    pendulum->mUnk_ec.x = pendulum->mMapObject.mPos.x >> 4;
    pendulum->mUnk_ec.y = pendulum->mMapObject.mPos.y >> 4;
    pendulum->mUnk_ec.z = pendulum->mMapObject.mPos.z >> 4;
    amplitudeSetting = courseRow->mUnk_2a;
    pendulum->mSwingAnglePerFrame = 0x640000u / (u32) courseRow->mUnk_28 / 0xf0u;
    pendulum->mSwingAmplitude = (u32) (amplitudeSetting * 0x1111) / 0x64u;
    pendulum->mRadius = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mScale.x, 0x64000);
    pendulum->mHalfSizeZ = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mScale.z, 0x32000);
    pendulum->mUnk_10c = FALSE;
}

#pragma thumb off

MapObjectKindData *CreateObPakkunSfKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02159208;
    return kindData;
}

MapObjectDrawList *CreateObPakkunSfDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gObPakkunSfDrawList = drawList;
    *drawList = data_021591dc;
    SetDrawListSlot(&gObPakkunSfDrawList);
    return gObPakkunSfDrawList;
}

MapObjectList *CreateObPakkunSfUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gObPakkunSfUpdateList = updateList;
    *updateList = data_021591b4;
    return updateList;
}

void SetupDrawObPakkunSf(void) {
    QueueNsbmdModelMaterial(gObPakkunSf);
}
