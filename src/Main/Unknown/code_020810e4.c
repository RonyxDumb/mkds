#include "Main/Unknown/code_020810e4.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"

void func_020810e4(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    if (kartEffects->mUnk_30 == NULL) {
        return;
    }
    DeleteEffect(kartEffects->mUnk_30);
    kartEffects->mUnk_30 = NULL;
}
