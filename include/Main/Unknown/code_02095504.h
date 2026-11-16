#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020e005c.h" // GroupFollower
#include "Main/Unknown/code_020e516c.h" // ShadowMatrix

// Object of kind 0x13c (Bakubaku): after the shared part, a counter at 0xa0, a vector at 0xa4 and a state at 0xb0.
typedef struct Bakubaku {
    /* 00 */ MapObject field0;
    /* a0 */ s32 mState4Timer;
    /* a4 */ Vec3 fieldA4;
    /* State number of this kind's own per-frame switch in baku_update; this object does not use
       MapObject.field80's state machine; also read by the draw (state 2 = drawn) */
    /* b0 */ u32 mState;
} Bakubaku;

// Object of kind 0x1a3 (MoveTree): after the shared part, three counters from 0xa0, a halfword at 0xac, a value at
// 0xb0, an GroupFollower at 0xb4, a state at 0xd8 and an ShadowMatrix at 0xdc.
typedef struct MoveTree {
    /* 00 */ MapObject field0;
    /* a0 */ s32 mState0Timer;
    /* a4 */ s32 fieldA4;
    /* a8 */ s32 fieldA8;
    /* ac */ u16 mNsbcaFrameIndex;
    /* ae */ u8 fieldAE[2];
    /* b0 */ s32 mNsbcaFrameStep;
    /* b4 */ GroupFollower mFollower;
    /* State number of this kind's own per-frame switch in mtree_update; this object does not use
       MapObject.field80's state machine */
    /* d8 */ u32 mState;
    /* dc */ ShadowMatrix fieldDC;
} MoveTree;

void baku_setupLogicPart(void);
void baku_setupRenderPart(void);
void baku_update(void *a, Bakubaku *bakubaku); /* skipped for objects with mFlags & 4 (parked pool objects) */
void baku_globalLogicInit(MapObjectList *mapObjectList);
void baku_render(void *a, Bakubaku *bakubaku);
void baku_loadModels(void *a);
void mtree_setupLogicPart(void);
void mtree_setupRenderPart(void);
void mtree_setupConfig(void);
void mtree_update(void *a, MoveTree *moveTree); /* skipped for objects with mFlags & 4 (parked pool objects) */
void mtree_globalLogicInit(MapObjectList *mapObjectList);
void mtree_render(void *a, MoveTree *moveTree, u32 c, u32 d);
void mtree_loadModel(void *a);
u8 mtree_onDriverCollide(MoveTree *moveTree, Kart *kart, u8 *c, u8 *d);
