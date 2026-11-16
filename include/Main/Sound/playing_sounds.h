#pragma once

#include "types.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_list.h" // SoundSource, PlayingSound

void ExpireWhileRequestedSounds(SoundSource *source);
u32 SetPlayingSoundsParams(SoundSource *source);
// StartSound for any kind: starts soundId of seqArcNo at volume on the source and returns its PlayingSound, or NULL
// when the source is not enabled. pitch is stored in the entry.
PlayingSound *StartSoundEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 volume, s16 pitch);
// StartSoundWhileRequested for any kind: starts soundId of seqArcNo on the source, or refreshes it when it was already
// started this way, and returns its PlayingSound.
PlayingSound *StartSoundWhileRequestedEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 volume, s16 pitch);
// StopSound for any kind: stops the first started soundId of seqArcNo on the source, fading out over fadeSteps (0 stops
// at once).
void StopSoundEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 fadeSteps);
// Stops the PlayingSound of the source, fading out over fadeSteps (0 stops at once), and takes it out of the source's
// list.
void StopPlayingSound(SoundSource *source, PlayingSound *sound, u32 fadeSteps);
void StopAllSoundsAndReleaseSoundSource(SoundSource *source);
void StopSoundsStartedWhileRequested(SoundSource *source, u32 fadeSteps);
// Undoes InitSoundSource: stops the sounds started because they were requested, without a fade, unlinks all other
// sounds from the source without stopping them, and takes the source out of the update lists and of the list of all
// sound sources (gSoundSources).
void ReleaseSoundSource(SoundSource *source);
