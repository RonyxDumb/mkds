#pragma once

#include "types.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h" // SoundSource, PlayingSound

void sfx_210CC3C(SoundSource *source);
u32 sfx_updateEmitter(SoundSource *source);
// sfx_21090C4 for any kind: starts sound c of kind b at volume d on the source a and returns its PlayingSound; e is
// stored in the mUnk_14 member of the entry. Returns NULL when the mUnk_10 member of SoundHandle_217D084 is 0 or the source
// is not enabled. Unlike sfx_21090C4 it does not test data_0217c780.
PlayingSound *sfx_emitSfx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 volume, s16 pitch);
// StartSoundWhileRequested for any kind: starts sound c of kind b on the source a, or refreshes it when it was already
// started this way, and returns its PlayingSound.
PlayingSound *StartSoundWhileRequestedEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 volume, s16 pitch);
// StopSound for any kind: stops the first started sound c of kind b on the source a, fading out over d (0 stops at
// once).
void StopSoundEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 fadeSteps);
// Stops the PlayingSound b of the source p, fading out over c (0 stops at once), and takes it out of the source's list.
void sfx_stopSfx(SoundSource *source, PlayingSound *sound, u32 fadeSteps);
void sfx_210C3A8(SoundSource *source);
void sfx_210C238(SoundSource *source, u32 fadeSteps);
// Undoes InitSoundSource: stops the sounds started because they were requested, without a fade, unlinks all other
// sounds from the source without stopping them, and takes the source out of the update lists and of the list of all
// sound sources (sfx_sActiveEmitterList).
void sfx_210C1B0(SoundSource *source);
