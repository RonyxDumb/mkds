#include "Main/Sound/sound_source_init.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"

void InitSoundSource(SoundSource *source, u32 falloffIndex, Vec3 *ownerPosSource) {
    source->mFalloffIndex = falloffIndex;
    source->mDistanceSquared = ~0u;
    InitAndRegisterSoundSource(source, ownerPosSource);
}
