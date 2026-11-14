#include "Main/Graphics/layout_entry_angle.h"
#include "Main/System/heap.h"
#include "Main/Graphics/font_and_player_character.h"
#include "code_0200eddc.h"
#include "g2d_NOB_load.h"
#include "code_02022aa8.h"
#include "Main/Graphics/text_draw.h"
#include "gfd_VramTransferManager.h"
#include "os_thread.h"
#include "Main/Graphics/font_and_player_character.h"
#include "g2d_CharCanvas.h"
#include "fx_mtx22.h"
#include "Main/Menu/data_0215d000.h"
#include "code_02147cd8.h"
#include "gx.h"

const u8 gOamShapeSizeCharBlocks[3][4] = {{1, 4, 0x10, 0x40}, {2, 4, 8, 0x20}, {2, 4, 8, 0x20}};

#pragma thumb on

void SetLayoutEntryAngleAndScale(LayoutTableEntry *entry, s32 angle, s32 scale) {
    s32 pairIndex;
    MtxFx22 *dividedValues;
    MtxFx22 *matrix;
    s64 inverseScale;
    s32 cosine;
    s32 sine;
    pairIndex = (angle >> 4) * 2;
    dividedValues = &entry->mInverseScaleMatrix;
    matrix = &entry->mMatrix;
    inverseScale = FX_Div(0x1000, scale);
    cosine = FX_SinCosTable_[pairIndex + 1];
    entry->mInverseScaleMatrix.a[0] = MUL_FIXED12_NO_ROUND(cosine, inverseScale);
    sine = FX_SinCosTable_[pairIndex];
    dividedValues->a[1] = MUL_FIXED12_NO_ROUND(sine, inverseScale);
    dividedValues->a[2] = -dividedValues->a[1];
    dividedValues->a[3] = entry->mInverseScaleMatrix.a[0];
    MTX_Rot22_(matrix, sine, cosine);
    entry->mMatrix.a[0] = FX_MulFunc(entry->mMatrix.a[0], scale);
    matrix->a[1] = FX_MulFunc(matrix->a[1], scale);
    matrix->a[2] = FX_MulFunc(matrix->a[2], scale);
    matrix->a[3] = FX_MulFunc(matrix->a[3], scale);
}

BOOL IsCellOamModeXlu(s32 index, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout) {
    NNSG2dCellDataWithBR *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    if ((cellData->mPOamAttrArray->mAttr0 & 0xc00) >> 10 == 1) {
        return TRUE;
    }
    return FALSE;
}

void SetCellOamModeXlu(u32 index, s32 enableXlu, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout) {
    NNSG2dCellDataWithBR *cellData;
    CellLayoutEntry *cellEntry;
    s32 oamIndex;
    NNSG2dCellOAMAttrData *oamEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    oamEntry = cellData->mPOamAttrArray;
    for (oamIndex = 0; oamIndex < cellData->mNumOAMAttrs; oamIndex++) {
        oamEntry->mAttr0 &= ~0xc00;
        if (enableXlu != 0) {
            oamEntry->mAttr0 |= 0x400;
        }
        oamEntry++;
    }
}

u8 GetCellPaletteIndex(u32 index, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout) {
    NNSG2dCellDataWithBR *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    return (cellData->mPOamAttrArray->mAttr2 & 0xf000) >> 12;
}

void SetCellPaletteIndex(s32 index, s32 paletteIndex, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout) {
    NNSG2dCellDataWithBR *cellData;
    CellLayoutEntry *cellEntry;
    s32 oamIndex;
    NNSG2dCellOAMAttrData *oamEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    oamEntry = cellData->mPOamAttrArray;
    for (oamIndex = 0; oamIndex < cellData->mNumOAMAttrs; oamIndex++) {
        oamEntry->mAttr2 &= ~0xf000;
        oamEntry->mAttr2 |= paletteIndex << 12;
        oamEntry++;
    }
}

