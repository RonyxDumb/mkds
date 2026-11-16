#pragma once

#include "types.h"

struct MapObjectSound;

typedef struct SoundStartParams SoundStartParams;

#include "Main/Kart/kart_drift.h" // Kart
#include "Main/Sound/sound_source_list.h"


void nullsub_13(void);
void StartIronBallSpeedSound(struct MapObjectSound *mapSound, s32 fixedValue);
void StartIronBallBounceSound(struct MapObjectSound *soundSource, s32 fixedValue);
void QueueBalloonSound(void *position, s32 distanceSquared);
void StartBalloonSound(void *position, s32 distanceSquared);
void QueueShine16Sound(struct MapObjectSound *mapSound, s32 soundId);
void QueueShine16SoundWhileRequested(struct MapObjectSound *mapSound, s32 soundId);
void StartMapObjectCounterSound(void *mapSound, s32 baseSoundId);
void ResetMapObjectSoundCounter(void);

extern SoundStartParams gBalloonSoundStartParams;

extern s32 gKartSurfaceSoundSortOffsets[4];
