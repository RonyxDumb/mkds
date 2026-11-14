#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList
#include "code_0201c528.h" // ParticleEmitter
#include "code_02012b30.h" // MtxFx43
#include "01/MapObjects/data_0209bc74.h"
#include "Main/MapObjects/map_object_kind_update_list.h" // MapObjectKindDescriptor

// Values of Flipper.mState; the ALT states are the same cycle at double step after mState4Timer was set.
enum {
    FLIPPER_STATE_START,
    FLIPPER_STATE_WAIT,
    FLIPPER_STATE_SWING_OUT,
    FLIPPER_STATE_SWING_BACK,
    FLIPPER_STATE_ALT_WAIT,
    FLIPPER_STATE_ALT_SWING_OUT,
    FLIPPER_STATE_ALT_SWING_BACK,
};

// Object of kind 0x1a9 (Flipper), up to 0xed4 bytes plus a table of words from 0xed4.
typedef struct Flipper {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mHitSide;
    /* 0a4 */ s32 mMirror;
    /* 0a8 */ MtxFx43 mSwingMatrices[30];
    /* 648 */ MtxFx43 mTiltedSwingMatrices[30];
    /* be8 */ Vec3 mEmitterStarts[30];
    /* d50 */ Vec3 mEmitterEnds[30];
    /* eb8 */ s32 mState1Timer;
    /* ebc */ s32 mState4Timer;
    /* ec0 */ s32 mSwingStep;
    /* ec4 */ u16 mNsbtpFrameIndex;
    /* ec6 */ u16 mNsbtaFrameIndex;
    /* ec8 */ s32 mIsAnimating;
    /* State number of this kind's own per-frame switch in UpdateFlipper; this object does not use
       MapObject.mStateMachine's state machine */
    /* ecc */ s32 mState;
    /* ed0 */ ParticleEmitter *mEmitter;
    /* ed4 */ s32 mKartCooldownFrames[1];
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
