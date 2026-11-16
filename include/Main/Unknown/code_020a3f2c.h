#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of kind 0x6a (Shine16), also typed MapObject (code_020a3f2c.c) where the
// pool list is walked. Object reached through mobj_getLogicPartForObjectId(0x6a), set up by shine_spawn and updated by
// shine_update: the shared MapObject part, then words up to 0xe8. shine_update switches on the word at 0xe0 (0 to 6).
typedef struct Shine16 {
    /* 00 */ MapObject mUnk_00;
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
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mMirror;
    /* bc */ s32 mNsbtpFramesSinceMirror;
    // Set to 0x19 when a kart takes the shine (a second pickup is refused while it is above 0), counted down while the
    // shine follows the kart; at 0 the shine shrinks away. 0 at spawn.
    /* c0 */ s32 mPickupTimer;
    /* c4 */ s32 mSpawnObjectIndex;
    // Index of the kart the shine follows in states 2 and 3: the kart that took it, or the kart it was released from.
    /* c8 */ u16 mKartIndex;
    /* ca */ u16 mUnk_ca;
    /* cc */ Vec3 mUnk_cc;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* State number of this kind's own per-frame switch in shine_update; this object does not use
       MapObject.mUnk_80's state machine; also read in the second draw callback func_020a683c */
    /* e0 */ s32 mState;
    /* e4 */ void *mEffect;
    /* e8 */ s32 mEffectTimer;
} Shine16;

#include "Main/Unknown/code_020a3fa8.h" // Unk020a3fa8

void *blncnt_setupLogicPart(void);
u32 CreateKartBalloonsKindData(void);
void blncnt_init(Unk020a3fa8 *a);
void blncnt_applyForceToDriverBalloons(u16 a, Vec3 *b);
void blncnt_onMgEnd(void);
void blncnt_onDriverKill(u16 a);
BOOL blncnt_loseBalloonOnDamage(u16 a, u16 b);
s32 BalloonKartsHitEachOtherCallback(u16 a, u16 b);
BOOL blncnt_tryStealBalloon(u16 a, u16 b);
void shine_driverLostSpawn(Kart *a, Kart *b);
void shine_spawn(Vec3 *a, s32 b, s32 c);
void shine_clearAll(void);
void *shine_setupLogicPart(void);
void *shine_setupRenderPart2(void);
void *shine_setupShineRenderPart(void);
void shine_setupCollision(void);
void shine_update(void *a, Shine16 *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
