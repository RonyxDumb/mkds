#include "Main/Sound/map_start_sound_full_volume.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Sound/sound_start_stop_and_release_wrapper.h"

void MapStartSoundWhileRequestedFullVolume(void *soundSource, int soundId) {
    StartSoundWhileRequested(soundSource, soundId, SOUND_VOLUME_MAX, 0);
}
