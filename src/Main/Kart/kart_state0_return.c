#include "Main/Kart/kart_state0_return.h"

u16 gKind7EntryCount;

s32 GetAbsoluteValue(s32 value) {
    return value <= 0 ? -value : value;
}

void KartState0Nop(struct Kart *kart) {}
