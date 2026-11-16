#include "Main/Sound/sound_distance_change.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"

u32 GetSoundDistanceChange(SoundDistanceSquaredChange *change) {
    return change->mDifference;
}
