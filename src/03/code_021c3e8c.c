#include "03/code_021c3e8c.h"
#include "03/code_021c3fa0.h"
#include "03/code_021c209c.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "03/code_021c25e0.h"
#include "03/code_021d1f70.h"
#include "03/code_021bf8c0.h"
#include "03/code_021c4220.h"
#include "03/code_021c46a8.h"
#include "03/code_021c482c.h"
#include "03/code_021cd2e0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"

void UpdateLinkMessageFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(0) == 0) {
        SetChildWaitCallback(LinkMessageResultCallback);
        SetUpdateFunction(UpdateLinkMessage);
    }
}

void UpdateLinkMessage(void) {
    UpdateLinkMessageInputNop();
    UpdateLinkMessageNop();
}

void UpdateLinkMessageInputNop(void) {}

void UpdateLinkMessageNop(void) {}

void StartLinkMessageFadeOut(void) {
    StartBlendBrightnessFade(3, 0, 0x15, 8);
    SetUpdateFunction(UpdateLinkMessageRelease);
}

void UpdateLinkMessageRelease(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if ((v1 == 0) && (v1 = IsChildWaitSessionReleased(), v1 != 0)) {
        ReleaseLinkLevel();
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        ClearDispcntBits(0, 0x15);
        SetPrimaryMenuPair(0, 1);
        if ((*(u8 *) &gLinkMessageResult) == 0) {
            SetUpdateFunction(SetupChildWaitMessage);
            return;
        }
        if ((*(u8 *) &gLinkMessageResult) == 2) {
            SetUpdateFunction(SetupTimedMessage);
            return;
        }
        SetUpdateFunction(SetupLinkMessageNext);
    }
}

void LinkMessageResultCallback(int a) {
    if (a == 2) {
        ResetApEntries();
        *(u8 *) &gLinkMessageResult = 1;
        StopSoundSeq();
        StartSoundSeq(0x10);
    } else if (a == 3) {
        *(u8 *) &gLinkMessageResult = 2;
        StopSoundSeq();
        StartSoundSeq(0x12);
    } else {
        *(u8 *) &gLinkMessageResult = 0;
        StopSoundSeq();
        StartSoundSeq(0x12);
    }
    SetChildWaitCallback(NULL);
    StartChildWaitStop();
    SetUpdateFunction(StartLinkMessageFadeOut);
}
