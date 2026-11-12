#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList
#include "code_0201c528.h" // ParticleEmitter
#include "code_02012b30.h" // MtxFx43
#include "01/MapObjects/data_0209bc74.h"
#include "Main/MapObjects/map_object_kind_update_list.h" // MapObjectKindDescriptor

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

MapObjectList *CreateFlipperUpdateList(void);
MapObjectList *CreateFlipperDrawList(void);
MapObjectKindData *CreateFlipperKindData(void);
void UpdateFlipper(void *mapObjectList,
                   Flipper *flipper); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitFlipperObjects(MapObjectList *mapObjectList);
void DrawFlipper(void *mapObjectList, Flipper *flipper);
void CreateFlipper(void *mapObjectList);
BOOL ComputeSphereHitOnFlipper(Flipper *flipper, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *pushOut);
u32 CollideKartWithFlipper(Flipper *flipper, Kart *kart, void *firstResponse, u8 *response);
void InitFlipper(Flipper *flipper); /* sets flag 0x200 and the ground matrix (RefreshMapObjectMatrixFromHitNormal) */

extern const Vec3 gFlipperFourthBoxHalfSizesPositive[2];
extern const Vec3 gFlipperSecondBoxHalfSizesPositive[2];
extern const Vec3 gFlipperFirstBoxHalfSizesNegative[2];
extern const Vec3 gFlipperFourthBoxHalfSizesNegative[2];
extern const Vec3 gFlipperFirstBoxHalfSizesPositive[2];
extern const Vec3 gFlipperThirdBoxHalfSizesPositive[2];
extern MapObjectKindDescriptor gFlipperKindDescriptor;
extern const Vec3 gFlipperThirdBoxHalfSizesNegative[2];
extern const u16 gCoverPooHoleInitMapObjectFlag;
extern const Vec3 gFlipperSecondBoxHalfSizesNegative[2];
extern struct MapObjectModel *gFlipper;
