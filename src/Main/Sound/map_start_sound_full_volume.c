#include "Main/Sound/map_start_sound_full_volume.h"
#include "Main/Sound/sound_start.h"

void MapStartSoundWhileRequestedFullVolume(void *soundSource, int soundId) {
    StartSoundWhileRequested(soundSource, soundId, 0x7f, 0);
}
