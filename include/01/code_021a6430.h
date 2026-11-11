#pragma once

#include "types.h"

void QueueMissionRunBossIcon(s32 rowIndex, s32 usePaletteIndex, void *destCells, void *destCellLayout, u32 destIndex,
                             u16 paletteSlot, s32 queueSelector);
void ClearMissionRunBossIconPointer(void);
void CreateMissionRunBossIcon(void *param_1);
void LoadMissionRunBossIconData(void);
