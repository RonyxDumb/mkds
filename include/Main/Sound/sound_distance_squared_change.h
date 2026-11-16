#pragma once

#include "types.h"

#include "Main/Sound/surface_sound_ids.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_list.h"
// SOUND_DISTANCE_CHANGE_SHIFT is the mShift that ResetSoundDistanceSquaredChange sets. SOUND_DISTANCE_CHANGE_LIMIT is
// the largest absolute mDifference that AdvanceSoundDistanceSquaredChange keeps (a larger one is replaced by the
// previous mDifference).
#define SOUND_DISTANCE_CHANGE_SHIFT 6
#define SOUND_DISTANCE_CHANGE_LIMIT 0x600

// The squared distance of a sound source, the previous one and the limited change between them.
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
