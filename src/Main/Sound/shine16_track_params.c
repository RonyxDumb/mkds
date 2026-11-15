#include "Main/Sound/shine16_track_params.h"
#include "Main/Sound/sound_source_list.h"

void Shine16TrackParamsNop(void *source, void *sound, void *unused) {}

void SetShine16TrackParamsNop(SoundSource *soundSource) {
    soundSource->mTrackParamsFunction = Shine16TrackParamsNop;
}
