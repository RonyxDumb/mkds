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

// CoverPooHole.mState values: the cover and poo rise from the hole, hold, and sink back; the short and tall cycles
// differ in how high the cover goes. A hit during a raise state ends in the matching hit state.
enum {
    COVER_POO_HOLE_STATE_WAIT_SHORT,
    COVER_POO_HOLE_STATE_RAISE_SHORT,
    COVER_POO_HOLE_STATE_LOWER_SHORT,
    COVER_POO_HOLE_STATE_WAIT_TALL,
    COVER_POO_HOLE_STATE_RAISE_TALL,
    COVER_POO_HOLE_STATE_LOWER_TALL,
    COVER_POO_HOLE_STATE_HIT_SHORT,
    COVER_POO_HOLE_STATE_HIT_TALL,
};

// CoverPooHole.mCoverHeight: resting height, the two peak heights and the change per frame while raising or lowering.
// mPooHeight follows the cover height at a fixed depth below it.
#define COVER_POO_HOLE_REST_HEIGHT 0x2000
#define COVER_POO_HOLE_SHORT_HEIGHT 0x7800
#define COVER_POO_HOLE_TALL_HEIGHT 0x124cd
#define COVER_POO_HOLE_SHORT_STEP 0x400
#define COVER_POO_HOLE_TALL_STEP 0xc00
#define COVER_POO_HOLE_POO_DEPTH 0xf000
#define COVER_POO_HOLE_REST_POO_HEIGHT (COVER_POO_HOLE_REST_HEIGHT - COVER_POO_HOLE_POO_DEPTH)
#define COVER_POO_HOLE_SHORT_POO_HEIGHT (COVER_POO_HOLE_SHORT_HEIGHT - COVER_POO_HOLE_POO_DEPTH)
#define COVER_POO_HOLE_TALL_POO_HEIGHT (COVER_POO_HOLE_TALL_HEIGHT - COVER_POO_HOLE_POO_DEPTH)

// Start values of the two wobbles that a hit begins (16-bit angles); the Change values are added each step.
#define COVER_POO_HOLE_YAW_WOBBLE_AMPLITUDE 0x2000
#define COVER_POO_HOLE_YAW_WOBBLE_AMPLITUDE_CHANGE -0x40
#define COVER_POO_HOLE_YAW_WOBBLE_ANGLE_STEP 0x200
#define COVER_POO_HOLE_TILT_WOBBLE_AMPLITUDE 0x1000
#define COVER_POO_HOLE_TILT_WOBBLE_AMPLITUDE_CHANGE -0x30
#define COVER_POO_HOLE_TILT_WOBBLE_ANGLE_STEP 0x800
#define COVER_POO_HOLE_TILT_WOBBLE_ANGLE_STEP_CHANGE 0x100

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

#define COVER_POO_HOLE_HIT_COVER_SPEED 0x4000
#define COVER_POO_HOLE_HIT_POO_SPEED 0x1333
#define COVER_POO_HOLE_HOLE_HEIGHT 0x1000

#define COVER_POO_HOLE_KART_HIT_SOUND_ID 0x16e
#define COVER_POO_HOLE_TILT_SOUND_ID 0x16f
#define COVER_POO_HOLE_ITEM_HIT_SOUND_ID 0x1b0

BOOL IsCoverPooHoleRaising(CoverPooHole *coverPooHole);
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
u32 SetFlipperAltWaitTimerByIndex(u32 flipperIndex);

extern const u32 gCoverPooHoleSkipSoundFlag;
extern const u32 gCoverPooHoleHitDistanceFlag;
extern const u16 gNsKiller2InitMapObjectFlag;
extern struct MapObjectModel *gPoo;
extern struct MapObjectModel *gCover;
extern struct MapObjectModel *gHole;
