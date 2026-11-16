#include "Main/Unknown/code_02120610.h"
#include "Main/Save/GhostTimes.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "Main/Net/WiFiSession.h"
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

void func_02121dec(u32 a) {
    gStruct217D384->mIndexMessages[func_ov000_0219bb50()].field40 = a != 0 ? 1 : 2;
}

s32 GetWiFiSessionCourseId(void) {
    if (menu_getRaceConfig()->mCourseId == 0) {
        return gStruct217D384->mIndexMessages[func_ov000_0219bb50()].mPickedCourseId;
    }
    return menu_getRaceConfig()->mCourseId;
}

BOOL func_02121d48(void) {
    if (gStruct217D384->mStep >= 5) {
        if (func_02120644() == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_02121d0c(void) {
    BOOL result = TRUE;
    WiFiSession *session = gStruct217D384;
    s32 step = session->mStep;

    if (step < 7) {
        if (session->field19AD != 1 || step != 0xc) {
            result = FALSE;
        }
    }
    return result;
}

s32 func_02121cd0(void) {
    BOOL result = TRUE;
    WiFiSession *session = gStruct217D384;
    s32 step = session->mStep;

    if (step < 10) {
        if (session->field19AD != 1 || step != 0xc) {
            result = FALSE;
        }
    }
    return result;
}

s32 func_02121c78(void) {
    s32 step;

    step = gStruct217D384->mStep;
    if (step >= 5) {
        if (gStruct217D384->mKartCount > 1) {
            return 1;
        }
        return 2;
    }
    if (gStruct217D384->field19AD == 1) {
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

    session = gStruct217D384;
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
    menu_getRaceConfig()->mCourseId = talliedCourseId;
}

void func_021219cc(void) {
    BOOL ownKind = FALSE;
    u8 i;

    for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
        if (gStruct217D384->mKartMask & (1 << i)) {
            if (i == func_ov000_0219bb50()) {
                s8 x;

                x = gStruct217D384->mPackedIndices[i];
                menu_getRaceConfig()->mEntries[x].mPlayerKind = ownKind;
            } else {
                s8 x;

                x = gStruct217D384->mPackedIndices[i];
                menu_getRaceConfig()->mEntries[x].mPlayerKind = PLAYER_KIND_PEER;
            }
            {
                WiFiSession *d;
                s8 x;

                d = gStruct217D384;
                x = d->mPackedIndices[i];
                menu_getRaceConfig()->mEntries[x].mCharacterIndex = d->mIndexMessages[i].mCharacterIndex;
            }
            {
                WiFiSession *d;
                s8 x;

                d = gStruct217D384;
                x = d->mPackedIndices[i];
                menu_getRaceConfig()->mEntries[x].mKartIndex = d->mIndexMessages[i].mKartIndex;
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
            if (gStruct217D384->mStep == 0 || gStruct217D384->mStep == 1) {
                return TRUE;
            }
            break;
        case 1:
            if (gStruct217D384->mStep == 0) {
                return TRUE;
            }
            break;
        case 2:
            if (gStruct217D384->mStep == 0 || gStruct217D384->mStep == 1) {
                return TRUE;
            }
            break;
        case 8:
            if ((u32) (gStruct217D384->mStep - 3) <= 1) {
                return TRUE;
            }
            break;
        case 9:
            if ((u32) (gStruct217D384->mStep - 3) <= 2) {
                return TRUE;
            }
            break;
        case 3:
            if (gStruct217D384->mStep == 1 || (u32) (gStruct217D384->mStep - 4) <= 2) {
                return TRUE;
            }
            break;
        case 4:
            if ((u32) (gStruct217D384->mStep - 5) <= 1) {
                return TRUE;
            }
            break;
        case 5:
            if ((u32) (gStruct217D384->mStep - 6) <= 1) {
                return TRUE;
            }
            break;
        case 6:
            if ((u32) (gStruct217D384->mStep - 7) <= 1) {
                return TRUE;
            }
            break;
        case 7:
            if ((u32) (gStruct217D384->mStep - 8) <= 1) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

u8 func_021216a8(void) {
    u8 i;
    u8 callCount;

    callCount = gStruct217D384->field19AC;
    if (callCount < 2) {
        gStruct217D384->field19AC = callCount + 1;
        return gStruct217D384->mStartKartCount;
    }
    for (i = gStruct217D384->field1999; i < gStruct217D384->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50()) {
            if (gStruct217D384->mKartMask & (1 << i)) {
                break;
            }
        }
    }
    if (gStruct217D384->field1999 >= gStruct217D384->mStartKartCount) {
        for (i = 0; i < gStruct217D384->field1999; i++) {
            if (i != func_ov000_0219bb50()) {
                if (gStruct217D384->mKartMask & (1 << i)) {
                    break;
                }
            }
        }
        if (i >= gStruct217D384->field1999) {
            return gStruct217D384->mStartKartCount;
        }
    }
    gStruct217D384->field1999 = i + 1;
    gStruct217D384->field19AC = 0;
    return i;
}

BOOL func_02121580(void) {
    u8 i;
    u8 receivedCount = 0;
    u8 checkedCount = 0;
    u8 startKartCount;
    u8 j;
    u8 rosterCount;
    u8 kartMask;

    for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50()) {
            if (gStruct217D384->mKartMask & (1 << i)) {
                checkedCount++;
                if ((gStruct217D384->mReceivedMask & (1 << i)) == 0) {
                    break;
                }
                receivedCount++;
            }
        }
    }
    if (checkedCount == 0) {
        gStruct217D384->field19AD = 1;
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        gStruct217D384->mStep = 0xb;
        return FALSE;
    }
    rosterCount = 0;
    startKartCount = gStruct217D384->mStartKartCount;
    kartMask = gStruct217D384->mKartMask;
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

    for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
        if ((ownIndex = func_ov000_0219bb50(), gStruct217D384->mIndexMessages[ownIndex].mKartIndices[i]) !=
                gStruct217D384->mReceiveBuffers[index].mKartIndices[i] ||
            (ownIndex = func_ov000_0219bb50(), gStruct217D384->mIndexMessages[ownIndex].mCharacterIndices[i]) !=
                gStruct217D384->mReceiveBuffers[index].mCharacterIndices[i]) {
            differs = 1;
        }
    }
    ownIndex = func_ov000_0219bb50();
    if (gStruct217D384->mReceiveBuffers[index].mTalliedCourseId !=
        gStruct217D384->mIndexMessages[ownIndex].mTalliedCourseId) {
        differs = 1;
    }
    if (differs == 0) {
        return;
    }
    gStruct217D384->field19AD = 1;
    func_ov000_021a2ccc();
    func_ov000_0219bbfc();
    gStruct217D384->mStep = 0xb;
}

BOOL func_02121434(void) {
    return func_ov000_021a2950(NULL) == 0;
}

u8 func_02121418(void) {
    return func_ov000_0219bb68();
}

BOOL func_021213f4(void) {
    return gStruct217D384->mStatus4BuddyCount != 0;
}

u32 func_021213e8(void) {
    return func_ov000_021a2cac();
}

BOOL func_021213a0(void) {
    if (func_ov000_021a2c64() != 0) {
        if (gStruct217D384->field8.mState == 3) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL IsKartKeysStartStatus2(void) {
    return gStruct217D384->mStartStatus == 2;
}

void func_02121190(u32 kartType, s32 b, s32 c) {
    StateMachine *stateMachine;

    func_ov000_0219bbfc();
    MI_CpuFill8(&gStruct217D384->mKeys[0], 0, 0x18);
    MI_CpuFill8(&gStruct217D384->mKeys[1], 0, 0x18);
    MI_CpuFill8(&gStruct217D384->mKeys[2], 0, 0x18);
    MI_CpuFill8(&gStruct217D384->mKeys[3], 0, 0x18);
    gStruct217D384->field194E = 0;
    gStruct217D384->field194C = 0;
    gStruct217D384->mStatus4BuddyCount = 0;
    gStruct217D384->mKartCount = 0;
    gStruct217D384->mStartKartCount = 0;
    gStruct217D384->mKartCountCopy = 0;
    gStruct217D384->mKartMask = 0;
    gStruct217D384->mKartRemoveMask = 0;
    MI_CpuFill8(&gStruct217D384->mStep, 0, 0x60);
    gStruct217D384->mKeys[1].mValue = kartType;
    gStruct217D384->field194C = 4;
    if (b == 0) {
        gStruct217D384->field18E0.field0 = 1;
        gStruct217D384->field18E0.field1 = 2;
        gStruct217D384->field18E0.field4 = 1;
    } else {
        gStruct217D384->field18E0.field0 = 1;
        gStruct217D384->field18E0.field1 = 2;
        gStruct217D384->field18E0.field4 = 0xea60;
    }
    func_ov000_021a299c(0, &gStruct217D384->field18E0, 0);
    stateMachine = &gStruct217D384->field8;
    stateMachine->mNextState = 3;
    stateMachine->mNextStateRequested = 1;
}

s32 func_0212111c(void) {
    if ((gStruct217D384->field194E != 0 && func_ov000_0219bb68() <= 1) || gStruct217D384->field1F44 == 7) {
        return -1;
    }
    return func_02121d48() != FALSE;
}

void RegisterKartKeysAndStart(void) {
    s32 eloHigh;
    s32 eloLow;

    func_02120610();
    MI_CpuFill8(gStruct217D384->mPlayerRecords, 0, 0x910);
    FillPlayerRecord((Unk0217aa00_45c *) &gStruct217D384->mPlayerRecords[0].mName);
    gStruct217D384->mKeys[0].mValue = gStruct217D384->mPlayerRecords[0].mRegion;
    gStruct217D384->mKeys[3].mValue = gStruct217D384->mPlayerRecords[0].mElo;
    __memcpy(gStruct217D384->mKeys[2].mName, "kart_filter", 12);
    gStruct217D384->mKeys[2].mId =
        func_ov000_021a2ad0(gStruct217D384->mKeys[2].mId, gStruct217D384->mKeys[2].mName, "ds_mario_kart_product");
    __memcpy(gStruct217D384->mKeys[1].mName, "kart_type", 10);
    gStruct217D384->mKeys[1].mId =
        func_ov000_021a2b9c(gStruct217D384->mKeys[1].mId, gStruct217D384->mKeys[1].mName, &gStruct217D384->mKeys[1]);
    __memcpy(gStruct217D384->mKeys[3].mName, "kart_elo", 9);
    gStruct217D384->mKeys[3].mId =
        func_ov000_021a2b9c(gStruct217D384->mKeys[3].mId, gStruct217D384->mKeys[3].mName, &gStruct217D384->mKeys[3]);
    __memcpy(gStruct217D384->mKeys[0].mName, "kart_region", 12);
    gStruct217D384->mKeys[0].mId =
        func_ov000_021a2b9c(gStruct217D384->mKeys[0].mId, gStruct217D384->mKeys[0].mName, &gStruct217D384->mKeys[0]);
    eloLow = gStruct217D384->mPlayerRecords[0].mElo - 0x3e8;
    if (eloLow <= 0) {
        eloLow = 0;
    }
    eloHigh = gStruct217D384->mPlayerRecords[0].mElo + 0x3e8;
    if (eloHigh > 0x2710) {
        eloHigh = 0x2710;
    }
    MI_CpuFill8(gKartFilterString, 0, 0x64);
    if (gStruct217D384->mKeys[1].mValue == 1) {
        sprintf(gKartFilterString, "%s = '%s' and %s > %d and %s < %d", "kart_filter", "ds_mario_kart_product",
                "kart_elo", eloLow, "kart_elo", eloHigh);
    } else {
        sprintf(gKartFilterString, "%s = '%s'", "kart_filter", "ds_mario_kart_product");
    }
    switch (gStruct217D384->mKeys[1].mValue) {
        case 3:
            StartWiFiMatchingWithFilter(gStruct217D384->field194C, gKartFilterString, KartKeysStartCallback, NULL,
                                        ComputeRegionEval, 0);
            break;
        case 4:
            StartWiFiMatchingWithFilter(gStruct217D384->field194C, gKartFilterString, KartKeysStartCallback, NULL,
                                        ComputeRegionEloEval, 0);
            break;
        case 0:
            StartWiFiMatchingWithBuddies(NULL, 0, gStruct217D384->field194C, 1, KartKeysStartCallback, NULL, 0, 0);
            break;
        case 1:
            StartWiFiMatchingWithFilter(gStruct217D384->field194C, gKartFilterString, KartKeysStartCallback, NULL,
                                        ComputeEloEval, 0);
            break;
    }
    gStruct217D384->mStartStatus = 1;
}

BOOL IsKartKeysStartStatus3(void) {
    s32 status;

    status = gStruct217D384->mStartStatus;
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

s32 ComputeEloEval(u32 a) {
    s32 kartType;
    s32 kartRegion;
    s32 z;
    WiFiSession *session;

    kartType = func_ov000_021a2a88(a, gStruct217D384->mKeys[1].mName, 5);
    kartRegion = func_ov000_021a2a88(a, gStruct217D384->mKeys[0].mName, 3);
    z = func_ov000_021a2a88(a, gStruct217D384->mKeys[3].mName, -1);
    if (kartType == 5 || kartRegion == 3 || z < 0) {
        return 0;
    }
    session = gStruct217D384;
    if (session->mPlayerRecords[0].mElo > z) {
        z = session->mPlayerRecords[0].mElo - z;
    } else {
        z = z - session->mPlayerRecords[0].mElo;
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

BOOL ComputeRegionEval(u32 a) {
    s32 kartType;
    s32 kartRegion;

    kartType = func_ov000_021a2a88(a, gStruct217D384->mKeys[1].mName, 5);
    kartRegion = func_ov000_021a2a88(a, gStruct217D384->mKeys[0].mName, 3);
    if (kartType == 5 || kartRegion == 3) {
        return FALSE;
    }
    if (kartType == 3) {
        if (gStruct217D384->mPlayerRecords[0].mRegion == kartRegion) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 ComputeRegionEloEval(u32 a) {
    s32 kartType;
    s32 kartRegion;
    s32 z;
    WiFiSession *session;

    kartType = func_ov000_021a2a88(a, gStruct217D384->mKeys[1].mName, 5);
    kartRegion = func_ov000_021a2a88(a, gStruct217D384->mKeys[0].mName, 3);
    z = func_ov000_021a2a88(a, gStruct217D384->mKeys[3].mName, -1);
    if (kartType == 5 || kartRegion == 3 || z < 0) {
        return 0;
    }
    if (kartType == 4) {
        return (kartRegion != gStruct217D384->mPlayerRecords[0].mRegion ? 2 : 1) * 0x7d0;
    }
    if (kartType == 1) {
        session = gStruct217D384;
        if (session->mPlayerRecords[0].mElo > z) {
            z = session->mPlayerRecords[0].mElo - z;
        } else {
            z = z - session->mPlayerRecords[0].mElo;
        }
        if (z < 0x3e8) {
            if (kartRegion != session->mPlayerRecords[0].mRegion) {
                return 0x7d0 - z;
            }
            return 0x3e8 - z;
        }
    }
    return 0;
}

void KartKeysStartCallback(u32 a, s32 b) {
    WiFiSession *session;
    u8 i;

    if (a == 0) {
        if (b != 0) {
            gStruct217D384->mStartStatus = 2;
            return;
        }
        gStruct217D384->mKartMask = 0;
        gStruct217D384->mKartCount = func_ov000_0219bb68();
        gStruct217D384->mStartKartCount = gStruct217D384->mKartCount;
        session = gStruct217D384;
        i = 0;
        while (i < session->mStartKartCount) {
            session->mKartMask |= 1 << i;
            session = gStruct217D384;
            i++;
        }
        MI_CpuFill8(session->mPlayerRecords, 0, 0x910);
        FillPlayerRecord((Unk0217aa00_45c *) &gStruct217D384->mPlayerRecords[func_ov000_0219bb50()].mName);
        SetupWiFiSession(0);
        gStruct217D384->mStartStatus = 3;
    } else {
        gStruct217D384->mStartStatus = 4;
    }
}

void func_021208e8(s32 a) {
    gStruct217D384->field1F40 = a;
    if (gStruct217D384->field1F40 != 2) {
        return;
    }
    func_ov000_021a2ccc();
    func_ov000_0219bbfc();
}

void ResetWiFiSession(void) {
    MI_CpuFill8(gStruct217D384->field1C, 0, 0x200);
    MI_CpuFill8(gStruct217D384->mPlayerRecords, 0, 0x910);
    MI_CpuFill8(gStruct217D384->mConnection, 0, 0xe24);
    MI_CpuFill8(&gStruct217D384->mStep, 0, 0x60);
    MI_CpuFill8(gStruct217D384->mUserData, 0, 0x350);
    MI_CpuFill8(gStruct217D384->mReceiveBuffers, 0, 0x110);
    MI_CpuFill8(gStruct217D384->mIndexMessages, 0, 0x110);
    MI_CpuFill8(&gStruct217D384->mLogin, 0, 0x10);
    gStruct217D384->field1F34 = FALSE;
    gStruct217D384->field1F38 = FALSE;
    gStruct217D384->field1F3C = 0;
    gStruct217D384->field1F40 = 0;
    gStruct217D384->field1F44 = 0;
    gStruct217D384->field1F48 = 0;
    gStruct217D384->field1F4C = 0;
    gStruct217D384->field1F4D = 0;
    MI_CpuFill8(gStruct217D384->mPackedIndices, 0, 4);
    gStruct217D384->mKartCount = 0;
    gStruct217D384->mStartKartCount = 0;
    gStruct217D384->mKartCountCopy = 0;
    gStruct217D384->mKartMask = 0;
    gStruct217D384->mKartRemoveMask = 0;
    gStruct217D384->mBuddyPollIndex = 0;
}

u32 func_02120644(void) {
    WiFiSession *session;
    StateMachine *stateMachine;
    s32 v;

    session = gStruct217D384;
    if (session->field8.mState != 0) {
        v = session->field1F44;
        if (v == 6 || v == 3 || v == 4 || v == 0xb) {
            return 3;
        }
        if (session->field1F40 == 2) {
            if (func_ov000_0219bb68() <= 1) {
                stateMachine = &gStruct217D384->field8;
                stateMachine->mNextState = 2;
                stateMachine->mNextStateRequested = 1;
                return 2;
            }
        } else if (session->field1F40 == 1) {
            stateMachine = &session->field8;
            stateMachine->mNextState = 2;
            stateMachine->mNextStateRequested = 1;
            return 1;
        }
    }
    return 0;
}

void func_02120610(void) {
    gStruct217D384->field1F44 = 0;
    gStruct217D384->field1F40 = 0;
    gStruct217D384->field1F48 = 0;
}
