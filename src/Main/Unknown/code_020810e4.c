#include "Main/Unknown/code_020810e4.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"

void ReleaseKartSpinFollowEffect(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    if (kartEffects->mSpinFollowEffect == NULL) {
        return;
    }
    DeleteEffect(kartEffects->mSpinFollowEffect);
    kartEffects->mSpinFollowEffect = NULL;
}
