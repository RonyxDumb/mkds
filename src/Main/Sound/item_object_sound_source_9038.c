#include "Main/Sound/item_object_sound_source_9038.h"
#include "Main/Sound/sound_source_list.h"

void ItemObjectInitSoundSource(SoundSource *source, u32 falloffIndex, Vec3 *ownerPosSource) {
    source->mFalloffIndex = falloffIndex;
    source->mDistanceSquared = ~0u;
    ItemObjectInitAndRegisterSoundSource(source, ownerPosSource);
}
