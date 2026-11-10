#include "Main/Unknown/code_0210bae8.h"
#include "Main/Unknown/code_0210bcf4.h"

u32 Shine16TrackParamsReturnArgument(u32 value) {
    return value;
}

void SetShine16TrackParamsReturnArgument(SoundSource *soundSource) {
    soundSource->mTrackParamsFunction = (void (*)(void *, void *, void *)) Shine16TrackParamsReturnArgument;
}
