#include "Main/System/key_recording_finish.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "arena_cache_init.h"

void FinishKeyRecording(KeyRecording *keyRecording) {
    if (keyRecording->mStatus != KEY_RECORDING_RECORDING) {
        return;
    }
    keyRecording->mBuffer->mPairByteCount = keyRecording->mPairIndex << 1;
    keyRecording->mStatus = KEY_RECORDING_IDLE;
    DC_StoreRange(keyRecording->mBuffer, 0xdcc);
}
