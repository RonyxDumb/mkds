#include "Main/Unknown/code_02081338.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"

void ReleaseKartContactEffect(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    if (kartEffects->mContactEffect == NULL) {
        return;
    }
    DeleteEffect(kartEffects->mContactEffect);
    kartEffects->mContactEffect = NULL;
}
