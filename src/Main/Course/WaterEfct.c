#include "Main/Course/WaterEfct.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020d4970.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02084000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020a02c8.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_021471bc.h"

// The map object water_initWater last received (type Unk020da384 is the 0x68-byte prefix view of MapObject: retype is a
// cleanup); water_init reads its x/z and water_render its mFlags; one water map object per course is assumed (a
// second would overwrite it).
Unk020da384 *gWaterObject;
WaterEfct *gSplashState;
Water *gWaterState;

// The mInitObject slot of the five water kinds (data_usa_021580a4): stores the map object in gWaterObject, clears
// mFlags bits 2 and 8, sets mUnk_66 to 0x1f, runs the creator the kind row holds (third argument), then loads the three
// water_efct files into gWaterState; once per water map object.
void water_initWater(Unk020da384 *mapObject, void *unused, UnkFunc *createWater) {
    gWaterObject = mapObject;
    mapObject->mUnk_02 &= ~2;
    mapObject->mUnk_02 &= ~8;
    mapObject->mUnk_66 = 0x1f;
    createWater();
    gWaterState->mEfctNsbmdFile = arc_getCourseArcFile("MapObj/water_efct.nsbmd");
    gWaterState->mEfctNsbcaFile = arc_getCourseArcFile("MapObj/water_efct.nsbca");
    gWaterState->mEfctNsbmaFile = arc_getCourseArcFile("MapObj/water_efct.nsbma");
}

// One step per race_update call while the course has water: advances the height swing (4 states) and the two circles;
// when mUnk_170 is set it also sets a value on entry 10 of data_0217c838 (GetSndHandleSlot) every call (from
// bsfx_getVolume on course 0x1f, else 0x7f000) and requests sound 0x114 when state 1 ends and 0x113 when state 3 ends.
void water_update(Water *water) {
    s32 volume;
    NNSSndSeqPlayer **soundHandleSlot;
    Unk0210b7a8 highSoundRequest;
    Unk0210b7a8 lowSoundRequest;
    u16 modelCAngle;
    s32 modelAIndex;
    s32 modelCIndex;
    soundHandleSlot = GetSndHandleSlot(10);
    if (water->mUnk_170 != 0) {
        if (gRaceMultiConfig->mCourseId != COURSE_ID_BEACH) {
            volume = 0x7f000;
        } else {
            volume = bsfx_getVolume();
        }
        if (volume >= 0) {
            SetSndHandleTrackVolume(soundHandleSlot, volume);
        }
    }
    switch (water->mState) {
        case 0:
            water->mHeightFactor = FX_SinCosTable_[(water->mHeightAngle >> 4) * 2];
            water->mHeight = water->mMidHeight + (s32) (((s64) water->mHeightAmplitude * water->mHeightFactor) >> 12);
            water->mModelCY = water->mHeight;
            water->mHeightAngle = water->mHeightAngle + water->mHeightAnglePerFrame;
            water->mUnk_3a = water->mUnk_3a + water->mHeightAnglePerFrame;
            if (water->mHeightAngle > 0x3fff && water->mHeightAngle < 0x7fff) {
                water->mState = 1;
                water->mHoldFrames = 0;
                water->mUnk_3e = water->mHeightAnglePerFrame;
            }
            break;
        case 1:
            water->mHoldFrames = water->mHoldFrames + 1;
            if (water->mHoldFrames > water->mHighHoldFrameCount) {
                water->mState = 2;
                if (water->mUnk_170 != 0 && volume >= 0) {
                    highSoundRequest.mSoundId = 0x114;
                    highSoundRequest.mPositionSource = NULL;
                    highSoundRequest.mUnk_08 = 4;
                    highSoundRequest.mDistanceSquared = mobj_calcXZCamDist(NULL);
                    func_0210b760(&highSoundRequest, soundHandleSlot);
                }
            } else if (water->mHoldFrames > (water->mHighHoldFrameCount >> 1)) {
                water->mUnk_3e = water->mUnk_3e + 1;
                water->mUnk_3a = water->mUnk_3a + water->mUnk_3e;
            } else {
                water->mUnk_3e = water->mUnk_3e - 1;
                water->mUnk_3a = water->mUnk_3a + water->mUnk_3e;
            }
            break;
        case 2:
            water->mHeightFactor = FX_SinCosTable_[(water->mHeightAngle >> 4) * 2];
            water->mHeight = water->mMidHeight + (s32) (((s64) water->mHeightAmplitude * water->mHeightFactor) >> 12);
            water->mModelCY = water->mHeight;
            water->mHeightAngle = water->mHeightAngle + water->mHeightAnglePerFrame;
            water->mUnk_3a = water->mUnk_3a + water->mHeightAnglePerFrame;
            if (water->mHeightAngle > 0xbfff) {
                water->mState = 3;
                water->mHoldFrames = 0;
                water->mUnk_3e = water->mHeightAnglePerFrame;
            }
            break;
        case 3:
            water->mHoldFrames = water->mHoldFrames + 1;
            if (water->mHoldFrames > water->mLowHoldFrameCount) {
                water->mState = 0;
                if (water->mUnk_170 != 0 && volume >= 0) {
                    lowSoundRequest.mSoundId = 0x113;
                    lowSoundRequest.mPositionSource = NULL;
                    lowSoundRequest.mUnk_08 = 4;
                    lowSoundRequest.mDistanceSquared = mobj_calcXZCamDist(NULL);
                    func_0210b760(&lowSoundRequest, soundHandleSlot);
                }
            } else if (water->mHoldFrames > (water->mLowHoldFrameCount >> 1)) {
                water->mUnk_3e = water->mUnk_3e + 1;
                water->mUnk_3a = water->mUnk_3a + water->mUnk_3e;
            } else {
                water->mUnk_3e = water->mUnk_3e - 1;
                water->mUnk_3a = water->mUnk_3a + water->mUnk_3e;
            }
            break;
    }
    water->mCircleAngle = water->mCircleAngle + water->mCircleAnglePerFrame;
    modelCAngle = water->mCircleAngle - water->mModelCAngleOffset;
    if (water->mModelAFile != NULL) {
        modelAIndex = (water->mCircleAngle >> 4) * 2;
        water->mModelAX = water->mCenterX + (s32) (((s64) water->mModelARadius * FX_SinCosTable_[modelAIndex]) >> 12);
        water->mModelAZ = water->mCenterZ + (s32) (((s64) water->mModelARadius * FX_SinCosTable_[modelAIndex + 1]) >> 12);
    }
    modelCIndex = (modelCAngle >> 4) * 2;
    water->mModelCX = water->mCenterX + (s32) (((s64) water->mModelCRadius * FX_SinCosTable_[modelCIndex]) >> 12);
    water->mModelCZ = water->mCenterZ + (s32) (((s64) water->mModelCRadius * FX_SinCosTable_[modelCIndex + 1]) >> 12);
}

