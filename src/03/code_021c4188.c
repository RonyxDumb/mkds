#include "03/code_021c4188.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c4164.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"

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
