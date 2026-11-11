#include "Main/Unknown/code_020caf98.h"
#include "Main/Unknown/code_020cae8c.h"
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