// Draws model A (when it exists) and model C at their circle positions and mHeight, in the order of mDrawModelAFirst;
// returns at once when the water map object's mFlags has bit 0x2 or 0x10; writes only the scratch matrix mUnk_140.
void water_render(Water *water, struct MtxFx43 *unused) {
    if ((gWaterObject->mUnk_02 & 0x12) != 0) {
        return;
    }
    if (water->mDrawModelAFirst != 0) {
        if (water->mModelAFile != NULL) {
            water->mDrawMatrix.mUnk_00[3].x = water->mModelAX >> 4;
            water->mDrawMatrix.mUnk_00[3].y = water->mHeight >> 4;
            water->mDrawMatrix.mUnk_00[3].z = water->mModelAZ >> 4;
            model_drawTransformed(&water->mModelA, &water->mDrawMatrix, NULL);
        }
        water->mDrawMatrix.mUnk_00[3].x = water->mModelCX >> 4;
        water->mDrawMatrix.mUnk_00[3].y = water->mModelCY >> 4;
        water->mDrawMatrix.mUnk_00[3].z = water->mModelCZ >> 4;
        model_drawTransformed(&water->mModelC, &water->mDrawMatrix, NULL);
    } else {
        water->mDrawMatrix.mUnk_00[3].x = water->mModelCX >> 4;
        water->mDrawMatrix.mUnk_00[3].y = water->mModelCY >> 4;
        water->mDrawMatrix.mUnk_00[3].z = water->mModelCZ >> 4;
        model_drawTransformed(&water->mModelC, &water->mDrawMatrix, NULL);
        if (water->mModelAFile != NULL) {
            water->mDrawMatrix.mUnk_00[3].x = water->mModelAX >> 4;
            water->mDrawMatrix.mUnk_00[3].y = water->mHeight >> 4;
            water->mDrawMatrix.mUnk_00[3].z = water->mModelAZ >> 4;
            model_drawTransformed(&water->mModelA, &water->mDrawMatrix, NULL);
        }
    }
}

