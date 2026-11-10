#include "Main/Unknown/code_02035d18.h"

#include "registers.h"
#include "Main/Unknown/code_02035000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0203606c.h"
#include "Main/Unknown/code_020360e4.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02058efc.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_0205e2cc.h"
#include "00/code_02181f98.h"

void WLMenuSetRaceSetupRequested(u32 value) {
    data_0217b488->mRaceSetupRequested = value;
}

void WLMenuSetMenuEntryKind(u32 value) {
    data_0217b488->mMenuEntryKind = value;
}

#pragma thumb on

s32 AdvanceWLMenuMBChildMessage(u32 sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case 0:
            if (AdvanceSetupByMultiBoot(0, 1) == 1) {
                gWLMenuMessage->mState = 2;
            }
            break;
        case 2:
            result = AdvanceConnectByMultiBoot(0);
            switch (result) {
                case 1:
                    SetMultiSimple(WLMenuIsWMInitializeStarted());
                    gWLMenuMessage->mState = 4;
                    break;
                case 2:
                    break;
            }
            break;
        case 4:
            result = AdvanceMPStateMachineWithOwnIndex();
            switch (result) {
                case 1:
                    if (func_02035e44() != 0) {
                        StopSeqZeroLoopWrapper();
                    }
                    StartCopyOtherEmblems(1);
                    gWLMenuMessage->mState = 6;
                    break;
                case 2:
                    break;
            }
            break;
        case 6:
            if (IsBackupBusy() == 0) {
                WLMenuSetRaceSetupRequested(1);
                WLMenuSetMenuEntryKind(4);
                if (sceneNumbers != 0) {
                    SetNextScene(sceneNumbers, 1);
                }
                gWLMenuMessage->mState = 11;
            }
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

s32 AdvanceWLMenuMessageToRace(u32 sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case 9:
            result = WLMenuToRaceAdvanceMPStateMachineWrapper();
            switch (result) {
                case 1:
                    if (func_02035e44() != 0) {
                        StopSeqZeroLoopWrapper();
                    }
                    gWLMenuMessage->mState = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (sceneNumbers != 0) {
                SetNextScene(sceneNumbers, 2);
            }
            gWLMenuMessage->mState = 11;
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

s32 AdvanceWLMenuMessageToResult(u32 sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case 9:
            result = WLMenuToResultAdvanceMPStateMachineWrapper();
            switch (result) {
                case 1:
                    if (func_02035e44() != 0) {
                        StopSeqZeroLoopWrapper();
                    }
                    gWLMenuMessage->mState = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (sceneNumbers != 0) {
                SetNextScene(sceneNumbers, 10);
            }
            gWLMenuMessage->mState = 11;
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

#pragma thumb off

u32 func_02035e44(void) {
    return gConnectionWork->mUnk_0457 != 0;
}

void StopSeqZeroLoopWrapper(void) {
    u32 value12;
    StopSeqZeroLoop();
}

void SetNextScene(u32 sceneNumbers, u32 nextScene) {
    *OFFSET_PTR(u16, sceneNumbers, 4) = nextScene;
}

#pragma thumb on

s32 AdvanceWLMenuMessageToMenu(u32 sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case 9:
            result = WLMenuToMenuAdvanceMPStateMachineWrapper();
            switch (result) {
                case 1:
                    if (func_02035e44() != 0) {
                        StopSeqZeroLoopWrapper();
                    }
                    gWLMenuMessage->mState = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (sceneNumbers != 0) {
                SetNextScene(sceneNumbers, 1);
            }
            gWLMenuMessage->mState = 11;
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

#pragma thumb off

#pragma thumb on

void ReleaseWLMenuMessage(void) {
    HeapDestroy(gWLMenuMessage->mHeap);
    *&gWLMenuMessage = NULL;
}

#pragma thumb off

void WLMenuMessageGXS_SetVisiblePlane(int bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (bits << 8);
}

void WLMenuMessageG2S_SetBG3Offset(u32 offsetX, int offsetY) {
    reg_G2S_DB_BG3OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x01ff0000);
}

#pragma thumb on

void WriteWLMenuMessageRegisters(void) {
    WLMenuMessageGXS_SetVisiblePlane(10);
    WLMenuMessageG2S_SetBG3Offset(-gWLMenuMessage->mBg3Offset, 0);
}

#pragma thumb off

#pragma thumb on
void WriteWLMenuMessageRegistersWrapper(void) {
    u32 value3;
    WriteWLMenuMessageRegisters();
}
#pragma thumb off
