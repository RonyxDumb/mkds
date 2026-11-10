#pragma once

#include "types.h"

struct MapObjectSound;

// The four words of gBalloonSoundStartParams, read as one 16-byte object.
typedef struct Unk0216ca48 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Vec3 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0216ca48;

#include "Main/Unknown/code_0206bcb0.h" // Kart

extern Unk0216ca48 gBalloonSoundStartParams;

void InitSceneSoundsNop(void);
void StartIronBallSpeedSound(struct MapObjectSound *mapSound, s32 fixedValue);
void StartIronBallBounceSound(struct MapObjectSound *soundSource, s32 fixedValue);
void QueueBalloonSound(void *position, s32 distanceSquared);
void StartBalloonSound(void *position, s32 distanceSquared);
void QueueShine16Sound(struct MapObjectSound *mapSound, s32 soundId);
void QueueShine16SoundWhileRequested(struct MapObjectSound *mapSound, s32 soundId);
void StartMapObjectCounterSound(void *mapSound, s32 baseSoundId);
void ResetMapObjectSoundCounter(void);
