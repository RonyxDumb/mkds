#include "Main/System/archive_slot_loaded.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

u32 IsArchiveSlotLoaded(u32 slotIndex) {
    return (gArchiveSlots->mSlots[slotIndex].mLoaded);
}

#pragma thumb off
