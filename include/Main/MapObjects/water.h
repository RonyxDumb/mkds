#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Course/code_02042044.h"
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "code_02012b30.h" // MtxFx43
#include "Main/MapObjects/segment_curve.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_koura_w.h"

struct MtxFx43;
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/MapObjects/code_020e6b58.h"

#define WATER_FALL_SOUND_ID 0x114
#define WATER_RISE_SOUND_ID 0x113

// The flat water level of a course (the map object's y) and the three water_efct effect files; 0x10 bytes, built by
// CreateWaterEfct (kinds 5, 0xe, 0xf) into gWaterEfct and published as gCourseWaterEfct.
typedef struct WaterEfct {
    // y of the flat water level (the map object's y); GetHeightAboveWaterOrEfct subtracts it from a y.
    /* 00 */ s32 mHeight;
    // The file MapObj/water_efct.nsbmd as FindCourseFile returned it in CreateWaterEfct (a pointer to the whole file,
    // not a built model object); returned by GetWaterEfctNsbmdFile.
    /* 04 */ void *mNsbmdFile;
    // The file MapObj/water_efct.nsbca (whole file), see mNsbmdFile.
    /* 08 */ void *mNsbcaFile;
    // The file MapObj/water_efct.nsbma (whole file), see mNsbmdFile.
    /* 0c */ void *mNsbmaFile;
} WaterEfct;

// Water.mState: the height angle advances towards the top, holds at the top, advances towards the bottom, holds at the
// bottom.
#define WATER_STATE_RISING 0
#define WATER_STATE_HOLD_TOP 1
#define WATER_STATE_FALLING 2
#define WATER_STATE_HOLD_BOTTOM 3

// The course water: two models (the files ..._waterA and ..._waterC, Yoshi has no A) circling a map object's x/z while
// the surface height swings between two heights the creator gives; 0x180 bytes, built by the five Create...Water
// functions into gWater and published as gCourseWater.
typedef struct Water {
    // X of model A (the model of mModelAFile, letter A from the file name ..._waterA): mCenterX + mModelARadius * the
    // first value of the FX_SinCosTable_ pair for mCircleAngle; UpdateWater writes it only while model A exists
    // (InitWaterFields first sets it to mCenterX).
    /* 00 */ s32 mModelAX;
    // y of the water surface: the models are drawn at it and the getters subtract it from a y; it stays 0 for the
    // courses whose creator passes both heights as 0.
    /* 04 */ s32 mHeight;
    // Z of model A: mCenterZ + mModelARadius * the second value of the pair for mCircleAngle; see mModelAX.
    /* 08 */ s32 mModelAZ;
    // X of model C (the model of mModelCFile, letter C from ..._waterC): mCenterX + mModelCRadius * the first pair
    // value for mCircleAngle - mModelCAngleOffset; its y is mModelCY (copy of mHeight).
    /* 0c */ s32 mModelCX;
    // y of model C: every write copies mHeight, the only reads are the translation y
    // of model C in DrawWater; it is only ever set from mHeight.
    /* 10 */ s32 mModelCY;
    // Z of model C, as mModelCX with the second pair value.
    /* 14 */ s32 mModelCZ;
    // x of the water map object (copied by InitWaterFields from gWaterMapObject); both models circle around it.
    /* 18 */ s32 mCenterX;
    // (a + b) / 2 of the two heights the creator gives; the height swings around it.
    /* 1c */ s32 mMidHeight;
    // z of the water map object; both models circle around it.
    /* 20 */ s32 mCenterZ;
    // UpdateWater switches on it; only UpdateWater writes it.
    /* 24 */ s32 mState;
    // (a - b) / 2 of the two heights the creator gives; mHeight is mMidHeight plus this times mHeightFactor (both
    // creators with different heights pass the larger first).
    /* 28 */ s32 mHeightAmplitude;
    // 0x10000 per turn, index (angle >> 4) * 2 into FX_SinCosTable_; advances only while rising or falling; 0x4000 is
    // the top (pair value +1.0), 0xc000 the bottom; GetWaterHeightAngle returns it.
    /* 2c */ u16 mHeightAngle;
    // 0x10000 / the cycle length (in UpdateWater calls) the creator gives; added to mHeightAngle per call while rising
    // or falling.
    /* 2e */ u16 mHeightAnglePerFrame;
    // 1.12 fixed (0x1000 = 1.0), the first value of the FX_SinCosTable_ pair for mHeightAngle (-1.0 .. +1.0), refreshed
    // while rising or falling; mHeight = mMidHeight + mHeightAmplitude * this; the HUD gauge reads it.
    /* 30 */ s32 mHeightFactor;
    // How many UpdateWater calls the top hold lasts (mHoldFrames must exceed it; the height and angle stay, the models
    // keep circling); the hold starts at angle 0x4000 where the pair value is +1.0 = the top, because the two creators
    // with different heights pass the larger first (0xe8000 > 0xc5000, 0x78000 > 0x62000).
    /* 34 */ u16 mHighHoldFrameCount;
    // How many UpdateWater calls the bottom hold lasts, at angle 0xc000 (pair value -1.0 = the bottom); see
    // mHighHoldFrameCount.
    /* 36 */ u16 mLowHoldFrameCount;
    // Counts up one per UpdateWater call while holding at the top or bottom, zeroed when the state is entered,
    // compared with mHighHoldFrameCount / mLowHoldFrameCount.
    /* 38 */ u16 mHoldFrames;
    /* 3a */ u16 mHeightAngleWithHold;
    // 0x10000 per turn: the angle of the circle model A moves on (model C uses it minus mModelCAngleOffset); advances
    // every UpdateWater call by mCircleAnglePerFrame.
    /* 3c */ u16 mCircleAngle;
    /* 3e */ u16 mHoldAngleStep;
    // mHeightAnglePerFrame / 4, added to mCircleAngle every UpdateWater call.
    /* 40 */ u16 mCircleAnglePerFrame;
    /* 42 */ u8 mUnk_42[2];
    // Radius of the circle of model A.
    /* 44 */ s32 mModelARadius;
    // Radius of the circle of model C.
    /* 48 */ s32 mModelCRadius;
    /* 4c */ s32 mUnk_4c;
    // Model C's angle is mCircleAngle minus this (0x7fff or 0x4e20 in the creators); one write, one read.
    /* 50 */ u16 mModelCAngleOffset;
    /* 52 */ u16 mUnk_52;
    // A creator argument that is 1 in all five creators; DrawWater draws A then C when it is non-zero and C then A when
    // it is 0, which the shipped creators never do.
    /* 54 */ s32 mDrawModelAFirst;
    /* 58 */ u16 mModelAAlpha;
    /* 5a */ u16 mModelCMaterialAlpha;
    /* 5c */ u16 mUnk_5c;
    /* 5e */ u8 mUnk_5e[2];
    // Pointer FindCourseMapObjFile returned for ..._waterA.nsbmd, NULL for Yoshi; every use of model A tests it.
    /* 60 */ void *mModelAFile;
    // Pointer FindCourseMapObjFile returned for ..._waterC.nsbmd; never NULL in the five creators.
    /* 64 */ void *mModelCFile;
    /* 68 */ Nsbmd mModelA;
    /* d4 */ Nsbmd mModelC;
    /* 140 */ MtxFx43 mDrawMatrix;
    /* 170 */ s32 mIsHeightUsed;
    // The file MapObj/water_efct.nsbmd as FindCourseFile returned it (a pointer to the whole file, not a built model
    // object), loaded by InitWater; the getter returns it when mIsHeightUsed is
    // non-zero and no WaterEfct exists.
    /* 174 */ void *mEfctNsbmdFile;
    // The file MapObj/water_efct.nsbca (whole file), loaded by InitWater; see mEfctNsbmdFile.
    /* 178 */ void *mEfctNsbcaFile;
    // The file MapObj/water_efct.nsbma (whole file), loaded by InitWater; see mEfctNsbmdFile.
    /* 17c */ void *mEfctNsbmaFile;
} Water;

