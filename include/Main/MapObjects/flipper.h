#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList
#include "particle_instance.h" // ParticleEmitter
#include "model_material_set.h" // MtxFx43
#include "01/MapObjects/map_object_model.h"
#include "Main/MapObjects/map_object_kind_update_list.h" // MapObjectKindDescriptor

#define FLIPPER_ALT_WAIT_FRAMES 0xaa

#define FLIPPER_WAIT_FRAMES 0x1e
#define FLIPPER_SWING_OUT_STEPS 0x1d
#define FLIPPER_ALT_SWING_OUT_STEPS 0x1c
#define FLIPPER_SWING_BACK_STEP_LIMIT 0xf

// Values of Flipper.mState; the ALT states are the same cycle at double step after mAltWaitFrames was set.
enum {
    FLIPPER_STATE_START,
    FLIPPER_STATE_WAIT,
    FLIPPER_STATE_SWING_OUT,
    FLIPPER_STATE_SWING_BACK,
    FLIPPER_STATE_ALT_WAIT,
    FLIPPER_STATE_ALT_SWING_OUT,
    FLIPPER_STATE_ALT_SWING_BACK,
};

// A flipper map object: its swing matrices, particle emitter positions, animation frames, timers and state.
typedef struct Flipper {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mHitSide;
    /* 0a4 */ s32 mMirror;
    /* 0a8 */ MtxFx43 mSwingMatrices[30];
    /* 648 */ MtxFx43 mTiltedSwingMatrices[30];
    /* be8 */ Vec3 mEmitterStarts[30];
    /* d50 */ Vec3 mEmitterEnds[30];
    /* eb8 */ s32 mWaitTimer;
    /* ebc */ s32 mAltWaitFrames;
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
void LoadFlipperMapObject(void *mapObjectList);
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
extern struct MapObjectModel *g_FlipperMapObject;
