#include "03/code_021c434c.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c4328.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"

void StartOptMenuMessageNextFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateOptMenuMessageNextFadeIn);
}

void UpdateOptMenuMessageNextFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        func_ov003_021bf5c8(4);
        SetUpdateFunction(UpdateOptMenuMessageNextButtonsIn);
    }
}
