#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

void sfx_emitFloorSfx2(SoundSource *source, int entryIndex, u32 surfaceKind, u32 surfaceVariant, u32 waterDepth);
