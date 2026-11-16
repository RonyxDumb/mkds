#include "Main/Sound/sound_distance_change.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_list.h"

u32 GetSoundDistanceChange(SoundDistanceSquaredChange *change) {
    return change->mDifference;
}