u8 GetCellPriority(s32 index, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout) {
    NNSG2dCellDataWithBR *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    return (cellData->mPOamAttrArray->mAttr2 & 0xc00) >> 10;
}

void SetCellPriority(u32 index, u32 priority, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout) {
    NNSG2dCellDataWithBR *cellData;
    CellLayoutEntry *cellEntry;
    s32 oamIndex;
    NNSG2dCellOAMAttrData *oamEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    oamEntry = cellData->mPOamAttrArray;
    for (oamIndex = 0; oamIndex < cellData->mNumOAMAttrs; oamIndex++) {
        oamEntry->mAttr2 &= ~0xc00;
        oamEntry->mAttr2 |= priority << 10;
        oamEntry++;
    }
}

u16 GetCellCharIndex(u32 index, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout) {
    NNSG2dCellDataWithBR *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    return cellData->mPOamAttrArray->mAttr2 & 0x3ff;
}

// Queues every entry's characters and used palette rows; copies the source palette index to the destination entries.
void QueueCellCharsAndCopyPalettes(u32 index, NNSG2dCellDataBank *cells, Ncgr *chars, Nclr *palette,
                                   LayoutEntryTable *cellLayout, s32 queueSelector, u32 destIndex,
                                   NNSG2dCellDataBank *destCells, LayoutEntryTable *destCellLayout) {
    u8 usedPalettes[16];
    s32 oamCount;
    s32 destCharOffset;
    u8 *charsSource;
    NNSG2dCellDataWithBR *cellData;
    s32 oamIndex;
    NNSG2dCellDataWithBR *destCellData;
    NNSG2dCellOAMAttrData *oamEntry;
    CellLayoutEntry *cellEntry;
    CellLayoutEntry *destCellEntry;
    s32 charBytes;
    u32 oamShape;
    u32 oamSize;
    u32 paletteIndex;
    u32 sourceAttr2;
    s32 paletteRow;
    s32 runStart;
    s32 runLength;
    u8 *paletteSource;
    s32 runBytes;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    destCellEntry = (CellLayoutEntry *) (destCellLayout + 1);
    destCellEntry += destIndex;
    destCellData = NNS_G2dGetCellDataByIdx(destCells, (u16) destCellEntry->mCellIndex);
    oamCount = cellData->mNumOAMAttrs;
    for (paletteRow = 0; paletteRow < 16; paletteRow++) {
        usedPalettes[paletteRow] = 0;
    }
    for (oamIndex = 0; oamIndex < oamCount; oamIndex++) {
        sourceAttr2 = cellData->mPOamAttrArray[oamIndex].mAttr2;
        destCharOffset = (destCellData->mPOamAttrArray[oamIndex].mAttr2 & 0x3ff) << 5;
        oamEntry = &cellData->mPOamAttrArray[oamIndex];
        oamSize = (((u32) oamEntry->mAttr1 << 16) & 0xc0000000) >> 30;
        oamShape = ((u32) cellData->mPOamAttrArray[oamIndex].mAttr0 & 0xc000) >> 14;
        charBytes = (&gOamShapeSizeCharBlocks[0][oamSize])[oamShape * 4] << 5;
        charsSource = (u8 *) chars->mData + ((sourceAttr2 & 0x3ff) << 5);
        DC_FlushRange(charsSource, charBytes);
        if (queueSelector == 0) {
            NNS_GfdRegisterNewVramTransferTask(0x13, destCharOffset, charsSource, charBytes);
        } else {
            NNS_GfdRegisterNewVramTransferTask(0x23, destCharOffset, charsSource, charBytes);
        }
        paletteIndex = (sourceAttr2 & 0xf000) >> 12;
        usedPalettes[paletteIndex] = 1;
        destCellData->mPOamAttrArray[oamIndex].mAttr2 &= ~0xf000;
        destCellData->mPOamAttrArray[oamIndex].mAttr2 |= paletteIndex << 12;
    }
    runStart = 0;
    runLength = 0;
    for (paletteRow = 0; paletteRow < 16; paletteRow++) {
        if (usedPalettes[paletteRow] != 0 && runStart + runLength < 15) {
            runLength++;
        } else if (runLength > 0) {
            runStart <<= 5;
            paletteSource = (u8 *) palette->mData + runStart;
            runBytes = runLength << 5;
            if (queueSelector == 0) {
                NNS_GfdRegisterNewVramTransferTask(0xe, runStart, paletteSource, runBytes);
            } else {
                NNS_GfdRegisterNewVramTransferTask(0x1e, runStart, paletteSource, runBytes);
            }
            runStart = paletteRow + 1;
            runLength = 0;
        } else {
            runStart = paletteRow + 1;
        }
    }
}

