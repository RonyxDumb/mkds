#pragma once

#include "types.h"

typedef struct SoundModeHolder SoundModeHolder;

// Values of SoundModeHolder.mMode (SetSoundMode). SCENE_SOUND_MODE_STOPPED: every sound and the scene sequences (main,
// second, kart star) stopped at once.
#define SCENE_SOUND_MODE_STOPPED 0
// Sounds stopped; sequences may start (volume restored after a pause). No caller in this build sets this mode.
#define SCENE_SOUND_MODE_SEQUENCES_ONLY 1
// Sounds and sequences on (the normal, replay and start races and the scenes outside the race; also after resuming from
// a pause).
#define SCENE_SOUND_MODE_PLAYING 2
// Sounds and the second sequence fade out; the main sequence keeps playing (set at the start of a race scene of the
// demo, award or staff roll kind, and when EndRaceSounds ends a race that was playing).
#define SCENE_SOUND_MODE_MAIN_SEQUENCE_ONLY 3
// Every sound and sequence fades out.
#define SCENE_SOUND_MODE_FADED_OUT 4
// Sequences and playing sounds fade to silence, sounds and sequence starts are switched off, and the previous mode is
// saved (pause).
#define SCENE_SOUND_MODE_PAUSED 5

void SetSoundMode(SoundModeHolder *modeHolder, u32 newMode);
