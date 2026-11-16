#include "Main/Sound/sound_start_stop_and_release_wrapper.h"
#include "Main/Sound/playing_sounds.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"

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
