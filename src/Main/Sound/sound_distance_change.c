#include "Main/Sound/sound_distance_change.h"
#include "Main/Sound/data_0210b000.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"

u32 GetSoundDistanceChange(SoundDistanceSquaredChange *change) {
    return change->mDifference;
}
