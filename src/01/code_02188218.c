#include "01/code_02188218.h"
#include "01/code_02188950.h"

u16 GetAbsoluteCounter(Unk02188950 *mapObject) {
    s32 counter;
    counter = mapObject->mUnk_0ac;
    if (counter < 0) {
        counter = -counter;
    }
    return counter & 0xffff;
}

void SetRepeatsRemaining(Unk02188950 *mapObject, s32 repeatsRemaining) {
    mapObject->mUnk_0b4 = repeatsRemaining;
}
