#pragma once

#include "types.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h" // SoundSource, PlayingSound

void ExpireWhileRequestedSounds(SoundSource *source);
u32 SetPlayingSoundsParams(SoundSource *source);
// StartSound for any kind: starts soundId of seqArcNo at volume on the source and returns its PlayingSound; pitch is
// stored in the mPitch member of the entry. Returns NULL when the mUnk_10 member of data_0217d084 is 0 or the source
// is not enabled. Unlike StartSound it does not test data_0217c780.
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
// sound sources (data_0217d028).
void ReleaseSoundSource(SoundSource *source);