Unk020d9de0 *water_setupSplashCollision(void) {
    Unk020d9de0 *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    {
        Unk020d9de0 v = {0};
        *kindData = v;
    }
    return kindData;
}

#pragma thumb on

// Called once by each Create...Water with 15 constants; sets 28 members of gWaterState (heights, step sizes, radii, hold
// counts, flags) and resets the matrix mUnk_140, nothing else.
void water_init(s32 highHeight, s32 lowHeight, s32 modelARadius, s32 modelCRadius, s32 e, u16 modelCAngleOffset,
                     u16 g, u16 framesPerCycle, u16 highHoldFrameCount, u16 lowHoldFrameCount, u16 drawModelAFirst,
                     u16 modelAAlpha, u16 modelCMaterialAlpha, u16 n, s32 o) {
    gWaterState->mMidHeight = (highHeight + lowHeight) >> 1;
    gWaterState->mHeight = gWaterState->mMidHeight;
    gWaterState->mModelCY = gWaterState->mHeight;
    gWaterState->mHeightAmplitude = (highHeight - lowHeight) >> 1;
    gWaterState->mHeightAngle = 0;
    gWaterState->mUnk_3a = 0;
    gWaterState->mCircleAngle = 0;
    gWaterState->mModelCAngleOffset = modelCAngleOffset;
    gWaterState->mUnk_52 = g;
    gWaterState->mHeightAnglePerFrame = 0x10000 / framesPerCycle;
    gWaterState->mCircleAnglePerFrame = (u32) gWaterState->mHeightAnglePerFrame >> 2;
    gWaterState->mState = 0;
    gWaterState->mHighHoldFrameCount = highHoldFrameCount;
    gWaterState->mLowHoldFrameCount = lowHoldFrameCount;
    gWaterState->mHeightFactor = 0;
    gWaterState->mCenterX = gWaterObject->mUnk_04;
    gWaterState->mModelAX = gWaterState->mCenterX;
    gWaterState->mCenterZ = gWaterObject->mUnk_0c;
    gWaterState->mModelAZ = gWaterState->mCenterZ;
    gWaterState->mModelARadius = modelARadius;
    gWaterState->mModelCRadius = modelCRadius;
    gWaterState->mUnk_4c = e;
    gWaterState->mDrawModelAFirst = drawModelAFirst;
    gWaterState->mModelAAlpha = modelAAlpha;
    gWaterState->mModelCMaterialAlpha = modelCMaterialAlpha;
    gWaterState->mUnk_5c = n;
    MTX_Identity43_(&gWaterState->mDrawMatrix);
    gWaterState->mUnk_170 = o;
}

void water_loadMiniStage3Water(void) {
    gWaterState = heap_alloc(proc_getHeap(proc_getCurrent()), 0x180);
    water_init(0xe8000, 0xc5000, 0x50000, 0x32000, 0x3c000, 0x7fff, 0x3fff, 0x1f4, 0x12c, 0x12c, 1, 5, 0xa, 0xa,
                    1);
    gWaterState->mModelAFile = mobj_getMapObjFile("mini_stage3_waterA.nsbmd");
    gWaterState->mModelCFile = mobj_getMapObjFile("mini_stage3_waterC.nsbmd");
    mobj_setWaterStatePointer(gWaterState);
}

void water_loadBeachWater(void) {
    gWaterState = heap_alloc(proc_getHeap(proc_getCurrent()), 0x180);
    water_init(0x78000, 0x62000, 0x50000, 0x43000, 0x3c000, 0x7fff, 0x3fff, 0x1f4, 0x96, 0x96, 1, 6, 0xa, 0xa, 1);
    gWaterState->mModelAFile = mobj_getMapObjFile("beach_waterA.nsbmd");
    gWaterState->mModelCFile = mobj_getMapObjFile("beach_waterC.nsbmd");
    mobj_setWaterStatePointer(gWaterState);
}

void water_loadTownWater(void) {
    gWaterState = heap_alloc(proc_getHeap(proc_getCurrent()), 0x180);
    water_init(0, 0, 0x29000, 0x1e000, 0xb000, 0x4e20, 0x3fff, 0x12c, 0x78, 0x1e, 1, 0xd, 0x19, 0x10, 0);
    gWaterState->mModelAFile = mobj_getMapObjFile("town_waterA.nsbmd");
    gWaterState->mModelCFile = mobj_getMapObjFile("town_waterC.nsbmd");
    mobj_setWaterStatePointer(gWaterState);
}