void QueueCellChars(u32 index, NNSG2dCellDataBank *cells, Ncgr *chars, LayoutEntryTable *cellLayout, s32 queueSelector,
                    u32 destIndex, NNSG2dCellDataBank *destCells, LayoutEntryTable *destCellLayout) {
    s32 oamIndex;
    NNSG2dCellDataWithBR *cellData;
    NNSG2dCellDataWithBR *destCellData;
    NNSG2dCellOAMAttrData *oamEntry;
    CellLayoutEntry *cellEntry;
    CellLayoutEntry *destCellEntry;
    s32 oamCount;
    u8 *charsSource;
    s32 destCharOffset;
    s32 charBytes;
    u32 oamSize;
    u32 oamShape;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    destCellEntry = (CellLayoutEntry *) (destCellLayout + 1);
    destCellEntry += destIndex;
    destCellData = NNS_G2dGetCellDataByIdx(destCells, (u16) destCellEntry->mCellIndex);
    oamIndex = 0;
    oamCount = cellData->mNumOAMAttrs;
    for (; oamIndex < oamCount; oamIndex++) {
        destCharOffset = (destCellData->mPOamAttrArray[oamIndex].mAttr2 & 0x3ff) << 5;
        oamEntry = &cellData->mPOamAttrArray[oamIndex];
        oamSize = (((u32) oamEntry->mAttr1 << 16) & 0xc0000000) >> 30;
        oamShape = ((u32) cellData->mPOamAttrArray[oamIndex].mAttr0 & 0xc000) >> 14;
        charBytes = (&gOamShapeSizeCharBlocks[0][oamSize])[oamShape * 4] << 5;
        charsSource = (u8 *) chars->mData + ((oamEntry->mAttr2 & 0x3ff) << 5);
        DC_FlushRange(charsSource, charBytes);
        if (queueSelector == 0) {
            NNS_GfdRegisterNewVramTransferTask(0x13, destCharOffset, charsSource, charBytes);
        } else {
            NNS_GfdRegisterNewVramTransferTask(0x23, destCharOffset, charsSource, charBytes);
        }
    }
}

