#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList
#include "code_0201c528.h" // Unk0201ca6c
#include "code_02012b30.h" // MtxFx43

// Object of kind 0x1a9 (Flipper), up to 0xed4 bytes plus a table of words from 0xed4.
typedef struct Flipper {
    /* 000 */ MapObject field0;
    /* 0a0 */ s32 fieldA0;
    /* 0a4 */ s32 mMirror;
    /* 0a8 */ MtxFx43 fieldA8[30];
    /* 648 */ MtxFx43 field648[30];
    /* be8 */ Vec3 fieldBE8[30];
    /* d50 */ Vec3 fieldD50[30];
    /* eb8 */ s32 mState1Timer;
    /* ebc */ s32 fieldEBC;
    /* ec0 */ s32 fieldEC0;
    /* ec4 */ u16 mNsbtpFrameIndex;
    /* ec6 */ u16 mNsbtaFrameIndex;
    /* ec8 */ s32 fieldEC8;
    /* State number of this kind's own per-frame switch in flip_update; this object does not use
       MapObject.field80's state machine */
    /* ecc */ s32 mState;
    /* ed0 */ Unk0201ca6c *fieldED0;
    /* ed4 */ s32 fieldED4[1];
} Flipper;

void *flip_setupLogicPart(void);
void *flip_setupRenderPart(void);
void flip_setupConfig(void);
void flip_update(void *a, Flipper *flipper); /* skipped for objects with mFlags & 4 (parked pool objects) */
void flip_globalLogicInit(MapObjectList *mapObjectList);
void flip_render(void *a, Flipper *flipper);
void flip_loadModel(void *a);
u32 flip_collide(Flipper *flipper, Vec3 *sphereCenter, s32 b, Vec3 *pushOut);
u32 flip_onDriverCollide(Flipper *flipper, Kart *kart, void *b, u8 *c);
void flip_init(Flipper *flipper); /* sets flag 0x200 and the ground matrix (mobj_setDirectionFromFloor) */
