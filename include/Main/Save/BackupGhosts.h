#pragma once

#include "types.h"

typedef struct GhostRecord GhostRecord;

void savd_readNkdg(u32 index, GhostRecord *ghostRecord);
void savd_writeNkdg(s32 index, const void *record);
void savd_readNkpg(u8 index, GhostRecord *ghostRecord);
void savd_writeNkpg(u32 index, const void *record);