void QueueCellCharsAndFirstPalette(u32 index, NNSG2dCellDataBank *cells, Ncgr *chars, Nclr *palette,
                                   LayoutEntryTable *cellLayout, s32 queueSelector, u32 destIndex,
                                   NNSG2dCellDataBank *destCells, LayoutEntryTable *destCellLayout) {
    s32 oamIndex;
    NNSG2dCellDataWithBR *cellData;
    NNSG2dCellDataWithBR *destCellData;
    NNSG2dCellOAMAttrData *oamEntry;
    CellLayoutEntry *cellEntry;
    CellLayoutEntry *destCellEntry;
    s32 oamCount;
    u8 *charsSource;
    s32 destCharOffset;
    s32 charBytes;
    u32 oamShape;
    u32 oamSize;
    u32 queueCommand;
    u32 destPaletteOffset;
    u8 *paletteSource;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    destCellEntry = (CellLayoutEntry *) (destCellLayout + 1);
    destCellEntry += destIndex;
    destCellData = NNS_G2dGetCellDataByIdx(destCells, (u16) destCellEntry->mCellIndex);
    oamIndex = 0;
    oamCount = cellData->mNumOAMAttrs;
    for (; oamIndex < oamCount; oamIndex++) {
        destCharOffset = (destCellData->mPOamAttrArray[oamIndex].mAttr2 & 0x3ff) << 5;
        oamEntry = &cellData->mPOamAttrArray[oamIndex];
        oamSize = (((u32) oamEntry->mAttr1 << 16) & 0xc0000000) >> 30;
        oamShape = ((u32) cellData->mPOamAttrArray[oamIndex].mAttr0 & 0xc000) >> 14;
        charBytes = (&gOamShapeSizeCharBlocks[0][oamSize])[oamShape * 4] << 5;
        charsSource = (u8 *) chars->mData + ((oamEntry->mAttr2 & 0x3ff) << 5);
        DC_FlushRange(charsSource, charBytes);
        if (queueSelector == 0) {
            NNS_GfdRegisterNewVramTransferTask(0x13, destCharOffset, charsSource, charBytes);
        } else {
            NNS_GfdRegisterNewVramTransferTask(0x23, destCharOffset, charsSource, charBytes);
        }
    }
    destPaletteOffset = (((u32) destCellData->mPOamAttrArray->mAttr2 & 0xf000) >> 12) << 5;
    paletteSource = (u8 *) palette->mData + ((((u32) cellData->mPOamAttrArray->mAttr2 & 0xf000) >> 12) << 5);
    if (queueSelector == 0) {
        queueCommand = 0xe;
    } else {
        queueCommand = 0x1e;
    }
    NNS_GfdRegisterNewVramTransferTask(queueCommand, destPaletteOffset, paletteSource, 0x20);
}

