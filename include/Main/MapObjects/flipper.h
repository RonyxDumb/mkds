#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "code_02146d78.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList
#include "code_0201c528.h" // ParticleEmitter
#include "code_02012b30.h" // MtxFx43

// Object of kind 0x1a9 (Flipper), up to 0xed4 bytes plus a table of words from 0xed4.
typedef struct Flipper {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mUnk_a0;
    /* 0a4 */ s32 mMirror;
    /* 0a8 */ MtxFx43 mUnk_a8[30];
    /* 648 */ MtxFx43 mUnk_648[30];
    /* be8 */ Vec3 mUnk_be8[30];
    /* d50 */ Vec3 mUnk_d50[30];
    /* eb8 */ s32 mState1Timer;
    /* ebc */ s32 mState4Timer;
    /* ec0 */ s32 mUnk_ec0;
    /* ec4 */ u16 mNsbtpFrameIndex;
    /* ec6 */ u16 mNsbtaFrameIndex;
    /* ec8 */ s32 mUnk_ec8;
    /* State number of this kind's own per-frame switch in UpdateFlipper; this object does not use
       MapObject.mUnk_80's state machine */
    /* ecc */ s32 mState;
    /* ed0 */ ParticleEmitter *mUnk_ed0;
    /* ed4 */ s32 mUnk_ed4[1];
} Flipper;

void *CreateFlipperUpdateList(void);
void *CreateFlipperDrawList(void);
void CreateFlipperKindData(void);
void UpdateFlipper(void *mapObjectList,
                   Flipper *flipper); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitFlipperObjects(MapObjectList *mapObjectList);
void DrawFlipper(void *mapObjectList, Flipper *flipper);
void CreateFlipper(void *mapObjectList);
BOOL ComputeSphereHitOnFlipper(Flipper *flipper, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *pushOut);
u32 CollideKartWithFlipper(Flipper *flipper, Kart *kart, void *firstResponse, u8 *response);
void InitFlipper(Flipper *flipper); /* sets flag 0x200 and the ground matrix (RefreshMapObjectMatrixFromHitNormal) */
