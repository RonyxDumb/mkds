#include "Main/Sound/snd_handle_slots.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"

#pragma optimize_for_size on

SoundFalloff gOtherKartSoundFalloff;

void StopSndHandleSlots7To11(void) {
    s32 slotIndex;

    for (slotIndex = 7; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(&gSndHandleSlots[slotIndex], 0);
    }
}
