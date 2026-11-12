#include "Main/Kart/kart_state0_return.h"

s32 GetAbsoluteValue(s32 value) {
    return value <= 0 ? -value : value;
}

u32 KartState0ReturnArgument(u32 value) {
    return value;
}
