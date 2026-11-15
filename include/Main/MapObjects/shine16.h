#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject

// Values of Shine16.mState.
#define SHINE16_STATE_DROPPING 0
#define SHINE16_STATE_RESTING 1
#define SHINE16_STATE_COLLECTED_BY_KART 2
#define SHINE16_STATE_RISING_FROM_KART 3
#define SHINE16_STATE_FLYING_TO_TARGET 4
#define SHINE16_STATE_LAUNCHED_UP 5
#define SHINE16_STATE_SHRINKING 6

// Shine16.mDrawScale: full size, and the change per frame while it grows or shrinks.
#define SHINE16_DRAW_SCALE_FULL TO_FIXED12(1)
#define SHINE16_DRAW_SCALE_STEP FIXED12_RATIO(1, 10)

// A Shine16 map object: its height above the followed kart, floor y, draw scale, animation frame and state.
typedef struct Shine16 {
    /* 00 */ MapObject mMapObject;
    // Height of the shine above the followed kart's position: 0 at spawn and pickup, then grows by the shine's vertical
    // speed each frame.
    /* a0 */ s32 mHeightAboveKart;
    // y at which a falling shine bounces (the spawn point's y + 0x14000); 0 for a shine that starts resting. Only the
    // fall state reads it.
    /* a4 */ s32 mFloorY;
    /* a8 */ s32 mDrawScale;
    /* ac */ u8 mUnk_ac[4];
    // Frame index of the shine's .nsbtp animation, stepped every few frames and wrapped at the animation's frame count;
    // the draw passes it to the frame setter.
    /* b0 */ s32 mNsbtpFrameIndex;
    /* b4 */ s32 mNsbtpFrameStepProgress;
    /* b8 */ s32 mMirror;
    /* bc */ s32 mNsbtpFramesSinceMirror;
    // Set to 0x19 when a kart takes the shine (a second pickup is refused while it is above 0), counted down while the
    // shine follows the kart; at 0 the shine shrinks away. 0 at spawn.
    /* c0 */ s32 mPickupTimer;
    /* c4 */ s32 mSpawnObjectIndex;
    // Index of the kart the shine follows in the states COLLECTED_BY_KART and RISING_FROM_KART: the kart that took it,
    // or the kart it was released from.
    /* c8 */ u16 mKartIndex;
    /* ca */ u16 mHitByKartIndex;
    /* cc */ Vec3 mTargetPos;
    /* d8 */ s32 mTargetDistanceSquared;
    /* dc */ s32 mTargetPickCount;
    /* State number of this kind's own per-frame switch in UpdateShine16; this object does not use
       MapObject.mUnk_80's state machine; also read in the shadow draw callback DrawShine16Shadow */
    /* e0 */ s32 mState;
    /* e4 */ void *mEffect;
    /* e8 */ s32 mEffectTimer;
} Shine16;

#include "Main/MapObjects/balloon.h" // Balloon
#include "01/MapObjects/map_object_model.h"

#define SHINE16_PICKUP_FRAMES 0x19
#define SHINE16_EFFECT_FRAMES 0xe
#define SHINE16_NSBTP_FRAME_STEP_LIMIT 3
#define SHINE16_NSBTP_MIRROR_FRAMES 8
#define SHINE16_TARGET_DISTANCE_SQUARED 0x9c400

#define SHINE16_HEIGHT_RANGE_MAX 0x190000

// KartBalloons.mState values: IDLE waits for the inflate input, AUTO_INFLATE makes the balloons given at the start,
// INFLATE_TO_HALF and INFLATE_TO_FULL inflate the balloon being made (from the first half of its size on, the input
// may stop), SHRINK deflates it.
enum {
    KART_BALLOONS_STATE_IDLE,
    KART_BALLOONS_STATE_AUTO_INFLATE,
    KART_BALLOONS_STATE_INFLATE_TO_HALF,
    KART_BALLOONS_STATE_INFLATE_TO_FULL,
    KART_BALLOONS_STATE_SHRINK,
};

