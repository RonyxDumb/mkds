#include "Main/MapObjects/pendulum.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/view_frustum.h"

#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "code_02147cd8.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/System/heap_call.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/choropu_state.h"
#include "registers.h"
#include "Main/Item/item_koura_w.h"

const MapObjectDrawList gPendulumDrawListData = {{NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreatePendulumAndPendulumShadow, NULL, DrawPendulum, NULL, 1, NULL, 0, NULL}, 0};
const MapObjectList gPendulumUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdatePendulum, NULL, 0, NULL, 0, NULL};
const MapObjectKindData gPendulumKindData = {NULL, NULL, 5, 0x70000, 0, 0, (s32 (*)(MapObject *, Vec3 *, s32, Vec3 *)) ComputeSphereHitOnPendulum, 1, 1, 0x174, 0, 0, 0, 0, 0, 0};
MapObjectList *gPendulumUpdateList;
MapObjectList *gObPakkunSfUpdateList;
MapObjectDrawList *gObPakkunSfDrawList;
MapObjectDrawList *gPendulumDrawList;
NsbmdModel *gObPakkunSf;
struct Nsbmd *gPendulum;
struct ShadowModel *gPendulumShadow;

#pragma thumb on

void FillNsbmdModel(Nsbmd *model, ModelAnimation *animation, NsbmdModel *record) {
    NNSG3dResMdl *resMdl;
    NNSG3dResMat *resMat;
    NNSG3dResShp *resShp;
    NNSG3dResMatData *matData;
    NNSG3dResShpData *shpData;
    NsbmdTexFrameWork frameWork;
    u16 frameCount;
    u16 frame;
    void *heap;
    enum { K0 } mask;

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
        frameWork.mTexImageParam = matData->mTexImageParam;
        frameCount = FROM_FIXED12(GetModelAnimationFrameCountFixed(animation));
        record->mFrameCount = frameCount;
        heap = GetHeap(GetCurrentHeapCall());
        record->mTexImageParams = HeapAlloc(heap, frameCount * 4);
        heap = GetHeap(GetCurrentHeapCall());
        record->mTexPlttBases = HeapAlloc(heap, frameCount * 4);
        frame = 0;
        if (frame < frameCount) {
            mask = 0xc00f0000;
            frameWork.mTexImageParam &= mask;
            frameWork.mDataIndex = 0;
            do {
                animation->mHead.mFrameIndex = TO_FIXED12(frame);
                animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
                NNSi_G3dAnmCalcNsBtp(&frameWork.mResult, animation->mAnmObjs[0], frameWork.mDataIndex);
                record->mTexImageParams[frame] = frameWork.mResult.mPrmTexImage & 0x3ff0ffff;
                record->mTexImageParams[frame] |= frameWork.mTexImageParam;
                record->mTexPlttBases[frame] = frameWork.mResult.mPrmTexPltt;
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

void InitNsbmdModel(NsbmdModel *record, void *nsbmdFile, void *nsbtpFile, s32 unused) {
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

void CreateNsbmdModel(NsbmdModel **recordSlot, void *nsbmdFile, void *nsbtpFile, u32 unused) {
    *recordSlot = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    InitNsbmdModel(*recordSlot, nsbmdFile, nsbtpFile, unused);
}

#pragma thumb off

MapObjectKindData *CreatePendulumKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gPendulumKindData;
    return kindData;
}

MapObjectDrawList *CreatePendulumDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gPendulumDrawList = drawList;
    *drawList = gPendulumDrawListData;
    SetDrawListSlot(&gPendulumDrawList);
    return gPendulumDrawList;
}

MapObjectList *CreatePendulumUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gPendulumUpdateList = updateList;
    *updateList = gPendulumUpdateListData;
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
            if (pendulum->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (pendulum->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
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
    s32 combinedRadius;
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
    combinedRadius = sphereRadius + pendulum->mRadius;
    distanceSquared = (s64) sphereOffset.x * sphereOffset.x + (s64) sphereOffset.y * sphereOffset.y +
                      (s64) sphereOffset.z * sphereOffset.z;
    if (distanceSquared < (s64) combinedRadius * combinedRadius) {
        reg_CP_SQRTCNT = 1;
        reg_CP_SQRT_PARAM = distanceSquared;
        while (reg_CP_SQRTCNT & 0x8000) {
        }
        combinedRadius -= reg_CP_SQRT_RESULT;
    } else {
        return FALSE;
    }
    if ((axisOverlap > 0 ? axisOverlap : -axisOverlap) < combinedRadius) {
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
        out->x = MUL_FIXED12_NO_ROUND(sphereOffset.x, combinedRadius);
        out->y = MUL_FIXED12_NO_ROUND(sphereOffset.y, combinedRadius);
        out->z = MUL_FIXED12_NO_ROUND(sphereOffset.z, combinedRadius);
        pendulum->mUnk_10c = TRUE;
    }
    return TRUE;
}

#pragma thumb on

void CreatePendulumAndPendulumShadow(void) {
    CreateNsbmd(&gPendulum, FindCourseMapObjFile("pendulum.nsbmd"), NULL);
    CreateShadowModel(&gPendulumShadow, FindCourseMapObjFile("pendulum_shadow.nsbmd"), 0x3f);
    SetNsbmdPolygonIdLightEmiAll(gPendulum, 0x3f, 2, 0x294a);
}

void InitPendulum(PendulumObject *pendulum, CourseMapRow *courseRow) {
    s32 amplitudeSetting;

    pendulum->mMapObject.mExtent.y = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mKindData->mExtentY, courseRow->mScale.z);
    QuaternionFromVec3Degrees(&courseRow->mRotationDegrees, &pendulum->mRotationQuaternion);
    pendulum->mShadowMatrix = pendulum->mMapObject.mMatrix.mAxes;
    pendulum->mCourseRowDistance = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mScale.y, 0x1f4000);
    pendulum->mSwingAngle = 0;
    pendulum->mCourseRowPos.x = courseRow->mPosition.x;
    pendulum->mCourseRowPos.y = courseRow->mPosition.y;
    pendulum->mCourseRowPos.z = courseRow->mPosition.z;
    VEC_MultAdd(-pendulum->mCourseRowDistance, &pendulum->mMapObject.mMatrix.mRows[1], &pendulum->mCourseRowPos,
                &pendulum->mMapObject.mPos);
    pendulum->mPrevPos = pendulum->mMapObject.mPos;
    pendulum->mUnk_ec.x = pendulum->mMapObject.mPos.x >> 4;
    pendulum->mUnk_ec.y = pendulum->mMapObject.mPos.y >> 4;
    pendulum->mUnk_ec.z = pendulum->mMapObject.mPos.z >> 4;
    amplitudeSetting = courseRow->mSettings[1];
    pendulum->mSwingAnglePerFrame = 0x640000u / (u32) courseRow->mSettings[0] / 0xf0u;
    pendulum->mSwingAmplitude = (u32) (amplitudeSetting * 0x1111) / 0x64u;
    pendulum->mRadius = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mScale.x, 0x64000);
    pendulum->mHalfSizeZ = MUL_FIXED12_NO_ROUND(pendulum->mMapObject.mScale.z, 0x32000);
    pendulum->mUnk_10c = FALSE;
}

#pragma thumb off

MapObjectKindData *CreateObPakkunSfKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gObPakkunSfKindData;
    return kindData;
}

MapObjectDrawList *CreateObPakkunSfDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gObPakkunSfDrawList = drawList;
    *drawList = gObPakkunSfDrawListData;
    SetDrawListSlot(&gObPakkunSfDrawList);
    return gObPakkunSfDrawList;
}

MapObjectList *CreateObPakkunSfUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gObPakkunSfUpdateList = updateList;
    *updateList = gObPakkunSfUpdateListData;
    return updateList;
}

void SetupDrawObPakkunSf(void) {
    QueueNsbmdModelMaterial(gObPakkunSf);
}
