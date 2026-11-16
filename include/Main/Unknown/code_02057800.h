#pragma once

#include "types.h"

typedef struct GhostRecord GhostRecord;

void savd_readGhostHeader(u32 isCourseGhost, u32 index, GhostRecord *ghostRecord);
void savd_readGhostHeaderWithEmblem(u32 isCourseGhost, u32 index, GhostRecord *ghostRecord);
