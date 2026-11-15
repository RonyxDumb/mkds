#pragma once

#include "types.h"
#include "code_02013bdc.h"
#include "Main/MapObjects/quaternion_math.h" // Quaternion
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Kart/shadow_model.h"

#define PENDULUM_SOUND_ANGLE_OFFSET 0x18f0

#define PENDULUM_SOUND_ID 0x173

// Object handled by InitPendulum, ComputeSphereHitOnPendulum, UpdatePendulum and
// DrawPendulum; at least 0x110 bytes.
typedef struct PendulumObject {
    /* 00 */ MapObject mMapObject;
    /* a0 */ Quaternion mRotationQuaternion;
    /* b0 */ Vec3 mPrevPos;
    /* bc */ Vec3 mCourseRowPos;
    /* c8 */ MtxFx33 mShadowMatrix;
    /* ec */ Vec3 mDrawPos;
    /* f8 */ s32 mCourseRowDistance;
    /* fc */ u16 mSwingAmplitude;
    /* fe */ u16 mSwingAnglePerFrame;
    /* 100 */ u16 mSwingAngle;
    /* 102 */ u8 mUnk_102[0x02];
    /* 104 */ s32 mRadius;
    /* 108 */ s32 mHalfSizeZ;
    /* 10c */ BOOL mLastHitRadial;
} PendulumObject;

// Fields of NsbmdModel.mPolygonAttributes (the polygon attribute word of the geometry engine): the alpha, from 0 to its
// all-ones maximum (opaque), and the polygon id.
#define POLYGON_ATTR_ALPHA_SHIFT 16
#define POLYGON_ATTR_ALPHA_MASK 0x1f0000
#define POLYGON_ATTR_ID_SHIFT 24
#define POLYGON_ATTR_ID_MASK 0x3f000000

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
    /* 24 */ Nsbmd *mNsbmd;
    /* 28 */ ModelAnimation *mNsbtpAnimation;
} NsbmdModel;

extern NsbmdModel gJgCloud;

extern NsbmdModel gJgMain;

// Work area of FillNsbmdModel on the stack: two words, then the object
// NNSi_G3dAnmCalcNsBtp fills in.
typedef struct NsbmdTexFrameWork {
    /* 00 */ u32 mTexImageParam;
    /* 04 */ u32 mDataIndex;
    /* 08 */ NNSG3dMatAnmResult mResult;
} NsbmdTexFrameWork;

void SetupDrawObPakkunSf(void);
MapObjectList *CreateObPakkunSfUpdateList(void);
MapObjectDrawList *CreateObPakkunSfDrawList(void);
MapObjectKindData *CreateObPakkunSfKindData(void);
void InitPendulum(PendulumObject *pendulum, CourseMapRow *courseRow);
void CreatePendulumAndPendulumShadow(void);
BOOL ComputeSphereHitOnPendulum(PendulumObject *pendulum, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *out);
void UpdatePendulum(u32 list, PendulumObject *pendulum);
void DrawPendulum(u32 unused0, PendulumObject *pendulum, u32 unused1, u32 alpha);
MapObjectList *CreatePendulumUpdateList(void);
MapObjectDrawList *CreatePendulumDrawList(void);
MapObjectKindData *CreatePendulumKindData(void);
void CreateNsbmdModel(NsbmdModel **recordSlot, void *nsbmdFile, void *nsbtpFile, u32 unused);
void InitNsbmdModel(NsbmdModel *record, void *nsbmdFile, void *nsbtpFile, s32 unused);
void FillNsbmdModel(Nsbmd *model, ModelAnimation *animation, NsbmdModel *record);

extern const MapObjectDrawList gPendulumDrawListData;
extern const MapObjectList gPendulumUpdateListData;
extern const MapObjectKindData gPendulumKindData;
extern MapObjectList *gPendulumUpdateList;
extern MapObjectList *gObPakkunSfUpdateList;
extern MapObjectDrawList *gObPakkunSfDrawList;
extern MapObjectDrawList *gPendulumDrawList;
extern NsbmdModel *gObPakkunSf;
extern struct Nsbmd *gPendulum;
extern struct ShadowModel *gPendulumShadow;
