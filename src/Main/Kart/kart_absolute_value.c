#include "Main/Kart/kart_absolute_value.h"

u16 gSequenceEntryCount;

s32 GetAbsoluteValue(s32 value) {
    return value <= 0 ? -value : value;
}

void KartNormalNop(struct Kart *kart) {}
