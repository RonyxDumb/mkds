#include "Main/Net/WiFiSession.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3000.h"
#include "00/code_021a3264.h"
#include "00/unk_021b5000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"

// Sets the session up for variant a (0 to 3): case 0 resets masks, records and picks and sets mStep 0, case 1 only
// packs the indices and counts the karts, cases 2 and 3 reset the picks and set mStep 7 and 3.
void SetupWiFiSession(u32 mode) {
    u8 i;
    u8 ownIndex;
    func_0211fe44();
    switch (mode) {
        case 0:
            MI_CpuFill8(&gStruct217D384->mStep, 0, 0x60);
            MI_CpuFill8(gStruct217D384->mIndexMessages, 0, 0x110);
            MI_CpuFill8(gStruct217D384->mReceiveBuffers, 0, 0x110);
            for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
                if (i != func_ov000_0219bb50()) {
                    SetPeerReceiveBuffer(i, &gStruct217D384->mPlayerRecords[i], 0x244);
                    menu_getRaceConfig()->mEntries[i].mPlayerKind = 3;
                } else {
                    gStruct217D384->mPlayerRecords[i].mUnk_238 = gSaveData->mFirstBlock->mUnk_34[4];
                    gStruct217D384->mPlayerRecords[i].mUnk_23c = gSaveData->mFirstBlock->mUnk_34[5];
                    menu_getRaceConfig()->mEntries[i].mPlayerKind = 0;
                }
                menu_getRaceConfig()->mEntries[i].mCharacterIndex = -1;
                menu_getRaceConfig()->mEntries[i].mKartIndex = -1;
                menu_getRaceConfig()->mCourseId = 0;
                gStruct217D384->mIndexMessages[i].mCharacterIndex = -1;
                gStruct217D384->mIndexMessages[i].mKartIndex = -1;
                gStruct217D384->mIndexMessages[i].mPickedCourseId = 0;
                gStruct217D384->mReceiveBuffers[i].mCharacterIndex = -1;
                gStruct217D384->mReceiveBuffers[i].mKartIndex = -1;
                gStruct217D384->mReceiveBuffers[i].mPickedCourseId = 0;
            }
            gStruct217D384->mStepFrames = 0;
            gStruct217D384->mSendRecordMask = 0;
            gStruct217D384->mReceivedMask = 0;
            func_ov000_021a323c(ReceiveWiFiSessionMessage);
            ownIndex = func_ov000_0219bb50();
            gStruct217D384->mPlayerRecords[ownIndex].mSeed = OS_GetTick();
            PackWiFiSessionIndices();
            gStruct217D384->mStep = 0;
            SetRaceSetupCopyEntryIndex((u8) gStruct217D384->mPackedIndices[func_ov000_0219bb50()]);
            SetSessionKartCount(gStruct217D384->mStartKartCount);
            break;
        case 1:
            PackWiFiSessionIndices();
            gStruct217D384->mKartCount = 0;
            for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
                if ((gStruct217D384->mKartMask & (1 << i)) != 0) {
                    gStruct217D384->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) gStruct217D384->mPackedIndices[func_ov000_0219bb50()]);
            SetSessionKartCount(gStruct217D384->mKartCount);
            break;
        case 2:
            for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
                if (i != func_ov000_0219bb50() && (gStruct217D384->mKartMask & (1 << i)) != 0) {
                    SetPeerReceiveBuffer(i, &gStruct217D384->mReceiveBuffers[i], 0x44);
                }
                menu_getRaceConfig()->mCourseId = 0;
                gStruct217D384->mIndexMessages[i].mPickedCourseId = 0;
                gStruct217D384->mReceiveBuffers[i].mPickedCourseId = 0;
            }
            func_ov000_021a323c(ReceiveWiFiSessionMessage);
            gStruct217D384->mStep = 7;
            gStruct217D384->mStepFrames = 0;
            gStruct217D384->mSendRecordMask = 0;
            gStruct217D384->mReceivedMask = 0;
            PackWiFiSessionIndices();
            gStruct217D384->mKartCount = 0;
            for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
                if ((gStruct217D384->mKartMask & (1 << i)) != 0) {
                    gStruct217D384->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) gStruct217D384->mPackedIndices[func_ov000_0219bb50()]);
            SetSessionKartCount(gStruct217D384->mKartCount);
            break;
        case 3:
            for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
                if (i != func_ov000_0219bb50() && (gStruct217D384->mKartMask & (1 << i)) != 0) {
                    SetPeerReceiveBuffer(i, &gStruct217D384->mReceiveBuffers[i], 0x44);
                }
                gStruct217D384->mStepFrames = 0;
                gStruct217D384->mSendRecordMask = 0;
                gStruct217D384->mReceivedMask = 0;
                menu_getRaceConfig()->mEntries[i].mCharacterIndex = -1;
                menu_getRaceConfig()->mEntries[i].mKartIndex = -1;
                menu_getRaceConfig()->mCourseId = 0;
                gStruct217D384->mIndexMessages[i].mCharacterIndex = -1;
                gStruct217D384->mIndexMessages[i].mKartIndex = -1;
                gStruct217D384->mIndexMessages[i].mPickedCourseId = 0;
                gStruct217D384->mIndexMessages[i].mUnk_40 = 0;
                gStruct217D384->mReceiveBuffers[i].mCharacterIndex = -1;
                gStruct217D384->mReceiveBuffers[i].mKartIndex = -1;
                gStruct217D384->mReceiveBuffers[i].mPickedCourseId = 0;
                gStruct217D384->mReceiveBuffers[i].mUnk_40 = 0;
            }
            func_ov000_021a323c(ReceiveWiFiSessionMessage);
            gStruct217D384->mStep = 3;
            break;
    }
}

