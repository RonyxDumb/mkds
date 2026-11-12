#include "03/Menu/opt_menu_message_next.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/code_021c4188.h"
#include "03/code_021c41d4.h"
#include "03/Menu/child_wait.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/task_input.h"

void UpdateOptMenuMessageNextInput(void) {
    int allKeysPressed;
    allKeysPressed = AreKeysPressed(1);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void UpdateOptMenuMessageNextNop(void) {}

void UpdateOptMenuMessageNextResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StartSoundSeq(6);
        SetUpdateFunction(StartOptMenuMessageNextClose);
    }
}

void StartOptMenuMessageNextClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateOptMenuMessageNextFadeOut);
}

void UpdateOptMenuMessageNextFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateOptMenuMessageNextRelease);
    }
}

void UpdateOptMenuMessageNextRelease(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if ((v1 == 0) && (v1 = IsSlideButtonsNotSlidingOut(), v1 != 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        ClearDispcntBits(0, 0x15);
        SetPrimaryMenuPair(0, 1);
        SetUpdateFunction(SetupChildWait);
    }
}

void SetupLinkMessageNext(void) {
    SetBgPriorities();
    PrintMessage(0x61);
    SetUpdateFunction(StartLinkMessageNextFadeIn);
}
