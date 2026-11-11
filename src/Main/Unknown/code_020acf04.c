#include "Main/Unknown/code_020acf04.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020acb08.h"

#pragma optimize_for_size on
#pragma thumb on

void UpdateTitleState1(void) {
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
        SetTitleState(2, 8);
        gTitleScene->mStartedOnSelected = FALSE;
    }
    SetupAndDrawTitleTable();
}

void StartTitleSelectedSound(void) {
    switch (gTitleScene->mSelectedIndex) {
        case 0:
        case 1:
        case 2:
            StartSoundOncePerFrame(9);
            break;
        case 3:
        case 4:
            StartSoundOncePerFrame(8);
            break;
        default:
            break;
    }
}

#pragma thumb off
