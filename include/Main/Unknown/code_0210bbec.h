#pragma once

#include "types.h"

typedef struct CourseSurfaceSoundEntry CourseSurfaceSoundEntry;

void CourseEntrySetSurfaceSoundIds(u32 rowIndex, u32 columnIndex, CourseSurfaceSoundEntry *entries);
void SetSurfaceSoundIds(u32 rowIndex, u32 columnIndex, void *entries);
