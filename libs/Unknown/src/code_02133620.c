#include "code_02133620.h"

// non-matching: tail of the routine before it, entered by a branch; returns the result words held in registers
u64 func_02133620(u32 a, u32 b) {
    return ((u64) b << 32) | a;
}
