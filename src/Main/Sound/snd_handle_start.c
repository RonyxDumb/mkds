#include "Main/Sound/snd_handle_start.h"
#include "Main/Sound/code_0210b760.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/data_0210b000.h"

void AdvanceSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker, u32 distanceSquared) {
    s32 value;
    s32 oldChange;

    value = tracker->mDistanceSquared;
    if (value == -1) {
        tracker->mDistanceSquared = distanceSquared;
        tracker->mDifference = 0;
        return;
    }
    oldChange = tracker->mDifference;
    tracker->mPrevDistanceSquared = value;
    tracker->mDistanceSquared = distanceSquared;
    tracker->mDifference = (tracker->mPrevDistanceSquared - tracker->mDistanceSquared) >> tracker->mShift;
    value = tracker->mDifference;
    if (value > 0x600 || value < -0x600) {
        tracker->mDifference = oldChange;
    }
}

void StartSoundFromParams(SoundStartParams *request) {
    if (gRaceSoundKind & 1) {
        StartSoundOnPoolEntry(0, request->mSoundId, request->mPositionSource, request);
    }
}

void StartSndHandleSound(SoundStartParams *request, NNSSndSeqPlayer **handle) {
    if (gRaceSoundKind & 1) {
        StartOrUpdateSndHandleSoundIfEnabled(0, request->mSoundId, request->mPositionSource, handle, request);
    }
}

void StartSndHandleSoundUnchecked(SoundStartParams *request, NNSSndSeqPlayer **handle) {
    u32 soundId = request->mSoundId;
    Vec3 *positionSource = request->mPositionSource;
    u32 result = StartOrUpdateSndHandleSound(0x0u, soundId, positionSource, handle, request);
}

void StartSndHandleSoundEx(SoundStartParams *request, NNSSndSeqPlayer **handle) {
    u32 soundId = request->mSoundId;
    Vec3 *positionSource = request->mPositionSource;
    u32 result = StartOrUpdateSndHandleSoundIfEnabled(0x0u, soundId, positionSource, handle, request);
}
