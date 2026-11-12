#include "Main/System/archive_slot_loaded.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

#pragma thumb on

u32 IsArchiveSlotLoaded(u32 slotIndex) {
    return (gArchiveSlots->mSlots[slotIndex].mLoaded);
}

#pragma thumb off
