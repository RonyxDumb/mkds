#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "matrix_3x3_basic.h"
#include "particle_instance.h" // ParticleEmitter
#include "Main/MapObjects/attractor.h" // MapObject

#define SUN_FIREBALL_LONG_LIFE_FRAMES 0x2a
#define SUN_FIREBALL_LONG_EMIT_INTERVAL 6
#define SUN_FIREBALL_MEDIUM_LIFE_FRAMES 0x23
#define SUN_FIREBALL_MEDIUM_EMIT_INTERVAL 5
#define SUN_FIREBALL_SHORT_LIFE_FRAMES 0x15
#define SUN_FIREBALL_SHORT_EMIT_INTERVAL 3

#define SUN_FIREBALL_SOUND_ID 0x195
#define SUN_FIREBALL_ITEM_HIT_SOUND_ID 0x196

// Values of SunFireball.mState: wait, fly in an arc (back to WAIT at each bounce), and after a kart hit rise and then
// spiral down.
enum {
    SUN_FIREBALL_STATE_WAIT,
    SUN_FIREBALL_STATE_ARC,
    SUN_FIREBALL_STATE_HIT_RISE,
    SUN_FIREBALL_STATE_HIT_SPIRAL,
};

// Values of SunFireball.mTimer, counted down while it flies or spirals: at the start, after a kart hit, and the frames
// left under which it no longer bounces off the course.
#define SUN_FIREBALL_LIFE_FRAMES 450
#define SUN_FIREBALL_HIT_FRAMES 360
#define SUN_FIREBALL_NO_BOUNCE_FRAMES 120

// Object of StartSunFireball: after the shared part, a halfword at 0xa0, a counter at 0xa4, a position at 0xa8, a
// halfword at 0xb4, a state at 0xb8 and two objects at 0xbc and 0xc0.
typedef struct SunFireball {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mTimer;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mWaitFrames;
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

void SunFireballInitNop(void);

typedef struct ItemObject ItemObject;

u8 CollideItemObjectWithSunFireball(SunFireball *sunFireball, ItemObject *itemObject, u8 *hitFlag, u8 *passedValue);
u8 CollideKartWithSunFireball(SunFireball *sunFireball, Kart *kart, u8 *hitFlag, u8 *passedValue);

typedef struct MapObject MapObject;

void InitSunFireball(MapObject *mapObject);

extern const u32 gSunFireballSkipSoundFlag;
extern const u16 gSunFireballHitFlag;
extern const u16 gSunFireballSecondHitFlag;
extern const u16 gBoundInitMapObjectFlag;
