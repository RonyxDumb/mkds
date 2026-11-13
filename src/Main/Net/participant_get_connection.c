#include "Main/Net/participant_get_connection.h"
#include "Main/Menu/title_scene.h"
#include "os_tick.h"
#include "code_0214d018.h"
#include "mb_parent.h"
#include "Main/Net/rom_archive.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/data_02154000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Menu/select_race_rule_state.h"

const u8 gDefaultParentParameter[64] = {0, 0, 0, 0, 0, 0, 0, 0, 0x25, 0, 0, 0, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0xc8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xbc, 1, 0x36, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#pragma opt_rebuildconditionals off

static inline u32 ParticipantGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline u32 ParticipantGetWorkConnectionMode(ConnectionWork *connectionWork) {
    if (connectionWork == NULL) {
        return 0;
    }
    return connectionWork->mConnectionMode;
}

u16 GetParticipantPadKeys(u32 participantIndex) {
    BOOL stateMatches;
    u32 result;

    stateMatches = FALSE;
    switch (gConnectionWork->mState) {
        case 8:
        case 9:
            stateMatches = TRUE;
            break;
    }
    if (stateMatches != FALSE) {
        result = gConnectionWork->mSharingReceiveRecords[participantIndex].mPadKeys;
    } else {
        result = 0;
    }
    return result;
}

BOOL IsDataSharingSyncDone(void) {
    BOOL result;

    result = FALSE;
    switch (gConnectionWork->mState) {
        case 8:
        case 9:
            result = TRUE;
            break;
    }
    return result;
}

BOOL TryGetScanSlotName(u16 entryIndex, void *destination) {
    ConnectionWork *connectionWork;
    BOOL result;

    connectionWork = gConnectionWork;
    result = FALSE;
    if (ParticipantGetWorkConnectionMode(connectionWork) != 2) {
        return FALSE;
    }
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return FALSE;
    }
    if (connectionWork->mScanSlots[entryIndex].mInUse != 0) {
        if (destination != NULL) {
            MI_CpuCopy8(connectionWork->mScanSlots[entryIndex].mName, destination, 0x14);
        }
        result = TRUE;
    }
    return result;
}

BOOL IsScanSlotMultiBoot(u16 entryIndex) {
    BOOL result;
    BOOL entryValid;

    result = FALSE;
    entryValid = FALSE;
    if (ParticipantGetConnectionMode() != 2) {
        entryValid = FALSE;
    } else if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        entryValid = FALSE;
    } else if (gConnectionWork->mScanSlots[entryIndex].mInUse != 0) {
        entryValid = TRUE;
    }
    if (entryValid != FALSE) {
        if (gConnectionWork->mScanSlots[entryIndex].mMultiBoot != 0) {
            result = TRUE;
        }
    }
    return result;
}

s32 GetScanSlotChildCount(u16 entryIndex) {
    s32 result;
    BOOL entryValid;

    result = 0;
    entryValid = FALSE;
    if (ParticipantGetConnectionMode() != 2) {
        entryValid = FALSE;
    } else if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        entryValid = FALSE;
    } else if (gConnectionWork->mScanSlots[entryIndex].mInUse != 0) {
        entryValid = TRUE;
    }
    if (entryValid != FALSE) {
        result = gConnectionWork->mScanSlots[entryIndex].mChildCount;
    }
    return result;
}

BOOL TryGetPlayerName(u16 entryIndex, void *destination) {
    BOOL result;
    void *childUser;

    result = FALSE;
    switch (ParticipantGetConnectionMode()) {
        case 1:
            result = FALSE;
            if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
                childUser = MB_CommGetChildUser(entryIndex);
                if ((gConnectionWork->mWaitToSendMask & (1 << entryIndex)) != 0 && childUser != NULL) {
                    if (destination != NULL) {
                        MI_CpuCopy8((u8 *) childUser + 2, destination, 0x14);
                    }
                    result = TRUE;
                }
            } else if ((gConnectionWork->mChildren.mChildMask & (1 << entryIndex)) != 0) {
                if (destination != NULL) {
                    MI_CpuCopy8(&gConnectionWork->mPlayerRecords[entryIndex], destination, 0x14);
                }
                result = TRUE;
            }
            break;
        case 2:
            result = FALSE;
            if ((gConnectionWork->mReceivedNameMask & (1 << entryIndex)) != 0) {
                if (destination != NULL) {
                    MI_CpuCopy8(&gConnectionWork->mPlayerRecords[entryIndex], destination, 0x14);
                }
                result = TRUE;
            }
            break;
    }
    return result;
}

