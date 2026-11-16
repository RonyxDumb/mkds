#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020e005c.h" // GroupFollower
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

// Object of kind 0x1a4 (MkdEfBurner); Unk02093708 is a view of the draw group record (word +0x1c), not of this
// object. After the shared part, a counter at 0xa0, a halfword at 0xa4, a value at 0xa8, a
// state at 0xac, a GroupFollower at 0xb0 and a table of countdowns at 0xd4.
typedef struct MkdEfBurner {
    /* 00 */ MapObject field0;
    /* a0 */ s32 mStateFrames;
    /* a4 */ u16 mNsbtaFrameIndex;
    /* a6 */ u8 fieldA6[2];
    /* a8 */ s32 mScaleFixed12;
    /* State number of this kind's own per-frame switch in efbnr_update; this object does not use
       MapObject.field80's state machine; state 4 only from the group pre-step */
    /* ac */ u32 mState;
    /* b0 */ GroupFollower mFollower;
    /* d4 */ s32 mKartTimers[8];
} MkdEfBurner;

// Object of efbnr_loadModel: a word at 0x1c.
typedef struct Unk02093708 {
    /* 00 */ u8 field0[0x1c];
    /* 1c */ s32 field1C;
} Unk02093708;

#include "Main/Unknown/unk_0217b000.h" // Unk0217b498_00

u16 efbnr_getMapIconType(Unk0217b498_00 *a);
void efbnr_setupLogicPart(void);
void efbnr_setupRenderPart(void);
void efbnr_setupConfig(void);
void efbnr_update(void *a,
                       MkdEfBurner *mkdEfBurner); /* skipped for objects with mFlags & 4 (parked pool objects) */
void efbnr_globalLogicInit(MapObjectList *mapObjectList);
void efbnr_render(void *a, MkdEfBurner *mkdEfBurner);
void efbnr_applyMaterial(void *a);
void efbnr_loadModel(Unk02093708 *p); /* also sets word +0x1c of the group record to 1 */
u8 efbnr_onDriverCollide(MkdEfBurner *mkdEfBurner, Kart *kart, u8 *c, u8 *d);
void efbnr_init(
    MapObject *mapObject); /* allocates the object's sound source (mobj_initSoundEmitterForObjectSfxParam2) */
