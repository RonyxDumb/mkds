#include "Main/Menu/title_state3.h"
#include "Main/Menu/title_state2.h"
#include "Main/Menu/title_table_draw.h"
#include "Main/Menu/title_state_set.h"
#include "Main/Menu/title_state_frames.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/MapObjects/data_0217b000.h"

u32 HasPlayerName(void) {
    return gBackupBuffers->mFirstBlock->mHasPlayerName != 0;
}

#pragma optimize_for_size on
#pragma thumb on

void UpdateTitleState3(void) {
    u32 subBase;
    s32 entryIndex;
    LayoutTableEntry *titleTable;

    titleTable = gTitleScene->mTitleTable;
    subBase = TitleGetCellLayoutCount(gTitleScene->mTitleSBncl);
    if (GetTitleStateFrames() < 10) {
        for (entryIndex = 0; entryIndex <= 14; entryIndex++) {
            titleTable[entryIndex].mOffsetX = InterpolateS16(1, 0, 0xf8, GetTitleStateFrames(), 10);
        }
        for (entryIndex = 0; entryIndex <= 1; entryIndex++) {
            titleTable[entryIndex + subBase].mOffsetX = InterpolateS16(1, 0, 0xf8, GetTitleStateFrames(), 10);
        }
    } else {
        for (entryIndex = 0; entryIndex <= 14; entryIndex++) {
            titleTable[entryIndex].mOffsetX = 0xf8;
        }
        for (entryIndex = 0; entryIndex <= 1; entryIndex++) {
            titleTable[entryIndex + subBase].mOffsetX = 0xf8;
        }
        if (HasPlayerName() != 0) {
            SetTitleState(gTitleScene->mNextState, 8);
        } else {
            SetTitleState(6, 8);
        }
    }
    SetupAndDrawTitleTable();
}

#pragma thumb off
