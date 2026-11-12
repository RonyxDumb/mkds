#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject

// Object of kind 0x6a (Shine16), also typed MapObject (code_020a3f2c.c) where the
// pool list is walked. Object reached through FindMapObjectKindUpdateList(0x6a), set up by StartShine16 and updated by
// UpdateShine16: the shared MapObject part, then words up to 0xe8. UpdateShine16 switches on the word at 0xe0 (0 to 6).
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
    // Index of the kart the shine follows in states 2 and 3: the kart that took it, or the kart it was released from.
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
    // Switched on by UpdateKartBalloons for this kart (0 to 4); the hit callbacks also store 4.
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

void UpdateKartBalloons(void *mapObjectList, KartBalloonsObject *kartBalloonsObject);

void *CreateKartBalloonsUpdateList(void);
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
void *CreateShine16UpdateList(void);
void *CreateShine16ShadowDrawList(void);
void *CreateShine16DrawList(void);
void CreateShine16KindData(void);
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
