#include "Main/System/key_recording_finish.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "arena_cache_init.h"

void FinishKeyRecording(KeyRecording *keyRecording) {
    if (keyRecording->mStatus != KEY_RECORDING_RECORDING) {
        return;
    }
    keyRecording->mBuffer->mPairByteCount = keyRecording->mPairIndex << 1;
    keyRecording->mStatus = KEY_RECORDING_IDLE;
    DC_StoreRange(keyRecording->mBuffer, 0xdcc);
}
