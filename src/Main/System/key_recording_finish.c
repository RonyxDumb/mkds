#include "Main/System/key_recording_finish.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "code_0200eddc.h"

void FinishKeyRecording(KeyRecording *keyRecording) {
    if (keyRecording->mStatus != 1) {
        return;
    }
    keyRecording->mBuffer->mPairByteCount = keyRecording->mPairIndex << 1;
    keyRecording->mStatus = 0;
    DC_StoreRange(keyRecording->mBuffer, 0xdcc);
}
