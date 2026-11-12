#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

#include "code_02146d78.h"
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

#include "Main/Unknown/code_020a3fa8.h" // KartBalloonsObject

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
