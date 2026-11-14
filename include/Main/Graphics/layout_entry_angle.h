#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx22
#include "g2d_CharCanvas.h" // NNSG2dCharCanvas
#include "g2d_NAN_load.h" // NNSG2dCellDataBank
#include "g2d_Animation.h" // NNSG2dCellDataWithBR, NNSG2dCellOAMAttrData
#include "Main/Graphics/layout_rect_table.h" // LayoutEntryTable

typedef struct Ncgr Ncgr;
typedef struct Nclr Nclr;

// 8-byte elements from offset 8 of an LayoutEntryTable (GetCellLayoutEntry indexes them).
typedef struct CellLayoutEntry {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            LayoutAxis mAxisX;
            LayoutAxis mAxisY;
        };
    };
    /* 04 */ u32 mCellIndex;
} CellLayoutEntry;

// 0x24 bytes at member 0x20 of LabelCanvas (DrawTextInRectFixedAdvance takes its address).
typedef struct LabelTextCanvas {
    /* 00 */ NNSG2dCharCanvas *mCharCanvas;
    /* 04 */ struct NNSG2dFont *mFont;
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
    /* 00 */ NNSG2dCharCanvas mCharCanvas;
    /* 20 */ LabelTextCanvas mTextCanvas;
    /* 44 */ NNSG2dCellDataWithBR *mCellData;
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

// 8-byte elements InitLabelCanvas fills and copies into NNSG2dCellOAMAttrData elements.
typedef struct OamAttrEntry {
    /* 00 */ union {
        u32 mAttr01;
        struct {
            u16 mAttr0;
            u16 mAttr1;
        };
    };
    /* 04 */ u16 mAttr2;
    /* 06 */ u16 mUnk_06;
} OamAttrEntry;

// 12-byte elements of the array GetLabelLayoutEntry indexes.
typedef struct LabelLayoutEntry {
    /* 00 */ LayoutAxis mAxisX;
    /* 02 */ LayoutAxis mAxisY;
    /* 04 */ s8 mCharSpacing;
    /* 05 */ s8 mLineSpacing;
    /* 06 */ u16 mColor : 8;
    /* 06 */ u16 mPaletteIndex : 4;
    /* 06 */ u16 mFontIndex : 4;
    /* 08 */ u8 mUnk_08[4];
} LabelLayoutEntry;

BOOL IsCellOamModeXlu(s32 index, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout);
void SetLayoutEntryAngleAndScale(LayoutTableEntry *entry, s32 angle, s32 scale);
void SetCellOamModeXlu(u32 index, s32 enableXlu, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout);
u8 GetCellPaletteIndex(u32 index, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout);
void SetCellPaletteIndex(s32 index, s32 paletteIndex, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout);
u8 GetCellPriority(s32 index, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout);
void SetCellPriority(u32 index, u32 priority, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout);
u16 GetCellCharIndex(u32 index, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout);
void QueueCellCharsAndCopyPalettes(u32 index, NNSG2dCellDataBank *cells, Ncgr *chars, Nclr *palette,
                                   LayoutEntryTable *cellLayout, s32 queueSelector, u32 destIndex,
                                   NNSG2dCellDataBank *destCells, LayoutEntryTable *destCellLayout);
void QueueCellChars(u32 index, NNSG2dCellDataBank *cells, Ncgr *chars, LayoutEntryTable *cellLayout, s32 queueSelector,
                    u32 destIndex, NNSG2dCellDataBank *destCells, LayoutEntryTable *destCellLayout);
void QueueCellCharsAndFirstPalette(u32 index, NNSG2dCellDataBank *cells, Ncgr *chars, Nclr *palette,
                                   LayoutEntryTable *cellLayout, s32 queueSelector, u32 destIndex,
                                   NNSG2dCellDataBank *destCells, LayoutEntryTable *destCellLayout);
s32 InitLabelCanvas(void *heap, s32 labelIndex, LayoutEntryTable *labelLayout, s32 width, s32 height, s32 entryIndex,
                    NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout, LayoutTableEntry *table, s32 charOffset);
void PrintLabelLayoutText(s32 queueSelector, s32 labelIndex, LayoutEntryTable *labelLayout, void *text,
                          LayoutEntryTable *cellLayout, LayoutTableEntry *table, s32 fixedDigitsOnly, s8 fixedAdvance);
void PrintLabelLayoutTextNoFixedAdvance(s32 queueSelector, s32 labelIndex, LayoutEntryTable *labelLayout, void *text,
                                        LayoutEntryTable *cellLayout, LayoutTableEntry *table);
void PrintLabelLayoutTextFixedAdvance(s32 queueSelector, s32 labelIndex, LayoutEntryTable *labelLayout, void *text,
                                      LayoutEntryTable *cellLayout, LayoutTableEntry *table, s8 fixedAdvance);
void PrintLabelLayoutTextFixedDigits(s32 queueSelector, u32 labelIndex, LayoutEntryTable *labelLayout, void *text,
                                     LayoutEntryTable *cellLayout, LayoutTableEntry *table, s8 fixedAdvance);
void ClearAndQueueLabelLayoutText(s32 queueSelector, s32 labelIndex, LayoutEntryTable *labelLayout,
                                  LayoutEntryTable *cellLayout, LayoutTableEntry *table);
BOOL IsLabelOamModeXlu(s32 labelIndex, void *labelLayout, LayoutTableEntry *table, LayoutEntryTable *cellLayout);
void SetLabelOamModeXlu(u32 labelIndex, u32 enableXlu, LayoutEntryTable *labelLayout, LayoutTableEntry *table,
                        LayoutEntryTable *cellLayout);
void SetLabelPaletteIndex(s32 labelIndex, u8 paletteIndex, LayoutEntryTable *labelLayout, LayoutTableEntry *table,
                          LayoutEntryTable *cellLayout);
u8 GetLabelPriority(s32 labelIndex, void *labelLayout, LayoutTableEntry *table, LayoutEntryTable *cellLayout);
void SetLabelPriority(u32 labelIndex, u32 priority, LayoutEntryTable *labelLayout, LayoutTableEntry *table,
                      LayoutEntryTable *cellLayout);

extern const u8 gOamShapeSizeCharBlocks[3][4];
