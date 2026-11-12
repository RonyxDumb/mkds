#include "Main/Menu/multi_select_ns_has_pair.h"

u32 MultiSelectNSGetPairHasPair(const void *pair) {
    return (*OFFSET_PTR(const u16, pair, 4));
}