s32 InitLabelCanvas(void *heap, s32 labelIndex, LayoutEntryTable *labelLayout, s32 width, s32 height, s32 entryIndex,
                    NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout, LayoutTableEntry *table, s32 charOffset) {
    OamAttrEntry oamBuffer[128];
    LabelLayoutEntry *labelEntry;
    LabelCanvas *canvas;
    NNSG2dCellDataWithBR *cellData;
    s32 widthBlocks;
    s32 heightBlocks;
    s32 blockCount;
    s32 oamCount;
    s32 oamIndex;
    s32 value;
    s32 originY;
    s32 priority;
    s32 isXlu;
    s32 charSpacing;
    s32 lineSpacing;
    s32 cellEntryCount;
    void *font;
    cellEntryCount = cellLayout->mCount;
    table[entryIndex].mLabelIndex = labelIndex;
    canvas = HeapAlloc(heap, 0x48);
    table[cellEntryCount + labelIndex].mLabelCanvas = canvas;
    labelEntry = GetLabelLayoutEntry(labelLayout, labelIndex);
    widthBlocks = ((width - 1) >> 3) + 1;
    heightBlocks = ((height - 1) >> 3) + 1;
    blockCount = widthBlocks * heightBlocks;
    canvas->mTextCanvas.mCharBytes = blockCount << 5;
    canvas->mTextCanvas.mCharIndex = ((charOffset - 0x100) >> 5) - blockCount;
    canvas->mTextCanvas.mCharBuffer = HeapAlloc(heap, canvas->mTextCanvas.mCharBytes);
    NNS_G2dCharCanvasInitForOBJ1D(canvas, canvas->mTextCanvas.mCharBuffer, widthBlocks, heightBlocks, 4);
    canvas->mCharCanvas.mPClear(&canvas->mCharCanvas, 0);
    lineSpacing = labelEntry->mLineSpacing;
    charSpacing = labelEntry->mCharSpacing;
    font = GetFontByIndex(labelEntry->mFontIndex);
    canvas->mTextCanvas.mCharCanvas = &canvas->mCharCanvas;
    canvas->mTextCanvas.mFont = font;
    canvas->mTextCanvas.mCharSpacing = charSpacing;
    canvas->mTextCanvas.mLineSpacing = lineSpacing;
    canvas->mTextCanvas.mWidth = width;
    canvas->mTextCanvas.mHeight = height;
    value = 0;
    originY = 0;
    if (entryIndex < cellEntryCount) {
        priority = GetCellPriority(entryIndex, cells, cellLayout);
        isXlu = IsCellOamModeXlu(entryIndex, cells, cellLayout);
    } else {
        entryIndex -= cellEntryCount;
        priority = GetLabelPriority(entryIndex, labelLayout, table, cellLayout);
        isXlu = IsLabelOamModeXlu(entryIndex, labelLayout, table, cellLayout);
    }
    switch (labelEntry->mAxisX.mAlign) {
        case 1:
            value = -(widthBlocks << 2);
            break;
        case 2:
            value = -(widthBlocks << 3);
            break;
    }
    switch (labelEntry->mAxisY.mAlign) {
        case 1:
            originY = -(heightBlocks << 2);
            break;
        case 2:
            originY = -(heightBlocks << 3);
            break;
    }
    oamCount =
        NNS_G2dArrangeOBJ1D(oamBuffer, widthBlocks, heightBlocks, value, originY, 0, canvas->mTextCanvas.mCharIndex, 0);
    cellData = HeapAlloc(heap, oamCount * 6 + 0x10);
    cellData->mNumOAMAttrs = oamCount;
    cellData->mCellAttr = 0;
    cellData->mPOamAttrArray = (NNSG2dCellOAMAttrData *) (cellData + 1);
    cellData->mMaxX = widthBlocks << 2;
    cellData->mMaxY = heightBlocks << 2;
    cellData->mMinX = -widthBlocks << 2;
    cellData->mMinY = -heightBlocks << 2;
    for (oamIndex = 0; oamIndex < oamCount; oamIndex++) {
        oamBuffer[oamIndex].mAttr2 = (oamBuffer[oamIndex].mAttr2 & ~0xc00) | (priority * 0x400);
        if (isXlu != 0) {
            value = labelEntry->mPaletteIndex;
            oamBuffer[oamIndex].mAttr01 = (oamBuffer[oamIndex].mAttr01 & ~0xc00) | 0x400;
            oamBuffer[oamIndex].mAttr2 = (oamBuffer[oamIndex].mAttr2 & ~0xf000) | (value * 0x1000);
        } else {
            value = labelEntry->mPaletteIndex;
            oamBuffer[oamIndex].mAttr01 &= ~0xc00;
            oamBuffer[oamIndex].mAttr2 = (oamBuffer[oamIndex].mAttr2 & ~0xf000) | (value * 0x1000);
        }
        oamBuffer[oamIndex].mAttr01 &= ~0x1000;
        oamBuffer[oamIndex].mAttr01 &= 0xc1fffcff;
        cellData->mPOamAttrArray[oamIndex].mAttr0 = oamBuffer[oamIndex].mAttr0;
        cellData->mPOamAttrArray[oamIndex].mAttr1 = oamBuffer[oamIndex].mAttr1;
        cellData->mPOamAttrArray[oamIndex].mAttr2 = oamBuffer[oamIndex].mAttr2;
    }
    canvas->mCellData = cellData;
    return canvas->mTextCanvas.mCharBytes;
}

