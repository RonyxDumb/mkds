#pragma once

#include "types.h"
#include "Main/MapObjects/teresa.h"
#include "Main/MapObjects/code_020e005c.h"
#include "Main/MapObjects/attractor.h"
#include "01/MapObjects/data_0209bc74.h"

#define CRAB_ITEM_HIT_SOUND_ID 0x10f

typedef struct ItemObject ItemObject;

// Crab.mState values: WAIT waves the hand until the timer ends, WALK follows the path, FLUNG is the flight after a
// hit, RISE comes back up to the course row's height and goes on with WAIT.
enum {
    CRAB_STATE_WAIT,
    CRAB_STATE_WALK,
    CRAB_STATE_FLUNG,
    CRAB_STATE_RISE,
};

// Object of kind 0x1ac (Crab), one state per value of mState; draws crab and crab_hand.
typedef struct Crab {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ u16 mRotateZAnglePerFrame;
    /* 0a2 */ u16 mRotateZAngle;
    /* 0a4 */ s32 mTimer;
    /* 0a8 */ s32 mCrabNsbtpFrameIndexFixed12;
    /* 0ac */ s32 mHandNsbtpFrameIndexFixed12;
    /* 0b0 */ TeresaWobble mCrabWobble;
    /* 0d0 */ TeresaWobble mHandWobble;
    /* 0f0 */ GroupFollower mFollower;
    /* State number of this kind's own per-frame switch in UpdateCrab; this object does not use
       MapObject.mStateMachine's state machine; also set by the group init and by the collision push (2) */
    /* 114 */ s32 mState;
} Crab;

typedef struct Crab Crab;
typedef struct Kart Kart;

void CreateCrabAndCrabHand(void *mapObjectList);

MapObjectList *CreateCrabUpdateList(void);
MapObjectList *CreateCrabDrawList(void);
MapObjectKindData *CreateCrabKindData(void);
void UpdateCrab(void *mapObjectList, Crab *crab); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 CrabFX_MulInline(s32 value, s32 factor);
s16 CrabFX_SinIdx(s32 angle);
void InitCrabObjects(MapObjectList *mapObjectList);
void DrawCrab(void *mapObjectList, Crab *crab);
void CrabSetupDrawNop(void);
u8 CollideItemObjectWithCrab(Crab *crab, ItemObject *itemObject, u8 *hitFlag, u8 *passedValue);
u8 CollideKartWithCrab(Crab *crab, Kart *kart, u8 *hitFlag, u8 *passedValue);
void StartCrabLaunch(Crab *crab, Vec3 *sourcePosition, Vec3 *sourceDirection, Vec3 *sourceVelocity);
void InitCrab(Crab *crab); /* starts the path follower (InitGroupFollower) */

extern struct MapObjectModel *gCrab;
extern struct MapObjectModel *gCrabHand;

extern const u16 gPakkunSpitInitMapObjectFlag;
extern const u16 gCrabLaunchFlag;
