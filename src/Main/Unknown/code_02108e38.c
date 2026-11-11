#include "Main/Unknown/code_02108e38.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_0212bcac.h"

#pragma optimize_for_size on

void StopSndHandleSlots7To11(void) {
    s32 slotIndex;

    for (slotIndex = 7; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(&gSndHandleSlots[slotIndex], 0);
    }
}
