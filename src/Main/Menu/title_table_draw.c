#include "Main/Menu/title_table_draw.h"
#include "Main/Menu/title_menu_input.h"
#include "Main/Menu/title_state_frames.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Menu/title_blend_in.h"
#include "Main/Graphics/layout_table_entry.h"

#pragma optimize_for_size on
#pragma thumb on

void SetupTitleTable(void) {
    LayoutTableEntry *titleTable;
    u32 layoutCount;
    s32 cellIndex;

    titleTable = g_SceneTitleContext->mTitleTable;
    layoutCount = TitleGetCellLayoutCount(g_SceneTitleContext->mTitleSBncl);
    for (cellIndex = 0; cellIndex <= 9; cellIndex++) {
        titleTable[cellIndex].mVisible = 1;
    }
    for (cellIndex = 10; cellIndex <= 14; cellIndex++) {
        titleTable[cellIndex].mVisible = 0;
    }
    for (cellIndex = 0; cellIndex <= 1; cellIndex++) {
        titleTable[layoutCount + cellIndex].mVisible = 1;
    }
    SetLabelPaletteIndex(0, 15, g_SceneTitleContext->mTitleSBnll, titleTable, g_SceneTitleContext->mTitleSBncl);
    SetLabelPaletteIndex(1, 15, g_SceneTitleContext->mTitleSBnll, titleTable, g_SceneTitleContext->mTitleSBncl);
    switch (g_SceneTitleContext->mSelectedIndex) {
        case TITLE_ENTRY_FIRST:
            if (g_SceneTitleContext->mState == TITLE_STATE_SELECT_PRESS) {
                titleTable[0].mOffsetX = g_SceneTitleContext->mSelectedOffset;
                titleTable[5].mOffsetX = g_SceneTitleContext->mSelectedOffset;
                titleTable[10].mOffsetX = g_SceneTitleContext->mSelectedOffset;
            }
            if (g_SceneTitleContext->mState != TITLE_STATE_SELECT_PRESS || g_SceneTitleContext->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[5].mVisible = 0;
                titleTable[10].mVisible = 1;
            }
            break;
        case TITLE_ENTRY_WL_MENU:
            if (g_SceneTitleContext->mState == TITLE_STATE_SELECT_PRESS) {
                titleTable[1].mOffsetX = g_SceneTitleContext->mSelectedOffset;
                titleTable[6].mOffsetX = g_SceneTitleContext->mSelectedOffset;
                titleTable[11].mOffsetX = g_SceneTitleContext->mSelectedOffset;
            }
            if (g_SceneTitleContext->mState != TITLE_STATE_SELECT_PRESS || g_SceneTitleContext->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[6].mVisible = 0;
                titleTable[11].mVisible = 1;
            }
            break;
        case TITLE_ENTRY_WIFI_MENU:
            if (g_SceneTitleContext->mState == TITLE_STATE_SELECT_PRESS) {
                titleTable[2].mOffsetX = g_SceneTitleContext->mSelectedOffset;
                titleTable[7].mOffsetX = g_SceneTitleContext->mSelectedOffset;
                titleTable[12].mOffsetX = g_SceneTitleContext->mSelectedOffset;
            }
            if (g_SceneTitleContext->mState != TITLE_STATE_SELECT_PRESS || g_SceneTitleContext->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[7].mVisible = 0;
                titleTable[12].mVisible = 1;
            }
            break;
        case TITLE_ENTRY_OPTION:
            if (g_SceneTitleContext->mState != TITLE_STATE_SELECT_PRESS || g_SceneTitleContext->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[8].mVisible = 0;
                titleTable[13].mVisible = 1;
                SetLabelPaletteIndex(0, 14, g_SceneTitleContext->mTitleSBnll, titleTable, g_SceneTitleContext->mTitleSBncl);
            }
            break;
        case TITLE_ENTRY_RECORD:
            if (g_SceneTitleContext->mState != TITLE_STATE_SELECT_PRESS || g_SceneTitleContext->mStartedOnSelected == FALSE ||
                GetTitleStateFrames() >= 5) {
                titleTable[9].mVisible = 0;
                titleTable[14].mVisible = 1;
                SetLabelPaletteIndex(1, 14, g_SceneTitleContext->mTitleSBnll, titleTable, g_SceneTitleContext->mTitleSBncl);
            }
            break;
    }
}

#pragma thumb off

#pragma thumb on

void SetupAndDrawTitleTable(void) {
    TitleScene *titleScene;
    SetupTitleTable();
    titleScene = g_SceneTitleContext;
    DrawLayoutTable(titleScene->mTitleSBncl, titleScene->mTitleSNceNcer, titleScene->mTitleSBnll, &titleScene->mSubOam,
                    titleScene->mTitleTable);
}

#pragma thumb off

#pragma thumb on
u32 TitleSlideInReturnArgumentWrapper(u32 value) {
    return TitleReturnArgument(value);
}
#pragma thumb off
