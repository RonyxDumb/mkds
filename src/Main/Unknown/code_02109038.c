#include "Main/Unknown/code_02109038.h"
#include "Main/Unknown/code_0210bcf4.h"

void func_02109038(SoundSource *source, u32 falloffIndex, Vec3 *ownerPosSource) {
    source->mFalloffIndex = falloffIndex;
    source->mDistanceSquared = ~0u;
    func_0210c134(source, ownerPosSource);
}
