#include "Main/Menu/title_state1.h"
#include "Main/Menu/title_state2.h"
#include "Main/Menu/title_table_draw.h"
#include "Main/Menu/title_state_set.h"
#include "Main/Menu/title_state_frames.h"
#include "Main/Graphics/oam.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Menu/title_state3.h"

#pragma optimize_for_size on
#pragma thumb on

void UpdateTitleSlideIn(void) {
    u32 subBase;
    s32 entryIndex;
    LayoutTableEntry *titleTable;

    titleTable = gTitleScene->mTitleTable;
    subBase = TitleGetCellLayoutCount(gTitleScene->mTitleSBncl);
    if (GetTitleStateFrames() < 10) {
        for (entryIndex = 0; entryIndex <= 14; entryIndex++) {
            titleTable[entryIndex].mOffsetX = InterpolateS16(1, 0xf8, 0, GetTitleStateFrames(), 10);
        }
        for (entryIndex = 0; entryIndex <= 1; entryIndex++) {
            titleTable[entryIndex + subBase].mOffsetX = InterpolateS16(1, 0xe4, 0, GetTitleStateFrames(), 10);
        }
    } else {
        for (entryIndex = 0; entryIndex <= 14; entryIndex++) {
            titleTable[entryIndex].mOffsetX = 0;
        }
        for (entryIndex = 0; entryIndex <= 1; entryIndex++) {
            titleTable[entryIndex + subBase].mOffsetX = 0;
        }
        SetTitleState(TITLE_STATE_MENU_INPUT, 8);
        gTitleScene->mStartedOnSelected = FALSE;
    }
    SetupAndDrawTitleTable();
}

void StartTitleSelectedSound(void) {
    switch (gTitleScene->mSelectedIndex) {
        case TITLE_ENTRY_FIRST:
        case TITLE_ENTRY_WL_MENU:
        case TITLE_ENTRY_WIFI_MENU:
            StartSoundOncePerFrame(9);
            break;
        case TITLE_ENTRY_OPTION:
        case TITLE_ENTRY_RECORD:
            StartSoundOncePerFrame(8);
            break;
        default:
            break;
    }
}

#pragma thumb off
