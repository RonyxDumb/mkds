#include "Main/Unknown/code_02028ff8.h"

u32 GetCellLayoutCount(void *cellLayout) {
    return *OFFSET_PTR(const u16, cellLayout, 6);
}

u32 GetLabelLayoutCount(void *labelLayout) {
    return *OFFSET_PTR(const u16, labelLayout, 6);
}
