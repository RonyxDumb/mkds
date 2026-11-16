#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;
typedef struct PlayingSound PlayingSound;

// Starts sound a at volume b on the sound source p and returns its PlayingSound. A sound of the same id already on the
// source is stopped first. Returns NULL when bit 0 of data_0217c780 is clear, when the field10 member of SoundHandle_217D084
// is 0 or when the source is not enabled (bit 0 of its field34 member). The fourth parameter is stored in the field14
// member of the entry.
PlayingSound *sfx_21090C4(SoundSource *source, u32 soundId, u32 volume, s16 pitch);
// Starts sound a on the source p and keeps it only while it is started again between two runs of the expiry step of
// sfx_210CC3C, which sfx_update runs after race_update has set data_0217d020. A sound already started this way
// on the source is refreshed with the new volume. Returns the PlayingSound, NULL under the conditions of sfx_21090C4.
PlayingSound *StartSoundWhileRequested(SoundSource *source, u32 soundId, u32 volume, s32 pitch);
// Stops the first started sound with id a on the source p without a fade. A sound the library has not started yet is
// not stopped.
void StopSound(SoundSource *source, u32 soundId);
void sub_2109054(SoundSource *source);
