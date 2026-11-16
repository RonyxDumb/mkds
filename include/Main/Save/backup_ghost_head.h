#pragma once

#include "types.h"

typedef struct GhostRecordHead GhostRecordHead;

void ReadBackupGhostRecordHead(u32 isCourseGhost, u32 index, GhostRecordHead *ghostRecord);
void ReadBackupGhostListEntry(u32 isCourseGhost, u32 index, GhostRecordHead *ghostRecord);

void CopyToSXSomePtr0x230_from_thumb(u32 *buffer, u32 length);
void CopyToSXSomePtr0x30_from_thumb(u32 *buffer, u32 length);

typedef struct GhostRecord GhostRecord;
typedef struct SlotGhostRecord SlotGhostRecord;

void ReadBackupSlotGhost(u32 index, SlotGhostRecord *ghostRecord);
void WriteBackupSlotGhost(s32 index, const void *record);
void ReadBackupCourseGhost(u8 index, GhostRecord *ghostRecord);
void WriteSaveChunk_NKPG_from_thumb(u32 index, const GhostRecord *record);
