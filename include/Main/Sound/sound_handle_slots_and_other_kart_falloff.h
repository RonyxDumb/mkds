#pragma once

#include "types.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"

void StopSndHandleSlots7To11(void);

// Volume curve of the Karts other than the entry kart (gRaceSetup.mEntryIndex) whose SoundSource.mFalloffIndex is 0.
extern SoundFalloff gOtherKartSoundFalloff;
