#include "03/Menu/opt_menu_message_next_update.h"
#include "03/code_021c43a4.h"
#include "registers.h"
#include "03/code_021c434c.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/code_021c4328.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/unk_021da000.h"
#include "03/Menu/slide_buttons.h"
#include "03/System/application.h"
#include "03/Menu/opt_menu_message_next.h"

void OptMenuMessageNextSetBgPriorities(void) {
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
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
