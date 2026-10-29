#include "code_0213377c.h"

// non-matching: tails of the routine before them, entered by branches with the result words held in registers
u64 func_0213377c(u32 a, u32 b, u32 c) {
    if ((a & 0x400000) != 0) {
        return func_02133620(c, b);
    }
    if ((b & 0x80000000) != 0) {
        return func_02133630(c, b);
    }
    return func_02133620(c, b);
}

// non-matching: tail of the routine before it, entered by a branch with the result words held in registers
u64 func_02133790(u32 a, u32 b) {
    if ((a & 0x80000000) == 0) {
        return func_02133630(b, a);
    }
    return func_02133620(b, a);
}
