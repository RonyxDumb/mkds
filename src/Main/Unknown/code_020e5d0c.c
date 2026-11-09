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

#pragma thumb on

void func_020e6514(Nsbmd *model, Unk020e6514 *animation, NsbmdModel *record) {
    NNSG3dResMdl *a;
    NNSG3dResMat *b;
    NNSG3dResShp *c;
    Unk020e53ac *d;
    Unk020e54e4 *e;
    Unk020e6514_8 x;
    u16 frameCount;
    u16 frame;
    void *t;
    enum { K0 } k;

    a = model->mResMdl;
    b = OFFSET_PTR(NNSG3dResMat, a, a->mOfsMat);
    d = OFFSET_PTR(Unk020e53ac, b, ((u32 *) OFFSET_PTR(u8, b, b->mDict.mOfsEntry))[2]);
    c = OFFSET_PTR(NNSG3dResShp, a, a->mOfsShp);
    e = OFFSET_PTR(Unk020e54e4, c, ((u32 *) OFFSET_PTR(u8, c, c->mDict.mOfsEntry))[1]);
    record->mUnk_00 = &e->mUnk_000[e->mUnk_008];
    record->mUnk_04 = e->mUnk_00c;
    record->mScale = model->mResMdl->mInfo.mPosScale;
    record->mUnk_0c = d->mUnk_004;
    record->mUnk_10 = d->mUnk_008;
    record->mPolygonAttributes = d->mUnk_00c & 0xfffffff0;
    record->mFrameIndex = 0;
    if (animation != NULL) {
        x.mUnk_00 = d->mUnk_014;
        frameCount = GetModelAnimationFrameCountFixed(animation) >> 12;
        record->mFrameCount = frameCount;
        t = GetHeap(GetCurrentHeapCall());
        record->mUnk_1c = HeapAlloc(t, frameCount * 4);
        t = GetHeap(GetCurrentHeapCall());
        record->mUnk_20 = HeapAlloc(t, frameCount * 4);
        frame = 0;
        if (frame < frameCount) {
            k = 0xc00f0000;
            x.mUnk_00 &= k;
            x.mUnk_04 = 0;
            do {
                animation->mUnk_00c = frame << 12;
                animation->mUnk_1c[animation->mUnk_1a]->mFrame = animation->mUnk_00c;
                NNSi_G3dAnmCalcNsBtp(&x.mUnk_08, animation->mUnk_1c[0], x.mUnk_04);
                record->mUnk_1c[frame] = x.mUnk_08.mUnk_10 & 0x3ff0ffff;
                record->mUnk_1c[frame] |= x.mUnk_00;
                record->mUnk_20[frame] = x.mUnk_08.mUnk_14;
                frame++;
            } while (frame < frameCount);
        }
    } else {
        record->mFrameCount = 1;
        record->mUnk_1c = HeapAlloc(GetHeap(GetCurrentHeapCall()), 4);
        record->mUnk_20 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 4);
        record->mUnk_1c[0] = d->mUnk_014;
        record->mUnk_20[0] = d->mUnk_01c;
    }
}

void func_020e64b8(NsbmdModel *record, void *nsbmdFile, void *nsbtpFile, s32 c) {
    record->mUnk_24 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x6c);
    InitNsbmd(record->mUnk_24, nsbmdFile);
    if (nsbtpFile != NULL) {
        record->mUnk_28 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
        InitModelAnimationWithEntries(2, record->mUnk_24, record->mUnk_28, nsbmdFile, nsbtpFile);
    } else {
        record->mUnk_28 = NULL;
    }
    func_020e6514(record->mUnk_24, record->mUnk_28, record);
}

void func_020e6488(NsbmdModel **recordSlot, void *nsbmdFile, void *nsbtpFile, u32 param_4) {
    *recordSlot = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    func_020e64b8(*recordSlot, nsbmdFile, nsbtpFile, param_4);
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
    data_0217b840 = drawList;
    *drawList = data_021592a4;
    SetDrawListSlot(&data_0217b840);
    return data_0217b840;
}

MapObjectList *CreatePendulumUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b834 = updateList;
    *updateList = data_0215927c;
    SetUpdateListSlot(&data_0217b834);
    return data_0217b834;
}

void DrawPendulum(u32 param_1, PendulumObject *pendulum, u32 param_3, u32 alpha) {
    pendulum->mMapObject.mMatrix.mUnk_00[3].x = pendulum->mCourseRowPos.x >> 4;
    pendulum->mMapObject.mMatrix.mUnk_00[3].y = pendulum->mCourseRowPos.y >> 4;
    pendulum->mMapObject.mMatrix.mUnk_00[3].z = pendulum->mCourseRowPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gPendulum, &pendulum->mMapObject.mMatrix, &pendulum->mMapObject.mScale, alpha);
    DrawShadowWithMaxAlpha(gPendulumShadow, &pendulum->mShadowMatrix, &pendulum->mMapObject.mScale, alpha);
}

