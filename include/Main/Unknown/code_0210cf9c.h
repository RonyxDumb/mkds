#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

void SetSoundSourceFlagBit(SoundSource *source, s32 bit, s32 value);
void sfx_210CF9C(SoundSource *source, s32 enabled);