// One frame of the exchange: counts the frames since each kart last called back, marks silent karts and drops them,
// then runs the handler of the current mStep (steps 2, 6, 7, 11 and 12 inline). Always returns 0.
s32 UpdateWiFiSessionStep(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    s32 waitFlag;
    Unk0217d384_1d00 *ownRecord;
    BackupAccess *backup;
    UpdateWiFiSessionKartTimeouts();
    RemoveWiFiSessionKarts();
    switch (gStruct217D384->mStep) {
        case 0:
            AdvanceWiFiSessionStep0();
            break;
        case 1:
            AdvanceWiFiSessionStep1();
            break;
        case 2:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (gSaveData->mBusy == 0) {
                backup = gSaveCore;
                if (backup->mBackupEnabled != 0) {
                    waitFlag = backup->mCommandRunning;
                } else {
                    waitFlag = 0;
                }
            } else {
                waitFlag = 1;
            }
            if (waitFlag == 0) {
                gStruct217D384->mStepFrames = 0;
                gStruct217D384->mStep = 5;
            }
            break;
        case 3:
            AdvanceWiFiSessionStep3();
            break;
        case 4:
            AdvanceWiFiSessionStep4();
            break;
        case 5:
            AdvanceWiFiSessionStep5();
            break;
        case 6:
            UpdateWiFiSessionStepTimeout(0x1c20);
            toIndex = func_021216a8();
            if (toIndex < gStruct217D384->mStartKartCount) {
                fromIndex = func_ov000_0219bb50();
                ownIndex = func_ov000_0219bb50();
                ownRecord = &gStruct217D384->mIndexMessages[ownIndex];
                ownRecord->mKind = 4;
                ownRecord->mSize = 0x44;
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = gStruct217D384->mKartMask;
                func_ov000_021a32a0(toIndex, &gStruct217D384->mIndexMessages[func_ov000_0219bb50()], 0x44);
            }
            if (func_02121580() != FALSE) {
                gStruct217D384->mSendRecordMask = 0;
                gStruct217D384->mReceivedMask = 0;
                CombineKartRemoveMask();
                gStruct217D384->mStep = 7;
                gStruct217D384->mStepFrames = 0;
            }
            break;
        case 7:
            UpdateWiFiSessionStepTimeout(0x1c20);
            toIndex = func_021216a8();
            if (toIndex < gStruct217D384->mStartKartCount) {
                fromIndex = func_ov000_0219bb50();
                ownIndex = func_ov000_0219bb50();
                ownRecord = &gStruct217D384->mIndexMessages[ownIndex];
                ownRecord->mKind = 5;
                ownRecord->mSize = 0x44;
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = gStruct217D384->mKartMask;
                func_ov000_021a32a0(toIndex, &gStruct217D384->mIndexMessages[func_ov000_0219bb50()], 0x44);
            }
            if (func_02121580() != FALSE) {
                ownIndex = func_ov000_0219bb50();
                if (gStruct217D384->mIndexMessages[ownIndex].mPickedCourseId != 0) {
                    gStruct217D384->mSendRecordMask = 0;
                    gStruct217D384->mReceivedMask = 0;
                    gStruct217D384->mStep = 8;
                    gStruct217D384->mStepFrames = 0;
                }
            }
            break;
        case 8:
            AdvanceWiFiSessionStep8();
            break;
        case 9:
            AdvanceWiFiSessionStep9();
            break;
        case 11:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (func_ov000_0219bb68() <= 1) {
                gStruct217D384->mStepFrames = 0;
                gStruct217D384->mStep = 12;
            }
            break;
        case 12:
            break;
    }
    return 0;
}

