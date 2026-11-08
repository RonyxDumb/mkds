#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210cf20.h"
#include "Main/Unknown/code_0210bcf4.h"

void InitSoundSource(SoundSource *source, u32 falloffIndex, Vec3 *ownerPosSource) {
    source->mFalloffIndex = falloffIndex;
    source->mDistanceSquared = ~0u;
    InitAndRegisterSoundSource(source, (u32) ownerPosSource);
}
