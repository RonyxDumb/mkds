#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02124efc.h"
#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_0201ea30.h"
#include "Main/Unknown/code_0201ea58.h"
#include "g2d_NOB_load.h"
#include "code_020222ec.h"

#pragma thumb on

void InitLayoutTable(void *heap, LayoutEntryTable *cellLayout, LayoutEntryTable *labelLayout,
                     LayoutTableEntry **tableOut) {
    u16 count;

    count = cellLayout->mCount;
    if (labelLayout != NULL) {
        count = count + labelLayout->mCount;
    }
    *tableOut = HeapAlloc(heap, count << 6);
    InitLayoutTableEntries(*tableOut, count);
}

// Draws entry a: first the entry it is chained to, then itself; appends the cell OAMs to the list, and returns without
// drawing when the entry is disabled or lies off the 256 x 192 screen.
u32 DrawLayoutEntry(s32 index, Unk02021dc8 *cells, LayoutEntryTable *cellLayout, LayoutEntryTable *labelLayout,
                    RaceHudOamBuffer *oamList, LayoutTableEntry *entry, s32 incrementFlag) {
    s32 width;
    s32 height;
    MtxFx22 *matrix;
    LayoutAxis axisRecords[3];
    s32 position[2];
    NNSG2dCellDataWithBR *cellData;
    CellLayoutEntry *cellEntry;
    u16 groupIndex;
    u32 oamCount;
    GXOamAffine *group;

    if (entry->mLabelIndex != -1) {
        DrawLayoutEntry(entry->mLabelIndex + cellLayout->mCount, cells, cellLayout, labelLayout, oamList,
                        entry - index + cellLayout->mCount + entry->mLabelIndex, incrementFlag);
    }
    matrix = NULL;
    if (entry->mVisible == 0) {
        return (u32) matrix;
    }
    if (index >= cellLayout->mCount) {
        LabelLayoutEntry *labelEntry = GetLabelLayoutEntry(labelLayout, index - cellLayout->mCount);
        cellData = entry->mLabelCanvas->mCellData;
        axisRecords[0] = labelEntry->mAxisX;
        axisRecords[1] = labelEntry->mAxisY;
        width = cellData->mMaxX - cellData->mMinX;
        height = cellData->mMaxY - cellData->mMinY;
        position[0] = TO_FIXED12(axisRecords[0].mUnk_00_0);
        position[1] = TO_FIXED12(axisRecords[1].mUnk_00_0);
    } else {
        cellEntry = GetCellLayoutEntry(cellLayout, index);
        cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
        axisRecords[2] = cellEntry->mUnk_00_0;
        axisRecords[0] = axisRecords[2];
        axisRecords[1] = cellEntry->mUnk_00_2;
        width = cellData->mMaxX - cellData->mMinX;
        height = cellData->mMaxY - cellData->mMinY;
        position[0] = TO_FIXED12((width >> 1) + GetLayoutAxisStartX(axisRecords[2], width));
        position[1] = TO_FIXED12((height >> 1) + GetLayoutAxisStartY(cellEntry->mUnk_00_2, height));
    }
    if (entry->mUsePosition != FALSE) {
        if (index >= cellLayout->mCount) {
            position[0] = TO_FIXED12(entry->mPositionX);
            position[1] = TO_FIXED12(entry->mPositionY);
        } else {
            position[0] = (entry->mPositionX + (width >> 1) * (1 - axisRecords[0].mUnk_00_12)) << 12;
            position[1] = (entry->mPositionY + (height >> 1) * (1 - axisRecords[1].mUnk_00_12)) << 12;
        }
    }
    position[0] += TO_FIXED12(entry->mOffsetX);
    position[1] += TO_FIXED12(entry->mOffsetY);
    if ((position[0] >> 12) + width < 0 || (position[0] >> 12) - width > 0x100 || (position[1] >> 12) + height < 0 ||
        FROM_FIXED12(position[1]) - height > 0xc0) {
        return 0;
    }
    groupIndex = GetOamMatrixCount(oamList);
    if (entry->mUseMatrix != 0) {
        matrix = &entry->mMatrix;
        group = &oamList->mMatrices[groupIndex];
        group->mPA = entry->mInverseScaleMatrix.mUnk_00[0] >> 4;
        group->mPB = entry->mInverseScaleMatrix.mUnk_00[1] >> 4;
        group->mPC = entry->mInverseScaleMatrix.mUnk_00[2] >> 4;
        group->mPD = entry->mInverseScaleMatrix.mUnk_00[3] >> 4;
        if (incrementFlag != 0) {
            IncrementOamMatrixCount(oamList);
        }
    }
    oamCount = oamList->mOamCount;
    oamList->mOamCount += NNS_G2dMakeCellToOams(&oamList->mOams[oamCount], 0x80 - oamCount, cellData, matrix, position,
                                                groupIndex, entry->mDoubleAffine);
}

void DrawLayoutTable(LayoutEntryTable *cellLayout, Unk02021dc8 *cells, LayoutEntryTable *labelLayout, void *oamList,
                     LayoutTableEntry *table) {
    s32 entryIndex;
    for (entryIndex = cellLayout->mCount - 1; entryIndex >= 0; entryIndex--) {
        DrawLayoutEntry(entryIndex, cells, cellLayout, labelLayout, oamList, table + entryIndex, 1);
    }
}

void DrawLayoutTableKeepMatrixCount(LayoutEntryTable *cellLayout, Unk02021dc8 *cells, LayoutEntryTable *labelLayout,
                                    void *oamList, LayoutTableEntry *table) {
    s32 entryIndex;
    for (entryIndex = cellLayout->mCount - 1; entryIndex >= 0; entryIndex--) {
        DrawLayoutEntry(entryIndex, cells, cellLayout, labelLayout, oamList, table + entryIndex, 0);
    }
}

#pragma thumb off
