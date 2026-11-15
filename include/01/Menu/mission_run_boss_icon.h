#pragma once

#include "types.h"
#include "01/unk_021ca000.h"

void QueueMissionRunBossIcon(s16 rowIndex, s32 usePaletteIndex, void *destCells, void *destCellLayout, u32 destIndex,
                             u16 paletteSlot, s32 queueSelector);
void ClearMissionRunBossIconPointer(void);
void CreateMissionRunBossIcon(void *heap);
void LoadMissionRunBossIconData(void);

extern const u16 gMissionRunBossIconCellIndices[7];
extern const u16 gMissionRunBossIconPaletteIndices[7];

extern const char *gMissionRunBossIconSNcgrName;
extern const char *gMissionRunBossIconSNcerName;
extern const char *gMissionRunBossIconSONclrName;
extern const char *gMissionRunBossIconSBnclName;
extern struct MissionRunBossIcon *gMissionRunBossIcon;
