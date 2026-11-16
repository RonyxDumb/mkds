#include "Main/Net/participant_get_connection.h"
#include "Main/Menu/title_scene.h"
#include "tick_counter.h"
#include "cpu_copy_fill.h"
#include "multiboot_parent_state_machine.h"
#include "Main/Net/rom_archive.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Race/race_setup_block.h"
#include "Main/MapObjects/map_object_park.h"

const u8 gDefaultParentParameter[64] = {0, 0, 0,    0, 0, 0, 0, 0, 0x25, 0, 0,    0, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0,
                                        0, 0, 0xc8, 0, 0, 0, 0, 0, 0,    0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0, 0, 0,    0, 0, 0, 0, 0, 0xbc, 1, 0x36, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
        case CONNECTION_STATE_SYNCED:
        case CONNECTION_STATE_SYNCED_RACE:
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
        case CONNECTION_STATE_SYNCED:
        case CONNECTION_STATE_SYNCED_RACE:
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
    if (ParticipantGetWorkConnectionMode(connectionWork) != CONNECTION_MODE_CHILD) {
        return FALSE;
    }
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return FALSE;
    }
    if (connectionWork->mScanSlots[entryIndex].mInUse != 0) {
        if (destination != NULL) {
            MI_CpuCopy8(connectionWork->mScanSlots[entryIndex].mName, destination, PLAYER_NAME_BYTES);
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
    if (ParticipantGetConnectionMode() != CONNECTION_MODE_CHILD) {
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
    if (ParticipantGetConnectionMode() != CONNECTION_MODE_CHILD) {
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
    MBUserInfo *childUser;

    result = FALSE;
    switch (ParticipantGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            result = FALSE;
            if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
                childUser = MB_CommGetChildUser(entryIndex);
                if (BIT_IS_SET(gConnectionWork->mWaitToSendMask, entryIndex) && childUser != NULL) {
                    if (destination != NULL) {
                        MI_CpuCopy8(childUser->mName, destination, PLAYER_NAME_BYTES);
                    }
                    result = TRUE;
                }
            } else if (BIT_IS_SET(gConnectionWork->mChildren.mChildMask, entryIndex)) {
                if (destination != NULL) {
                    MI_CpuCopy8(&gConnectionWork->mPlayerRecords[entryIndex], destination, PLAYER_NAME_BYTES);
                }
                result = TRUE;
            }
            break;
        case CONNECTION_MODE_CHILD:
            result = FALSE;
            if (BIT_IS_SET(gConnectionWork->mReceivedNameMask, entryIndex)) {
                if (destination != NULL) {
                    MI_CpuCopy8(&gConnectionWork->mPlayerRecords[entryIndex], destination, PLAYER_NAME_BYTES);
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
    gameInfo->mCharacterIndex = CHARACTER_MARIO;
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
        generatorState = generatorState * RANDOM_STATE64_MULTIPLIER + RANDOM_STATE64_INCREMENT;
        highWord = generatorState >> 32;
        parentParameter->mTgid = (u16) (highWord * 0x10000 >> 32) | PARENT_TGID_FLAG;
    }
    parentParameter->mChannel = gConnectionWork->mParentChannel;
    parentParameter->mBeaconPeriod = WM_GetDispersionBeaconPeriod();
    parentParameter->mUserGameInfo = gConnectionWork->mChildren.mGameInfo;
    parentParameter->mUserGameInfoLength = USER_GAME_INFO_BYTES;
    parentParameter->mMaxEntry = CHILD_LIST_MAX_CHILDREN;
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
    MI_CpuCopy8(ghostRecord->mName, gameInfo, PLAYER_NAME_BYTES);
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
    generatorState = generatorState * RANDOM_STATE64_MULTIPLIER + RANDOM_STATE64_INCREMENT;
    highWord = generatorState >> 32;
    parentParameter->mTgid = (u16) (highWord * 0x10000 >> 32) | PARENT_TGID_FLAG;
    parentParameter->mChannel = gConnectionWork->mParentChannel;
    parentParameter->mBeaconPeriod = WM_GetDispersionBeaconPeriod();
    parentParameter->mUserGameInfo = gConnectionWork->mChildren.mGameInfo;
    parentParameter->mUserGameInfoLength = USER_GAME_INFO_BYTES;
    parentParameter->mMaxEntry = 1;
    parentParameter->mParentMaxSize = CONNECTION_PARENT_MAX_SIZE;
    parentParameter->mChildMaxSize = CONNECTION_CHILD_MAX_SIZE;
}

void SetGroupSendMaskAsParent(u8 sendMask) {
    BOOL proceed;
    BOOL allowed;

    proceed = FALSE;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        allowed = TRUE;
        if (ParticipantGetConnectionMode() != CONNECTION_MODE_PARENT) {
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
    if (ParticipantGetConnectionMode() != CONNECTION_MODE_PARENT) {
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
    gConnectionWork->mErrorCode = CONNECTION_ERROR_NO_CHANNEL;
    gConnectionWork->mRequestPending = 0;
}
