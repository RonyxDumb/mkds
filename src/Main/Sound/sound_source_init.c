#include "Main/Sound/sound_source_init.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Sound/sound_source_list.h"

void StructMQRacerEntry_SomeFn_45(SoundSource *source, u32 falloffIndex, Vec3 *ownerPosSource) {
    source->mFalloffIndex = falloffIndex;
    source->mDistanceSquared = ~0u;
    StructMQRacerEntry_SomeFn_46(source, ownerPosSource);
}
