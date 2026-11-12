#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/code_020e005c.h" // GroupFollower

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
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ s32 mWobbleXMid;
    /* 0c8 */ s32 mWobbleXAmplitude;
    /* 0cc */ s32 mWobbleXAmplitudePerFrame;
    /* 0d0 */ s32 mWobbleXAnglePerFrame;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ u16 mWobbleYAngle;
    /* 0da */ u8 mUnk_0da[2];
    /* 0dc */ s32 mWobbleScaleY;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ s32 mWobbleYMid;
    /* 0e8 */ s32 mWobbleYAmplitude;
    /* 0ec */ s32 mWobbleYAmplitudePerFrame;
    /* 0f0 */ s32 mWobbleYAnglePerFrame;
    /* 0f4 */ s32 mUnk_0f4;
    /* 0f8 */ GroupFollower mUnk_0f8;
    // TRUE while the scale wobbles; cleared when both amplitudes have reached 0.
    /* 11c */ BOOL mWobbling;
    // Per kart index: set to 0x1f after a push and counted down every frame; a push is only computed at 0.
    /* 120 */ s32 mKartTimers[8];
} Bound;

// Sun, kind 0x1ad: UpdateSun steps mState 0 to 4 and back; state 3 unparks a MAP_OBJECT_KIND_SUN_FIREBALL object twice
// per cycle.
typedef struct Sun {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ u32 mUnk_0a0;
    /* 0a4 */ u16 mUnk_0a4;
    /* 0a6 */ u8 mUnk_0a6[2];
    /* 0a8 */ s32 mTimer;
    /* 0ac */ u32 mUnk_0ac;
    /* 0b0 */ u16 mUnk_0b0;
    /* 0b2 */ u16 mNsbcaFrameIndex;
    // 1.12 fixed: mNsbcaFrameIndex grows by this >> 12; rises to 0x8000 in state 3, falls to 0x1000 in the others.
    /* 0b4 */ s32 mNsbcaFrameIndexPerFrame;
    /* 0b8 */ GroupFollower mUnk_0b8;
    /* 0dc */ s32 mState;
} Sun;

extern const char gBerryNsbmdName[];
extern const char gCreamEffectNsbmdName[];
extern const char gCreamNsbmdName[];
extern const char gBoundNsbmdName[];
extern const char gBoundNsbtpName[];
extern const char gSunNsbmdName[];
extern const char gSunNsbcaName[];
extern const char gSunLODNsbmdName[];

void CreateBound(void *mapObjectList);

extern u32 data_usa_021565d0;
extern u16 data_usa_021565d4;
extern const char data_usa_02167328[];

MapObjectKindData *CreateMapObjectKindDataWithSound(void *collideKartCallback, void *collideItemObjectCallback,
                                                    void *sphereHitCallback, u32 wordValue, u16 halfValue, u16 soundId);
MapObjectKindData *CreateEmptyMapObjectKindData(void);
void *CreateMapObjectKindData(void *collideKartCallback, void *collideItemObjectCallback, void *sphereHitCallback,
                              u32 wordValue, u16 halfValue);
BOOL StartBoundWobble(s32 mapObjectIndex);
void CreateBoundUpdateList(void);
void CreateBerryDrawList(void);
void CreateCreamDrawList(void);
void CreateBoundDrawList(void);
void CreateBerryKindData(void);
void CreateCreamKindData(void);
void CreateBoundKindData(void);
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
void CreateSunUpdateList(void);
void CreateSunDrawList(void);
void UpdateSun(MapObjectList *mapObjectList, Sun *sun); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitSunObjects(MapObjectList *mapObjectList);
void DrawSun(void *mapObjectList, Sun *sun);
