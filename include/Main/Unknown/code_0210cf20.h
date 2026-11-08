#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

void InitAndRegisterSoundSource(SoundSource *source, Vec3 *positionSource);
