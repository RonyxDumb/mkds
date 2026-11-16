#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

void StartWhileRequestedFullVolumeWrapper(SoundSource *soundSource, u32 soundId);
void StartSoundFullVolumeWrapper(void *soundSource, u32 soundId);
