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
void menu_modeSelectStateRender(s32 a) {
    u32 v;
    u32 pairX;
    s32 touchedIndex;
    s32 previousSelected;
    MenuScene *menu;

    if (a != 0) {
        v = menu_input_getDefaultInputId();
        if (func_020cb1f4(v, PAD_KEY_A)) {
            menu_gotoState(3, 0x1f);
            func_020cb1cc(5);
            gMenuSceneState->field934 = TRUE;
        } else if (func_020cb1f4(v, PAD_KEY_B)) {
            menu_gotoState(2, 0x1b);
            RequestSelectReturnState3WithSound(1);
        } else if (mutil_checkKeys(v, PAD_KEY_UP)) {
            menu = gMenuSceneState;
            menu->mSinglePlaySelectModeIndex = (menu->mSinglePlaySelectModeIndex + 4) % 5;
            sfx_2105AC0(0);
        } else if (mutil_checkKeys(v, PAD_KEY_DOWN)) {
            menu = gMenuSceneState;
            menu->mSinglePlaySelectModeIndex = (menu->mSinglePlaySelectModeIndex + 6) % 5;
            sfx_2105AC0(0);
        } else if (func_020cb11c(v)) {
            pairX = func_020cb0f4(v);
            v = func_020cb0cc(v);
            touchedIndex = FindRectContainingPoint(pairX, v, gMenuSceneState->mSinglePlaySelectModeSBnbl);
            menu = gMenuSceneState;
            previousSelected = menu->mSinglePlaySelectModeIndex;
            if (touchedIndex != -1) {
                if (previousSelected == touchedIndex) {
                    menu->field934 = TRUE;
                }
                gMenuSceneState->mSinglePlaySelectModeIndex = touchedIndex;
                menu_gotoState(3, 0x1f);
                func_020cb1cc(5);
            } else if (gmenu_checkSelectReturnTouch(pairX, v)) {
                menu_gotoState(2, 0x1b);
                RequestSelectReturnState3WithSound(1);
            }
        }
    }
    menu_renderModeSelectUI();
}