// Clears the character canvas of entry b, draws the string d into it and queues its upload.
void PrintLabelLayoutText(s32 queueSelector, s32 labelIndex, LayoutEntryTable *labelLayout, void *text,
                          LayoutEntryTable *cellLayout, LayoutTableEntry *table, s32 fixedDigitsOnly, s8 fixedAdvance) {
    s32 canvasWidth;
    s32 offsetX;
    s32 offsetY;
    LabelLayoutEntry *labelEntry;
    LabelCanvas *canvas;
    s32 alignedWidth;
    s32 alignedHeight;
    s32 canvasHeight;
    u32 flags;
    void *chars;
    s32 destOffset;
    s32 charBytes;
    labelEntry = GetLabelLayoutEntry(labelLayout, labelIndex);
    canvas = (table + cellLayout->mCount + labelIndex)->mLabelCanvas;
    canvasWidth = canvas->mTextCanvas.mWidth;
    canvasHeight = canvas->mTextCanvas.mHeight;
    alignedWidth = ((canvasWidth - 1) >> 3) + 1 << 3;
    alignedHeight = ((canvasHeight - 1) >> 3) + 1 << 3;
    flags = 0;
    offsetX = 0;
    offsetY = 0;
    if (labelEntry->mAxisX.mAlign == 0) {
        flags |= 0x200;
    } else if (labelEntry->mAxisX.mAlign == 1) {
        flags |= 0x400;
        offsetX = (alignedWidth - canvasWidth) >> 1;
    } else if (labelEntry->mAxisX.mAlign == 2) {
        flags |= 0x800;
        offsetX = alignedWidth - canvasWidth;
    }
    if (labelEntry->mAxisY.mAlign == 0) {
        flags |= 0x40;
    } else if (labelEntry->mAxisY.mAlign == 1) {
        flags |= 0x80;
        offsetY = (alignedHeight - canvasHeight) >> 1;
    } else if (labelEntry->mAxisY.mAlign == 2) {
        flags |= 0x100;
        offsetY = alignedHeight - canvasHeight;
    }
    canvas->mCharCanvas.mPClear(&canvas->mCharCanvas, 0);
    DrawTextInRectFixedAdvance(&canvas->mTextCanvas, offsetX, offsetY, canvasWidth, canvasHeight, labelEntry->mColor,
                               flags, labelEntry->mAxisX.mLineAlign, text, fixedDigitsOnly, fixedAdvance);
    chars = canvas->mTextCanvas.mCharBuffer;
    destOffset = canvas->mTextCanvas.mCharIndex << 5;
    charBytes = canvas->mTextCanvas.mCharBytes;
    DC_FlushRange(chars, charBytes);
    if (queueSelector == 0) {
        NNS_GfdRegisterNewVramTransferTask(0x13, destOffset, chars, charBytes);
    } else {
        NNS_GfdRegisterNewVramTransferTask(0x23, destOffset, chars, charBytes);
    }
}

void PrintLabelLayoutTextNoFixedAdvance(s32 queueSelector, s32 labelIndex, LayoutEntryTable *labelLayout, void *text,
                                        LayoutEntryTable *cellLayout, LayoutTableEntry *table) {
    PrintLabelLayoutText(queueSelector, labelIndex, labelLayout, text, cellLayout, table, 0, -1);
}

void PrintLabelLayoutTextFixedAdvance(s32 queueSelector, s32 labelIndex, LayoutEntryTable *labelLayout, void *text,
                                      LayoutEntryTable *cellLayout, LayoutTableEntry *table, s8 fixedAdvance) {
    PrintLabelLayoutText(queueSelector, labelIndex, labelLayout, text, cellLayout, table, 0, fixedAdvance);
}

void PrintLabelLayoutTextFixedDigits(s32 queueSelector, u32 labelIndex, LayoutEntryTable *labelLayout, void *text,
                                     LayoutEntryTable *cellLayout, LayoutTableEntry *table, s8 fixedAdvance) {
    PrintLabelLayoutText(queueSelector, labelIndex, labelLayout, text, cellLayout, table, 1, fixedAdvance);
}

