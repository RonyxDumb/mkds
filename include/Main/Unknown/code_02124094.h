#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx22
#include "g2d_CharCanvas.h" // Unk02023374
#include "g2d_NAN_load.h" // Unk02021dc8
#include "code_02022030.h" // Unk020224e0_c, Unk020224e0_s
#include "code_0201ea58.h" // Unk0201ea30

typedef struct Ncgr Ncgr;
typedef struct Nclr Nclr;

// 8-byte elements from offset 8 of an Unk0201ea30 (func_0201ea30 indexes them).
typedef struct CellLayoutEntry {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            Unk0201ea84 mUnk_00_0;
            Unk0201ea84 mUnk_00_2;
        };
    };
    /* 04 */ u32 mCellIndex;
} CellLayoutEntry;

// 0x24 bytes at member 0x20 of LabelCanvas (func_02125808 takes its address).
typedef struct LabelTextCanvas {
    /* 00 */ Unk02023374 *mCharCanvas;
    /* 04 */ struct Unk02022aa8 *mFont;
    /* 08 */ s32 mCharSpacing;
    /* 0c */ s32 mLineSpacing;
    /* 10 */ void *mCharBuffer;
    /* 14 */ s32 mCharBytes;
    /* 18 */ s32 mCharIndex;
    /* 1c */ s32 mWidth;
    /* 20 */ s32 mHeight;
} LabelTextCanvas;

// Object of 0x48 bytes allocated by InitLabelCanvas.
typedef struct LabelCanvas {
    /* 00 */ Unk02023374 mCharCanvas;
    /* 20 */ LabelTextCanvas mTextCanvas;
    /* 44 */ Unk020224e0_c *mCellData;
} LabelCanvas;

// 0x40-byte element of the tables InitLayoutTable allocates and InitLayoutTableEntries sets up: behind
// WiFiVSMatching.mUnk_10d4, members 0x14, 0x24 and 0x3c of RecordVSErase, and the tables of the objects behind
// gRecordVS to gSelectRaceRuleWait and of several overlay globals.
typedef struct LayoutTableEntry {
    /* 00 */ s32 mVisible;
    /* 04 */ s16 mOffsetX;
    /* 06 */ s16 mOffsetY;
    /* 08 */ BOOL mUsePosition;
    /* 0c */ s16 mPositionX;
    /* 0e */ s16 mPositionY;
    /* 10 */ s32 mUseMatrix;
    /* 14 */ MtxFx22 mInverseScaleMatrix;
    /* 24 */ MtxFx22 mMatrix;
    /* 34 */ s32 mDoubleAffine;
    /* 38 */ s32 mLabelIndex;
    /* 3c */ LabelCanvas *mLabelCanvas;
} LayoutTableEntry;

// 8-byte elements InitLabelCanvas fills and copies into Unk020224e0_s elements.
typedef struct Unk02022eb0 {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            u16 mUnk_00_0;
            u16 mUnk_00_2;
        };
    };
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk02022eb0;

// 12-byte elements of the array func_0201ea58 indexes.
typedef struct LabelLayoutEntry {
    /* 00 */ Unk0201ea84 mAxisX;
    /* 02 */ Unk0201ea84 mAxisY;
    /* 04 */ s8 mCharSpacing;
    /* 05 */ s8 mLineSpacing;
    /* 06 */ u16 mColor : 8;
    /* 06 */ u16 mPaletteIndex : 4;
    /* 06 */ u16 mFontIndex : 4;
    /* 08 */ u8 mUnk_08[4];
} LabelLayoutEntry;

BOOL IsCellOamModeXlu(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void SetLayoutEntryAngleAndScale(LayoutTableEntry *entry, s32 angle, s32 scale);
void SetCellOamModeXlu(u32 index, s32 enableXlu, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
u8 GetCellPaletteIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void SetCellPaletteIndex(s32 index, s32 paletteIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
u8 GetCellPriority(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void SetCellPriority(u32 index, u32 priority, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
u16 GetCellCharIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void QueueCellCharsAndCopyPalettes(u32 index, Unk02021dc8 *cells, Ncgr *chars, Nclr *palette, Unk0201ea30 *cellLayout,
                                   s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells,
                                   Unk0201ea30 *destCellLayout);
void QueueCellChars(u32 index, Unk02021dc8 *cells, Ncgr *chars, Unk0201ea30 *cellLayout, s32 queueSelector,
                    u32 destIndex, Unk02021dc8 *destCells, Unk0201ea30 *destCellLayout);
void QueueCellCharsAndFirstPalette(u32 index, Unk02021dc8 *cells, Ncgr *chars, Nclr *palette, Unk0201ea30 *cellLayout,
                                   s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells,
                                   Unk0201ea30 *destCellLayout);
s32 InitLabelCanvas(void *heap, s32 labelIndex, Unk0201ea30 *labelLayout, s32 width, s32 height, s32 entryIndex,
                    Unk02021dc8 *cells, Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 j);
void PrintLabelLayoutText(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text,
                          Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 fixedDigitsOnly, s8 fixedAdvance);
void PrintLabelLayoutTextNoFixedAdvance(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text,
                                        Unk0201ea30 *cellLayout, LayoutTableEntry *table);
void PrintLabelLayoutTextFixedAdvance(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text,
                                      Unk0201ea30 *cellLayout, LayoutTableEntry *table, s8 fixedAdvance);
void PrintLabelLayoutTextFixedDigits(s32 queueSelector, u32 labelIndex, Unk0201ea30 *labelLayout, void *text,
                                     Unk0201ea30 *cellLayout, LayoutTableEntry *table, s8 fixedAdvance);
void ClearAndQueueLabelLayoutText(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, Unk0201ea30 *cellLayout,
                                  LayoutTableEntry *table);
BOOL IsLabelOamModeXlu(s32 labelIndex, void *labelLayout, LayoutTableEntry *table, Unk0201ea30 *cellLayout);
void SetLabelOamModeXlu(u32 labelIndex, u32 enableXlu, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                        Unk0201ea30 *cellLayout);
void SetLabelPaletteIndex(s32 labelIndex, u8 paletteIndex, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                          Unk0201ea30 *cellLayout);
u8 GetLabelPriority(s32 labelIndex, void *labelLayout, LayoutTableEntry *table, Unk0201ea30 *cellLayout);
void SetLabelPriority(u32 labelIndex, u32 priority, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                      Unk0201ea30 *cellLayout);
