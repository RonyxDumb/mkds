#include "Main/Sound/map_start_sound_full_volume.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_start.h"

void MapStartSoundWhileRequestedFullVolume(void *soundSource, int soundId) {
    StartSoundWhileRequested(soundSource, soundId, SOUND_VOLUME_MAX, 0);
}
