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

DWCAccFriendData *GetPlayerRecordFriendData(u32 index) {
    return &gWiFiSession->mPlayerRecords[index].mPlayer.mFriendData;
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

u8 HasPlayerRecordEmblem(u32 index) {
    return gWiFiSession->mPlayerRecords[index].mPlayer.mHasEmblem;
}

u32 GetPlayerRecordFirstTotal(u32 index) {
    return gWiFiSession->mPlayerRecords[index].mFirstTotal;
}

u32 GetPlayerRecordSecondTotal(u32 index) {
    return gWiFiSession->mPlayerRecords[index].mSecondTotal;
}

int GetPlayerRecordElo(int index) {
    return gWiFiSession->mPlayerRecords[index].mPlayer.mElo;
}

void SetPlayerRecordElo(int index, s16 elo) {
    gWiFiSession->mPlayerRecords[index].mPlayer.mElo = elo;
}

u8 GetPlayerRecordLowestGrandPrixValue(int index) {
    return gWiFiSession->mPlayerRecords[index].mPlayer.mLowestGrandPrixRecordValue;
}

void AdvanceWiFiSessionOnIrq(void) {
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
    session->mIrqCallbackCount++;
    if (gWiFiSession->mStateMachine.mState != WIFI_SESSION_STATE_RACE) {
        return;
    }
    if (gWiFiSession->mRaceSyncEnabled == FALSE) {
        return;
    }
    AdvanceWiFiRaceSyncFrames();
}

void EnterWiFiSessionLogin(void *stateObject) {
    SetupWiFiSessionLogin();
}

void UpdateWiFiSessionLoginState(void *stateObject) {
    StateMachine *stateMachine;

    if (UpdateWiFiSessionLogin() == 0) {
        return;
    }
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_IDLE;
    stateMachine->mNextStateRequested = 1;
}

void EnterWiFiSessionSearch(void *stateObject) {
    RegisterKartKeysAndStart();
}

void UpdateWiFiSessionSearch(void *stateObject) {
    StateMachine *stateMachine;

    if (IsKartKeysStartStatus3() == FALSE) {
        return;
    }
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_EXCHANGE;
    stateMachine->mNextStateRequested = 1;
}

void EnterWiFiSessionExchangeNop(void *stateObject) {}

void UpdateWiFiSessionExchange(void *stateObject) {
    UpdateWiFiSessionStep();
}

void EnterWiFiSessionRace(void *stateObject) {
    WiFiRaceSync *wiFiRaceSync;

    DWC_SetUserSendCallback(FinishWiFiRaceSyncSend);
    DWC_SetUserRecvCallback(WiFiRaceSyncReceiveCallback);
    wiFiRaceSync = gWiFiRaceSync;
    wiFiRaceSync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_PROBE;
    wiFiRaceSync->mStateMachine.mNextStateRequested = 1;
}

void UpdateWiFiSessionRace(void *stateObject) {
    u32 unused;
    AdvanceWiFiRaceSync();
}

void UpdateWiFiSessionUnusedNop(void *stateObject) {}
