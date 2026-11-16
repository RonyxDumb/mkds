#include "Main/Sound/sound_handle_start_and_distance_change.h"
#include "Main/Sound/start_sound_from_params.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_and_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_distance_squared_change.h"

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
    if (value > SOUND_DISTANCE_CHANGE_LIMIT || value < -SOUND_DISTANCE_CHANGE_LIMIT) {
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
