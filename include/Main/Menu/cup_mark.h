#pragma once

#include "types.h"

typedef struct LayoutEntryTable LayoutEntryTable;

typedef struct Unk02021dc8 Unk02021dc8;

void QueueSelectCupNameM(u32 nameIndex, Unk02021dc8 *cells, LayoutEntryTable *cellLayout, u32 destIndex,
                         u32 queueSelector);
void CreateSelectCupNameM(void *heap);
void LoadSelectCupNameMData(void);
void QueueCupMark(u32 cupMarkIndex, Unk02021dc8 *cells, LayoutEntryTable *cellLayout, u32 destIndex, u16 paletteSlot,
                  s32 queueSelector);
void ClearCupMarkPointer(void);