void water_loadYoshiWater(void) {
    gWaterState = heap_alloc(proc_getHeap(proc_getCurrent()), 0x180);
    water_init(0, 0, 0xc8000, 0x55000, 0x3c000, 0x7fff, 0x3fff, 0x1c2, 0x78, 0x1e, 1, 0xa, 0x17, 0x10, 0);
    gWaterState->mModelAFile = NULL;
    gWaterState->mModelCFile = mobj_getMapObjFile("yoshi_waterC.nsbmd");
    mobj_setWaterStatePointer(gWaterState);
}

void water_loadHyudoroWater(void) {
    gWaterState = heap_alloc(proc_getHeap(proc_getCurrent()), 0x180);
    water_init(0, 0, 0x63000, 0x4d000, 0x1e000, 0x7fff, 0x3fff, 0x1c2, 0x78, 0x1e, 1, 0xf, 0x19, 0x10, 0);
    gWaterState->mModelAFile = mobj_getMapObjFile("hyudoro_waterA.nsbmd");
    gWaterState->mModelCFile = mobj_getMapObjFile("hyudoro_waterC.nsbmd");
    mobj_setWaterStatePointer(gWaterState);
}

// Once per course, from mobj_initAllRenderParts in mobj_init: builds the embedded model of each file (mUnk_68 only when A
// exists, mUnk_d4) and sets material values (NNS_G3dMdlSetMdlPolygonID: 1 for A, 2 for C; the two 5-bit values mUnk_58
// / mUnk_5a through NNS_G3dMdlSetMdlAlpha).
void water_initModels(Water *water) {
    u32 materialIndex;
    NNSG3dResMdl *modelResMdl;
    NNSG3dResMdl *modelCResMdl;
    s32 alphaMaterialIndex;
    u32 modelAAlpha;
    if (water->mModelAFile != NULL) {
        model_initFromNsbmd(&water->mModelA, water->mModelAFile);
        materialIndex = 0;
        modelResMdl = water->mModelA.mResMdl;
        for (; materialIndex < modelResMdl->mInfo.mNumMat; materialIndex++) {
            NNS_G3dMdlSetMdlEmi(modelResMdl, materialIndex, 0x294a);
        }
        materialIndex = 0;
        modelResMdl = water->mModelA.mResMdl;
        for (; materialIndex < modelResMdl->mInfo.mNumMat; materialIndex++) {
            NNS_G3dMdlSetMdlPolygonID(modelResMdl, materialIndex, 1);
        }
    }
    model_initFromNsbmd(&water->mModelC, water->mModelCFile);
    materialIndex = 0;
    modelResMdl = water->mModelC.mResMdl;
    for (; materialIndex < modelResMdl->mInfo.mNumMat; materialIndex++) {
        NNS_G3dMdlSetMdlEmi(modelResMdl, materialIndex, 0x294a);
    }
    materialIndex = 0;
    modelResMdl = water->mModelC.mResMdl;
    for (; materialIndex < modelResMdl->mInfo.mNumMat; materialIndex++) {
        NNS_G3dMdlSetMdlPolygonID(modelResMdl, materialIndex, 2);
    }
    modelCResMdl = water->mModelC.mResMdl;
    alphaMaterialIndex = NNS_G3dGetResDictIdxByName((u8 *) modelCResMdl + modelCResMdl->mOfsMat + 4, aWaterc);
    if (water->mModelAFile != NULL) {
        modelAAlpha = water->mModelAAlpha;
        materialIndex = 0;
        modelResMdl = water->mModelA.mResMdl;
        for (; materialIndex < modelResMdl->mInfo.mNumMat; materialIndex++) {
            NNS_G3dMdlSetMdlAlpha(modelResMdl, materialIndex, modelAAlpha);
        }
    }
    NNS_G3dMdlSetMdlAlpha(modelCResMdl, alphaMaterialIndex, water->mModelCMaterialAlpha);
}