void AdvanceWiFiSessionStep0(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u32 toBit;
    WiFiPlayerRecord *ownPlayerRecord;
    WiFiSessionMessageHeader header;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gStruct217D384->mStartKartCount) {
        toBit = 1 << toIndex;
        if ((gStruct217D384->mSendRecordMask & toBit) != 0) {
            fromIndex = func_ov000_0219bb50();
            ownIndex = func_ov000_0219bb50();
            ownPlayerRecord = &gStruct217D384->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = 1;
            ownPlayerRecord->mSize = 0x244;
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = gStruct217D384->mKartMask;
            ownIndex = func_ov000_0219bb50();
            func_ov000_021a32a0(toIndex, &gStruct217D384->mPlayerRecords[ownIndex], 0x244);
            gStruct217D384->mSendRecordMask &= ~toBit;
        } else if ((gStruct217D384->mReceivedMask & toBit) == 0) {
            header.mFromIndex = func_ov000_0219bb50();
            header.mSize = 0xc;
            header.mToIndex = toIndex;
            header.mKind = 0;
            header.mKartMask = gStruct217D384->mKartMask;
            func_ov000_021a32a0(toIndex, &header, 0xc);
        }
    }
    if (func_02121580() == FALSE) {
        return;
    }
    gStruct217D384->mSendRecordMask = 0;
    gStruct217D384->mReceivedMask = 0;
    gStruct217D384->mStepFrames = 0;
    gStruct217D384->mStep = 1;
}

void AdvanceWiFiSessionStep1(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 i;
    u32 toBit;
    u32 seedSum;
    WiFiSession *session;
    WiFiPlayerRecord *ownPlayerRecord;
    RandomState64 *generator;
    WiFiSessionMessageHeader header;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gStruct217D384->mStartKartCount) {
        toBit = 1 << toIndex;
        if ((gStruct217D384->mSendRecordMask & toBit) != 0) {
            fromIndex = func_ov000_0219bb50();
            ownIndex = func_ov000_0219bb50();
            ownPlayerRecord = &gStruct217D384->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = 1;
            ownPlayerRecord->mSize = 0x244;
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = gStruct217D384->mKartMask;
            ownIndex = func_ov000_0219bb50();
            func_ov000_021a32a0(toIndex, &gStruct217D384->mPlayerRecords[ownIndex], 0x244);
            gStruct217D384->mSendRecordMask &= ~toBit;
        } else {
            header.mFromIndex = func_ov000_0219bb50();
            header.mSize = 0xc;
            header.mToIndex = toIndex;
            header.mKind = 2;
            header.mKartMask = gStruct217D384->mKartMask;
            func_ov000_021a32a0(toIndex, &header, 0xc);
        }
    }
    if (func_02121580() == FALSE) {
        return;
    }
    session = gStruct217D384;
    seedSum = 0;
    for (i = 0; i < session->mStartKartCount; i++) {
        seedSum += session->mPlayerRecords[i].mSeed;
    }
    generator = &session->mRandom;
    generator->mValue = seedSum;
    generator->mMultiplier = 0x5d588b656c078965;
    generator->mIncrement = 0x269ec3;
    StartCopyOtherEmblems(0);
    gStruct217D384->mSendRecordMask = 0;
    gStruct217D384->mReceivedMask = 0;
    gStruct217D384->mStepFrames = 0;
    gStruct217D384->mStep = 2;
}

