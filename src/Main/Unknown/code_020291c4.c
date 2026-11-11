#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0201ea58.h"

s32 FindRectContainingPoint(u32 pointX, u32 pointY, LayoutEntryTable *rects) {
    return RectTableFindContaining(rects, pointX, pointY);
}
