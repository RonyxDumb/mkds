#include "Main/System/archive_buffer.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "arena_cache_init.h"
#include "cpu_copy_fill.h"

#pragma thumb on

void DecompressLzssAndDCClean_from_thumb(const void *source, void *destination, u32 size) {
    DecompressLzss(source, destination);
    DC_SomeClean(destination, size);
}

void InitializeMountDatas_from_thumb(int bufferIndex) {
    ArchiveBuffer *buffer;
    buffer = &g_MountManager->mBuffers[bufferIndex];
    buffer->mHeap = NULL;
    buffer->mUnk_08 = buffer->mUnk_08 & (0xe0000000u);
    buffer->mUnk_08 = buffer->mUnk_08 | (0x20000000u);
    buffer->mUnk_08 = buffer->mUnk_08 & (0xbfffffffu);
}

#pragma thumb off
