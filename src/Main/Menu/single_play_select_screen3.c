#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/rect_containing_point.h"
#include "Main/Menu/is.h"
#include "Main/Menu/menu_sound.h"
#include "Main/Menu/menu_new_bits.h"
#include "Main/Menu/single_play_select_screen1_registers.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Menu/select_return.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_setup.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"

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
            SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_PRESS, SCREEN_NONE);
            StartMenuSound(5);
            gMenuScene->mSinglePlaySelectStartedOnSelected = TRUE;
        } else if (MenuGetNewBits(value, PAD_KEY_B)) {
            SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_SLIDE_OUT, 0x1b);
            RequestSelectReturnPressWithSound(1);
        } else if (GetNewOrRepeatBits(value, PAD_KEY_DIRECTION_UP)) {
            menu = gMenuScene;
            menu->mSinglePlaySelectModeIndex = (menu->mSinglePlaySelectModeIndex + 4) % 5;
            StartSoundOncePerFrame(0);
        } else if (GetNewOrRepeatBits(value, PAD_KEY_DIRECTION_DOWN)) {
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
                SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_PRESS, SCREEN_NONE);
                StartMenuSound(5);
            } else if (IsSelectReturnShownNoRequestAndInRect(pairX, value)) {
                SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_SLIDE_OUT, 0x1b);
                RequestSelectReturnPressWithSound(1);
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
        offset = InterpolateS16(1, 0, SINGLE_PLAY_SELECT_OFFSCREEN_X, frame, 10);
        for (cellIndex = 0; cellIndex <= 14; cellIndex++) {
            subCells[cellIndex].mOffsetX = offset;
        }
    } else {
        mainCells->mOffsetY = -0x28;
        for (cellIndex = 0; cellIndex <= 14; cellIndex++) {
            subCells[cellIndex].mOffsetX = SINGLE_PLAY_SELECT_OFFSCREEN_X;
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
        SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_SLIDE_OUT,
                         nextScreenAndModeTable[gMenuScene->mSinglePlaySelectModeIndex][0]);
        ResetRaceSetupCopy();
        GetRaceSetupCopy()->mMode = nextScreenAndModeTable[gMenuScene->mSinglePlaySelectModeIndex][1];
    }
    DrawSinglePlaySelectCells();
}
#pragma thumb off