void UpdatePendulum(u32 param_1, PendulumObject *pendulum) {
    u32 swingRotation[4];
    Unk0210b7a8 soundRequest;
    u32 previousAngle;
    u16 swingAngle;
    s32 falloffIndex;

    previousAngle = pendulum->mSwingAngle;
    pendulum->mSwingAngle = previousAngle + pendulum->mSwingAnglePerFrame;
    swingAngle = ((s64) (s32) pendulum->mSwingAmplitude * gPairsByAngle[(pendulum->mSwingAngle >> 4) * 2]) >> 12;
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
            soundRequest.mUnk_08 = falloffIndex;
            soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&pendulum->mMapObject.mPos);
            func_0210b7a8(&soundRequest);
        }
    }
    QuaternionMultiplyAngleAroundZ(&pendulum->mRotationQuaternion, swingAngle, swingRotation);
    Matrix3x3FromQuaternion(&pendulum->mMapObject.mMatrix.mUnk_00_m, swingRotation);
    VEC_MultAdd(-pendulum->mCourseRowDistance, &pendulum->mMapObject.mMatrix.mUnk_00[1], &pendulum->mCourseRowPos,
                &pendulum->mMapObject.mPos);
    pendulum->mUnk_ec.x = pendulum->mMapObject.mPos.x >> 4;
    pendulum->mUnk_ec.y = pendulum->mMapObject.mPos.y >> 4;
    pendulum->mUnk_ec.z = pendulum->mMapObject.mPos.z >> 4;
    VEC_Subtract(&pendulum->mMapObject.mPos, &pendulum->mPrevPos, &pendulum->mMapObject.mUnk_10);
    pendulum->mPrevPos = pendulum->mMapObject.mPos;
}

BOOL ComputeSphereHitOnPendulum(PendulumObject *pendulum, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *out) {
    Vec3 v;
    s32 axisDistance;
    s32 t;
    s32 d;
    s64 distanceSquared;

    VEC_Subtract(sphereCenter, &pendulum->mMapObject.mPos, &v);
    axisDistance = Vec3DotUnrounded(&v, &pendulum->mMapObject.mMatrix.mUnk_00[2]);
    if (axisDistance > 0) {
        t = pendulum->mHalfSizeZ + sphereRadius - axisDistance;
        if (t < 0) {
            return FALSE;
        }
    } else {
        t = -(pendulum->mHalfSizeZ + sphereRadius) - axisDistance;
        if (t > 0) {
            return FALSE;
        }
    }
    d = sphereRadius + pendulum->mRadius;
    distanceSquared = (s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z;
    if (distanceSquared < (s64) d * d) {
        reg_CP_SQRTCNT = 1;
        reg_CP_SQRT_PARAM = distanceSquared;
        while (reg_CP_SQRTCNT & 0x8000) {
        }
        d -= reg_CP_SQRT_RESULT;
    } else {
        return FALSE;
    }
    if ((t > 0 ? t : -t) < d) {
        out->x = ((s64) pendulum->mMapObject.mMatrix.mUnk_00[2].x * t) >> 12;
        out->y = ((s64) pendulum->mMapObject.mMatrix.mUnk_00[2].y * t) >> 12;
        out->z = ((s64) pendulum->mMapObject.mMatrix.mUnk_00[2].z * t) >> 12;
        pendulum->mUnk_10c = FALSE;
    } else {
        if (v.y < 0) {
            v.y = 0;
        }
        distanceSquared = (s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z;
        if (distanceSquared >= 16) {
            Vec3NormalizeAndGetLengthUnchecked(&v, &v);
        }
        out->x = ((s64) v.x * d) >> 12;
        out->y = ((s64) v.y * d) >> 12;
        out->z = ((s64) v.z * d) >> 12;
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

void InitPendulum(PendulumObject *pendulum, Unk020e5e24_2 *courseRow) {
    s32 m;

    pendulum->mMapObject.mExtent.y = ((s64) pendulum->mMapObject.mKindData->mUnk_10 * courseRow->mUnk_20) >> 12;
    QuaternionFromVec3Degrees(&courseRow->mUnk_0c, &pendulum->mRotationQuaternion);
    pendulum->mShadowMatrix = pendulum->mMapObject.mMatrix.mUnk_00_m;
    pendulum->mCourseRowDistance = ((s64) pendulum->mMapObject.mScale.y * 0x1f4000) >> 12;
    pendulum->mSwingAngle = 0;
    pendulum->mCourseRowPos.x = courseRow->mUnk_00.x;
    pendulum->mCourseRowPos.y = courseRow->mUnk_00.y;
    pendulum->mCourseRowPos.z = courseRow->mUnk_00.z;
    VEC_MultAdd(-pendulum->mCourseRowDistance, &pendulum->mMapObject.mMatrix.mUnk_00[1], &pendulum->mCourseRowPos,
                &pendulum->mMapObject.mPos);
    pendulum->mPrevPos = pendulum->mMapObject.mPos;
    pendulum->mUnk_ec.x = pendulum->mMapObject.mPos.x >> 4;
    pendulum->mUnk_ec.y = pendulum->mMapObject.mPos.y >> 4;
    pendulum->mUnk_ec.z = pendulum->mMapObject.mPos.z >> 4;
    m = courseRow->mUnk_2a;
    pendulum->mSwingAnglePerFrame = 0x640000u / (u32) courseRow->mUnk_28 / 0xf0u;
    pendulum->mSwingAmplitude = (u32) (m * 0x1111) / 0x64u;
    pendulum->mRadius = ((s64) pendulum->mMapObject.mScale.x * 0x64000) >> 12;
    pendulum->mHalfSizeZ = ((s64) pendulum->mMapObject.mScale.z * 0x32000) >> 12;
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
    data_0217b82c = drawList;
    *drawList = data_021591dc;
    SetDrawListSlot(&data_0217b82c);
    return data_0217b82c;
}

MapObjectList *CreateObPakkunSfUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b828 = updateList;
    *updateList = data_021591b4;
    return updateList;
}

void SetupDrawObPakkunSf(void) {
    QueueNsbmdModelMaterial(gObPakkunSf);
}
