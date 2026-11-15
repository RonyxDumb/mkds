#include "03/Menu/yb5_multi_next_update.h"
#include "03/code_021c34c4.h"
#include "03/unk_021da000.h"
#include "03/Menu/slide_buttons.h"
#include "03/System/application.h"
#include "03/code_021c34ac.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/System/task_input.h"
#include "code_0200fc8c.h"
#include "pm.h"

void UpdateYb5MultiNextButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateYb5MultiNext);
    }
}

void UpdateYb5MultiNext(void) {
    UpdateYb5MultiNextInput();
    UpdateYb5MultiNextNop();
    UpdateYb5MultiNextResult();
}

void UpdateYb5MultiNextInput(void) {
    int allKeysPressed;
    allKeysPressed = AreKeysPressed(1);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateYb5MultiNextNop(void) {}

void UpdateYb5MultiNextResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StartSoundSeq(6);
        SetUpdateFunction(StartYb5MultiNextClose);
    }
}

void StartYb5MultiNextClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateYb5MultiNextFadeOut);
}

void UpdateYb5MultiNextFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartBlendBrightnessFade(3, 1, 0x3f, 0x40);
        StartBlendBrightnessFade(3, 0, 0x3f, 0x40);
        SetUpdateFunction(UpdateYb5MultiNextPowerOff);
    }
}

void UpdateYb5MultiNextPowerOff(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        OS_SpinWait((0x01000000u));
        PM_ForceToPowerOff();
    }
}
