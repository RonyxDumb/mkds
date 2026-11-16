#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_0206bcb0.h" // Kart

// Object of kind 0x19f (Basabasa), 0xd8 bytes: the MapObject it starts with, a vector at 0xa0 and words and halfwords
// up to 0xd4.
typedef struct Basabasa {
    /* 00 */ MapObject field0;
    /* a0 */ Vec3 mVelocity;
    /* ac */ u16 mNsbtpFrameIndex;
    /* ae */ u8 fieldAE[2];
    /* b0 */ s32 mDelayTimer;
    /* b4 */ s32 mState0Timer;
    /* b8 */ s32 mState2Timer;
    /* bc */ s32 mSoundRequested;
    /* c0 */ u16 fieldC0;
    /* c2 */ u8 fieldC2[2];
    /* c4 */ s32 fieldC4;
    /* c8 */ s32 fieldC8;
    /* cc */ s32 mRotateZNegated;
    /* d0 */ u8 mHitKartMask;
    /* d1 */ u8 fieldD1[3];
    /* State number of this kind's own per-frame switch in basa_update; this object does not use
       MapObject.field80's state machine */
    /* d4 */ s32 mState;
} Basabasa;

typedef struct Basabasa Basabasa;

void basa_loadModel(void *a);

void basa_spawn(u32 state2TimerBase, const Vec3 *startPos, const Vec3 *velocity, u32 state0TimerBase,
                   s32 soundRequested, u16 f);
void basa_setupLogicPart(void);
void basa_setupRenderPart(void);
void basa_setupConfig(void);
void basa_update(void *a, Basabasa *basabasa); /* skipped for objects with mFlags & 4 (parked pool objects) */
void basa_render(void *a, Basabasa *basabasa);
void basa_globalPreRender(void *a);
u8 basa_onDriverCollide(Basabasa *basabasa, Kart *kart, void *c, u8 *d);
/* creates the pooled object hidden (parks it with mobj_setInvisible); the spawner later takes it with
 * mobj_acquireFreeObject */
void basa_init(MapObject *mapObject);
