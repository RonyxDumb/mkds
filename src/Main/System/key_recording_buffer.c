#include "Main/System/key_recording_buffer.h"
#include "Main/System/heap.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/select_race_rule_state.h"

u32 SetMultiSimple(u32 flag) {
    u32 value0 = flag;
    u32 value1;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return value0;
    }
    value0 = (value0) & (1u);
    value1 = gStartupWork->mUnk_1c;
    value1 = (value1) & ~(4u);
    value0 = (value1) | ((value0 << 2));
    gStartupWork->mUnk_1c = value0;
    return value0;
}

KeyRecordingBuffer *InitKeyRecordingBuffer(KeyRecording *record, void *heap) {
    KeyRecordingBuffer *buffer = HeapAlloc(heap, 0xdcc);
    record->mBuffer = buffer;
    return buffer;
}