void FillParentParameter(s32 flag) {
    ParentParameter *parentParameter;
    UserGameInfo *gameInfo;
    RTCTime time;
    u32 hour;
    u16 seconds;
    u64 generatorState;
    u64 highWord;

    parentParameter = gConnectionWork->mParentParameter;
    MIi_CpuCopy32(gDefaultParentParameter, parentParameter, 0x40);
    gameInfo = gConnectionWork->mChildren.mGameInfo;
    gameInfo->mGameInfoPart.mHasGhost = 0;
    gameInfo->mGameInfoPart.mKartIndex = 0;
    gameInfo->mCharacterIndex = 0;
    gameInfo->mCupCourseIndex = 0;
    gameInfo->mMinute = 0;
    gameInfo->mSecond = 0;
    gameInfo->mMillisecond = 0;
    gameInfo->mGameInfoPart.mChildCount = 0;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        parentParameter->mTgid = (gConnectionWork->mParentTgid + 7) & 0x7fff;
    } else {
        GetClockTimeOrZero(&time);
        hour = time.mHour;
        if (hour >= 0x12) {
            hour -= 0x12;
        }
        seconds = (hour * 0x3c + time.mMinute) * 0x3c + time.mSecond;
        generatorState = OS_GetTickLo() | seconds << 16;
        generatorState = generatorState * 0x5d588b656c078965ull + 0x269ec3;
        highWord = generatorState >> 32;
        parentParameter->mTgid = (u16) (highWord * 0x10000 >> 32) | 0x8000;
    }
    parentParameter->mChannel = gConnectionWork->mParentChannel;
    parentParameter->mBeaconPeriod = WM_GetDispersionBeaconPeriod();
    parentParameter->mUserGameInfo = gConnectionWork->mChildren.mGameInfo;
    parentParameter->mUserGameInfoLength = 0x1c;
    parentParameter->mMaxEntry = 7;
    parentParameter->mEntryFlag = flag != 0 ? 1 : 0;
}

void FillGhostParentParameter(GhostRecordHead *ghostRecord) {
    ParentParameter *parentParameter;
    UserGameInfo *gameInfo;
    RTCTime time;
    u32 hour;
    u16 seconds;
    u64 generatorState;
    u64 highWord;

    parentParameter = gConnectionWork->mParentParameter;
    MIi_CpuCopy32(gDefaultParentParameter, parentParameter, 0x40);
    gameInfo = gConnectionWork->mChildren.mGameInfo;
    gameInfo->mGameInfoPart.mHasGhost = 1;
    MI_CpuCopy8(ghostRecord->mName, gameInfo, 0x14);
    gameInfo->mGameInfoPart.mKartIndex = ghostRecord->mKartIndex;
    gameInfo->mCharacterIndex = ghostRecord->mCharacterIndex;
    gameInfo->mCupCourseIndex = (u8) FindCupCourseIndex(ghostRecord->mCourseId);
    gameInfo->mMinute = ghostRecord->mMinute;
    gameInfo->mSecond = ghostRecord->mSecond;
    gameInfo->mMillisecond = ghostRecord->mMillisecond;
    GetClockTimeOrZero(&time);
    hour = time.mHour;
    if (hour >= 0x12) {
        hour -= 0x12;
    }
    seconds = (hour * 0x3c + time.mMinute) * 0x3c + time.mSecond;
    generatorState = OS_GetTickLo() | seconds << 16;
    generatorState = generatorState * 0x5d588b656c078965ull + 0x269ec3;
    highWord = generatorState >> 32;
    parentParameter->mTgid = (u16) (highWord * 0x10000 >> 32) | 0x8000;
    parentParameter->mChannel = gConnectionWork->mParentChannel;
    parentParameter->mBeaconPeriod = WM_GetDispersionBeaconPeriod();
    parentParameter->mUserGameInfo = gConnectionWork->mChildren.mGameInfo;
    parentParameter->mUserGameInfoLength = 0x1c;
    parentParameter->mMaxEntry = 1;
    parentParameter->mParentMaxSize = 0x1b6;
    parentParameter->mChildMaxSize = 0x2e;
}

void SetGroupSendMaskAsParent(u8 sendMask) {
    BOOL proceed;
    BOOL allowed;

    proceed = FALSE;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        allowed = TRUE;
        if (ParticipantGetConnectionMode() != 1) {
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                allowed = FALSE;
            }
        }
        if (allowed != FALSE) {
            proceed = TRUE;
        }
    }
    if (proceed == FALSE) {
        return;
    }
    if (ParticipantGetConnectionMode() != 1) {
        return;
    }
    SetRomArchiveGroupSendMask(sendMask);
}

void SetParentChannelLowestSum(void) {
    s32 index;
    s32 lowest;
    s8 lowestIndex;
    s32 value;

    lowestIndex = -1;
    lowest = 0x7fff;
    for (index = 1; index < 14; index++) {
        value = gConnectionWork->mChannelSums[index];
        if (value != -1 && value < lowest) {
            lowest = value;
            lowestIndex = index;
        }
    }
    if (lowestIndex != -1) {
        gConnectionWork->mParentChannel = lowestIndex;
        return;
    }
    gConnectionWork->mParentChannel = -1;
    gConnectionWork->mErrorCode = 3;
    gConnectionWork->mRequestPending = 0;
}
