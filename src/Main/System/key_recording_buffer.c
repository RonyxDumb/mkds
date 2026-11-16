#include "Main/System/key_recording_buffer.h"
#include "Main/System/heap.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/select_race_rule_state.h"

u32 SetMultiSimple(u32 flag) {
    u32 newStartupFlags = flag;
    u32 startupFlags;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return newStartupFlags;
    }
    newStartupFlags = (newStartupFlags) & (1u);
    startupFlags = gStartupWork->mUnk_1c;
    startupFlags = (startupFlags) & ~(4u);
    newStartupFlags = (startupFlags) | ((newStartupFlags << 2));
    gStartupWork->mUnk_1c = newStartupFlags;
    return newStartupFlags;
}

KeyRecordingBuffer *InitKeyRecordingBuffer(KeyRecording *record, void *heap) {
    KeyRecordingBuffer *buffer = HeapAlloc(heap, sizeof(KeyRecordingBuffer));
    record->mBuffer = buffer;
    return buffer;
}
