#include "Main/Unknown/code_02124094.h"
#include "Main/System/Heap.h"
#include "code_0200eddc.h"
#include "g2d_NOB_load.h"
#include "Main/Unknown/code_02022000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b4000.h"
#include "g2d_CharCanvas.h"
#include "code_02146cb0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "gx.h"

#pragma thumb on

void jn_ui_setElementAffine(LayoutTableEntry *entry, s32 angle, s32 scale) {
    s32 pairIndex;
    s32 *dividedValues;
    s32 *matrix;
    s64 inverseScale;
    s32 cosine;
    s32 sine;
    pairIndex = (angle >> 4) * 2;
    dividedValues = entry->field14;
    matrix = entry->mMatrix;
    inverseScale = FX_Div(0x1000, scale);
    cosine = FX_SinCosTable_[pairIndex + 1];
    entry->field14[0] = ((s64) cosine * inverseScale) >> 12;
    sine = FX_SinCosTable_[pairIndex];
    dividedValues[1] = ((s64) sine * inverseScale) >> 12;
    dividedValues[2] = -dividedValues[1];
    dividedValues[3] = entry->field14[0];
    MTX_Rot22_(matrix, sine, cosine);
    entry->mMatrix[0] = FX_MulFunc(entry->mMatrix[0], scale);
    matrix[1] = FX_MulFunc(matrix[1], scale);
    matrix[2] = FX_MulFunc(matrix[2], scale);
    matrix[3] = FX_MulFunc(matrix[3], scale);
}

BOOL jn_ui_getCellIsTranslucent(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    if ((cellData->field4->field0 & 0xc00) >> 10 == 1) {
        return TRUE;
    }
    return FALSE;
}

void jn_ui_setCellIsTranslucent(u32 index, s32 value, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    s32 i;
    Unk020224e0_s *oamEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    oamEntry = cellData->field4;
    for (i = 0; i < cellData->field0; i++) {
        oamEntry->field0 &= ~0xc00;
        if (value != 0) {
            oamEntry->field0 |= 0x400;
        }
        oamEntry++;
    }
}

u8 GetCellPaletteIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    return (cellData->field4->field4 & 0xf000) >> 12;
}

void jn_ui_setCellCparam(s32 index, s32 paletteIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    s32 i;
    Unk020224e0_s *oamEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    oamEntry = cellData->field4;
    for (i = 0; i < cellData->field0; i++) {
        oamEntry->field4 &= ~0xf000;
        oamEntry->field4 |= paletteIndex << 12;
        oamEntry++;
    }
}

u8 jn_ui_getCellPriority(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    return (cellData->field4->field4 & 0xc00) >> 10;
}

void jn_ui_setCellPriority(u32 index, u32 value, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    s32 i;
    Unk020224e0_s *oamEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    oamEntry = cellData->field4;
    for (i = 0; i < cellData->field0; i++) {
        oamEntry->field4 &= ~0xc00;
        oamEntry->field4 |= value << 10;
        oamEntry++;
    }
}

u16 GetCellCharIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    return cellData->field4->field4 & 0x3ff;
}

