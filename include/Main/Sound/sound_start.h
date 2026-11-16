#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;
typedef struct PlayingSound PlayingSound;

// Queues soundId at volume on the source (the sequence starts in the next sound pass) and returns its PlayingSound, or
// NULL when bit 0 of gRaceSoundKind is clear, the sound mode has sounds off, or the source is not enabled. A sound with
// the same id on the source is restarted in its entry.
PlayingSound *StartSound(SoundSource *source, u32 soundId, u32 volume, s16 pitch);
// Starts sound a on the source p and keeps it only while it is started again between two runs of the expiry step of
// ExpireWhileRequestedSounds, which UpdateSoundSources runs after UpdateRace has set gExpireWhileRequestedSounds. A
// sound already started this way on the source is refreshed with the new volume. Returns the PlayingSound, NULL under
// the conditions of StartSound.
PlayingSound *StartSoundWhileRequested(SoundSource *source, u32 soundId, u32 volume, s32 pitch);
// Stops the first started sound with id soundId on source without a fade. A sound that has not been started yet is not
// stopped. Does nothing while sounds are off in the sound mode.
void StopSound(SoundSource *source, u32 soundId);
void ReleaseSoundSourceWrapper(SoundSource *source);
