#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

// Sets up source: falloffIndex picks the volume curve, ownerPosSource points to the owner's position, the sound list is
// empty, the source is entered in gSoundSources and starts not enabled (SOUND_SOURCE_FLAG_ENABLED is clear in
// mSourceFlags).
void InitSoundSource(SoundSource *source, u32 falloffIndex, Vec3 *ownerPosSource);