void func_0212481c(u32 index, Unk02021dc8 *cells, Unk0212463c_c *chars, Unk0212463c_d *palette, Unk0201ea30 *cellLayout,
                   s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells, Unk0201ea30 *destCellLayout) {
    u8 usedPalettes[16];
    s32 oamCount;
    s32 destCharOffset;
    u8 *charsSource;
    Unk020224e0_c *cellData;
    s32 j;
    Unk020224e0_c *destCellData;
    Unk020224e0_s *oamEntry;
    CellLayoutEntry *cellEntry;
    CellLayoutEntry *destCellEntry;
    s32 charBytes;
    u32 x;
    u32 y;
    u32 paletteIndex;
    u32 w;
    s32 k;
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
    oamCount = cellData->field0;
    for (k = 0; k < 16; k++) {
        usedPalettes[k] = 0;
    }
    for (j = 0; j < oamCount; j++) {
        w = cellData->field4[j].field4;
        destCharOffset = (destCellData->field4[j].field4 & 0x3ff) << 5;
        oamEntry = &cellData->field4[j];
        y = (((u32) oamEntry->field2 << 16) & 0xc0000000) >> 30;
        x = ((u32) cellData->field4[j].field0 & 0xc000) >> 14;
        charBytes = (&data_0215d024[y])[x * 4] << 5;
        charsSource = chars->field14 + ((w & 0x3ff) << 5);
        DC_FlushRange(charsSource, charBytes);
        if (queueSelector == 0) {
            NNS_GfdRegisterNewVramTransferTask(0x13, destCharOffset, charsSource, charBytes);
        } else {
            NNS_GfdRegisterNewVramTransferTask(0x23, destCharOffset, charsSource, charBytes);
        }
        paletteIndex = (w & 0xf000) >> 12;
        usedPalettes[paletteIndex] = 1;
        destCellData->field4[j].field4 &= ~0xf000;
        destCellData->field4[j].field4 |= paletteIndex << 12;
    }
    runStart = 0;
    runLength = 0;
    for (k = 0; k < 16; k++) {
        if (usedPalettes[k] != 0 && runStart + runLength < 15) {
            runLength++;
        } else if (runLength > 0) {
            runStart <<= 5;
            paletteSource = palette->fieldC + runStart;
            runBytes = runLength << 5;
            if (queueSelector == 0) {
                NNS_GfdRegisterNewVramTransferTask(0xe, runStart, paletteSource, runBytes);
            } else {
                NNS_GfdRegisterNewVramTransferTask(0x1e, runStart, paletteSource, runBytes);
            }
            runStart = k + 1;
            runLength = 0;
        } else {
            runStart = k + 1;
        }
    }
}

void jn_ui_fillPlaceholder(u32 index, Unk02021dc8 *cells, void *chars, Unk0201ea30 *cellLayout, s32 queueSelector,
                    u32 destIndex, Unk02021dc8 *destCells, Unk0201ea30 *destCellLayout) {
    s32 i;
    Unk020224e0_c *cellData;
    Unk020224e0_c *destCellData;
    Unk020224e0_s *oamEntry;
    CellLayoutEntry *cellEntry;
    CellLayoutEntry *destCellEntry;
    s32 oamCount;
    u8 *charsSource;
    s32 destCharOffset;
    s32 charBytes;
    u32 t;
    u32 x;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    destCellEntry = (CellLayoutEntry *) (destCellLayout + 1);
    destCellEntry += destIndex;
    destCellData = NNS_G2dGetCellDataByIdx(destCells, (u16) destCellEntry->mCellIndex);
    i = 0;
    oamCount = cellData->field0;
    for (; i < oamCount; i++) {
        destCharOffset = (destCellData->field4[i].field4 & 0x3ff) << 5;
        oamEntry = &cellData->field4[i];
        t = (((u32) oamEntry->field2 << 16) & 0xc0000000) >> 30;
        x = ((u32) cellData->field4[i].field0 & 0xc000) >> 14;
        charBytes = (&data_0215d024[t])[x * 4] << 5;
        charsSource = ((Unk0212463c_c *) chars)->field14 + ((oamEntry->field4 & 0x3ff) << 5);
        DC_FlushRange(charsSource, charBytes);
        if (queueSelector == 0) {
            NNS_GfdRegisterNewVramTransferTask(0x13, destCharOffset, charsSource, charBytes);
        } else {
            NNS_GfdRegisterNewVramTransferTask(0x23, destCharOffset, charsSource, charBytes);
        }
    }
}

