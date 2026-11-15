#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"

void StartSoundFullVolumeWrapper(void *soundSource, u32 soundId) {
    void *handle = soundSource;
    u32 soundIdCopy = soundId;
    u32 unused;
    handle = StartSoundFullVolume(handle, soundIdCopy);
}

void StartWhileRequestedFullVolumeWrapper(SoundSource *soundSource, u32 soundId) {
    u32 soundIdCopy = soundId;
    u32 unused;
    StartSoundWhileRequestedFullVolume(soundSource, soundIdCopy);
}