// Clears the character canvas of entry b and queues its upload.
void ClearAndQueueLabelLayoutText(s32 queueSelector, s32 labelIndex, LayoutEntryTable *labelLayout,
                                  LayoutEntryTable *cellLayout, LayoutTableEntry *table) {
    LabelCanvas *canvas;
    void *chars;
    s32 destOffset;
    s32 charBytes;
    GetLabelLayoutEntry(labelLayout, labelIndex);
    canvas = (table + cellLayout->mCount + labelIndex)->mLabelCanvas;
    canvas->mCharCanvas.mPClear(&canvas->mCharCanvas, 0);
    chars = canvas->mTextCanvas.mCharBuffer;
    destOffset = canvas->mTextCanvas.mCharIndex << 5;
    charBytes = canvas->mTextCanvas.mCharBytes;
    DC_FlushRange(chars, charBytes);
    if (queueSelector == 0) {
        NNS_GfdRegisterNewVramTransferTask(0x13, destOffset, chars, charBytes);
    } else {
        NNS_GfdRegisterNewVramTransferTask(0x23, destOffset, chars, charBytes);
    }
}

BOOL IsLabelOamModeXlu(s32 labelIndex, void *labelLayout, LayoutTableEntry *table, LayoutEntryTable *cellLayout) {
    LayoutTableEntry *entry;
    LayoutTableEntry *labelTableEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mCount;
    if ((labelTableEntry->mLabelCanvas->mCellData->mPOamAttrArray->mAttr0 & 0xc00) >> 10 == 1) {
        return TRUE;
    }
    return FALSE;
}

void SetLabelOamModeXlu(u32 labelIndex, u32 enableXlu, LayoutEntryTable *labelLayout, LayoutTableEntry *table,
                        LayoutEntryTable *cellLayout) {
    LayoutTableEntry *labelTableEntry;
    LayoutTableEntry *entry;
    s32 oamIndex;
    NNSG2dCellDataWithBR *cellData;
    NNSG2dCellOAMAttrData *oamEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mCount;
    cellData = labelTableEntry->mLabelCanvas->mCellData;
    oamEntry = cellData->mPOamAttrArray;
    for (oamIndex = 0; oamIndex < cellData->mNumOAMAttrs; oamIndex++) {
        oamEntry->mAttr0 &= ~0xc00;
        if (enableXlu != 0) {
            oamEntry->mAttr0 |= 0x400;
        }
        oamEntry++;
    }
}

void SetLabelPaletteIndex(s32 labelIndex, u8 paletteIndex, LayoutEntryTable *labelLayout, LayoutTableEntry *table,
                          LayoutEntryTable *cellLayout) {
    LayoutTableEntry *labelTableEntry;
    LayoutTableEntry *entry;
    s32 oamIndex;
    NNSG2dCellDataWithBR *cellData;
    NNSG2dCellOAMAttrData *oamEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mCount;
    cellData = labelTableEntry->mLabelCanvas->mCellData;
    oamEntry = cellData->mPOamAttrArray;
    for (oamIndex = 0; oamIndex < cellData->mNumOAMAttrs; oamIndex++) {
        oamEntry->mAttr2 &= ~0xf000;
        oamEntry->mAttr2 |= paletteIndex << 12;
        oamEntry++;
    }
}

u8 GetLabelPriority(s32 labelIndex, void *labelLayout, LayoutTableEntry *table, LayoutEntryTable *cellLayout) {
    LayoutTableEntry *entry;
    LayoutTableEntry *labelTableEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mCount;
    return (labelTableEntry->mLabelCanvas->mCellData->mPOamAttrArray->mAttr2 & 0xc00) >> 10;
}

void SetLabelPriority(u32 labelIndex, u32 priority, LayoutEntryTable *labelLayout, LayoutTableEntry *table,
                      LayoutEntryTable *cellLayout) {
    LayoutTableEntry *labelTableEntry;
    LayoutTableEntry *entry;
    s32 oamIndex;
    NNSG2dCellDataWithBR *cellData;
    NNSG2dCellOAMAttrData *oamEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mCount;
    cellData = labelTableEntry->mLabelCanvas->mCellData;
    oamEntry = cellData->mPOamAttrArray;
    for (oamIndex = 0; oamIndex < cellData->mNumOAMAttrs; oamIndex++) {
        oamEntry->mAttr2 &= ~0xc00;
        oamEntry->mAttr2 |= priority << 10;
        oamEntry++;
    }
}

#pragma thumb off