void QueueCellCharsAndFirstPalette(u32 index, Unk02021dc8 *cells, Unk0212463c_c *chars, Unk0212463c_d *palette,
                                   Unk0201ea30 *cellLayout, s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells,
                                   Unk0201ea30 *destCellLayout) {
    s32 j;
    Unk020224e0_c *cellData;
    Unk020224e0_c *destCellData;
    Unk020224e0_s *oamEntry;
    CellLayoutEntry *cellEntry;
    CellLayoutEntry *destCellEntry;
    s32 oamCount;
    u8 *charsSource;
    s32 destCharOffset;
    s32 charBytes;
    u32 x;
    u32 y;
    u32 queueCommand;
    u32 destPaletteOffset;
    u8 *paletteSource;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    destCellEntry = (CellLayoutEntry *) (destCellLayout + 1);
    destCellEntry += destIndex;
    destCellData = NNS_G2dGetCellDataByIdx(destCells, (u16) destCellEntry->mCellIndex);
    j = 0;
    oamCount = cellData->field0;
    for (; j < oamCount; j++) {
        destCharOffset = (destCellData->field4[j].field4 & 0x3ff) << 5;
        oamEntry = &cellData->field4[j];
        y = (((u32) oamEntry->field2 << 16) & 0xc0000000) >> 30;
        x = ((u32) cellData->field4[j].field0 & 0xc000) >> 14;
        charBytes = (&data_0215d024[y])[x * 4] << 5;
        charsSource = chars->field14 + ((oamEntry->field4 & 0x3ff) << 5);
        DC_FlushRange(charsSource, charBytes);
        if (queueSelector == 0) {
            NNS_GfdRegisterNewVramTransferTask(0x13, destCharOffset, charsSource, charBytes);
        } else {
            NNS_GfdRegisterNewVramTransferTask(0x23, destCharOffset, charsSource, charBytes);
        }
    }
    destPaletteOffset = (((u32) destCellData->field4->field4 & 0xf000) >> 12) << 5;
    paletteSource = palette->fieldC + ((((u32) cellData->field4->field4 & 0xf000) >> 12) << 5);
    if (queueSelector == 0) {
        queueCommand = 0xe;
    } else {
        queueCommand = 0x1e;
    }
    NNS_GfdRegisterNewVramTransferTask(queueCommand, destPaletteOffset, paletteSource, 0x20);
}

s32 jn_ui_initLabel(void *heap, s32 labelIndex, Unk0201ea30 *labelLayout, s32 width, s32 height, s32 entryIndex,
                    Unk02021dc8 *cells, Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 j) {
    Unk02022eb0 oamBuffer[128];
    LabelLayoutEntry *labelEntry;
    LabelCanvas *canvas;
    Unk020224e0_c *cellData;
    s32 widthBlocks;
    s32 heightBlocks;
    s32 blockCount;
    s32 oamCount;
    s32 k;
    s32 m;
    s32 n;
    s32 u;
    s32 v;
    s32 sa;
    s32 sb;
    s32 cellEntryCount;
    void *font;
    cellEntryCount = cellLayout->field6;
    table[entryIndex].mLabelIndex = labelIndex;
    canvas = heap_alloc(heap, 0x48);
    table[cellEntryCount + labelIndex].mLabelCanvas = canvas;
    labelEntry = jn_ui_getBnllElement(labelLayout, labelIndex);
    widthBlocks = ((width - 1) >> 3) + 1;
    heightBlocks = ((height - 1) >> 3) + 1;
    blockCount = widthBlocks * heightBlocks;
    canvas->field20.field14 = blockCount << 5;
    canvas->field20.field18 = ((j - 0x100) >> 5) - blockCount;
    canvas->field20.field10 = heap_alloc(heap, canvas->field20.field14);
    NNS_G2dCharCanvasInitForOBJ1D(canvas, canvas->field20.field10, widthBlocks, heightBlocks, 4);
    canvas->field18(canvas, 0);
    sb = labelEntry->field5;
    sa = labelEntry->field4;
    font = m2d_getFont(labelEntry->field6_12);
    canvas->field20.mCharCanvas = canvas;
    canvas->field20.mFont = font;
    canvas->field20.mCharSpacing = sa;
    canvas->field20.mLineSpacing = sb;
    canvas->field20.field1C = width;
    canvas->field20.field20 = height;
    m = 0;
    n = 0;
    if (entryIndex < cellEntryCount) {
        u = jn_ui_getCellPriority(entryIndex, cells, cellLayout);
        v = jn_ui_getCellIsTranslucent(entryIndex, cells, cellLayout);
    } else {
        entryIndex -= cellEntryCount;
        u = jn_ui_getLabelPriority(entryIndex, labelLayout, table, cellLayout);
        v = jn_ui_getLabelIsTranslucent(entryIndex, labelLayout, table, cellLayout);
    }
    switch (labelEntry->field0.field0_12) {
        case 1:
            m = -(widthBlocks << 2);
            break;
        case 2:
            m = -(widthBlocks << 3);
            break;
    }
    switch (labelEntry->field2.field0_12) {
        case 1:
            n = -(heightBlocks << 2);
            break;
        case 2:
            n = -(heightBlocks << 3);
            break;
    }
    oamCount = NNS_G2dArrangeOBJ1D(oamBuffer, widthBlocks, heightBlocks, m, n, 0, canvas->field20.field18, 0);
    cellData = heap_alloc(heap, oamCount * 6 + 0x10);
    cellData->field0 = oamCount;
    cellData->field2 = 0;
    cellData->field4 = (Unk020224e0_s *) (cellData + 1);
    cellData->field8 = widthBlocks << 2;
    cellData->fieldA = heightBlocks << 2;
    cellData->fieldC = -widthBlocks << 2;
    cellData->fieldE = -heightBlocks << 2;
    for (k = 0; k < oamCount; k++) {
        oamBuffer[k].field4 = (oamBuffer[k].field4 & ~0xc00) | (u * 0x400);
        if (v != 0) {
            m = labelEntry->field6_8;
            oamBuffer[k].field0 = (oamBuffer[k].field0 & ~0xc00) | 0x400;
            oamBuffer[k].field4 = (oamBuffer[k].field4 & ~0xf000) | (m * 0x1000);
        } else {
            m = labelEntry->field6_8;
            oamBuffer[k].field0 &= ~0xc00;
            oamBuffer[k].field4 = (oamBuffer[k].field4 & ~0xf000) | (m * 0x1000);
        }
        oamBuffer[k].field0 &= ~0x1000;
        oamBuffer[k].field0 &= 0xc1fffcff;
        cellData->field4[k].field0 = oamBuffer[k].field0_0;
        cellData->field4[k].field2 = oamBuffer[k].field0_2;
        cellData->field4[k].field4 = oamBuffer[k].field4;
    }
    canvas->field44 = cellData;
    return canvas->field20.field14;
}

