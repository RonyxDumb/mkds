#include "Main/System/archive_buffer.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma thumb on

void UncompressLZ8AndStoreRange(const void *source, void *destination, u32 size) {
    MI_UncompressLZ8(source, destination);
    DC_StoreRange(destination, size);
}

void ResetArchiveBuffer(int bufferIndex) {
    ArchiveBuffer *buffer;
    buffer = &gArchiveSlots->mBuffers[bufferIndex];
    buffer->mHeap = NULL;
    buffer->mUnk_08 = buffer->mUnk_08 & (0xe0000000u);
    buffer->mUnk_08 = buffer->mUnk_08 | (0x20000000u);
    buffer->mUnk_08 = buffer->mUnk_08 & (0xbfffffffu);
}

#pragma thumb off
