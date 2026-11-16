#include "Main/Unknown/code_0212030c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020467d0.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0211ffb0.h"
#include "Main/Unknown/code_02120610.h"
#include "00/code_0219b580.h"
#include "00/code_021a3264.h"
#include "00/code_021a3758.h"
#include "00/unk_021b5000.h"
#include "00/code_021a369c.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02120044.h"
#include "Main/Unknown/code_02120048.h"
#include "Main/Unknown/code_02120054.h"
#include "Main/Unknown/code_021200a4.h"
#include "Main/Unknown/code_021200a8.h"
#include "00/code_0219daa8.h"
#include "00/code_0219c384.h"
#include "00/code_0219b000.h"
#include "00/code_021a3000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_020176c0.h"

UnkFunc *data_0216e21c[14] = {
    0,
    0,
    EnterWiFiSessionState1,
    UpdateWiFiSessionState1,
    0,
    0,
    EnterWiFiSessionState3,
    UpdateWiFiSessionState3,
    func_021200a4,
    UpdateWiFiSessionState4,
    EnterWiFiSessionState5,
    UpdateWiFiSessionState5,
    0,
    func_02120044,
};

u32 func_021205e8(void) {
    return func_ov000_021a3758();
}

#pragma thumb on
void InitWiFiSession(void *heap) {
    StateMachine *stateMachine;

    gStruct217D384 = heap_allocEx(heap, 0x1f58, 0x20);
    sm_init(&gStruct217D384->mUnk_0008, data_0216e21c, 8, NULL);
    stateMachine = &gStruct217D384->mUnk_0008;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}

// Creates the 0x3e800-byte exp heap and registers WiFiSessionHeapAlloc / Free with the net layer (the heap is used only
// through them).
void CreateWiFiSessionHeap(void *heap) {
    gStruct217D384->mHeapBuffer = heap_allocEx(heap, 0x3e800, 0x20);
    gStruct217D384->mHeap = NNS_FndCreateExpHeapEx(gStruct217D384->mHeapBuffer, 0x3e800, 1);
    gStruct217D384->mHeapCreated = TRUE;
    func_ov000_021a3744(WiFiSessionHeapAlloc, WiFiSessionHeapFree);
}

// Destroys the heap and frees its buffer (mHeap is left set), clears mHeapCreated and requests state 0.
void DeleteWiFiSessionHeap(void) {
    StateMachine *stateMachine;

    if (gStruct217D384->mHeap != NULL) {
        NNS_FndDestroyExpHeap(gStruct217D384->mHeap);
        heap_free(proc_getHeap(proc_getCurrent()), gStruct217D384->mHeapBuffer);
    }
    gStruct217D384->mHeapCreated = FALSE;
    stateMachine = &gStruct217D384->mUnk_0008;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}
#pragma thumb off

void func_021204d0(void) {
    StateMachine *stateMachine;

    ResetWiFiSession();
    gStruct217D384->mUnk_1f34 = TRUE;
    stateMachine = &gStruct217D384->mUnk_0008;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}

// Polls one buddy entry's status per call and counts the entries with status 4 into mStatus4BuddyCount.
void UpdateBuddyStatuses(void) {
    u8 status4Count = 0;
    WiFiSession *session;
    WiFiSession *countSession;
    u8 i;

    if (gStruct217D384->mBuddyPollIndex >= 0x3c) {
        gStruct217D384->mBuddyPollIndex = 0;
    }
    session = gStruct217D384;
    session->mBuddyStatuses[session->mBuddyPollIndex] =
        func_ov000_0219daa8(&session->mBuddies[session->mBuddyPollIndex], NULL);
    gStruct217D384->mBuddyPollIndex++;
    countSession = gStruct217D384;
    i = 0;
    do {
        switch (countSession->mBuddyStatuses[i]) {
            case 2:
                break;
            case 4:
                status4Count++;
                break;
        }
        i++;
    } while (i < 0x3c);
    countSession->mStatus4BuddyCount = status4Count;
}

void UpdateWiFiSession(void) {
    if (gStruct217D384 == NULL) {
        return;
    }
    if (gOverlayData->mCurrentOverlay != 0) {
        return;
    }
    UpdateWiFiConnection();
    if (func_ov000_0219c3cc(NULL) != 0) {
        gStruct217D384->mUnk_1f44 = func_ov000_0219c3cc(&gStruct217D384->mUnk_1f48);
        func_ov000_0219c3b0();
    }
    if (gStruct217D384->mUnk_0008.mState != 0) {
        UpdateBuddyStatuses();
    }
    sm_execute(&gStruct217D384->mUnk_0008);
}

s32 func_02120340(u32 a, void *b, s32 c, u32 (*d)(void)) {
    return func_ov000_021a32a0(a, b, c);
}

// Returns the name+emblem part of the index's record, or NULL if the index is not in mKartMask.
void *GetWiFiSessionPlayerRecordData(u32 index) {
    WiFiSession *session = gStruct217D384;

    if (session->mKartMask & (1 << index)) {
        return &session->mPlayerRecords[index].mName;
    }
    return NULL;
}