// Clears the character canvas of entry b, draws the string d into it and queues its upload.
void jn_ui_212428C(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text,
                          Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 g, s8 h) {
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
    labelEntry = jn_ui_getBnllElement(labelLayout, labelIndex);
    canvas = (table + cellLayout->field6 + labelIndex)->mLabelCanvas;
    canvasWidth = canvas->field20.field1C;
    canvasHeight = canvas->field20.field20;
    alignedWidth = ((canvasWidth - 1) >> 3) + 1 << 3;
    alignedHeight = ((canvasHeight - 1) >> 3) + 1 << 3;
    flags = 0;
    offsetX = 0;
    offsetY = 0;
    if (labelEntry->field0.field0_12 == 0) {
        flags |= 0x200;
    } else if (labelEntry->field0.field0_12 == 1) {
        flags |= 0x400;
        offsetX = (alignedWidth - canvasWidth) >> 1;
    } else if (labelEntry->field0.field0_12 == 2) {
        flags |= 0x800;
        offsetX = alignedWidth - canvasWidth;
    }
    if (labelEntry->field2.field0_12 == 0) {
        flags |= 0x40;
    } else if (labelEntry->field2.field0_12 == 1) {
        flags |= 0x80;
        offsetY = (alignedHeight - canvasHeight) >> 1;
    } else if (labelEntry->field2.field0_12 == 2) {
        flags |= 0x100;
        offsetY = alignedHeight - canvasHeight;
    }
    canvas->field18(canvas, 0);
    jn_ui_drawFormattedTextRectMonospace(&canvas->field20, offsetX, offsetY, canvasWidth, canvasHeight, labelEntry->field6_0, flags,
                  labelEntry->field0.field0_14, text, g, h);
    chars = canvas->field20.field10;
    destOffset = canvas->field20.field18 << 5;
    charBytes = canvas->field20.field14;
    DC_FlushRange(chars, charBytes);
    if (queueSelector == 0) {
        NNS_GfdRegisterNewVramTransferTask(0x13, destOffset, chars, charBytes);
    } else {
        NNS_GfdRegisterNewVramTransferTask(0x23, destOffset, chars, charBytes);
    }
}

