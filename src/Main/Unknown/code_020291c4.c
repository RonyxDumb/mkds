#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0201ea58.h"

s32 FindRectContainingPoint(u32 x, u32 y, LayoutEntryTable *rects) {
    return RectTableFindContaining(rects, x, y);
}
