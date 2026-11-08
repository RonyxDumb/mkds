#include "Main/Unknown/code_02081338.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"

void func_02081338(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    if (kartEffects->mUnk_28 == NULL) {
        return;
    }
    DeleteEffect(kartEffects->mUnk_28);
    kartEffects->mUnk_28 = NULL;
}