void jn_ui_212426C(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table) {
    jn_ui_212428C(queueSelector, labelIndex, labelLayout, text, cellLayout, table, 0, -1);
}

void jn_ui_2124248(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table, s8 g) {
    jn_ui_212428C(queueSelector, labelIndex, labelLayout, text, cellLayout, table, 0, g);
}

void jn_ui_2124224(s32 queueSelector, u32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table, s8 g) {
    jn_ui_212428C(queueSelector, labelIndex, labelLayout, text, cellLayout, table, 1, g);
}

// Clears the character canvas of entry b and queues its upload.
void jn_ui_21241C0(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, Unk0201ea30 *cellLayout,
                                  LayoutTableEntry *table) {
    LabelCanvas *canvas;
    void *chars;
    s32 destOffset;
    s32 charBytes;
    jn_ui_getBnllElement(labelLayout, labelIndex);
    canvas = (table + cellLayout->field6 + labelIndex)->mLabelCanvas;
    canvas->field18(canvas, 0);
    chars = canvas->field20.field10;
    destOffset = canvas->field20.field18 << 5;
    charBytes = canvas->field20.field14;
    DC_FlushRange(chars, charBytes);
    if (queueSelector == 0) {
        NNS_GfdRegisterNewVramTransferTask(0x13, destOffset, chars, charBytes);
    } else {
        NNS_GfdRegisterNewVramTransferTask(0x23, destOffset, chars, charBytes);
    }
}

BOOL jn_ui_getLabelIsTranslucent(s32 labelIndex, void *b, LayoutTableEntry *table, Unk0201ea30 *cellLayout) {
    LayoutTableEntry *entry;
    LayoutTableEntry *labelTableEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->field6;
    if ((labelTableEntry->mLabelCanvas->field44->field4->field0 & 0xc00) >> 10 == 1) {
        return TRUE;
    }
    return FALSE;
}

void jn_ui_setLabelIsTranslucent(u32 labelIndex, u32 value, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                   Unk0201ea30 *cellLayout) {
    LayoutTableEntry *labelTableEntry;
    LayoutTableEntry *entry;
    s32 i;
    Unk020224e0_c *cellData;
    Unk020224e0_s *oamEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->field6;
    cellData = labelTableEntry->mLabelCanvas->field44;
    oamEntry = cellData->field4;
    for (i = 0; i < cellData->field0; i++) {
        oamEntry->field0 &= ~0xc00;
        if (value != 0) {
            oamEntry->field0 |= 0x400;
        }
        oamEntry++;
    }
}

void jn_ui_setLabelColorParam(s32 labelIndex, u8 paletteIndex, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                          Unk0201ea30 *cellLayout) {
    LayoutTableEntry *labelTableEntry;
    LayoutTableEntry *entry;
    s32 i;
    Unk020224e0_c *cellData;
    Unk020224e0_s *oamEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->field6;
    cellData = labelTableEntry->mLabelCanvas->field44;
    oamEntry = cellData->field4;
    for (i = 0; i < cellData->field0; i++) {
        oamEntry->field4 &= ~0xf000;
        oamEntry->field4 |= paletteIndex << 12;
        oamEntry++;
    }
}

u8 jn_ui_getLabelPriority(s32 labelIndex, void *b, LayoutTableEntry *table, Unk0201ea30 *cellLayout) {
    LayoutTableEntry *entry;
    LayoutTableEntry *labelTableEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->field6;
    return (labelTableEntry->mLabelCanvas->field44->field4->field4 & 0xc00) >> 10;
}

void jn_ui_setLabelPriority(u32 labelIndex, u32 value, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                   Unk0201ea30 *cellLayout) {
    LayoutTableEntry *labelTableEntry;
    LayoutTableEntry *entry;
    s32 i;
    Unk020224e0_c *cellData;
    Unk020224e0_s *oamEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->field6;
    cellData = labelTableEntry->mLabelCanvas->field44;
    oamEntry = cellData->field4;
    for (i = 0; i < cellData->field0; i++) {
        oamEntry->field4 &= ~0xc00;
        oamEntry->field4 |= value << 10;
        oamEntry++;
    }
}

#pragma thumb off
