#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02056464.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02123000.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2950.h"
#include "00/code_021a2cac.h"
#include "00/code_021a2ccc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02029890.h"
#include "code_02134398.h"
#include "code_0214d018.h"

#pragma opt_arithtransformation off

// Own answer on the battle results screen: nonzero is CONTINUE (stored 1), zero is QUIT (stored 2).
void SetWiFiSessionOwnContinueChoice(u32 wantsContinue) {
    gWiFiSession->mIndexMessages[GetOwnParticipantIndex()].mContinueChoice = wantsContinue != 0 ? 1 : 2;
}

s32 GetWiFiSessionCourseId(void) {
    if (GetRaceSetupCopy()->mCourseId == 0) {
        return gWiFiSession->mIndexMessages[GetOwnParticipantIndex()].mPickedCourseId;
    }
    return GetRaceSetupCopy()->mCourseId;
}

BOOL IsWiFiStep5ReachedNoDisconnect(void) {
    if (gWiFiSession->mStep >= 5) {
        if (CheckWiFiSessionDisconnect() == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL IsWiFiSessionStep7Reached(void) {
    BOOL result = TRUE;
    WiFiSession *session = gWiFiSession;
    s32 step = session->mStep;

    if (step < 7) {
        if (session->mUnk_19ad != 1 || step != 0xc) {
            result = FALSE;
        }
    }
    return result;
}

BOOL IsWiFiSessionStep10Reached(void) {
    BOOL result = TRUE;
    WiFiSession *session = gWiFiSession;
    s32 step = session->mStep;

    if (step < 10) {
        if (session->mUnk_19ad != 1 || step != 0xc) {
            result = FALSE;
        }
    }
    return result;
}

// Result of the CONTINUE/QUIT answers: 0 not settled, 1 more than one kart is left, 2 one kart left or the run ended.
s32 GetWiFiSessionContinueResult(void) {
    s32 step;

    step = gWiFiSession->mStep;
    if (step >= 5) {
        if (gWiFiSession->mKartCount > 1) {
            return 1;
        }
        return 2;
    }
    if (gWiFiSession->mUnk_19ad == 1) {
        if (step == 0xc) {
            return 2;
        }
    }
    if (step == 0xc) {
        return 2;
    }
    return 0;
}

// Counts the course picks of the indices in mKartMask and stores the most picked in the race setup's mCourseId; ties
// are settled with the object's own LCG (mRandom).
void TallyPickedCourse(void) {
    u8 i;
    u8 highestCount = 0;
    u8 tiedCount = 0;
    u32 tiedCourses[4] = {0, 0, 0, 0};
    u8 pickCounts[0x37] = {0};
    u8 j;
    WiFiSession *session;
    RandomState64 *randomState;
    u32 tieIndex;
    u32 talliedCourseId;

    session = gWiFiSession;
    for (i = 0; i < session->mStartKartCount; i++) {
        if (session->mKartMask & (1 << i)) {
            pickCounts[session->mIndexMessages[i].mPickedCourseId]++;
            if (highestCount < pickCounts[session->mIndexMessages[i].mPickedCourseId]) {
                highestCount = pickCounts[session->mIndexMessages[i].mPickedCourseId];
            }
        }
    }
    for (j = 0; j < 0x37; j++) {
        if (highestCount == pickCounts[j]) {
            tiedCourses[tiedCount++] = j;
        }
    }
    randomState = &session->mRandom;
    if (tiedCount == 0) {
        tieIndex = 0;
    } else {
        randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
        if (tiedCount == 0) {
            tieIndex = randomState->mValue >> 32;
        } else {
            tieIndex = ((randomState->mValue >> 32) * (u32) tiedCount) >> 32;
        }
    }
    talliedCourseId = tiedCourses[(u16) tieIndex];
    GetRaceSetupCopy()->mCourseId = talliedCourseId;
}

void WriteWiFiSessionToRaceSetupCopy(void) {
    BOOL ownKind = FALSE;
    u8 i;

    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if (gWiFiSession->mKartMask & (1 << i)) {
            if (i == GetOwnParticipantIndex()) {
                s8 entryIndex;

                entryIndex = gWiFiSession->mPackedIndices[i];
                GetRaceSetupCopy()->mEntries[entryIndex].mPlayerKind = ownKind;
            } else {
                s8 entryIndex;

                entryIndex = gWiFiSession->mPackedIndices[i];
                GetRaceSetupCopy()->mEntries[entryIndex].mPlayerKind = PLAYER_KIND_PEER;
            }
            {
                WiFiSession *wiFiSession;
                s8 entryIndex;

                wiFiSession = gWiFiSession;
                entryIndex = wiFiSession->mPackedIndices[i];
                GetRaceSetupCopy()->mEntries[entryIndex].mCharacterIndex =
                    wiFiSession->mIndexMessages[i].mCharacterIndex;
            }
            {
                WiFiSession *wiFiSession;
                s8 entryIndex;

                wiFiSession = gWiFiSession;
                entryIndex = wiFiSession->mPackedIndices[i];
                GetRaceSetupCopy()->mEntries[entryIndex].mKartIndex = wiFiSession->mIndexMessages[i].mKartIndex;
            }
        }
    }
}

BOOL DoesMessageHeaderMatch(WiFiSessionMessageHeader *header, u32 size, u32 fromIndex, u32 toIndex) {
    if (header->mKind < 10) {
        if (header->mSize == size) {
            if (header->mFromIndex == fromIndex) {
                if (header->mToIndex == toIndex) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

BOOL IsWiFiSessionMessageKindAllowed(u32 kind) {
    switch (kind) {
        case 0:
            if (gWiFiSession->mStep == 0 || gWiFiSession->mStep == 1) {
                return TRUE;
            }
            break;
        case 1:
            if (gWiFiSession->mStep == 0) {
                return TRUE;
            }
            break;
        case 2:
            if (gWiFiSession->mStep == 0 || gWiFiSession->mStep == 1) {
                return TRUE;
            }
            break;
        case 8:
            if ((u32) (gWiFiSession->mStep - 3) <= 1) {
                return TRUE;
            }
            break;
        case 9:
            if ((u32) (gWiFiSession->mStep - 3) <= 2) {
                return TRUE;
            }
            break;
        case 3:
            if (gWiFiSession->mStep == 1 || (u32) (gWiFiSession->mStep - 4) <= 2) {
                return TRUE;
            }
            break;
        case 4:
            if ((u32) (gWiFiSession->mStep - 5) <= 1) {
                return TRUE;
            }
            break;
        case 5:
            if ((u32) (gWiFiSession->mStep - 6) <= 1) {
                return TRUE;
            }
            break;
        case 6:
            if ((u32) (gWiFiSession->mStep - 7) <= 1) {
                return TRUE;
            }
            break;
        case 7:
            if ((u32) (gWiFiSession->mStep - 8) <= 1) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

// Index the next message goes to; mStartKartCount means none (the two calls after a pick, or no index left).
u8 PickNextToIndex(void) {
    u8 i;
    u8 callCount;

    callCount = gWiFiSession->mCallsSincePick;
    if (callCount < 2) {
        gWiFiSession->mCallsSincePick = callCount + 1;
        return gWiFiSession->mStartKartCount;
    }
    for (i = gWiFiSession->mPickStartIndex; i < gWiFiSession->mStartKartCount; i++) {
        if (i != GetOwnParticipantIndex()) {
            if (gWiFiSession->mKartMask & (1 << i)) {
                break;
            }
        }
    }
    if (gWiFiSession->mPickStartIndex >= gWiFiSession->mStartKartCount) {
        for (i = 0; i < gWiFiSession->mPickStartIndex; i++) {
            if (i != GetOwnParticipantIndex()) {
                if (gWiFiSession->mKartMask & (1 << i)) {
                    break;
                }
            }
        }
        if (i >= gWiFiSession->mPickStartIndex) {
            return gWiFiSession->mStartKartCount;
        }
    }
    gWiFiSession->mPickStartIndex = i + 1;
    gWiFiSession->mCallsSincePick = 0;
    return i;
}

// TRUE once every other counted index has sent the message of this step; with no other index left it ends the run.
BOOL AreAllStepMessagesReceived(void) {
    u8 i;
    u8 receivedCount = 0;
    u8 checkedCount = 0;
    u8 startKartCount;
    u8 j;
    u8 rosterCount;
    u8 kartMask;

    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if (i != GetOwnParticipantIndex()) {
            if (gWiFiSession->mKartMask & (1 << i)) {
                checkedCount++;
                if ((gWiFiSession->mReceivedMask & (1 << i)) == 0) {
                    break;
                }
                receivedCount++;
            }
        }
    }
    if (checkedCount == 0) {
        gWiFiSession->mUnk_19ad = 1;
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        gWiFiSession->mStep = 0xb;
        return FALSE;
    }
    rosterCount = 0;
    startKartCount = gWiFiSession->mStartKartCount;
    kartMask = gWiFiSession->mKartMask;
    for (j = 0; j < startKartCount; j++) {
        if (kartMask & (1 << j)) {
            rosterCount++;
        }
    }
    return receivedCount == rosterCount - 1;
}

void EndWiFiSessionOnPicksMismatch(u32 index) {
    u8 i;
    u8 differs = 0;
    u8 ownIndex;

    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if ((ownIndex = GetOwnParticipantIndex(), gWiFiSession->mIndexMessages[ownIndex].mKartIndices[i]) !=
                gWiFiSession->mReceiveBuffers[index].mKartIndices[i] ||
            (ownIndex = GetOwnParticipantIndex(), gWiFiSession->mIndexMessages[ownIndex].mCharacterIndices[i]) !=
                gWiFiSession->mReceiveBuffers[index].mCharacterIndices[i]) {
            differs = 1;
        }
    }
    ownIndex = GetOwnParticipantIndex();
    if (gWiFiSession->mReceiveBuffers[index].mTalliedCourseId !=
        gWiFiSession->mIndexMessages[ownIndex].mTalliedCourseId) {
        differs = 1;
    }
    if (differs == 0) {
        return;
    }
    gWiFiSession->mUnk_19ad = 1;
    func_ov000_021a2ccc();
    func_ov000_0219bbfc();
    gWiFiSession->mStep = 0xb;
}

BOOL IsWiFiMatchingBeforeTimeLimit(void) {
    return func_ov000_021a2950(NULL) == 0;
}

u8 GetWiFiMatchingParticipantCount(void) {
    return func_ov000_0219bb68();
}

BOOL HasWiFiBuddyStatus4(void) {
    return gWiFiSession->mStatus4BuddyCount != 0;
}

u32 StopWiFiSessionMatching(void) {
    return func_ov000_021a2cac();
}

BOOL IsWiFiSessionMatchingActive(void) {
    if (func_ov000_021a2c64() != 0) {
        if (gWiFiSession->mStateMachine.mState == 3) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL IsKartKeysStartStatus2(void) {
    return gWiFiSession->mStartStatus == 2;
}

void RequestWiFiSessionMatching(u32 kartType, s32 useTimeLimit, s32 unused) {
    StateMachine *stateMachine;

    func_ov000_0219bbfc();
    MI_CpuFill8(&gWiFiSession->mKeys[0], 0, 0x18);
    MI_CpuFill8(&gWiFiSession->mKeys[1], 0, 0x18);
    MI_CpuFill8(&gWiFiSession->mKeys[2], 0, 0x18);
    MI_CpuFill8(&gWiFiSession->mKeys[3], 0, 0x18);
    gWiFiSession->mEarlyStepTimedOut = 0;
    gWiFiSession->mUnk_194c = 0;
    gWiFiSession->mStatus4BuddyCount = 0;
    gWiFiSession->mKartCount = 0;
    gWiFiSession->mStartKartCount = 0;
    gWiFiSession->mKartCountCopy = 0;
    gWiFiSession->mKartMask = 0;
    gWiFiSession->mKartRemoveMask = 0;
    MI_CpuFill8(&gWiFiSession->mStep, 0, 0x60);
    gWiFiSession->mKeys[1].mValue = kartType;
    gWiFiSession->mUnk_194c = 4;
    if (useTimeLimit == 0) {
        gWiFiSession->mUnk_18e0.mUnk_00 = 1;
        gWiFiSession->mUnk_18e0.mUnk_01 = 2;
        gWiFiSession->mUnk_18e0.mTimeLimit = 1;
    } else {
        gWiFiSession->mUnk_18e0.mUnk_00 = 1;
        gWiFiSession->mUnk_18e0.mUnk_01 = 2;
        gWiFiSession->mUnk_18e0.mTimeLimit = 0xea60;
    }
    func_ov000_021a299c(0, &gWiFiSession->mUnk_18e0, 0);
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = 3;
    stateMachine->mNextStateRequested = 1;
}

s32 CheckWiFiMatchingResult(void) {
    if ((gWiFiSession->mEarlyStepTimedOut != 0 && func_ov000_0219bb68() <= 1) || gWiFiSession->mErrorKind == 7) {
        return -1;
    }
    return IsWiFiStep5ReachedNoDisconnect() != FALSE;
}

void RegisterKartKeysAndStart(void) {
    s32 eloHigh;
    s32 eloLow;

    ClearWiFiDisconnectStatus();
    MI_CpuFill8(gWiFiSession->mPlayerRecords, 0, 0x910);
    FillPlayerRecord(&gWiFiSession->mPlayerRecords[0].mPlayer);
    gWiFiSession->mKeys[0].mValue = gWiFiSession->mPlayerRecords[0].mPlayer.mRegion;
    gWiFiSession->mKeys[3].mValue = gWiFiSession->mPlayerRecords[0].mPlayer.mElo;
    __memcpy(gWiFiSession->mKeys[2].mName, "kart_filter", 12);
    gWiFiSession->mKeys[2].mId =
        func_ov000_021a2ad0(gWiFiSession->mKeys[2].mId, gWiFiSession->mKeys[2].mName, "ds_mario_kart_product");
    __memcpy(gWiFiSession->mKeys[1].mName, "kart_type", 10);
    gWiFiSession->mKeys[1].mId =
        func_ov000_021a2b9c(gWiFiSession->mKeys[1].mId, gWiFiSession->mKeys[1].mName, &gWiFiSession->mKeys[1]);
    __memcpy(gWiFiSession->mKeys[3].mName, "kart_elo", 9);
    gWiFiSession->mKeys[3].mId =
        func_ov000_021a2b9c(gWiFiSession->mKeys[3].mId, gWiFiSession->mKeys[3].mName, &gWiFiSession->mKeys[3]);
    __memcpy(gWiFiSession->mKeys[0].mName, "kart_region", 12);
    gWiFiSession->mKeys[0].mId =
        func_ov000_021a2b9c(gWiFiSession->mKeys[0].mId, gWiFiSession->mKeys[0].mName, &gWiFiSession->mKeys[0]);
    eloLow = gWiFiSession->mPlayerRecords[0].mPlayer.mElo - 0x3e8;
    if (eloLow <= 0) {
        eloLow = 0;
    }
    eloHigh = gWiFiSession->mPlayerRecords[0].mPlayer.mElo + 0x3e8;
    if (eloHigh > 0x2710) {
        eloHigh = 0x2710;
    }
    MI_CpuFill8(gKartFilterString, 0, 0x64);
    if (gWiFiSession->mKeys[1].mValue == 1) {
        sprintf(gKartFilterString, "%s = '%s' and %s > %d and %s < %d", "kart_filter", "ds_mario_kart_product",
                "kart_elo", eloLow, "kart_elo", eloHigh);
    } else {
        sprintf(gKartFilterString, "%s = '%s'", "kart_filter", "ds_mario_kart_product");
    }
    switch (gWiFiSession->mKeys[1].mValue) {
        case 3:
            StartWiFiMatchingWithFilter(gWiFiSession->mUnk_194c, gKartFilterString, KartKeysStartCallback, NULL,
                                        ComputeRegionEval, 0);
            break;
        case 4:
            StartWiFiMatchingWithFilter(gWiFiSession->mUnk_194c, gKartFilterString, KartKeysStartCallback, NULL,
                                        ComputeRegionEloEval, 0);
            break;
        case 0:
            StartWiFiMatchingWithBuddies(NULL, 0, gWiFiSession->mUnk_194c, 1, KartKeysStartCallback, NULL, 0, 0);
            break;
        case 1:
            StartWiFiMatchingWithFilter(gWiFiSession->mUnk_194c, gKartFilterString, KartKeysStartCallback, NULL,
                                        ComputeEloEval, 0);
            break;
    }
    gWiFiSession->mStartStatus = 1;
}

BOOL IsKartKeysStartStatus3(void) {
    s32 status;

    status = gWiFiSession->mStartStatus;
    switch (status) {
        case 1:
            break;
        case 3:
            return TRUE;
        case 4:
            break;
    }
    return FALSE;
}

s32 ComputeEloEval(u32 serverIndex) {
    s32 kartType;
    s32 kartRegion;
    s32 z;
    WiFiSession *session;

    kartType = func_ov000_021a2a88(serverIndex, gWiFiSession->mKeys[1].mName, 5);
    kartRegion = func_ov000_021a2a88(serverIndex, gWiFiSession->mKeys[0].mName, 3);
    z = func_ov000_021a2a88(serverIndex, gWiFiSession->mKeys[3].mName, -1);
    if (kartType == 5 || kartRegion == 3 || z < 0) {
        return 0;
    }
    session = gWiFiSession;
    if (session->mPlayerRecords[0].mPlayer.mElo > z) {
        z = session->mPlayerRecords[0].mPlayer.mElo - z;
    } else {
        z = z - session->mPlayerRecords[0].mPlayer.mElo;
    }
    if (z < 0x3e8) {
        if (kartType == 1) {
            return 0x7d0 - z;
        }
        if (kartType == 4) {
            return 0x3e8 - z;
        }
    }
    return 0;
}

BOOL ComputeRegionEval(u32 serverIndex) {
    s32 kartType;
    s32 kartRegion;

    kartType = func_ov000_021a2a88(serverIndex, gWiFiSession->mKeys[1].mName, 5);
    kartRegion = func_ov000_021a2a88(serverIndex, gWiFiSession->mKeys[0].mName, 3);
    if (kartType == 5 || kartRegion == 3) {
        return FALSE;
    }
    if (kartType == 3) {
        if (gWiFiSession->mPlayerRecords[0].mPlayer.mRegion == kartRegion) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 ComputeRegionEloEval(u32 serverIndex) {
    s32 kartType;
    s32 kartRegion;
    s32 z;
    WiFiSession *session;

    kartType = func_ov000_021a2a88(serverIndex, gWiFiSession->mKeys[1].mName, 5);
    kartRegion = func_ov000_021a2a88(serverIndex, gWiFiSession->mKeys[0].mName, 3);
    z = func_ov000_021a2a88(serverIndex, gWiFiSession->mKeys[3].mName, -1);
    if (kartType == 5 || kartRegion == 3 || z < 0) {
        return 0;
    }
    if (kartType == 4) {
        return (kartRegion != gWiFiSession->mPlayerRecords[0].mPlayer.mRegion ? 2 : 1) * 0x7d0;
    }
    if (kartType == 1) {
        session = gWiFiSession;
        if (session->mPlayerRecords[0].mPlayer.mElo > z) {
            z = session->mPlayerRecords[0].mPlayer.mElo - z;
        } else {
            z = z - session->mPlayerRecords[0].mPlayer.mElo;
        }
        if (z < 0x3e8) {
            if (kartRegion != session->mPlayerRecords[0].mPlayer.mRegion) {
                return 0x7d0 - z;
            }
            return 0x3e8 - z;
        }
    }
    return 0;
}

void KartKeysStartCallback(u32 result, s32 flag) {
    WiFiSession *session;
    u8 i;

    if (result == 0) {
        if (flag != 0) {
            gWiFiSession->mStartStatus = 2;
            return;
        }
        gWiFiSession->mKartMask = 0;
        gWiFiSession->mKartCount = func_ov000_0219bb68();
        gWiFiSession->mStartKartCount = gWiFiSession->mKartCount;
        session = gWiFiSession;
        i = 0;
        while (i < session->mStartKartCount) {
            session->mKartMask |= 1 << i;
            session = gWiFiSession;
            i++;
        }
        MI_CpuFill8(session->mPlayerRecords, 0, 0x910);
        FillPlayerRecord(&gWiFiSession->mPlayerRecords[GetOwnParticipantIndex()].mPlayer);
        SetupWiFiSession(0);
        gWiFiSession->mStartStatus = 3;
    } else {
        gWiFiSession->mStartStatus = 4;
    }
}

void SetWiFiDisconnectKind(s32 kind) {
    gWiFiSession->mDisconnectKind = kind;
    if (gWiFiSession->mDisconnectKind != 2) {
        return;
    }
    func_ov000_021a2ccc();
    func_ov000_0219bbfc();
}

void ResetWiFiSession(void) {
    MI_CpuFill8(gWiFiSession->mUnk_001c, 0, 0x200);
    MI_CpuFill8(gWiFiSession->mPlayerRecords, 0, 0x910);
    MI_CpuFill8(gWiFiSession->mConnection, 0, 0xe24);
    MI_CpuFill8(&gWiFiSession->mStep, 0, 0x60);
    MI_CpuFill8(&gWiFiSession->mUserData, 0, 0x350);
    MI_CpuFill8(gWiFiSession->mReceiveBuffers, 0, 0x110);
    MI_CpuFill8(gWiFiSession->mIndexMessages, 0, 0x110);
    MI_CpuFill8(&gWiFiSession->mLogin, 0, 0x10);
    gWiFiSession->mUnk_1f34 = FALSE;
    gWiFiSession->mRaceSyncEnabled = FALSE;
    gWiFiSession->mIrqCallbackCount = 0;
    gWiFiSession->mDisconnectKind = 0;
    gWiFiSession->mErrorKind = 0;
    gWiFiSession->mErrorCode = 0;
    gWiFiSession->mUnk_1f4c = 0;
    gWiFiSession->mUnk_1f4d = 0;
    MI_CpuFill8(gWiFiSession->mPackedIndices, 0, 4);
    gWiFiSession->mKartCount = 0;
    gWiFiSession->mStartKartCount = 0;
    gWiFiSession->mKartCountCopy = 0;
    gWiFiSession->mKartMask = 0;
    gWiFiSession->mKartRemoveMask = 0;
    gWiFiSession->mBuddyPollIndex = 0;
}

// 0 none, 1 no input for 30 seconds, 2 the opponent left, 3 error; for 1 and 2 it also requests state 2.
u32 CheckWiFiSessionDisconnect(void) {
    WiFiSession *session;
    StateMachine *stateMachine;
    s32 errorKind;

    session = gWiFiSession;
    if (session->mStateMachine.mState != 0) {
        errorKind = session->mErrorKind;
        if (errorKind == 6 || errorKind == 3 || errorKind == 4 || errorKind == 0xb) {
            return 3;
        }
        if (session->mDisconnectKind == 2) {
            if (func_ov000_0219bb68() <= 1) {
                stateMachine = &gWiFiSession->mStateMachine;
                stateMachine->mNextState = 2;
                stateMachine->mNextStateRequested = 1;
                return 2;
            }
        } else if (session->mDisconnectKind == 1) {
            stateMachine = &session->mStateMachine;
            stateMachine->mNextState = 2;
            stateMachine->mNextStateRequested = 1;
            return 1;
        }
    }
    return 0;
}

void ClearWiFiDisconnectStatus(void) {
    gWiFiSession->mErrorKind = 0;
    gWiFiSession->mDisconnectKind = 0;
    gWiFiSession->mErrorCode = 0;
}