// The balloons of one kart (0x38 bytes, one per kart index in the kind 0x69 object; Standings.mKartBalloons points at
// the first): the list of its Balloon objects with the state that makes, inflates and holds them.
typedef struct KartBalloons {
    // Frames left before the next balloon is made (state 0); 30 after a balloon is finished with none left to make, 0
    // when one is gone.
    /* 00 */ s32 mSpawnTimer;
    // Balloons state 1 still makes: from the course row's word or 1; counted down by each balloon made.
    /* 04 */ s32 mRemainingSpawnCount;
    /* 08 */ s32 mSwing;
    /* 0c */ s32 mSwingPerFrame;
    // The kart's balloons in order; the one being inflated is at the index equal to the kart's count.
    /* 10 */ Balloon *mBalloons[8];
    // Frame index every balloon of this kart is created with (Balloon.mNsbtpFrameIndex): the course row's word when it
    // is non-zero, else team index 0 gives 1, team index 1 gives 3, any other value the kart index. Never stepped.
    /* 30 */ u16 mBalloonNsbtpFrameIndex;
    /* 32 */ u8 mUnk_32[0x2];
    // Switched on by UpdateKartBalloons for this kart; the hit callbacks also store SHRINK.
    /* 34 */ s32 mState;
} KartBalloons;

// Object of map object kind 0x69: steps the balloons of every kart. A MapObject first, then mStartTimer, eight
// KartBalloons and the balloon offsets; 0x364 bytes, the size in its kind descriptor.
typedef struct KartBalloonsObject {
    /* 000 */ MapObject mMapObject;
    // Frames left before the first balloons are made: the update does nothing until it reaches 0, then puts every entry
    // in state 1. Starts at 0x3c, or 0xffff when gRace.mUseChainCameras is non-zero.
    /* 0a0 */ s32 mStartTimer;
    // One KartBalloons entry per kart index (the first mKartCount are used).
    /* 0a4 */ KartBalloons mKartBalloons[8];
    // Sideways offsets of one kart's balloons, indexed [balloon count - 1][balloon index]: 0xc00 apart, centred on the
    // kart; added to the local kart's sway offset.
    /* 264 */ s32 mBalloonOffsets[8][8];
} KartBalloonsObject;

typedef struct MapObjectList MapObjectList;

void UpdateKartBalloons(void *mapObjectList, KartBalloonsObject *kartBalloonsObject);

MapObjectList *CreateKartBalloonsUpdateList(void);
MapObjectKindData *CreateKartBalloonsKindData(void);
void InitKartBalloons(KartBalloonsObject *kartBalloonsObject);
void BalloonKartOffsetCallback(u16 kartIndex, Vec3 *offset);
void BalloonEndCallback(void);
void BalloonKartEliminatedCallback(u16 kartIndex);
BOOL BalloonKartHitCallback(u16 kartIndex, u16 hitByKartIndex);
s32 BalloonKartsHitEachOtherCallback(u16 firstKartIndex, u16 secondKartIndex);
BOOL BalloonKartHitByKartCallback(u16 hitKartIndex, u16 hitByKartIndex);
void StartShine16FromKart(Kart *hitKart, Kart *hitByKart);
void StartShine16(Vec3 *position, s32 spawnObjectIndex, s32 dropFromAbove);
void ParkShine16Objects(void);
MapObjectList *CreateShine16UpdateList(void);
MapObjectList *CreateShine16ShadowDrawList(void);
MapObjectList *CreateShine16DrawList(void);
MapObjectKindData *CreateShine16KindData(void);
void UpdateShine16(void *mapObjectList,
                   Shine16 *shine16); /* skipped for objects with mFlags & 4 (parked pool objects) */

void AdvanceShine16ShadowAngleIndex(void);
void DrawShine16Shadow(void *mapObjectList, Shine16 *shine16, void *unused, s32 maxAlpha);

u16 *ResetShine16ShadowAngleIndex(void);

u32 CollideKartWithShine16(Shine16 *shine16, Kart *kart, u8 *firstResponse, u8 *response);
void CreateShine16(void *mapObjectList);
void SetupDrawShine16(void *mapObjectList);
void DrawShine16(void *mapObjectList, Shine16 *shine16);

typedef struct MapObject MapObject;

void InitShine16(MapObject *mapObject); /* parks the pooled object, then allocates its 0x44 effect record */

extern const u16 gShine16ShadowAngles[4];
extern const u16 gShine16HitFlag;
extern const u16 gBalloonHideThirdFlag;
extern const u16 gBalloonHideSecondFlag;
extern const u16 gBalloonHideFirstFlag;
extern u16 gShine16ShadowAngleIndex;
extern struct MapObjectModel *gShine16;