void InitWater(MapObject *mapObject, void *unused, void (*createWater)(void));
void UpdateWater(Water *water);
void DrawWater(Water *water, struct MtxFx43 *unused);
MapObjectKindData *CreateWaterEfctKindData(void);
void InitWaterFields(s32 highHeight, s32 lowHeight, s32 modelARadius, s32 modelCRadius, s32 unk4cValue,
                     u16 modelCAngleOffset, u16 unk52Value, u16 framesPerCycle, u16 highHoldFrameCount,
                     u16 lowHoldFrameCount, u16 drawModelAFirst, u16 modelAAlpha, u16 modelCMaterialAlpha,
                     u16 unk5cValue, s32 unk170Value);
void CreateMiniStage3Water(void);
void CreateBeachWater(void);
void CreateTownWater(void);
void CreateYoshiWater(void);
void CreateHyudoroWater(void);
void InitWaterModels(Water *water);
void CreateWaterEfct(MapObject *mapObject);
extern const u32 gWaterCMaterialName[4];
void GetCurveWeights(s32 fraction, s32 *weight0, s32 *weight1, s32 *weight2, s32 *weight3);
void GetCurveAndSlopeWeights(s32 fraction, s32 *weight0, s32 *weight1, s32 *weight2, s32 *weight3, s32 *slopeWeight0,
                             s32 *slopeWeight1, s32 *slopeWeight2, s32 *slopeWeight3);
void ComputeWeightedPoint(const Vec3 *points, Vec3 *result, s32 weight0, s32 weight1, s32 weight2, s32 weight3);
void ComputeWeightedPointXz(const Vec3 *points, Vec3 *result, s32 weight0, s32 weight1, s32 weight2, s32 weight3);
