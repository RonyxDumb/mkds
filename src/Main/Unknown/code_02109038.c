#include "Main/Unknown/code_02109038.h"
#include "Main/Unknown/code_0210bcf4.h"

void ItemObjectInitSoundSource(SoundSource *source, u32 falloffIndex, Vec3 *ownerPosSource) {
    source->mFalloffIndex = falloffIndex;
    source->mDistanceSquared = ~0u;
    ItemObjectInitAndRegisterSoundSource(source, ownerPosSource);
}
