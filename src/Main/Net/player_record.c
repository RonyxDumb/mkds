#include "Main/Net/player_record.h"
#include "Main/Net/wifi_race_sync_advance.h"

#include "Main/Net/wifi_session_login.h"
#include "Main/Net/wifi_race_sync_send.h"
#include "Main/Net/wi_fi_session_step.h"
#include "Main/Net/wifi_session.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/data_transport.h"
#include "Main/Save/ghost_record_file.h"

DWCAccFriendData *GetSomeBTKFriendCode(u32 index) {
    return &g_GlobalB->mPlayerRecords[index].mPlayer.mFriendData;
}

u32 GetMaybeSomeWifiIdx(u32 index) {
    return g_GlobalB->mPlayerRecords[index].mPlayer.mRegion;
}

void *GetSomeBTKNickname(u32 index) {
    return &g_GlobalB->mPlayerRecords[index].mPlayer.mName;
}

void *GetSomeBTKEmblemData(u32 index) {
    return &g_GlobalB->mPlayerRecords[index].mPlayer.mEmblem;
}

u8 GetSomeBTKUseCustomEmblemFlag(u32 index) {
    return g_GlobalB->mPlayerRecords[index].mPlayer.mHasEmblem;
}

u32 GetPlayerRecordFirstTotal(u32 index) {
    return g_GlobalB->mPlayerRecords[index].mFirstTotal;
}

u32 GetPlayerRecordSecondTotal(u32 index) {
    return g_GlobalB->mPlayerRecords[index].mSecondTotal;
}

int GetTKSomeSize(int index) {
    return g_GlobalB->mPlayerRecords[index].mPlayer.mElo;
}

void SetTKSomeSize(int index, s16 elo) {
    g_GlobalB->mPlayerRecords[index].mPlayer.mElo = elo;
}

u8 GetWorstRankStarValue(int index) {
    return g_GlobalB->mPlayerRecords[index].mPlayer.mLowestGrandPrixRecordValue;
}

void DisplayConfig_VblankFnImpl(void) {
    WiFiSession *session;
    BOOL hasHeap = FALSE;

    session = g_GlobalB;
    if (session != NULL) {
        if (session->mHeapCreated != FALSE) {
            hasHeap = TRUE;
        }
    }
    if (hasHeap == FALSE) {
        return;
    }
    session->mIrqCallbackCount++;
    if (g_GlobalB->mStateMachine.mState != WIFI_SESSION_STATE_RACE) {
        return;
    }
    if (g_GlobalB->mRaceSyncEnabled == FALSE) {
        return;
    }
    AdvanceWiFiRaceSyncFrames();
}

void GlobalB_E7Fn_1A(void *stateObject) {
    GlobalB_E7Fn_1AImpl();
}

void GlobalB_E7Fn_1B(void *stateObject) {
    StateMachine *stateMachine;

    if (UpdateWiFiSessionLogin() == 0) {
        return;
    }
    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_IDLE;
    stateMachine->mNextStateRequested = 1;
}

void GlobalB_E7Fn_3A(void *stateObject) {
    GlobalB_E7Fn_3AImpl();
}

void GlobalB_E7Fn_3B(void *stateObject) {
    StateMachine *stateMachine;

    if (IsKartKeysStartStatus3() == FALSE) {
        return;
    }
    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_EXCHANGE;
    stateMachine->mNextStateRequested = 1;
}

void GlobalB_E7Fn_4A(void *stateObject) {}

void GlobalB_E7Fn_4B(void *stateObject) {
    GlobalB_E7Fn_4BImpl();
}

void GlobalB_E7Fn_5A(void *stateObject) {
    WiFiRaceSync *wiFiRaceSync;

    DWC_SetUserSendCallback(FinishWiFiRaceSyncSend);
    DWC_SetUserRecvCallback(WiFiRaceSyncReceiveCallback);
    wiFiRaceSync = g_GlobalAA;
    wiFiRaceSync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_PROBE;
    wiFiRaceSync->mStateMachine.mNextStateRequested = 1;
}

void GlobalB_E7Fn_5B(void *stateObject) {
    u32 unused;
    GlobalB_E7Fn_5BImpl();
}

void GlobalB_E7Fn_6B(void *stateObject) {}
