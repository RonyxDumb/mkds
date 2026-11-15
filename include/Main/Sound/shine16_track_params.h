#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

void SetShine16TrackParamsNop(SoundSource *soundSource);
void Shine16TrackParamsNop(void *source, void *sound, void *unused);
