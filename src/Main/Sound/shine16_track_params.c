#include "Main/Sound/shine16_track_params.h"
#include "Main/Sound/sound_source_list.h"

u32 Shine16TrackParamsReturnArgument(u32 value) {
    return value;
}

void SetShine16TrackParamsReturnArgument(SoundSource *soundSource) {
    soundSource->mTrackParamsFunction = (void (*)(void *, void *, void *)) Shine16TrackParamsReturnArgument;
}
