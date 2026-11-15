#pragma once

#include "types.h"

#include "Main/Sound/surface_sound_ids.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"
// Object of AdvanceSoundDistanceSquaredChange: a value at 0x00, the previous value at 0x04, their difference at 0x08
// and a shift at 0x0c; 0x1c bytes in all.
// SoundDistanceSquaredChange.mShift ResetSoundDistanceSquaredChange sets, and the largest change in mDifference
// AdvanceSoundDistanceSquaredChange keeps (a larger one is dropped for the previous change).
#define SOUND_DISTANCE_CHANGE_SHIFT 6
#define SOUND_DISTANCE_CHANGE_LIMIT 0x600

typedef struct SoundDistanceSquaredChange {
    /* 00 */ s32 mDistanceSquared;
    /* 04 */ s32 mPrevDistanceSquared;
    /* 08 */ s32 mDifference;
    /* 0c */ u32 mShift;
    /* 10 */ u8 mUnk_10[0xc];
} SoundDistanceSquaredChange;

#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/map_object_sound_counter.h"
