#pragma once

#include "types.h"

u16 func_ov003_021b7c44(u16 value);

static inline u16 func_ov003_021b7c44_inline(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}
