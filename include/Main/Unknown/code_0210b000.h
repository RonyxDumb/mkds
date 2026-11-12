#pragma once

#include "types.h"

#include "Main/Sound/surface_sound_ids.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"
// Object of AdvanceSoundDistanceSquaredChange: a value at 0x00, the previous value at 0x04, their difference at 0x08
// and a shift at 0x0c.
typedef struct SoundDistanceSquaredChange {
    /* 00 */ s32 mDistanceSquared;
    /* 04 */ s32 mPrevDistanceSquared;
    /* 08 */ s32 mDifference;
    /* 0c */ u32 mShift;
} SoundDistanceSquaredChange;

extern SoundStartParams gSoundStartParamsDefault;
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b610.h"
#include "Main/Sound/map_object_sound_counter.h"
