#include "Main/Unknown/code_020ad028.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void SetupTitleTable(void) {
    LayoutTableEntry *titleTable;
    u32 layoutCount;
    s32 cellIndex;

    titleTable = gTitleScene->mTitleTable;
    layoutCount = TitleGetCellLayoutCount(gTitleScene->mTitleSBncl);
    for (cellIndex = 0; cellIndex <= 9; cellIndex++) {
        titleTable[cellIndex].mVisible = 1;
    }
    for (cellIndex = 10; cellIndex <= 14; cellIndex++) {
        titleTable[cellIndex].mVisible = 0;
    }
    for (cellIndex = 0; cellIndex <= 1; cellIndex++) {
        titleTable[layoutCount + cellIndex].mVisible = 1;
    }
    SetLabelPaletteIndex(0, 15, gTitleScene->mTitleSBnll, titleTable, gTitleScene->mTitleSBncl);
    SetLabelPaletteIndex(1, 15, gTitleScene->mTitleSBnll, titleTable, gTitleScene->mTitleSBncl);
    switch (gTitleScene->mSelectedIndex) {
        case 0:
            if (gTitleScene->mState == 4) {
                titleTable[0].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[5].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[10].mOffsetX = gTitleScene->mSelectedOffset;
            }
            if (gTitleScene->mState != 4 || gTitleScene->mStartedOnSelected == FALSE || GetTitleStateFrames() >= 5) {
                titleTable[5].mVisible = 0;
                titleTable[10].mVisible = 1;
            }
            break;
        case 1:
            if (gTitleScene->mState == 4) {
                titleTable[1].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[6].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[11].mOffsetX = gTitleScene->mSelectedOffset;
            }
            if (gTitleScene->mState != 4 || gTitleScene->mStartedOnSelected == FALSE || GetTitleStateFrames() >= 5) {
                titleTable[6].mVisible = 0;
                titleTable[11].mVisible = 1;
            }
            break;
        case 2:
            if (gTitleScene->mState == 4) {
                titleTable[2].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[7].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[12].mOffsetX = gTitleScene->mSelectedOffset;
            }
            if (gTitleScene->mState != 4 || gTitleScene->mStartedOnSelected == FALSE || GetTitleStateFrames() >= 5) {
                titleTable[7].mVisible = 0;
                titleTable[12].mVisible = 1;
            }
            break;
        case 3:
            if (gTitleScene->mState != 4 || gTitleScene->mStartedOnSelected == FALSE || GetTitleStateFrames() >= 5) {
                titleTable[8].mVisible = 0;
                titleTable[13].mVisible = 1;
                SetLabelPaletteIndex(0, 14, gTitleScene->mTitleSBnll, titleTable, gTitleScene->mTitleSBncl);
            }
            break;
        case 4:
            if (gTitleScene->mState != 4 || gTitleScene->mStartedOnSelected == FALSE || GetTitleStateFrames() >= 5) {
                titleTable[9].mVisible = 0;
                titleTable[14].mVisible = 1;
                SetLabelPaletteIndex(1, 14, gTitleScene->mTitleSBnll, titleTable, gTitleScene->mTitleSBncl);
            }
            break;
    }
}

#pragma thumb off
