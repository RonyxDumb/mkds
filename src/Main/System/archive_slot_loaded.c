#include "Main/System/archive_slot_loaded.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"

#pragma thumb on

u32 IsMountEntryLoaded_from_thumb(u32 slotIndex) {
    return (g_MountManager->mSlots[slotIndex].mLoaded);
}

#pragma thumb off
