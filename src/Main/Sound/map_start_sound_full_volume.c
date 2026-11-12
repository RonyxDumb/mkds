#include "Main/Sound/map_start_sound_full_volume.h"
#include "Main/Sound/sound_start.h"
#include "Main/Unknown/code_02109000.h"

void MapStartSoundWhileRequestedFullVolume(void *soundSource, int soundId) {
    StartSoundWhileRequested(soundSource, soundId, 0x7f, 0);
}
