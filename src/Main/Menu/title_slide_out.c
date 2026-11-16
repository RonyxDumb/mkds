#include "Main/Menu/title_slide_out.h"
#include "Main/Menu/title_menu_input.h"
#include "Main/Menu/title_table_draw.h"
#include "Main/Menu/title_state_set.h"
#include "Main/Menu/title_state_frames.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Save/ghost_record_file.h"

u32 HasPlayerName(void) {
    return g_SaveDataHolder->mFirstBlock->mHasPlayerName != 0;
}

#pragma optimize_for_size on
#pragma thumb on

void UpdateTitleSlideOut(void) {
    u32 subBase;
    s32 entryIndex;
    LayoutTableEntry *titleTable;

    titleTable = g_SceneTitleContext->mTitleTable;
    subBase = TitleGetCellLayoutCount(g_SceneTitleContext->mTitleSBncl);
    if (GetTitleStateFrames() < 10) {
        for (entryIndex = 0; entryIndex <= 14; entryIndex++) {
            titleTable[entryIndex].mOffsetX = ComputeValueInterpolation_from_thumb(1, 0, 0xf8, GetTitleStateFrames(), 10);
        }
        for (entryIndex = 0; entryIndex <= 1; entryIndex++) {
            titleTable[entryIndex + subBase].mOffsetX = ComputeValueInterpolation_from_thumb(1, 0, 0xf8, GetTitleStateFrames(), 10);
        }
    } else {
        for (entryIndex = 0; entryIndex <= 14; entryIndex++) {
            titleTable[entryIndex].mOffsetX = TITLE_OFFSCREEN_X;
        }
        for (entryIndex = 0; entryIndex <= 1; entryIndex++) {
            titleTable[entryIndex + subBase].mOffsetX = TITLE_OFFSCREEN_X;
        }
        if (HasPlayerName() != 0) {
            SetTitleState(g_SceneTitleContext->mNextState, 8);
        } else {
            SetTitleState(TITLE_STATE_REQUEST_NICKNAME_SCENE, 8);
        }
    }
    SetupAndDrawTitleTable();
}

#pragma thumb off
