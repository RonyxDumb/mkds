#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Kart/kart_drift.h" // Kart

// Object of kind 0x19f (Basabasa), 0xd8 bytes: the MapObject it starts with, a vector at 0xa0 and words and halfwords
// up to 0xd4.
typedef struct Basabasa {
    /* 00 */ MapObject mMapObject;
    /* a0 */ Vec3 mVelocity;
    /* ac */ u16 mNsbtpFrameIndex;
    /* ae */ u8 mUnk_ae[2];
    /* b0 */ s32 mDelayTimer;
    /* b4 */ s32 mState0Timer;
    /* b8 */ s32 mState2Timer;
    /* bc */ s32 mSoundRequested;
    /* c0 */ u16 mRaceHudSubScreenCellKind;
    /* c2 */ u8 mUnk_c2[2];
    /* c4 */ s32 mUnk_c4;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mRotateZNegated;
    /* d0 */ u8 mHitKartMask;
    /* d1 */ u8 mUnk_d1[3];
    /* State number of this kind's own per-frame switch in UpdateBasabasa; this object does not use
       MapObject.mUnk_80's state machine */
    /* d4 */ s32 mState;
} Basabasa;

typedef struct Basabasa Basabasa;

void CreateBasabasa(void *mapObjectList);

void StartBasabasa(u32 state2TimerBase, const Vec3 *startPos, const Vec3 *velocity, u32 state0TimerBase,
                   s32 soundRequested, u16 subScreenCellKind);
void CreateBasabasaUpdateList(void);
void CreateBasabasaDrawList(void);
void CreateBasabasaKindData(void);
void UpdateBasabasa(void *mapObjectList,
                    Basabasa *basabasa); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawBasabasa(void *mapObjectList, Basabasa *basabasa);
void SetupDrawBasabasa(void *mapObjectList);
u8 CollideKartWithBasabasa(Basabasa *basabasa, Kart *kart, void *unusedArg1, u8 *inOutResult);
/* creates the pooled object hidden (parks it with ParkMapObject); the spawner later takes it with
 * UnparkFirstParkedMapObject */
void InitBasabasa(MapObject *mapObject);
