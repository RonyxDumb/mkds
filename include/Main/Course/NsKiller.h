#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020e005c.h" // GroupFollower
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange

// Object of kind 0x1a2 (NsKiller2), pool objects: after the shared part, a counter at 0xa0, mMode at 0xa4 and an
// object at 0xa8.
typedef struct NsKiller2 {
    /* 00 */ MapObject field0;
    /* a0 */ s32 mParkTimer;
    /* a4 */ s32 mMode;
    /* a8 */ SoundDistanceSquaredChange *mSoundDistanceSquaredChange;
} NsKiller2;

// Object of kind 0x1a1 (NsKiller1), creates 20 NsKiller2 in its Init: after the shared part, a counter at 0xa0, a state
// at 0xa8 and an GroupFollower at 0xac.
typedef struct NsKiller1 {
    /* 00 */ MapObject field0;
    /* a0 */ s32 mStateTimer;
    /* a4 */ u8 fieldA4[4];
    /* State number of this kind's own per-frame switch in nsk1_update; this object does not use
       MapObject.field80's state machine */
    /* a8 */ s32 mState;
    /* ac */ GroupFollower mFollower;
} NsKiller1;

void nsk2_spawn(Vec3 *startPos, Vec3 *b, u16 angle);
void nsk2_setupLogicPart(void);
void nsk2_setupRenderPart(void);
void nsk2_setupConfig(void);
void nsk2_update(void *a, NsKiller2 *nsKiller2); /* skipped for objects with mFlags & 4 (parked pool objects) */
void nsk2_render(void *a, NsKiller2 *nsKiller2);
void nsk2_loadModels(void *a);
u8 nsk2_onDriverCollide(NsKiller2 *nsKiller2, Kart *kart, u8 *c, u8 *d);
/* creates the pooled object hidden (parks it with mobj_setInvisible); the spawner later takes it with
 * mobj_acquireFreeObject */
void nsk2_init(NsKiller2 *nsKiller2);
void nsk1_setupLogicPart(void);
void nsk1_setupRenderPart(void);
void nsk1_update(void *a, NsKiller1 *nsKiller1); /* skipped for objects with mFlags & 4 (parked pool objects) */
void nsk1_globalLogicInit(MapObjectList *mapObjectList);
void nsk1_render(void *a, NsKiller1 *nsKiller1);
void nsk1_loadModel(void *a);
