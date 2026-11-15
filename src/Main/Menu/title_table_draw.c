#include "Main/Menu/title_table_draw.h"
#include "Main/Menu/title_state2.h"
#include "Main/Menu/title_state_frames.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Menu/title_state0.h"
#include "Main/Graphics/layout_table_entry.h"

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
            if (gTitleScene->mState == TITLE_STATE_SELECT_PRESS) {
                titleTable[0].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[5].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[10].mOffsetX = gTitleScene->mSelectedOffset;
            }
            if (gTitleScene->mState != TITLE_STATE_SELECT_PRESS || gTitleScene->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[5].mVisible = 0;
                titleTable[10].mVisible = 1;
            }
            break;
        case 1:
            if (gTitleScene->mState == TITLE_STATE_SELECT_PRESS) {
                titleTable[1].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[6].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[11].mOffsetX = gTitleScene->mSelectedOffset;
            }
            if (gTitleScene->mState != TITLE_STATE_SELECT_PRESS || gTitleScene->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[6].mVisible = 0;
                titleTable[11].mVisible = 1;
            }
            break;
        case 2:
            if (gTitleScene->mState == TITLE_STATE_SELECT_PRESS) {
                titleTable[2].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[7].mOffsetX = gTitleScene->mSelectedOffset;
                titleTable[12].mOffsetX = gTitleScene->mSelectedOffset;
            }
            if (gTitleScene->mState != TITLE_STATE_SELECT_PRESS || gTitleScene->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[7].mVisible = 0;
                titleTable[12].mVisible = 1;
            }
            break;
        case 3:
            if (gTitleScene->mState != TITLE_STATE_SELECT_PRESS || gTitleScene->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[8].mVisible = 0;
                titleTable[13].mVisible = 1;
                SetLabelPaletteIndex(0, 14, gTitleScene->mTitleSBnll, titleTable, gTitleScene->mTitleSBncl);
            }
            break;
        case 4:
            if (gTitleScene->mState != TITLE_STATE_SELECT_PRESS || gTitleScene->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[9].mVisible = 0;
                titleTable[14].mVisible = 1;
                SetLabelPaletteIndex(1, 14, gTitleScene->mTitleSBnll, titleTable, gTitleScene->mTitleSBncl);
            }
            break;
    }
}

#pragma thumb off

#pragma thumb on

void SetupAndDrawTitleTable(void) {
    TitleScene *titleScene;
    SetupTitleTable();
    titleScene = gTitleScene;
    DrawLayoutTable(titleScene->mTitleSBncl, titleScene->mTitleSNceNcer, titleScene->mTitleSBnll, &titleScene->mSubOam,
                    titleScene->mTitleTable);
}

#pragma thumb off

#pragma thumb on
u32 TitleSlideInReturnArgumentWrapper(u32 value) {
    return TitleReturnArgument(value);
}
#pragma thumb off
