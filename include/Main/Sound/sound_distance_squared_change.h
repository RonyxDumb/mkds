#pragma once

#include "types.h"

#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
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
#include "Main/Sound/kart_sound_starts_and_track_params.h"
#include "Main/Sound/map_object_sound_starts_and_queues.h"
