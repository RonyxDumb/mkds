#include "Main/Unknown/code_02030a10.h"

u32 MultiSelectNSGetCellLayoutCount(const void *cellLayout) {
    return (*OFFSET_PTR(const u16, cellLayout, 6));
}

u32 MultiSelectNSGetLabelLayoutCount(const void *labelLayout) {
    return (*OFFSET_PTR(const u16, labelLayout, 6));
}
