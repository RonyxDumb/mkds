#pragma once

#include "types.h"

typedef struct LayoutTableEntry LayoutTableEntry;
typedef struct Unk0201ea30 Unk0201ea30;

void RectTableSetEntryXY(int id, int x, int y, Unk0201ea30 *graphics);
void func_02025bf0(u32 entryId, LayoutTableEntry *output, Unk0201ea30 *labelLayout);
void func_02025c1c(u32 entryId, LayoutTableEntry *output, Unk0201ea30 *cellLayout);
void func_02025c48(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout);
void func_02025c6c(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout);
void func_02025c94(int id, int x, int y, Unk0201ea30 *graphics);
