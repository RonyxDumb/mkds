#include "Main/Sound/snd_handle_slots.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"

#pragma optimize_for_size on

void StopSndHandleSlots7To11(void) {
    s32 slotIndex;

    for (slotIndex = 7; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(&gSndHandleSlots[slotIndex], 0);
    }
}
