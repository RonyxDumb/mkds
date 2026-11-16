#pragma once

#include "types.h"

typedef struct Kart Kart;

typedef struct Kart Kart;

typedef struct Kart Kart;
typedef struct PointLink PointLink;

#include "Main/Unknown/code_0206bcb0.h"

// Declared here until the code that defines them is decompiled.
BOOL TryHoldKartStill(Kart *kart, u32 b, void *c);
void StructMQRacerEntry_SomeFn_88(Kart *kart, Vec4 *quaternion);
void driver_pipeTeleport(Kart *kart, u32 key);
void driver_handleCannon(Kart *kart);
void driver_emitCannonBlastEffect(Kart *kart);
void driver_cannonLaunch(Kart *kart, s32 b);
void StartKartModelScaleAnimation(Kart *kart, s32 a);
void AdvanceKartHeadingSwing(Kart *kart);
void sub_2071568(Kart *kart);
void AdvanceKartModelScaleAnimation(Kart *kart);
void driver_tryEmitItemUseVoice(Kart *kart);
void func_02071914(void *kart, int soundId);
void driver_emitFloorSfx2(Kart *kart, s32 entryIndex);
void driver_emitFloorSfx(void *kart, int entryIndex);
void driver_emitSfx(u32 soundSource, u32 soundId);
PlayingSound *driver_emitSfx2(SoundSource *soundSource, u32 soundId);
void driver_initField450(Kart *kart);
void driver_initSound(Kart *kart);
void driver_initTimers(KartItemEffectState *itemEffectState);
void driver_initField7C(Kart *kart);
void StructMQRacerEntry_SomeFn_48(Kart *kart);
void driver_initField514(Kart *kart, void *heap);
void ResetKart(Kart *kart);
void StructMQRacerEntry_SomeFn_11(Kart *kart);
void driver_initPhysicalParams(Kart *kart);
// Slot 7 of Kart.mSlotFunctions, never called: when bit 0x20 of field7C is set, resets the Kart at its course start
// placement, creates its collision objects if it has none and sets bit 0x80 of field7C while clearing 0x60.
void ResetKartToStartPlacement(Kart *kart);
void driver_reset(Kart *kart);
void driver_2072B94(Kart *kart, const Vec3 *position, const Vec3 *forward, PointLink *link);
s32 driver_handlePreRespawn(Kart *kart, s32 *a);
// Slot 6 of Kart.mSlotFunctions: puts the Kart back on the course at the respawn place of Kart.mRespawnSlot (chosen
// first when -1; in battle the course hands out its next respawn slot), starts the respawn effect and counts the
// respawn of the selected entry's Kart.
void driver_respawn(Kart *kart);
void AdvanceKartScaleFactor(Kart *kart);
// Declared here until the code that defines them is decompiled.
