#pragma once

#include "types.h"

typedef struct GhostRecord GhostRecord;
typedef struct Unk0202ddd8 Unk0202ddd8;

void ReadBackupSlotGhost(u32 index, Unk0202ddd8 *ghostRecord);
void WriteBackupSlotGhost(s32 index, const void *record);
void ReadBackupCourseGhost(u8 index, GhostRecord *ghostRecord);
void WriteBackupCourseGhost(u32 index, const void *record);
