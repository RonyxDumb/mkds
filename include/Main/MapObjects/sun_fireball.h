#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "fx_mtx33.h"
#include "code_0201c528.h" // ParticleEmitter
#include "Main/MapObjects/attractor.h" // MapObject

// Values of SunFireball.mState: wait, fly in an arc (back to WAIT at each bounce), and after a kart hit rise and then
// spiral down.
enum {
    SUN_FIREBALL_STATE_WAIT,
    SUN_FIREBALL_STATE_ARC,
    SUN_FIREBALL_STATE_HIT_RISE,
    SUN_FIREBALL_STATE_HIT_SPIRAL,
};

// Object of StartSunFireball: after the shared part, a halfword at 0xa0, a counter at 0xa4, a position at 0xa8, a
// halfword at 0xb4, a state at 0xb8 and two objects at 0xbc and 0xc0.
typedef struct SunFireball {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mTimer;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mState0Timer;
    /* a8 */ Vec3 mStartPos;
    /* b4 */ u16 mMoveAngle;
    /* b6 */ u8 mUnk_b6[2];
    /* b8 */ u32 mState;
    /* bc */ ParticleEmitter *mEmitterA;
    /* c0 */ ParticleEmitter *mEmitterB;
} SunFireball;

void StartSunFireball(Vec3 *startPos, Vec3 *direction);
MapObjectList *CreateSunFireballUpdateList(void);
MapObjectKindData *CreateSunFireballKindData(void);
void UpdateSunFireball(void *mapObjectList, SunFireball *sunFireball);

unsigned int SunFireballInitReturnArgument(unsigned int value);

typedef struct ItemObject ItemObject;

u8 CollideItemObjectWithSunFireball(SunFireball *sunFireball, ItemObject *itemObject, u8 *hitFlag, u8 *passedValue);
u8 CollideKartWithSunFireball(SunFireball *sunFireball, Kart *kart, u8 *hitFlag, u8 *passedValue);

typedef struct MapObject MapObject;

void InitSunFireball(MapObject *mapObject);

extern const u32 gSunFireballSkipSoundFlag;
extern const u16 gSunFireballHitFlag;
extern const u16 gSunFireballSecondHitFlag;
extern const u16 gBoundInitMapObjectFlag;
