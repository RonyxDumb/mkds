#include "Main/Graphics/rect_containing_point.h"
#include "Main/Graphics/layout_rect_table.h"

s32 FindRectContainingPoint(u32 pointX, u32 pointY, LayoutEntryTable *rects) {
    return RectTableFindContaining(rects, pointX, pointY);
}
