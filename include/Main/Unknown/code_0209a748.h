#pragma once

#include "types.h"
#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020e6fd4.h"

typedef struct ItemObject ItemObject;

// Object of kind 0x1ac (Crab), one state per value of mState; draws crab and crab_hand.
typedef struct Crab {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mRotateZAnglePerFrame;
    /* 0a2 */ u16 mRotateZAngle;
    /* 0a4 */ s32 mTimer;
    /* 0a8 */ s32 mCrabNsbtpFrameIndexFixed12;
    /* 0ac */ s32 mHandNsbtpFrameIndexFixed12;
    /* 0b0 */ TeresaWobble mCrabWobble;
    /* 0d0 */ TeresaWobble mHandWobble;
    /* 0f0 */ GroupFollower mFollower;
    /* State number of this kind's own per-frame switch in crab_update; this object does not use MapObject.mUnk_80's
       state machine; also set by the group init and by the collision push (2) */
    /* 114 */ s32 mState;
} Crab;

// Table of object pointers with a halfword count behind it.
typedef struct Unk0209af98 {
    /* 00 */ Crab **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
} Unk0209af98;

typedef struct Crab Crab;
typedef struct Kart Kart;

void crab_loadModels(void *a);

void *crab_setupLogicPart(void);
void *crab_setupRenderPart(void);
void crab_setupConfig(void);
void crab_update(void *a, Crab *crab); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 crab_FX_MulInline(s32 a, s32 b);
s16 crab_FX_SinIdx(s32 a);
void crab_globalLogicInit(Unk0209af98 *mapObjectList);
void crab_render(void *a, Crab *crab);
unsigned int crab_globalPreRender(unsigned int p0);
u8 crab_onItemCollide(Crab *crab, ItemObject *itemObject, u8 *c, u8 *d);
u8 crab_onDriverCollide(Crab *crab, Kart *kart, u8 *c, u8 *d);
void crab_209B388(Crab *crab, Vec3 *sourcePosition, Vec3 *sourceDirection, Vec3 *sourceVelocity);
void crab_init(u32 crab); /* starts the path follower (pw_initFromObject) */
