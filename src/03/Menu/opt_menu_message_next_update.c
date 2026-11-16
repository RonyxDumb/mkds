#include "03/Menu/opt_menu_message_next_update.h"
#include "03/Menu/opt_menu_message_next_bg_priorities.h"
#include "registers.h"
#include "03/Menu/opt_menu_message_next_fade_in.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/opt_menu_message_next_buttons_in.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/slide_buttons.h"
#include "03/System/application.h"
#include "03/Menu/opt_menu_message_next.h"

void OptMenuMessageNextSetBgPriorities(void) {
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 3;
}

void StartOptMenuMessageNextFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateOptMenuMessageNextFadeIn);
}

void UpdateOptMenuMessageNextFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(4);
        SetUpdateFunction(UpdateOptMenuMessageNextButtonsIn);
    }
}

void UpdateOptMenuMessageNextButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateOptMenuMessageNext);
    }
}

void UpdateOptMenuMessageNext(void) {
    UpdateOptMenuMessageNextInput();
    UpdateOptMenuMessageNextNop();
    UpdateOptMenuMessageNextResult();
}
