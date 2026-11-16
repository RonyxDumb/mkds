#pragma once

#include "types.h"
#include "g2d_NAN_load.h" // Unk02021dc8
#include "code_02022030.h" // Unk020224e0_c, Unk020224e0_s
#include "code_0201ea58.h" // Unk0201ea30

// 8-byte elements from offset 8 of an Unk0201ea30 (jn_ui_getBnclElement indexes them).
typedef struct CellLayoutEntry {
    /* 00 */ union {
        u32 field0;
        struct {
            Unk0201ea84 field0_0;
            Unk0201ea84 field0_2;
        };
    };
    /* 04 */ u32 mCellIndex;
} CellLayoutEntry;

// 0x24 bytes at member 0x20 of LabelCanvas (jn_ui_drawFormattedTextRectMonospace takes its address).
typedef struct LabelTextCanvas {
    /* 00 */ struct LabelCanvas *mCharCanvas;
    /* 04 */ struct Unk02022aa8 *mFont;
    /* 08 */ s32 mCharSpacing;
    /* 0c */ s32 mLineSpacing;
    /* 10 */ void *field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
} LabelTextCanvas;

// Object of 0x48 bytes allocated by jn_ui_initLabel.
typedef struct LabelCanvas {
    /* 00 */ u8 field0[0x18];
    /* 18 */ void (*field18)(struct LabelCanvas *a, s32 b);
    /* 1c */ u8 field1C[0x4];
    /* 20 */ LabelTextCanvas field20;
    /* 44 */ Unk020224e0_c *field44;
} LabelCanvas;

// 0x40-byte element of the tables jn_ui_initLayout allocates and initLayoutElements sets up: behind
// WiFiVSMatching.field10D4, members 0x14, 0x24 and 0x3c of RecordVSErase, and the tables of the objects behind
// gRecordVS to gSelectRaceRuleWait and of several overlay globals.
typedef struct LayoutTableEntry {
    /* 00 */ s32 mVisible;
    /* 04 */ s16 mOffsetX;
    /* 06 */ s16 mOffsetY;
    /* 08 */ BOOL field8;
    /* 0c */ s16 mPositionX;
    /* 0e */ s16 mPositionY;
    /* 10 */ s32 mUseMatrix;
    /* 14 */ s32 field14[4];
    /* 24 */ s32 mMatrix[4];
    /* 34 */ s32 field34;
    /* 38 */ s32 mLabelIndex;
    /* 3c */ LabelCanvas *mLabelCanvas;
} LayoutTableEntry;

// 8-byte elements jn_ui_initLabel fills and copies into Unk020224e0_s elements.
typedef struct Unk02022eb0 {
    /* 00 */ union {
        u32 field0;
        struct {
            u16 field0_0;
            u16 field0_2;
        };
    };
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
} Unk02022eb0;

// 12-byte elements of the array jn_ui_getBnllElement indexes.
typedef struct LabelLayoutEntry {
    /* 00 */ Unk0201ea84 field0;
    /* 02 */ Unk0201ea84 field2;
    /* 04 */ s8 field4;
    /* 05 */ s8 field5;
    /* 06 */ u16 field6_0 : 8;
    /* 06 */ u16 field6_8 : 4;
    /* 06 */ u16 field6_12 : 4;
    /* 08 */ u8 field8[4];
} LabelLayoutEntry;

// Object whose field14 is the base address QueueCellCharsAndFirstPalette, jn_ui_fillPlaceholder and func_0212481c add offsets
// to.
typedef struct Unk0212463c_c {
    /* 00 */ u8 field0[0x14];
    /* 14 */ u8 *field14;
} Unk0212463c_c;

// Object whose fieldC is the base address QueueCellCharsAndFirstPalette and func_0212481c add an offset to.
typedef struct Unk0212463c_d {
    /* 00 */ u8 field0[0xc];
    /* 0c */ u8 *fieldC;
} Unk0212463c_d;

BOOL jn_ui_getCellIsTranslucent(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void jn_ui_setElementAffine(LayoutTableEntry *entry, s32 angle, s32 scale);
void jn_ui_setCellIsTranslucent(u32 index, s32 value, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
u8 GetCellPaletteIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void jn_ui_setCellCparam(s32 index, s32 paletteIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
u8 jn_ui_getCellPriority(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void jn_ui_setCellPriority(u32 index, u32 value, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
u16 GetCellCharIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void func_0212481c(u32 index, Unk02021dc8 *cells, Unk0212463c_c *chars, Unk0212463c_d *palette, Unk0201ea30 *cellLayout,
                   s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells, Unk0201ea30 *destCellLayout);
void jn_ui_fillPlaceholder(u32 index, Unk02021dc8 *cells, void *chars, Unk0201ea30 *cellLayout, s32 queueSelector,
                    u32 destIndex, Unk02021dc8 *destCells, Unk0201ea30 *destCellLayout);
void QueueCellCharsAndFirstPalette(u32 index, Unk02021dc8 *cells, Unk0212463c_c *chars, Unk0212463c_d *palette,
                                   Unk0201ea30 *cellLayout, s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells,
                                   Unk0201ea30 *destCellLayout);
s32 jn_ui_initLabel(void *heap, s32 labelIndex, Unk0201ea30 *labelLayout, s32 width, s32 height, s32 entryIndex,
                    Unk02021dc8 *cells, Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 j);
void jn_ui_212428C(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text,
                          Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 g, s8 h);
void jn_ui_212426C(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table);
void jn_ui_2124248(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table, s8 g);
void jn_ui_2124224(s32 queueSelector, u32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table, s8 g);
void jn_ui_21241C0(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, Unk0201ea30 *cellLayout,
                                  LayoutTableEntry *table);
BOOL jn_ui_getLabelIsTranslucent(s32 labelIndex, void *b, LayoutTableEntry *table, Unk0201ea30 *cellLayout);
void jn_ui_setLabelIsTranslucent(u32 labelIndex, u32 value, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                   Unk0201ea30 *cellLayout);
void jn_ui_setLabelColorParam(s32 labelIndex, u8 paletteIndex, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                          Unk0201ea30 *cellLayout);
u8 jn_ui_getLabelPriority(s32 labelIndex, void *b, LayoutTableEntry *table, Unk0201ea30 *cellLayout);
void jn_ui_setLabelPriority(u32 labelIndex, u32 value, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                   Unk0201ea30 *cellLayout);
