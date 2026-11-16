#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

// Sets up the sound source p: its number a (the volume curve), the pointer v to the owner's position, an empty sound
// list and the entry in the list of all sound sources (gSoundSources). The source starts not enabled (bit 0 of its
// mUnk_34 member is clear).
void StructMQRacerEntry_SomeFn_45(SoundSource *source, u32 falloffIndex, Vec3 *ownerPosSource);
