#include "Main/Sound/snd_handle_slots.h"
#include "Main/Unknown/unk_0217c000.h"
#include "player.h"

#pragma optimize_for_size on

void StopSndHandleSlots7To11(void) {
    s32 slotIndex;

    for (slotIndex = 7; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(&gSndHandleSlots[slotIndex], 0);
    }
}
