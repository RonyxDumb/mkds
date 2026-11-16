#pragma once

#include "types.h"

typedef struct SoundModeHolder SoundModeHolder;

// Values of SoundModeHolder.mMode (SetSoundMode).
// Every sound and sequence stopped at once.
#define SCENE_SOUND_MODE_STOPPED 0
// Sounds stopped; sequences may start (volume restored after a pause).
#define SCENE_SOUND_MODE_SEQUENCES_ONLY 1
// Sounds and sequences on (race running, and after resuming from a pause).
#define SCENE_SOUND_MODE_PLAYING 2
// Sounds and the second sequence fade out; the NtrMain sequence keeps playing (the start of the cup results scene).
#define SCENE_SOUND_MODE_MAIN_SEQUENCE_ONLY 3
// Every sound and sequence fades out.
#define SCENE_SOUND_MODE_FADED_OUT 4
// Sequences faded to silence and the previous mode saved (pause).
#define SCENE_SOUND_MODE_PAUSED 5

void SetSoundMode(SoundModeHolder *modeHolder, u32 newMode);
