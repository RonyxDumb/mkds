#pragma once

#include "types.h"
#include "Main/Kart/shadow_model.h" // ShadowModel
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/MapObjects/woodbox1_state.h" // Woodbox1
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/woodbox1_kind_data.h"

#define WOODBOX1_BROKEN_FRAMES 900
#define WOODBOX1_SETTLE_FRAMES 90
#define WOODBOX1_SMASH_VELOCITY 0x3000
#define WOODBOX1_HEADING_ANGLE_OFFSET 0x1555

typedef struct NNSG3dResMdl NNSG3dResMdl;
typedef struct Woodbox1 Woodbox1;

// Woodbox1.mMapObject.mStateMachine states, in the order of gWoodbox1StateTable. INTACT rests at its base; a hit breaks
// it open (BROKEN, 900 frames); FALL drops the box back in; SETTLE bounces it until it rests.
enum {
    WOODBOX1_STATE_INTACT,
    WOODBOX1_STATE_BROKEN,
    WOODBOX1_STATE_FALL,
    WOODBOX1_STATE_SETTLE,
};
typedef struct Kart Kart;
typedef struct MapObjectList MapObjectList;
typedef struct CourseMapRow CourseMapRow;
typedef struct ItemObject ItemObject;

// Sphere (sphereCenter, sphereRadius) against the cylinder at cylinderCenter whose axes are the rows of axes; returns
// 0 for no hit, else 2, and writes the move out to pushOut unless it is NULL.
s32 ComputeSphereHitOnRotatedCylinder(Vec3 *sphereCenter, Vec3 *cylinderCenter, Vec3 *axes, s32 cylinderRadius,
                                      s32 halfHeightPositive, s32 halfHeightNegative, s32 sphereRadius, Vec3 *pushOut);
// Sphere (radius) against the box at boxCenter whose axes are the rows of axes and whose half sizes are
// halfSizesPositive and halfSizesNegative; returns 0 for no hit, 1 when the y axis (positive side) has the least
// overlap, else 3 (x axis) or 4 (z axis), and writes the move out to pushOut unless it is NULL.
s32 ComputeSphereHitOnRotatedBox(Vec3 *sphereCenter, Vec3 *boxCenter, Vec3 *axes, const Vec3 *halfSizesPositive,
                                 const Vec3 *halfSizesNegative, s32 radius, Vec3 *pushOut);
void CreateWoodbox1(MapObjectList *list);

void DrawNsbmdWithMaxAlphaAndMaterial(Nsbmd *model, s32 maxAlpha);
// Draws the model with its alpha capped at maxAlpha (put back afterwards), through NNS_G3dDraw1Mat1Shp.
void DrawNsbmd1Mat1ShpWithMaxAlpha(Nsbmd *model, s32 maxAlpha);
// Draws the model with its alpha capped at maxAlpha (put back afterwards).
void DrawNsbmdWithMaxAlpha(Nsbmd *model, s32 maxAlpha);
void StructMLFnPtr2(NNSG3dRS *renderState);
// Draws the shadow model with its alpha capped at maxAlpha (put back afterwards).
void DrawShadowWithMaxAlpha(ShadowModel *shadow, void *matrix, Vec3 *scale, u32 maxAlpha);
// Draws the model with the matrix and scale, its alpha capped at maxAlpha (put back afterwards).
void DrawNsbmdWithMatrixAndMaxAlpha(Nsbmd *model, MtxFx43 *matrix, Vec3 *scale, s32 maxAlpha);
void BounceVelocityOffUnnormalizedSurface(Vec3 *velocity, Vec3 *surfaceNormal, s32 tangentScale, s32 bounceScale,
                                          s32 minNormalSpeed, Vec3 *result);
// Splits the velocity along surfaceNormal: the rest is scaled by tangentScale, the part along is reversed and scaled
// by bounceScale; the result goes to result.
void BounceVelocityOffSurface(Vec3 *velocity, Vec3 *surfaceNormal, s32 tangentScale, s32 bounceScale,
                              s32 minNormalSpeed, Vec3 *result);
void BlendDirectionTowardUp(Vec3 *direction, s32 blendFactor);
void BlendDirectionTowardVector(Vec3 *direction, s32 blendFactor, Vec3 *target, Vec3 *result);
// Writes to offset the move that puts the point position out of the cylinder at center (radius in x/z, halfHeight in
// y); the move has y = 0.
void ComputeCylinderOverlapOffset(Vec3 *position, Vec3 *center, s32 radius, s32 halfHeight, Vec3 *offset);
// Writes to offset the move that puts the point position exactly radius away from center.
void ComputeSphereOverlapOffset(Vec3 *position, Vec3 *center, s32 radius, Vec3 *offset);
void InitWoodbox1(Woodbox1 *woodbox, CourseMapRow *courseRow);
void ClearWoodbox1Pointer(MapObjectList *list);
u32 CollideItemObjectWithWoodbox1(Woodbox1 *woodbox, ItemObject *itemObject, u8 *firstResponse, u8 *response);
u32 CollideKartWithWoodbox1(Woodbox1 *woodbox, Kart *kart, u8 *firstResponse, u8 *response);
void UpdateWoodbox1Settle(void *stateObject);
void UpdateWoodbox1Fall(void *stateObject);
void EnterWoodbox1Fall(void *stateObject);
// Landing test of the box: when it is below the ground and falling, lifts it, reverses and scales its fall speed and
// returns TRUE.
BOOL BounceWoodbox1OffGround(Woodbox1 *woodbox);
void UpdateWoodbox1Broken(void *stateObject);
void EnterWoodbox1Broken(void *stateObject);

void AdvanceWoodbox1(u32 unused, Woodbox1 *woodbox);

extern const u16 gWoodbox1SecondFlag;
extern const u16 gWoodbox1Flag;
extern const u16 gWoodbox1ThirdFlag;
extern s32 gSavedModelAlpha;
extern Vec3 gWoodbox1GroundUp;
extern StateCallbacks gWoodbox1StateTable[4];

extern Woodbox1 *gBouncingWoodbox1;
extern Nsbmd *gWoodbox1;
extern u32 gWoodbox1PolyAttr;
extern MapObjectList *gWoodbox1UpdateList;
extern MapObjectDrawList *gWoodbox1DrawList;
