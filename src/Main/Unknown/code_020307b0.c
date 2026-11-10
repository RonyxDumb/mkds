#include "Main/Unknown/code_020307b0.h"

u32 MultiSelectNSGetPairHasPair(const void *pair) {
    return (*OFFSET_PTR(const u16, pair, 4));
}
