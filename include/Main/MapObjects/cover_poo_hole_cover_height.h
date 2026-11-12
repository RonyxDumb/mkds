#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList

typedef struct CoverPooHole CoverPooHole;

s32 GetCoverPooHoleHitCoverHeight(CoverPooHole *object);

typedef struct ItemObject ItemObject;

// CoverPooHole.mHitState values.
#define COVER_POO_HOLE_HIT_NONE 0
#define COVER_POO_HOLE_HIT_THROWN 1
#define COVER_POO_HOLE_HIT_WOBBLING 2

// Object up to 0x109 bytes.
typedef struct CoverPooHole {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mCoverHeight;
    /* a4 */ s32 mPooHeight;
    /* a8 */ s32 mHoleHeight;
    /* ac */ s32 mTimer;
    /* b0 */ s32 mState;
    /* b4 */ s32 mHitCoverHeight;
    /* b8 */ s32 mHitPooHeight;
    /* bc */ s32 mHitCoverSpeed;
    /* c0 */ s32 mHitPooSpeed;
    /* c4 */ u16 mYawWobbleAngle;
    /* c6 */ u8 mUnk_c6[2];
    /* c8 */ s32 mYawWobbleOffset;
    /* cc */ s32 mYawWobbleOffsetDelta;
    /* d0 */ s32 mYawWobbleCenter;
    /* d4 */ s32 mYawWobbleAmplitude;
    /* d8 */ s32 mYawWobbleAmplitudeChange;
    /* dc */ s32 mYawWobbleAngleStep;
    /* e0 */ s32 mYawWobbleAngleStepChange;
    /* e4 */ u16 mTiltWobbleAngle;
    /* e6 */ u8 mUnk_e6[2];
    /* e8 */ s32 mTiltWobbleOffset;
    /* ec */ s32 mTiltWobbleOffsetDelta;
    /* f0 */ s32 mTiltWobbleCenter;
    /* f4 */ s32 mTiltWobbleAmplitude;
    /* f8 */ s32 mTiltWobbleAmplitudeChange;
    /* fc */ s32 mTiltWobbleAngleStep;
    /* 100 */ s32 mTiltWobbleAngleStepChange;
    /* 104 */ s32 mHitState;
    /* 108 */ u8 mKartHitMask;
} CoverPooHole;

#include "Main/Kart/kart_drift.h" // Kart
#include "01/MapObjects/data_0209bc74.h"

BOOL IsCoverPooHoleState1Or4(CoverPooHole *coverPooHole);
MapObjectList *CreateCoverPooHoleUpdateList(void);
MapObjectList *CreateCoverPooHoleDrawList(void);
MapObjectKindData *CreateCoverPooHoleKindData(void);
void UpdateCoverPooHole(void *mapObjectList,
                        CoverPooHole *coverPooHole); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 CoverPooHoleFX_MulInline(s32 value, s32 scale);
s32 CoverPooHoleFX_SinIdx(s32 angle);
void InitCoverPooHoleObjects(MapObjectList *mapObjectList);
void DrawCoverPooHole(void *mapObjectList, CoverPooHole *coverPooHole);
void CreateCoverPooHole(void *mapObjectList);
BOOL TryGetCoverPooHolePushOut(CoverPooHole *coverPooHole, const Vec3 *position, s32 radius, Vec3 *pushOut);
u32 CollideItemObjectWithCoverPooHole(CoverPooHole *coverPooHole, ItemObject *itemObject, u8 *firstResponsePtr,
                                      u8 *secondResponsePtr);
u32 CollideKartWithCoverPooHole(CoverPooHole *coverPooHole, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
void InitCoverPooHole(MapObject *mapObject);
u32 SetFlipperState4TimerByIndex(u32 flipperIndex);

extern const u32 gCoverPooHoleSkipSoundFlag;
extern const u32 data_021564b8;
extern const u16 gNsKiller2InitMapObjectFlag;
extern struct MapObjectModel *gPoo;
extern struct MapObjectModel *gCover;
extern struct MapObjectModel *gHole;