void AdvanceWiFiSessionStep3(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    Unk0217d384_1d00 *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    ownIndex = func_ov000_0219bb50();
    if (gStruct217D384->mIndexMessages[ownIndex].mUnk_40 == 2) {
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        gStruct217D384->mStep = 11;
        return;
    }
    toIndex = func_021216a8();
    if (toIndex < gStruct217D384->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gStruct217D384->mIndexMessages[ownIndex];
        ownRecord->mKind = 8;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gStruct217D384->mKartMask;
        func_ov000_021a32a0(toIndex, &gStruct217D384->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    ownIndex = func_ov000_0219bb50();
    if (gStruct217D384->mIndexMessages[ownIndex].mUnk_40 == 0) {
        return;
    }
    gStruct217D384->mSendRecordMask = 0;
    gStruct217D384->mReceivedMask = 0;
    gStruct217D384->mStep = 4;
    gStruct217D384->mStepFrames = 0;
}

void AdvanceWiFiSessionStep4(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    Unk0217d384_1d00 *ownRecord;
    StateMachine *stateMachine;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gStruct217D384->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gStruct217D384->mIndexMessages[ownIndex];
        ownRecord->mKind = 9;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gStruct217D384->mKartMask;
        func_ov000_021a32a0(toIndex, &gStruct217D384->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    if (gStruct217D384->mKartCount == 1) {
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        stateMachine = &gStruct217D384->mUnk_0008;
        stateMachine->mNextState = 2;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    gStruct217D384->mSendRecordMask = 0;
    gStruct217D384->mReceivedMask = 0;
    gStruct217D384->mStep = 5;
    gStruct217D384->mStepFrames = 0;
    ownIndex = func_ov000_0219bb50();
    SetRaceSetupCopyEntryIndex((u8) gStruct217D384->mPackedIndices[ownIndex]);
    SetSessionKartCount(gStruct217D384->mKartCount);
}

void AdvanceWiFiSessionStep5(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    Unk0217d384_1d00 *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gStruct217D384->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gStruct217D384->mIndexMessages[ownIndex];
        ownRecord->mKind = 3;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gStruct217D384->mKartMask;
        func_ov000_021a32a0(toIndex, &gStruct217D384->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    ownIndex = func_ov000_0219bb50();
    if (gStruct217D384->mIndexMessages[ownIndex].mCharacterIndex == -1) {
        return;
    }
    ownIndex = func_ov000_0219bb50();
    if (gStruct217D384->mIndexMessages[ownIndex].mKartIndex == -1) {
        return;
    }
    gStruct217D384->mSendRecordMask = 0;
    gStruct217D384->mReceivedMask = 0;
    gStruct217D384->mStep = 6;
    gStruct217D384->mStepFrames = 0;
}

void AdvanceWiFiSessionStep8(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 i;
    Unk0217d384_1d00 *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = func_021216a8();
    if (toIndex < gStruct217D384->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gStruct217D384->mIndexMessages[ownIndex];
        ownRecord->mKind = 6;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gStruct217D384->mKartMask;
        func_ov000_021a32a0(toIndex, &gStruct217D384->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    gStruct217D384->mSendRecordMask = 0;
    gStruct217D384->mReceivedMask = 0;
    CombineKartRemoveMask();
    TallyPickedCourse();
    for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
        ownIndex = func_ov000_0219bb50();
        gStruct217D384->mIndexMessages[ownIndex].mKartIndices[i] = gStruct217D384->mIndexMessages[i].mKartIndex;
        ownIndex = func_ov000_0219bb50();
        gStruct217D384->mIndexMessages[ownIndex].mCharacterIndices[i] = gStruct217D384->mIndexMessages[i].mCharacterIndex;
    }
    ownIndex = func_ov000_0219bb50();
    gStruct217D384->mIndexMessages[ownIndex].mTalliedCourseId = menu_getRaceConfig()->mCourseId;
    gStruct217D384->mStep = 9;
    gStruct217D384->mStepFrames = 0;
}

void AdvanceWiFiSessionStep9(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 i;
    Unk0217d384_1d00 *ownRecord;
    toIndex = func_021216a8();
    if (toIndex < gStruct217D384->mStartKartCount) {
        fromIndex = func_ov000_0219bb50();
        ownIndex = func_ov000_0219bb50();
        ownRecord = &gStruct217D384->mIndexMessages[ownIndex];
        ownRecord->mKind = 7;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gStruct217D384->mKartMask;
        func_ov000_021a32a0(toIndex, &gStruct217D384->mIndexMessages[func_ov000_0219bb50()], 0x44);
    }
    if (UpdateWiFiSessionStepTimeout(0x78) == FALSE) {
        return;
    }
    for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50() && (gStruct217D384->mKartMask & (1 << i)) != 0) {
            if (SetPeerReceiveBuffer(i, gStruct217D384->mUnk_001c[i], 0x80) == FALSE) {
                return;
            }
        }
    }
    gStruct217D384->mSendRecordMask = 0;
    gStruct217D384->mReceivedMask = 0;
    gStruct217D384->mStep = 10;
    gStruct217D384->mStepFrames = 0;
}

// Only while 5 <= mStep < 9: ORs into mKartRemoveMask every kart in mKartMask that some stored mask (own included) does
// not list.
void CombineKartRemoveMask(void) {
    u8 i;
    u8 commonMask = 0xff;
    if (gStruct217D384->mStep < 5) {
        return;
    }
    if (gStruct217D384->mStep >= 9) {
        return;
    }
    for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
        if ((gStruct217D384->mKartMask & (1 << i)) != 0) {
            commonMask &= gStruct217D384->mIndexMessages[i].mKartMask;
        }
    }
    for (i = 0; i < gStruct217D384->mStartKartCount; i++) {
        if ((gStruct217D384->mKartMask & (1 << i)) != 0) {
            if ((commonMask & (1 << i)) == 0) {
                gStruct217D384->mKartRemoveMask |= 1 << i;
            }
        }
    }
}
