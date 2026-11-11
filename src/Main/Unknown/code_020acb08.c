#include "Main/Unknown/code_020acb08.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"

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
