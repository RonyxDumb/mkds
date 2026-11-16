#pragma once

#include "types.h"

typedef struct Kart Kart;

typedef struct Kart Kart;

typedef struct Kart Kart;
typedef struct PointLink PointLink;

#include "Main/Kart/kart_drift.h"

BOOL TryHoldKartStill(Kart *kart, u32 collisionBits, void *hitListPtr);
void StructMQRacerEntry_SomeFn_88(Kart *kart, Vec4 *quaternion);
void PlaceKartAtKeyedPlacement(Kart *kart, u32 key);
void AdvanceKartToKeyedPlacement(Kart *kart);
void StructMQRacerEntry_SomeFn_12(Kart *kart);
void ResetKartMotionState(Kart *kart, s32 flag);
void StartKartModelScaleAnimation(Kart *kart, s32 mode);
void AdvanceKartHeadingSwing(Kart *kart);
void AdvanceKartOffsetCycle(Kart *kart);
void StructMQRacerEntry_SomeFn_85(Kart *kart);
void StartKartSeqArcSoundOffset7(Kart *kart);
void StartKartSoundWhileRequested(void *kart, int soundId);
void StartSurfaceSoundFromKart(Kart *kart, s32 entryIndex);
void StartKartSurfaceSoundWhileRequestedFromKart(void *kart, int entryIndex);
void StartSoundWhileRequestedFullVolume(SoundSource *soundSource, u32 soundId);
PlayingSound *StartSoundFullVolume(SoundSource *soundSource, u32 soundId);
void StructMQRacerEntry_SomeFn_24(Kart *kart);
void StructMQRacerEntry_SomeFn_49(Kart *kart);
void ClearKartItemEffectState(KartItemEffectState *itemEffectState);
void StructMQRacerEntry_SomeFn_44(Kart *kart);
void StructMQRacerEntry_SomeFn_48(Kart *kart);
void StructMQRacerEntry_InitializeSub(Kart *kart, void *heap);
void StructMQRacerEntry_Fn1(Kart *kart);
void StructMQRacerEntry_SomeFn_11(Kart *kart);
void StructMQRacerEntry_SomeFn_43(Kart *kart);
// Slot 7 of Kart.mSlotFunctions, never called: when KART_ENTRY_REMOVED is set, resets the Kart at its course start
// placement, creates its collision objects if it has none and sets KART_ENTRY_SCALING_IN in mEntryFlags while clearing
// KART_ENTRY_REMOVED and KART_ENTRY_HIDDEN.
void StructMQRacerEntry_Fn7(Kart *kart);
void StructMQRacerEntry_SomeFn_16(Kart *kart);
void StructMQRacerEntry_SomeFn_63(Kart *kart, const Vec3 *position, const Vec3 *forward, PointLink *link);
s32 AdvanceKartRespawnWait(Kart *kart, s32 *outVelocityScale);
// Slot 6 of Kart.mSlotFunctions: puts the Kart back on the course at the respawn place of Kart.mRespawnSlot (chosen
// first when -1; in battle the course hands out its next respawn slot), starts the respawn effect and counts the
// respawn of the selected entry's Kart.
void StructMQRacerEntry_Fn6(Kart *kart);
void AdvanceKartScaleFactor(Kart *kart);

extern const Vec3 g_UnitX_VecFx32;
extern const Vec3 g_UnitY_VecFx32;
extern const Vec3 g_UnitZ_VecFx32;
extern const Vec3 gKartOffsetCycleStartAmount;
extern const Vec3 gKartVec3Zero;
