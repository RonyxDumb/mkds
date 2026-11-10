#pragma once

#include "types.h"

typedef struct Kart Kart;

typedef struct Kart Kart;

typedef struct Kart Kart;
typedef struct PointLink PointLink;

#include "Main/Unknown/code_0206bcb0.h"

BOOL TryHoldKartStill(Kart *kart, u32 b, void *c);
void ComputeKartAirTiltQuaternion(Kart *kart, Vec4 *quaternion);
void PlaceKartAtKeyedPlacement(Kart *kart, u32 key);
void AdvanceKartToKeyedPlacement(Kart *kart);
void StartFixedPositionEffects(Kart *kart);
void ResetKartMotionState(Kart *kart, s32 b);
void StartKartModelScaleAnimation(Kart *kart, s32 a);
void AdvanceKartHeadingSwing(Kart *kart);
void AdvanceKartOffsetCycle(Kart *kart);
void AdvanceKartModelScaleAnimation(Kart *kart);
void StartKartSeqArcSoundOffset7(Kart *kart);
void StartKartSoundWhileRequested(void *kart, int soundId);
void StartSurfaceSoundFromKart(Kart *kart, s32 entryIndex);
void StartKartSurfaceSoundWhileRequestedFromKart(void *kart, int entryIndex);
void StartSoundWhileRequestedFullVolume(SoundSource *soundSource, u32 soundId);
PlayingSound *StartSoundFullVolume(SoundSource *soundSource, u32 soundId);
void InitKartSoundParams(Kart *kart);
void InitKartSound(Kart *kart);
void ClearKartItemEffectState(KartItemEffectState *itemEffectState);
void InitKartFlags(Kart *kart);
void ResetParticipantKartRecordPos(Kart *kart);
void InitParticipantKartRecordState(Kart *kart, void *heap);
void ResetKart(Kart *kart);
void ResetKartMotionVectorsAndFactors(Kart *kart);
void InitKartPhysicalParams(Kart *kart);
// Slot 7 of Kart.mSlotFunctions, never called: when bit 0x20 of mUnk_7c is set, resets the Kart at its course start
// placement, creates its collision objects if it has none and sets bit 0x80 of mUnk_7c while clearing 0x60.
void ResetKartToStartPlacement(Kart *kart);
void StopKartItemsAndEffects(Kart *kart);
void ResetKartAndSetPos(Kart *kart, const Vec3 *position, const Vec3 *forward, PointLink *link);
s32 AdvanceKartRespawnWait(Kart *kart, s32 *a);
// Slot 6 of Kart.mSlotFunctions: puts the Kart back on the course at the respawn place of Kart.mRespawnSlot (chosen
// first when -1; in battle the course hands out its next respawn slot), starts the respawn effect and counts the
// respawn of the selected entry's Kart.
void ResetKartToRespawnPoint(Kart *kart);
void AdvanceKartScaleFactor(Kart *kart);
