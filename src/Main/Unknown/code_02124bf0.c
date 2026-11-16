#include "Main/Unknown/code_02124bf0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02124efc.h"
#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "code_0201ea30.h"
#include "code_0201ea58.h"
#include "g2d_NOB_load.h"
#include "code_020222ec.h"

#pragma thumb on

void jn_ui_initLayout(void *heap, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout, LayoutTableEntry **tableOut) {
    u16 count;

    count = cellLayout->field6;
    if (labelLayout != NULL) {
        count = count + labelLayout->field6;
    }
    *tableOut = heap_alloc(heap, count << 6);
    initLayoutElements(*tableOut, count);
}

// Draws entry a: first the entry it is chained to, then itself; appends the cell OAMs to the list, and returns without
// drawing when the entry is disabled or lies off the 256 x 192 screen.
u32 renderElement(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout, OamList *oamList,
                    LayoutTableEntry *entry, s32 incrementFlag) {
    s32 width;
    s32 height;
    s32 *matrix;
    Unk0201ea84 axisRecords[3];
    s32 position[2];
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    u16 groupIndex;
    u32 oamCount;
    Unk02124c70_00 *group;

    if (entry->mLabelIndex != -1) {
        renderElement(entry->mLabelIndex + cellLayout->field6, cells, cellLayout, labelLayout, oamList,
                        entry - index + cellLayout->field6 + entry->mLabelIndex, incrementFlag);
    }
    matrix = NULL;
    if (entry->mVisible == 0) {
        return (u32) matrix;
    }
    if (index >= cellLayout->field6) {
        LabelLayoutEntry *labelEntry = jn_ui_getBnllElement(labelLayout, index - cellLayout->field6);
        cellData = entry->mLabelCanvas->field44;
        axisRecords[0] = labelEntry->field0;
        axisRecords[1] = labelEntry->field2;
        width = cellData->field8 - cellData->fieldC;
        height = cellData->fieldA - cellData->fieldE;
        position[0] = axisRecords[0].field0_0 << 12;
        position[1] = axisRecords[1].field0_0 << 12;
    } else {
        cellEntry = jn_ui_getBnclElement(cellLayout, index);
        cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
        axisRecords[2] = cellEntry->field0_0;
        axisRecords[0] = axisRecords[2];
        axisRecords[1] = cellEntry->field0_2;
        width = cellData->field8 - cellData->fieldC;
        height = cellData->fieldA - cellData->fieldE;
        position[0] = ((width >> 1) + jn_ui_calcOriginCoordX(axisRecords[2], width)) << 12;
        position[1] = ((height >> 1) + jn_ui_calcOriginCoordY(cellEntry->field0_2, height)) << 12;
    }
    if (entry->field8 != FALSE) {
        if (index >= cellLayout->field6) {
            position[0] = entry->mPositionX << 12;
            position[1] = entry->mPositionY << 12;
        } else {
            position[0] = (entry->mPositionX + (width >> 1) * (1 - axisRecords[0].field0_12)) << 12;
            position[1] = (entry->mPositionY + (height >> 1) * (1 - axisRecords[1].field0_12)) << 12;
        }
    }
    position[0] += entry->mOffsetX << 12;
    position[1] += entry->mOffsetY << 12;
    if ((position[0] >> 12) + width < 0 || (position[0] >> 12) - width > 0x100 || (position[1] >> 12) + height < 0 ||
        (position[1] >> 12) - height > 0xc0) {
        return 0;
    }
    groupIndex = oam_getAffineCount(oamList);
    if (entry->mUseMatrix != 0) {
        matrix = entry->mMatrix;
        group = &oamList->field0[groupIndex];
        group->field0[0].field0[3] = entry->field14[0] >> 4;
        group->field0[1].field0[3] = entry->field14[1] >> 4;
        group->field0[2].field0[3] = entry->field14[2] >> 4;
        group->field0[3].field0[3] = entry->field14[3] >> 4;
        if (incrementFlag != 0) {
            oam_increaseAffineCount(oamList);
        }
    }
    oamCount = oamList->mOamCount;
    oamList->mOamCount += NNS_G2dMakeCellToOams(&oamList->field0[0].field0[oamCount], 0x80 - oamCount, cellData,
                                                matrix, position, groupIndex, entry->field34);
}

void jn_ui_renderElements(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, Unk0201ea30 *labelLayout, void *oamList,
                     LayoutTableEntry *table) {
    s32 i;
    for (i = ((Unk0201ea30 *) cellLayout)->field6 - 1; i >= 0; i--) {
        renderElement(i, cells, cellLayout, labelLayout, oamList, (LayoutTableEntry *) table + i, 1);
    }
}

void jn_ui_renderElementsNoIncrAffine(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, void *labelLayout, void *oamList, void *table) {
    s32 i;
    for (i = ((Unk0201ea30 *) cellLayout)->field6 - 1; i >= 0; i--) {
        renderElement(i, cells, cellLayout, labelLayout, oamList, (LayoutTableEntry *) table + i, 0);
    }
}

#pragma thumb off