void water_initSplash(Unk020da384 *mapObject) {
    WaterEfct *waterEfct;
    waterEfct = heap_alloc(proc_getHeap(proc_getCurrent()), 0x10);
    gSplashState = waterEfct;
    waterEfct->mHeight = mapObject->mUnk_08;
    gSplashState->mNsbmdFile = arc_getCourseArcFile("MapObj/water_efct.nsbmd");
    gSplashState->mNsbcaFile = arc_getCourseArcFile("MapObj/water_efct.nsbca");
    gSplashState->mNsbmaFile = arc_getCourseArcFile("MapObj/water_efct.nsbma");
    mobj_setSplashStatePointer(gSplashState);
}

#pragma thumb off

void pw_hermiteSplineCalcCoef(s32 fraction, s32 *weight0, s32 *weight1, s32 *weight2, s32 *weight3) {
    s32 remaining = 0x1000000 - fraction;
    s32 v = ((s64) remaining * remaining) >> 24;
    *weight0 = ((s64) remaining * v) >> 24;
    *weight1 = (s32) (((s64) remaining * fraction) >> 24) * 3;
    *weight2 = ((s64) *weight1 * fraction) >> 24;
    v = ((s64) fraction * fraction) >> 24;
    *weight3 = ((s64) fraction * v) >> 24;
    *weight1 = ((s64) *weight1 * remaining) >> 24;
}

void pw_hermiteSplineCalcCoef2(s32 fraction, s32 *weight0, s32 *weight1, s32 *weight2, s32 *weight3, s32 *slopeWeight0,
                             s32 *slopeWeight1, s32 *slopeWeight2, s32 *slopeWeight3) {
    s32 remaining = 0x1000000 - fraction;
    *slopeWeight0 = ((s64) remaining * remaining) >> 24;
    *weight0 = ((s64) *slopeWeight0 * remaining) >> 24;
    *slopeWeight3 = ((s64) fraction * fraction) >> 24;
    *weight3 = ((s64) *slopeWeight3 * fraction) >> 24;
    *weight1 = (s32) (((s64) remaining * fraction) >> 24) * 3;
    *slopeWeight0 = *slopeWeight0 * 3;
    *slopeWeight3 = *slopeWeight3 * 3;
    *slopeWeight2 = *weight1 << 1;
    *slopeWeight1 = *slopeWeight0 - *slopeWeight2;
    *slopeWeight2 = *slopeWeight2 - *slopeWeight3;
    *slopeWeight0 = -*slopeWeight0;
    *weight2 = ((s64) *weight1 * fraction) >> 24;
    *weight1 = ((s64) *weight1 * remaining) >> 24;
}

void pw_applyCoefXYZ(const Vec3 *points, Vec3 *result, s32 weight0, s32 weight1, s32 weight2, s32 weight3) {
    result->x = ((s64) points[0].x * weight0) >> 24;
    result->y = ((s64) points[0].y * weight0) >> 24;
    result->z = ((s64) points[0].z * weight0) >> 24;
    result->x = result->x + (s32) (((s64) points[1].x * weight1) >> 24);
    result->y = result->y + (s32) (((s64) points[1].y * weight1) >> 24);
    result->z = result->z + (s32) (((s64) points[1].z * weight1) >> 24);
    result->x = result->x + (s32) (((s64) points[2].x * weight2) >> 24);
    result->y = result->y + (s32) (((s64) points[2].y * weight2) >> 24);
    result->z = result->z + (s32) (((s64) points[2].z * weight2) >> 24);
    result->x = result->x + (s32) (((s64) points[3].x * weight3) >> 24);
    result->y = result->y + (s32) (((s64) points[3].y * weight3) >> 24);
    result->z = result->z + (s32) (((s64) points[3].z * weight3) >> 24);
}

void pw_applyCoefXZ(const Vec3 *points, Vec3 *result, s32 weight0, s32 weight1, s32 weight2, s32 weight3) {
    result->x = ((s64) points[0].x * weight0) >> 24;
    result->z = ((s64) points[0].z * weight0) >> 24;
    result->x = result->x + (s32) (((s64) points[1].x * weight1) >> 24);
    result->z = result->z + (s32) (((s64) points[1].z * weight1) >> 24);
    result->x = result->x + (s32) (((s64) points[2].x * weight2) >> 24);
    result->z = result->z + (s32) (((s64) points[2].z * weight2) >> 24);
    result->x = result->x + (s32) (((s64) points[3].x * weight3) >> 24);
    result->z = result->z + (s32) (((s64) points[3].z * weight3) >> 24);
}
