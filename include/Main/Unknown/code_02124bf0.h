#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // LayoutTableEntry, Unk02021dc8, Unk0201ea30
#include "code_02022030.h" // GXOamAttr

// 0x20 bytes: four 8-byte entries (the table behind OamList is indexed in 8-byte steps by renderElement and in
// 0x20-byte steps for the groups of four it fills).
typedef struct Unk02124c70_00 {
    /* 00 */ GXOamAttr field0[4];
} Unk02124c70_00;

// 0x404 bytes: 0x20 groups of four 8-byte entries, then two halfwords (renderElement adds the return value of
// NNS_G2dMakeCellToOams to field400; oam_getAffineCount returns field402).
typedef struct OamList {
    /* 000 */ Unk02124c70_00 field0[0x20];
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 mMatrixCount;
} OamList;

void jn_ui_initLayout(void *heap, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout, LayoutTableEntry **tableOut);
u32 renderElement(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout, OamList *oamList,
                    LayoutTableEntry *entry, s32 incrementFlag);
void jn_ui_renderElements(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, Unk0201ea30 *labelLayout, void *oamList,
                     LayoutTableEntry *table);
void jn_ui_renderElementsNoIncrAffine(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, void *labelLayout, void *oamList, void *table);
