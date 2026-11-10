#pragma once

#include "types.h"

typedef struct Vec3 Vec3;
typedef struct SoundSource SoundSource;

void ItemObjectInitSoundSource(SoundSource *source, u32 falloffIndex, Vec3 *ownerPosSource);
