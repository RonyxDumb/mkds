#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/code_020e005c.h" // GroupFollower
#include "01/MapObjects/data_0209bc74.h"

// Object of kinds 0x1a8, 0x1b4 and 0x1b5 (Bound, Cream, Berry); mWobbling is set while its scale wobbles.
typedef struct Bound {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ u16 mNsbtpFrameIndex;
    /* 0a2 */ u8 mUnk_0a2[2];
    /* 0a4 */ s32 mSphereHit;
    /* 0a8 */ u8 mUnk_0a8[0xc];
    /* 0b4 */ s32 mInitialScaleX;
    /* 0b8 */ u16 mWobbleXAngle;
    /* 0ba */ u8 mUnk_0ba[2];
    // Scale factor of x and z (1.12 fixed): mWobbleXMid plus mWobbleXAmplitude times the angle pair of mWobbleXAngle.
    /* 0bc */ s32 mWobbleScaleX;
    /* 0c0 */ s32 mWobbleScaleXDelta;
    /* 0c4 */ s32 mWobbleXMid;
    /* 0c8 */ s32 mWobbleXAmplitude;
    /* 0cc */ s32 mWobbleXAmplitudePerFrame;
    /* 0d0 */ s32 mWobbleXAnglePerFrame;
    /* 0d4 */ s32 mWobbleXAnglePerFrameChange;
    /* 0d8 */ u16 mWobbleYAngle;
    /* 0da */ u8 mUnk_0da[2];
    /* 0dc */ s32 mWobbleScaleY;
    /* 0e0 */ s32 mWobbleScaleYDelta;
    /* 0e4 */ s32 mWobbleYMid;
    /* 0e8 */ s32 mWobbleYAmplitude;
    /* 0ec */ s32 mWobbleYAmplitudePerFrame;
    /* 0f0 */ s32 mWobbleYAnglePerFrame;
    /* 0f4 */ s32 mWobbleYAnglePerFrameChange;
    /* 0f8 */ GroupFollower mFollower;
    // TRUE while the scale wobbles; cleared when both amplitudes have reached 0.
    /* 11c */ BOOL mWobbling;
    // Per kart index: set to 0x1f after a push and counted down every frame; a push is only computed at 0.
    /* 120 */ s32 mKartTimers[8];
} Bound;

// Sun, kind 0x1ad: UpdateSun steps mState 0 to 4 and back; state 3 unparks a MAP_OBJECT_KIND_SUN_FIREBALL object twice
// per cycle.
typedef struct Sun {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ u32 mFireballIndex;
    /* 0a4 */ u16 mFireballAngle;
    /* 0a6 */ u8 mUnk_0a6[2];
    /* 0a8 */ s32 mTimer;
    /* 0ac */ u32 mDrawOffsetRadiusAngle;
    /* 0b0 */ u16 mDrawOffsetAngle;
    /* 0b2 */ u16 mNsbcaFrameIndex;
    // 1.12 fixed: mNsbcaFrameIndex grows by this >> 12; rises to 0x8000 in state 3, falls to 0x1000 in the others.
    /* 0b4 */ s32 mNsbcaFrameIndexPerFrame;
    /* 0b8 */ GroupFollower mFollower;
    /* 0dc */ s32 mState;
} Sun;

void CreateBound(void *mapObjectList);

MapObjectKindData *CreateMapObjectKindDataWithSound(void *collideKartCallback, void *collideItemObjectCallback,
                                                    void *sphereHitCallback, u32 wordValue, u16 halfValue, u16 soundId);
MapObjectKindData *CreateEmptyMapObjectKindData(void);
void *CreateMapObjectKindData(void *collideKartCallback, void *collideItemObjectCallback, void *sphereHitCallback,
                              u32 wordValue, u16 halfValue);
BOOL StartBoundWobble(s32 mapObjectIndex);
MapObjectList *CreateBoundUpdateList(void);
MapObjectList *CreateBerryDrawList(void);
MapObjectList *CreateCreamDrawList(void);
MapObjectList *CreateBoundDrawList(void);
MapObjectKindData *CreateBerryKindData(void);
MapObjectKindData *CreateCreamKindData(void);
MapObjectKindData *CreateBoundKindData(void);
void UpdateBoundAndCreamAndBerry(MapObjectList *mapObjectList, Bound *bound);
s32 BoundFX_MulInline(s32 value, s32 scale);
s16 BoundFX_SinIdx(s32 angle);
void InitBoundAndCreamAndBerryObjects(MapObjectList *mapObjectList);
void DrawBerry(MapObjectList *mapObjectList, Bound *bound);
void DrawCream(MapObjectList *mapObjectList, Bound *bound);
void CreateBerry(void *mapObjectList); /* also loads cream_effect.nsbmd */
void CreateCream(void *mapObjectList); /* also loads cream_effect.nsbmd */
void DrawBound(MapObjectList *mapObjectList, Bound *bound);
BOOL ComputeSphereHitOnBound(Bound *bound, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *pushOut);
u8 CollideItemObjectWithBound(Bound *bound, void *itemObject, u8 *firstResponse, u8 *response);
s32 CollideKartWithBound(Bound *bound, Kart *kart, u8 *firstResponse, u8 *response);
void InitBound(Bound *bound);
MapObjectList *CreateSunUpdateList(void);
MapObjectList *CreateSunDrawList(void);
void UpdateSun(MapObjectList *mapObjectList, Sun *sun); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitSunObjects(MapObjectList *mapObjectList);
void DrawSun(void *mapObjectList, Sun *sun);

extern const u32 gBoundHitDistanceFlag;
extern struct MapObjectModel *gBound;
extern struct MapObjectModel *gBerry;
extern struct MapObjectModel *gCream;
