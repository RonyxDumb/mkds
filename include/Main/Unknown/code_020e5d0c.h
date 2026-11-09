#pragma once

#include "types.h"
#include "code_02013bdc.h"
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e5684.h"

// Second argument of InitPendulum, read at 0x00..0x2b.
typedef struct Unk020e5e24_2 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[0x08];
    /* 20 */ s32 mUnk_20;
    /* 24 */ u8 mUnk_24[0x04];
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
} Unk020e5e24_2;

// Object handled by InitPendulum, ComputeSphereHitOnPendulum, UpdatePendulum and
// DrawPendulum; at least 0x110 bytes.
typedef struct PendulumObject {
    /* 00 */ MapObject mMapObject;
    /* a0 */ Quaternion mRotationQuaternion;
    /* b0 */ Vec3 mPrevPos;
    /* bc */ Vec3 mCourseRowPos;
    /* c8 */ MtxFx33 mShadowMatrix;
    /* ec */ Vec3 mUnk_ec;
    /* f8 */ s32 mCourseRowDistance;
    /* fc */ u16 mSwingAmplitude;
    /* fe */ u16 mSwingAnglePerFrame;
    /* 100 */ u16 mSwingAngle;
    /* 102 */ u8 mUnk_102[0x02];
    /* 104 */ s32 mRadius;
    /* 108 */ s32 mHalfSizeZ;
    /* 10c */ BOOL mUnk_10c;
} PendulumObject;

// Allocated by CreateNsbmdModel and CreateItemModel, filled in by FillNsbmdModel, 0x2c bytes.
typedef struct NsbmdModel {
    /* 00 */ u8 *mDisplayList;
    /* 04 */ u32 mDisplayListSize;
    /* 08 */ u32 mScale;
    /* 0c */ s32 mDiffAmb;
    /* 10 */ s32 mSpecEmi;
    /* 14 */ u32 mPolygonAttributes;
    /* 18 */ u16 mFrameIndex;
    /* 1a */ u16 mFrameCount;
    /* 1c */ u32 *mTexImageParams;
    /* 20 */ u32 *mTexPlttBases;
    /* 24 */ void *mNsbmd;
    /* 28 */ void *mNsbtpAnimation;
} NsbmdModel;

extern NsbmdModel gJgCloud;

extern NsbmdModel gJgMain;

// Work area of FillNsbmdModel on the stack: two words, then the object
// NNSi_G3dAnmCalcNsBtp fills in.
typedef struct Unk020e6514_8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ NNSG3dMatAnmResult mUnk_08;
} Unk020e6514_8;

void SetupDrawObPakkunSf(void);
MapObjectList *CreateObPakkunSfUpdateList(void);
MapObjectDrawList *CreateObPakkunSfDrawList(void);
MapObjectKindData *CreateObPakkunSfKindData(void);
void InitPendulum(PendulumObject *pendulum, Unk020e5e24_2 *courseRow);
void CreatePendulumAndPendulumShadow(void);
BOOL ComputeSphereHitOnPendulum(PendulumObject *pendulum, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *out);
void UpdatePendulum(u32 list, PendulumObject *pendulum);
void DrawPendulum(u32 unused0, PendulumObject *pendulum, u32 unused1, u32 alpha);
MapObjectList *CreatePendulumUpdateList(void);
MapObjectDrawList *CreatePendulumDrawList(void);
MapObjectKindData *CreatePendulumKindData(void);
void CreateNsbmdModel(NsbmdModel **recordSlot, void *nsbmdFile, void *nsbtpFile, u32 param_4);
void InitNsbmdModel(NsbmdModel *record, void *nsbmdFile, void *nsbtpFile, s32 c);
void FillNsbmdModel(Nsbmd *model, ModelAnimation *animation, NsbmdModel *record);
