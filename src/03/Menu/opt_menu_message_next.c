#include "03/Menu/opt_menu_message_next.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/link_message_next_fade_in.h"
#include "03/Menu/link_message_next_bg_priorities.h"
#include "03/Menu/child_wait.h"
#include "03/Sound/sound_seq.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/task_input.h"

void UpdateOptMenuMessageNextInput(void) {
    int allKeysPressed;
    allKeysPressed = AreKeysPressed(1);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone(0);
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
    int checkResult;
    checkResult = IsBlendBrightnessFadeSlotBusy(0);
    if ((checkResult == 0) && (checkResult = IsSlideButtonsNotSlidingOut(), checkResult != 0)) {
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
