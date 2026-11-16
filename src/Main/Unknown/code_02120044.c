#include "Main/Unknown/code_02120044.h"
#include "Main/Unknown/code_0205b0b4.h"
#include "Main/Unknown/code_0205b0f4.h"

#include "Main/Unknown/code_02120048.h"
#include "Main/Unknown/code_02120054.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0211ff74.h"
#include "Main/Net/WiFiSession.h"
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

u32 GetSomeBTKFriendCode(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    value2 = (u32) &gStruct217D384;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value2 = (value2) + (0x440u);
    value0 = (value1) * (value0) + (value2);
    return value0;
}

u32 GetPlayerRecordRegion(u32 index) {
    return gStruct217D384->mPlayerRecords[index].mRegion;
}

void *GetPlayerRecordName(u32 index) {
    return &gStruct217D384->mPlayerRecords[index].mName;
}

void *GetPlayerRecordEmblem(u32 index) {
    return &gStruct217D384->mPlayerRecords[index].mEmblem;
}

u8 GetSomeBTKUseCustomEmblemFlag(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    value2 = (u32) &gStruct217D384;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u8 *) ((value1) + (1084));
    return value0;
}

u32 func_0212025c(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    value2 = (u32) &gStruct217D384;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (1108));
    return value0;
}

u32 func_02120240(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    value2 = (u32) &gStruct217D384;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (1112));
    return value0;
}

int GetPlayerRecordElo(int index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    value2 = (u32) &gStruct217D384;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0x400u);
    value0 = *(const s16 *) ((value0) + (62));
    return value0;
}

void SetPlayerRecordElo(int index, s16 elo) {
    u32 value0 = index;
    u32 value1 = elo;
    u32 value2;
    u32 value3;
    value3 = (u32) &gStruct217D384;
    value2 = 0x244u;
    value3 = *(const u32 *) ((value3) + (0));
    value2 = (value0) * (value2) + (value3);
    value0 = (value2) + (0x400u);
    *(u16 *) ((value0) + (62)) = value1;
}

u8 GetWorstRankStarValue(int index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    value2 = (u32) &gStruct217D384;
    value1 = 0x244u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u8 *) ((value1) + (1105));
    return value0;
}

void DisplayConfig_VblankFnImpl(void) {
    WiFiSession *session;
    BOOL hasHeap = FALSE;

    session = gStruct217D384;
    if (session != NULL) {
        if (session->mHeapCreated != FALSE) {
            hasHeap = TRUE;
        }
    }
    if (hasHeap == FALSE) {
        return;
    }
    session->field1F3C++;
    if (gStruct217D384->field8.mState != 5) {
        return;
    }
    if (gStruct217D384->field1F38 == FALSE) {
        return;
    }
    sub_205CCEC();
}

void EnterWiFiSessionState1(void) {
    SetupWiFiSessionLogin();
}

void UpdateWiFiSessionState1(void) {
    StateMachine *stateMachine;

    if (UpdateWiFiSessionLogin() == 0) {
        return;
    }
    stateMachine = &gStruct217D384->field8;
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
    stateMachine = &gStruct217D384->field8;
    stateMachine->mNextState = 4;
    stateMachine->mNextStateRequested = 1;
}

void GlobalB_E7Fn_4A(void) {}

void UpdateWiFiSessionState4(void) {
    UpdateWiFiSessionStep();
}

void EnterWiFiSessionState5(void) {
    Unk0217aa14 *p;

    func_ov000_021a3250(func_0211ff74);
    func_ov000_021a323c(func_0211fef4);
    p = gStruct217AA14;
    p->field10 = 1;
    p->field12 = 1;
}

void UpdateWiFiSessionState5(void) {
    u32 value12;
    GlobalB_E7Fn_5BImpl();
}

void GlobalB_E7Fn_6B(void) {}
