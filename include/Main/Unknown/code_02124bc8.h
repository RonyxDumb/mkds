#pragma once

#include "types.h"

typedef struct LayoutTableEntry LayoutTableEntry;

typedef struct Unk02021dc8 Unk02021dc8;

typedef struct Unk0201ea30 Unk0201ea30;

void jn_ui_renderElement(s32 index, Unk0201ea30 *cellLayout, Unk02021dc8 *cells, Unk0201ea30 *labelLayout,
                          void *oamList, LayoutTableEntry *table);
