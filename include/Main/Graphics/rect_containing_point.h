#pragma once

#include "types.h"

typedef struct LayoutEntryTable LayoutEntryTable;

s32 FindRectContainingPoint(u32 pointX, u32 pointY, LayoutEntryTable *rects);
