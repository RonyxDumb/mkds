#include "Main/Sound/sound_start.h"
#include "Main/Sound/playing_sounds.h"
#include "Main/Unknown/unk_0217c000.h"

PlayingSound *StartSound(SoundSource *source, u32 soundId, u32 volume, s16 pitch) {
    if (!(gRaceSoundKind & 1)) {
        return NULL;
    }
    return ((PlayingSound * (*) (SoundSource *, u32, u32, u32, s32)) StartSoundEx)(source, 0, soundId, volume, pitch);
}

PlayingSound *StartSoundWhileRequested(SoundSource *source, u32 soundId, u32 volume, s32 pitch) {
    if (!(gRaceSoundKind & 1)) {
        return NULL;
    }
    return ((PlayingSound * (*) (SoundSource *, u32, u32, u32, s32)) StartSoundWhileRequestedEx)(source, 0, soundId,
                                                                                                 volume, pitch);
}

void StopSound(SoundSource *source, u32 soundId) {
    StopSoundEx(source, 0, soundId, 0);
}

void ReleaseSoundSourceWrapper(SoundSource *source) {
    ReleaseSoundSource(source);
}
