#include "Main/Unknown/code_02120044.h"
#include "Main/Unknown/code_0205b0b4.h"
#include "Main/Unknown/code_0205b0f4.h"

#include "Main/Unknown/code_02120048.h"
#include "Main/Unknown/code_02120054.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0211ff74.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/code_02123000.h"
#include "Main/Unknown/code_021200a4.h"
#include "Main/Unknown/code_021200a8.h"
#include "Main/Unknown/code_02120610.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0205c000.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_021202f0.h"
#include "00/unk_021b5000.h"
#include "00/code_021a2ccc.h"

DWCAccFriendData *func_021202f0(u32 index) {
    return &gWiFiSession->mPlayerRecords[index].mPlayer.mUnk_218;
}

u32 GetPlayerRecordRegion(u32 index) {
    return gWiFiSession->mPlayerRecords[index].mPlayer.mRegion;
}

void *GetPlayerRecordName(u32 index) {
    return &gWiFiSession->mPlayerRecords[index].mPlayer.mName;
}

void *GetPlayerRecordEmblem(u32 index) {
    return &gWiFiSession->mPlayerRecords[index].mPlayer.mEmblem;
}

u8 func_02120278(u32 index) {
    return gWiFiSession->mPlayerRecords[index].mPlayer.mUnk_214;
}

u32 func_0212025c(u32 index) {
    return gWiFiSession->mPlayerRecords[index].mUnk_238;
}

u32 func_02120240(u32 index) {
    return gWiFiSession->mPlayerRecords[index].mUnk_23c;
}

int GetPlayerRecordElo(int index) {
    return gWiFiSession->mPlayerRecords[index].mPlayer.mElo;
}

void SetPlayerRecordElo(int index, s16 elo) {
    gWiFiSession->mPlayerRecords[index].mPlayer.mElo = elo;
}

u8 func_021201e4(int index) {
    return gWiFiSession->mPlayerRecords[index].mPlayer.mUnk_229;
}

void func_02120150(void) {
    WiFiSession *session;
    BOOL hasHeap = FALSE;

    session = gWiFiSession;
    if (session != NULL) {
        if (session->mHeapCreated != FALSE) {
            hasHeap = TRUE;
        }
    }
    if (hasHeap == FALSE) {
        return;
    }
    session->mUnk_1f3c++;
    if (gWiFiSession->mUnk_0008.mState != 5) {
        return;
    }
    if (gWiFiSession->mUnk_1f38 == FALSE) {
        return;
    }
    AdvanceWiFiRaceSyncFrames();
}

void EnterWiFiSessionState1(void) {
    SetupWiFiSessionLogin();
}

void UpdateWiFiSessionState1(void) {
    StateMachine *stateMachine;

    if (UpdateWiFiSessionLogin() == 0) {
        return;
    }
    stateMachine = &gWiFiSession->mUnk_0008;
    stateMachine->mNextState = 2;
    stateMachine->mNextStateRequested = 1;
}

void EnterWiFiSessionState3(void) {
    RegisterKartKeysAndStart();
}

void UpdateWiFiSessionState3(void) {
    StateMachine *stateMachine;

    if (IsKartKeysStartStatus3() == FALSE) {
        return;
    }
    stateMachine = &gWiFiSession->mUnk_0008;
    stateMachine->mNextState = 4;
    stateMachine->mNextStateRequested = 1;
}

void func_021200a4(void) {}

void UpdateWiFiSessionState4(void) {
    UpdateWiFiSessionStep();
}

void EnterWiFiSessionState5(void) {
    WiFiRaceSync *p;

    func_ov000_021a3250(FinishWiFiRaceSyncSend);
    func_ov000_021a323c(func_0211fef4);
    p = gWiFiRaceSync;
    p->mStateMachine.mNextState = 1;
    p->mStateMachine.mNextStateRequested = 1;
}

void UpdateWiFiSessionState5(void) {
    u32 value12;
    func_0205b0b4();
}

void func_02120044(void) {}
