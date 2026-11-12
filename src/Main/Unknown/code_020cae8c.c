#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020caf98.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_020cb0cc.h"
#include "Main/Unknown/code_020cb0f4.h"
#include "Main/Unknown/code_020cb11c.h"
#include "Main/Unknown/code_020cb1cc.h"
#include "Main/Unknown/code_020cb1f4.h"
#include "Main/Unknown/code_020cb224.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020caf90.h"
#include "Main/Unknown/code_020cb3e4.h"
#include "Main/Unknown/code_020caf08.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020caf00.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02029890.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0202993c.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateSinglePlaySelectInput(s32 inputEnabled) {
    u32 value;
    u32 pairX;
    s32 touchedIndex;
    s32 previousSelected;
    MenuScene *menu;

    if (inputEnabled != 0) {
        value = GetMenuInputSlot();
        if (MenuGetNewBits(value, PAD_KEY_A)) {
            SwitchMenuScreen(3, 0x1f);
            StartMenuSound(5);
            gMenuScene->mSinglePlaySelectStartedOnSelected = TRUE;
        } else if (MenuGetNewBits(value, PAD_KEY_B)) {
            SwitchMenuScreen(2, 0x1b);
            RequestSelectReturnState3WithSound(1);
        } else if (GetNewOrRepeatBits(value, PAD_KEY_UP)) {
            menu = gMenuScene;
            menu->mSinglePlaySelectModeIndex = (menu->mSinglePlaySelectModeIndex + 4) % 5;
            StartSoundOncePerFrame(0);
        } else if (GetNewOrRepeatBits(value, PAD_KEY_DOWN)) {
            menu = gMenuScene;
            menu->mSinglePlaySelectModeIndex = (menu->mSinglePlaySelectModeIndex + 6) % 5;
            StartSoundOncePerFrame(0);
        } else if (MenuIsSlotPairNew(value)) {
            pairX = MenuGetSlotPairX(value);
            value = MenuGetSlotPairY(value);
            touchedIndex = FindRectContainingPoint(pairX, value, gMenuScene->mSinglePlaySelectModeSBnbl);
            menu = gMenuScene;
            previousSelected = menu->mSinglePlaySelectModeIndex;
            if (touchedIndex != -1) {
                if (previousSelected == touchedIndex) {
                    menu->mSinglePlaySelectStartedOnSelected = TRUE;
                }
                gMenuScene->mSinglePlaySelectModeIndex = touchedIndex;
                SwitchMenuScreen(3, 0x1f);
                StartMenuSound(5);
            } else if (IsSelectReturnState2NoState3Or4RequestAndInRect(pairX, value)) {
                SwitchMenuScreen(2, 0x1b);
                RequestSelectReturnState3WithSound(1);
            }
        }
    }
    DrawSinglePlaySelectCells();
}
#pragma thumb off

#pragma thumb on
void WriteSinglePlaySelect2Registers(void) {
    u32 unusedValue;
    SetupSinglePlaySelectGraphics();
}
#pragma thumb off

#pragma thumb on
#pragma optimize_for_size on
void UpdateSinglePlaySelectMenuScreen2(void) {
    s32 frame;
    LayoutTableEntry *mainCells;
    LayoutTableEntry *subCells;
    s32 cellIndex;
    s16 offset;

    frame = GetFramesSinceMenuScreenSwitch();
    mainCells = gMenuScene->mSinglePlaySelectModeMLayoutTable;
    subCells = gMenuScene->mSinglePlaySelectModeSLayoutTable;
    if (frame < 10) {
        mainCells->mOffsetY = InterpolateS16(1, 0, -0x28, frame, 10);
        offset = InterpolateS16(1, 0, 0xf0, frame, 10);
        for (cellIndex = 0; cellIndex <= 14; cellIndex++) {
            subCells[cellIndex].mOffsetX = offset;
        }
    } else {
        mainCells->mOffsetY = -0x28;
        for (cellIndex = 0; cellIndex <= 14; cellIndex++) {
            subCells[cellIndex].mOffsetX = 0xf0;
        }
        SwitchMenuScreen(GetNextMenuScreenNumber(), 0x1f);
    }
    DrawSinglePlaySelectCells();
}
#pragma thumb off

#pragma thumb on
void WriteSinglePlaySelect3Registers(void) {
    u32 unusedValue;
    SetupSinglePlaySelectGraphics();
}
#pragma thumb off

#pragma thumb on
#pragma optimize_for_size on
void UpdateSinglePlaySelectMenuScreen3(void) {
    s32 nextScreenAndModeTable[5][2] = {{4, 0}, {0x14, 1}, {8, 3}, {0xe, 2}, {0x12, 4}};
    s32 framesSinceSwitch;

    framesSinceSwitch = GetFramesSinceMenuScreenSwitch();
    gMenuScene->mSinglePlaySelectModePressOffset = GetSelectedPressOffset(framesSinceSwitch);
    if (framesSinceSwitch >= 10) {
        SwitchMenuScreen(2, nextScreenAndModeTable[gMenuScene->mSinglePlaySelectModeIndex][0]);
        ResetRaceSetupCopy();
        GetRaceSetupCopy()->mMode = nextScreenAndModeTable[gMenuScene->mSinglePlaySelectModeIndex][1];
    }
    DrawSinglePlaySelectCells();
}
#pragma thumb off
