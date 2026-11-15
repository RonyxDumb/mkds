#pragma once

#include "types.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"

void StopSndHandleSlots7To11(void);

// Volume curve of the Karts other than the selected entry whose sound source number is 0.
extern SoundFalloff gOtherKartSoundFalloff;
