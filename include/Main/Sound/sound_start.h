#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;
typedef struct PlayingSound PlayingSound;

// Starts soundId at volume on the source and returns its PlayingSound, or NULL when sound is off or the source is not
// enabled. pitch is stored in the entry.
PlayingSound *StartSound(SoundSource *source, u32 soundId, u32 volume, s16 pitch);
// Starts sound a on the source p and keeps it only while it is started again between two runs of the expiry step of
// ExpireWhileRequestedSounds, which UpdateSoundSources runs after UpdateRace has set data_0217d020. A sound already
// started this way on the source is refreshed with the new volume. Returns the PlayingSound, NULL under the conditions
// of StartSound.
PlayingSound *StartSoundWhileRequested(SoundSource *source, u32 soundId, u32 volume, s32 pitch);
// Stops the first started sound with id a on the source p without a fade. A sound the library has not started yet is
// not stopped.
void StopSound(SoundSource *source, u32 soundId);
void ReleaseSoundSourceWrapper(SoundSource *source);
