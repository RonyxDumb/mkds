#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"

void StartSoundFullVolumeWrapper(void *soundSource, u32 soundId) {
    void *value0 = soundSource;
    u32 soundIdCopy = soundId;
    u32 unused;
    value0 = StartSoundFullVolume(value0, soundIdCopy);
}

void StartWhileRequestedFullVolumeWrapper(SoundSource *soundSource, u32 soundId) {
    u32 soundIdCopy = soundId;
    u32 unused;
    StartSoundWhileRequestedFullVolume(soundSource, soundIdCopy);
}
