#pragma once

#include "types.h"

typedef struct LayoutEntryTable LayoutEntryTable;

s32 FindRectContainingPoint(u32 x, u32 y, LayoutEntryTable *rects);
