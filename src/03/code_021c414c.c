#include "03/code_021c414c.h"
#include "03/code_021c41d4.h"
#include "registers.h"
#include "03/code_021c4188.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c4164.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021c3fc8.h"

void SetBgPriorities(void) {
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
}

void StartLinkMessageNextFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateLinkMessageNextFadeIn);
}

void UpdateLinkMessageNextFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        CreateSlideButtonsForMenuPair(5);
        SetUpdateFunction(UpdateLinkMessageNextButtonsIn);
    }
}

void UpdateLinkMessageNextButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateLinkMessageNext);
    }
}

void UpdateLinkMessageNext(void) {
    UpdateLinkMessageNextInput();
    UpdateLinkMessageNextNop();
    UpdateLinkMessageNextResult();
}
